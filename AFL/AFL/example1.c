// basic BoF 
// but no crash when compiled with -03 !

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{ 
  int i1 ;
  FILE *f = fopen(argv[1], "r") ;
  int t[2] ; 

  if (argc != 2) return 1 ;
  fscanf(f, "%d", &i1) ;
  if (i1==54365476) {
	  t[100]= 0;
  }
  fclose (f) ;
  return 0 ;
}
