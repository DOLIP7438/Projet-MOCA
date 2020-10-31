
# compile the example with instrumented code
# (seems required to enforce non 03 optimization to preserve crashes !)
echo "compile the pgm for AFL"
AFL_DONT_OPTIMIZE=1 ../afl-2.52b/afl-gcc $1 

# launch the fuzzing campaign (ended by ^C)
echo "run AFL !"
AFL_SKIP_CPUFREQ=1 ../afl-2.52b/afl-fuzz -i testcases/ -o findings/ ./a.out @@
