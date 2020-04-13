PROF=/home/m/monniaud
PATH=$PROF/bin:$PATH
LD_LIBRARY_PATH=$PROF/lib:$LD_LIBRARY_PATH
KLEE=$PROF/packages/klee/2017-09-26_c7a1f9d/
export LD_LIBRARY_PATH
export KLEE

LLVM_COMPILER=clang
export LLVM_COMPILER

PYTHONPATH=$PROF/.local/lib/python2.7/site-packages/
export PYTHONPATH
