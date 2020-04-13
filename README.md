# Projet-MOCA
[README]				MOCA
Noel-Lardin Thomas			Résumé
Lang Hoai
Moissonnier Shane
Martinez Anthony

MAKEFILE : 

Utiliser la commande : make CFLAGS=-DDEBUG
pour activer le debug à partir du Makefile

Utiliser la commande : make CFLAGS=-DN=valeur de n
pour changer dynamiquement la valeur de N par défaut

#	Compiler bibliotheque statique -> make LIBS=s
#	Compiler bibliotheque dynamique -> make LIBS=d
#	Par default, compile avec fichier locaux
#	Rajouter TEST=1 dans la commande pour compiler (En dynamique) avec les tests 
#	AFL source ~mounlaur/installe_afl.sh
# 	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./my_lib
#	COV=1 pour test couverture
#	make rungcov pour lancer gcov
#	AFL=1 pour le fuzzing
#	Pour Klee, source ~monniaud/env.sh dans le terminal
#	KLEE=1 pour utliser KLEE
#	ASAN=1 pour utiliser ASAN et il faut lancer en dynamique
#	Pour le lancer en mode debug DEBUG=1

Arborescence :
.
├── afl_in //fichier texte utilisé par AFL pour faire ses tests
│   ├── hugo.txt
│   └── orwell.txt
├── afl_out //dossier contenant les résultats d’AFL
│   ├── crashes //problèmes trouvés
│   │   ├── id:000000,sig:11,src:000000,op:flip1,pos:445
│   │   ├── id:000001,sig:11,src:000000,op:flip2,pos:444
│   │   .
│   │   .
│   │   .
│   │   ├── id:000035,sig:11,src:000000,op:havoc,rep:128
│   │   └── README.txt
│   ├── fuzz_bitmap
│   ├── fuzzer_stats
│   ├── plot_data
│   └── queue
│     	.
│       ├── id:000184,src:000000,op:havoc,rep:128
│       └── id:000185,src:000000,op:havoc,rep:128
├── debug.sh //script bash pour automatiser les tests
├── dictionnaires.txt //Fichier de sortie contenant le dictionnaire créé
├── donnees //dossier contenant tous nos fichiers textes pour les tests
│   ├── diction.txt
│   ├── fic1.txt
│   ├── hugo1.txt
│   ├── hugo.txt
│   ├── or1.txt
│   ├── orwell.txt
│   ├── res1.txt
│   └── wells.txt
├── main //Exécutable 
├── Makefile
├── my_header //Dossier contenant tous les .h
│   ├── AllTests.h
│   ├── charFunc.h
│   ├── conversion.h
│   ├── dataStruct.h
│   ├── dico.h
│   ├── globals.h
│   ├── macro.h
│   ├── maillon.h
│   ├── tests
│   │   └── AllTests.h
│   └── wordFunc.h
├── my_lib //Dossier contenant les bibliothèques statique et dynamique
│   ├── lib_obj
│   ├── test_lib
│   │   ├── CuTest.c
│   │   └── CuTest.h
│   └── test_obj
├── my_obj // Dossier contenant les fichiers pour les tests de couverture
│   └── tests
│       ├── AllTests.gcda
│       ├── AllTests.gcno
│       ├── AllTests.o
│       ├── SuiteDeTests.gcda
│       ├── SuiteDeTests.gcno
│       └── SuiteDeTests.o
├── my_src //Dossier avec tous les fichiers sources
│   ├── charFunc.c
│   ├── conversion.c
│   ├── dico.c
│   ├── maillon.c
│   ├── main.c
│   ├── tests
│   │   ├── AllTests.c
│   │   └── SuiteDeTests.c
│   └── wordFunc.c
├── README //contient tous les changements effectué au cours du projet
├── Resultat_valgrind //dossier contenant les fichiers avec les erreurs de valgrind
│   └── Resultat_Dynamique.txt //Erreurs trouvées avec la bibliothèque dynamique
├── setup_afl //dossier contenant les fichiers source pour utiliser AFL
│   └── installe_afl.sh
├── setup_klee //dossier contenant les fichiers source pour utiliser Klee
│   └── env.sh
└── test_couverture  ├── id:000000,orig:hugo.txt
│      	.
│    	.
│    	.
│       ├── id:000184,src:000000,op:havoc,rep:128
│       └── id:000185,src:000000,op:havoc,rep:128
├── debug.sh //script bash pour automatiser les tests
├── dictionnaires.txt //Fichier de sortie contenant le dictionnaire créé
├── donnees //dossier contenant tous nos fichiers textes pour les tests
│   ├── diction.txt
│   ├── fic1.txt
│   ├── hugo1.txt
│   ├── hugo.txt
│   ├── or1.txt
│   ├── orwell.txt
│   ├── res1.txt
│   └── wells.txt
├── main //Exécutable 
├── Makefile
├── my_header //Dossier contenant tous les .h
│   ├── AllTests.h
│   ├── charFunc.h
│   ├── conversion.h
│   ├── dataStruct.h
│   ├── dico.h
│   ├── globals.h
│   ├── macro.h
│   ├── maillon.h
│   ├── tests
│   │   └── AllTests.h
│   └── wordFunc.h
├── my_lib //Dossier contenant les bibliothèques statique et dynamique
│   ├── lib_obj
│   ├── test_lib
│   │   ├── CuTest.c
│   │   └── CuTest.h
│   └── test_obj
├── my_obj // Dossier contenant les fichiers pour les tests de couverture
│   └── tests
│       ├── AllTests.gcda
│       ├── AllTests.gcno
│       ├── AllTests.o
│       ├── SuiteDeTests.gcda
│       ├── SuiteDeTests.gcno
│       └── SuiteDeTests.o
├── my_src //Dossier avec tous les fichiers sources
│   ├── charFunc.c
│   ├── conversion.c
│   ├── dico.c
│   ├── maillon.c
│   ├── main.c
│   ├── tests
│   │   ├── AllTests.c
│   │   └── SuiteDeTests.c
│   └── wordFunc.c
├── README //contient tous les changements effectué au cours du projet
├── Resultat_valgrind //dossier contenant les fichiers avec les erreurs de valgrind
│   └── Resultat_Dynamique.txt //Erreurs trouvées avec la bibliothèque dynamique
├── setup_afl //dossier contenant les fichiers source pour utiliser AFL
│   └── installe_afl.sh
├── setup_klee //dossier contenant les fichiers source pour utiliser Klee
│   └── env.sh
└── test_couverture //fichier contenant les résultats lorsqu'on lance gcov à partir du MAKEFILE


