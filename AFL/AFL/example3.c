// basic BoF 
// but no crash when compiled with -03 !

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char *argv[]) 
{ 
  int x, y, z ;
  FILE *f = fopen(argv[1], "r") ;

  if (argc != 2) return 1 ;
  fscanf(f, "%d", &x) ;
  fscanf(f, "%d", &y) ;
   assert (x+10 != 0) ;
   int *t = (int *) malloc((x+10) * sizeof(int)) ;
   z = 2*y ;
   if (x == z) {
      assert (y <= x +10) ;
      assert (y > 0) ;
      t[y] = 0 ;
   }
  fclose (f) ;
  return 0 ;
}


