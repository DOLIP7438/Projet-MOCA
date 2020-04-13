#!/bin/bash
selection(){
	echo "#########################################"
	echo "#	   -AFL	    	-Valgrind	#"
	echo "#	   -ASan    	-Klee    	#"
	echo "#	   -Test_Unit   -ALL	 	#"
	echo "#		  -Quit		 	#"
	echo "#########################################"
	echo
	echo "Saisir le mode de debug :"
	read saisie
	val_ret=$saisie
}

AFL_prog(){
	make clean
	source setup_afl/installe_afl.sh
	make LIBS=d AFL=1
	afl-fuzz -i afl_in/ -o afl_out/ ./main @@
}

Valgrind_prog(){
	make clean
	case $1 in
		d | s)
			make LIBS=$1 DEBUG=1
			if [ $1 == d ]
			then
				valgrind --log-file=Resultat_valgrind/Resultat_Dynamique.txt ./main donnees/$2
			else
				valgrind --log-file=Resultat_valgrind/Resultat_Statique.txt ./main donnees/$2
			fi
		;;
		a)
			make LIBS=s DEBUG=1
			valgrind --log-file=Resultat_valgrind/Resultat_Statique.txt ./main donnees/$2
			make clean
			make LIBS=d DEBUG=1
			valgrind --log-file=Resultat_valgrind/Resultat_Dynamique.txt ./main donnees/$2
		;;
		*)
			echo "Option : $1 non connu"
		;;
	esac
}

ASan_prog(){
	echo "a faire ASan"
}

Klee_prog(){
	echo "a faire Klee"
}
Test_unitaire(){
	make clean
	make LIBS=d TEST=1
	./main
}
affiche(){
	echo "################################################################################"
	echo "			Programme executé : $1 "
	echo "################################################################################"
}
option_valgrind(){
	echo "Choisir option de linkage de la bibliothèque"
	echo " Statique - s	Dynamique - d Les deux modes - a "
	read option
	echo "Selectionnez un nom de fichier :"
	echo "-------------------------------------------------------------------------------------------------------------------------------------------------"
	ls donnees
	echo "-------------------------------------------------------------------------------------------------------------------------------------------------"
	read fichier
}
All_prog(){
	affiche Valgrind
		option_valgrind
		Valgrind_prog $option $fichier
	affiche ASan
		ASan_prog
	affiche Klee
		Klee_prog
	affiche Test_Unitaire
		Test_unitaire
	affiche AFL
		AFL_prog
}
val_ret=""
while [[ $val_ret != "Quit" ]]
do
	selection
	case $val_ret in
		AFL)
			AFL_prog
		;;
		Valgrind)
			option_valgrind
			Valgrind_prog $option $fichier
		;;
		ASan)
			ASan_prog
		;;
		Klee)
			Klee_prog
		;;
		Test_Unit)
			Test_unitaire
		;;
		ALL)
			All_prog
		;;
		Quit);;
		*)
			echo "Aucun débug connu ! Veuillez selection les commandes ci dessous"
		;;
	esac
done

