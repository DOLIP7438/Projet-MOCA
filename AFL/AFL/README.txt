
%=====================================================================

Installing AFL


%=====================================================================

Using AFL


# before starting, make sure that a core will be produced 
# in the current directory in case of crash ...
sudo bash -c 'echo core >  /proc/sys/kernel/core_pattern'

# compile the example with instrumented code
# (seems required to enforce non 03 optimization to preserve crashes !)
AFL_DONT_OPTIMIZE=1 afl-gcc exo_5.c 

# launch the fuzzing campaign (ended by ^C)
AFL_SKIP_CPUFREQ=1 afl-fuzz -i testcases/ -o findings/ ./a.out @@

# build a graphical summary of the fuzzing campaign (optionnal)
mkdir plot ; fl-plot findings plot

# if crashes have been found, you can re-run the target pgm 
# with the corresponding input file ...
./a.out findings/crashes/....

%=====================================================================

Some small examples

* example0.c - initial seed exo.txt
* example1.c - initial seed ex1.txt

% ---------------------------------------------------------------

A voir :

- autres exemples AFL ?
   - les notres ??
   - des exemples de la distrib ?

- un exemple sans fichier ???
   on ne peut fuzzer que des entrees sur file ou sur stdin ...

% ---------------------------------------------------------------


Bilan des exemples :
   exo_5.c : OK
   exemple1-BO.c : PAS DE CRASH TROUVE ???
   exemple2-BO.c : PAS DE CRASH TROUVE ???