Changements effectués :
	TP2 :
En compilant le programme « dico.c » nous obtenons les warnings suivants :

	- warning : implicit declaration of function ‘setCharnum’
	- warning : conflicting types for ‘setCharnum ‘

	Ces deux warnings sont liés,ils proviennent de la déclaration de la fonction ‘setCharnum ‘ qui est utilisée dans une fonction située avant la définition de ‘setCharnum’. Pour régler le problème il suffit de déplacer la définition de la fonction ‘setCharnum’ avant les fonctions qu’ils l’utilisent.

	- In function ‘compareWord’:
	  warning : unused variable ‘j’
		int i, j = 0;
	Nous l'avons remplacé par ça :
		int i; //j = 0; »


	- In function ‘getSizeMaillon’:
	dico.c:175:1: warning: control reaches end of non-void function

	Ce warning provient du fait que la fonction ‘getSizeMaillon’ est censé retourner un int et que dans la condition « else » aucune valeur n’est retournée.
	Nous avons donc retourné la valeur de res. Ajout dde la ligne return res;


	-2 : En exécutant le programme dico nous observons une erreur de segmentation.
	En suivant le trace de gdb nous remarquons que le programme tente d’ouvrir un fichier qui n’existe pas en l’occurrence « dictionnaires.txt » dans la fonction « displayDico ». 
	Pour régler le problème nous avons rajouté une condition pour vérifier que le descripteur de fichier n’est pas null et dans le cas où il le serait afficher un message d’erreur et quitter le programme avec « exit(0) ; ».
	if (f == NULL){
       		fprintf(stderr,"Le fichier n'existe pas ou n'a pas pu être ouvert en mode lecture/ecriture\n");
        		exit(0);
  	}


	-3 : Pour pouvoir passer le nom du fichier d’entrée en paramètre nous avons modifié la fonction main avec cette nouvelle définition : int main(int argc, char* argv[])
	Une fois dans le main nous vérifions au début que l’utilisateur n’a pas oublié de donner le nom du fichier en paramètre, sinon on quitte le programme. 
	if (argc < 2){
        		printf("Vous avez oublié le nom du fichier d'entrée : \n\t./%s <NOM_FICHIER>\n", argv[0]);
        		exit(0);
  	}
	Ensuite on vérifie que le fichier passé en paramètre est valide, et qu’on puisse le lire, dans le cas contraire on quitte le programme en affichant un message d’erreur.
	f = fopen(argv[1], "r");
  	if (f == NULL){
       		fprintf(stderr,"Le fichier n'existe pas ou n'a pas pu être ouvert en mode lecture/ecriture\n");
        		exit(0);
  	}
	
	-Déclaration de variables globales dans global.h :
		separators;
		current_line;
		current_col;
	 Initialisation dans main.c :
	 	separators = SEP;
    		current_line = 1;
    		current_col = 1;


	TP4 : tests
	- maillon.c : getSizeMaillon() ajout de return res
	- wordFunc.c : compareWord() initialisation de i à 0
	-  macro.h : ajout de separateurs (macro SEP)
	On n'a pas réussi à corriger l'erreur : suivant le premiers mot ajouté, 
	les mots suivants qui sont avant dans l'odre lexicographique ne sont pas ajouté au dictionnaire (insertDico() ?), dico.c
	
	TP5 : fuzzing
	- wordFunc.c: next_word() arrete le prg si le char est non lowercase
	-  macro.h : ajout de separateurs supplémentaires (macro SEP)
	Plus aucune erreur décetée par Fuzzing
	
	TP6 :
		Klee nous a trouvé une erreur de type "Error: memory error: out of bound pointer" mais nous n'avons pas réussi à la corriger.
		Asan nous renvoie une segmentationFault que nous n'avons pas réussi à corriger non plus.

Utilisation de Valgrind :
	- valgrind ./main <FICHIER>
	- valgrind --log-file=problems ./main <FICHIER>
	
	Correction : 
	//+2 for the last char
	conversion.c : maillonToString() char* word = (char*) malloc(sizeof(char)*getSizeMaillon(link)+2);
	main.c : initialisation 
	dictionary->mot = NULL;
    	dictionary->next = NULL;
	
	Nous n'avons pas réussi à corriger l'erreur : 
	wordFunc.c : compareWord(), word1 et word2 sont mal initialisés, l'erreur provient peut être de maillonToString()
