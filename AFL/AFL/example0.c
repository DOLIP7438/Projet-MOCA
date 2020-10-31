// basic BoF 

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{ 
  int t[100] ; 
  FILE *f = fopen(argv[1], "r") ;
  int i;
  int i1 ;
  int *p ;

  p = NULL ;
  if (argc != 2) return 1 ;
  fscanf(f, "%d", &i1) ;
  for (i=0;i<=i1;i++) { 
	  t[i]= t[i] -1;
  	  if (i>100) *p = 1 ;
  }
  fclose (f) ;
  return 0 ;
}
