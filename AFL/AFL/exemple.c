#include <stdlib.h>
#include <assert.h>

int example0 (int i1) 
{ 
  int t[2] ; 
  int i;

  for (i=0;i<=i1;i++) { 
	  t[i]= 0;
  }
  return 0 ;
}


int example1 (int i1) 
{ 
  int t[2] ; 

  if (i1==54365476) {
	  t[100]= 0;
  }
  return 0 ;
}

void example2 (int x, int y) 
{
   int z ;
   // assert (x+10 != 0)
   int *t = (int *) malloc((x+10) * sizeof(int)) ;
   z = 2*y ;
   if (x == z) {
      // assert (y <= x +10) ;
      // assert (y > 0) ;
      t[y] = 0 ;
   }
}

void example3 (int x, int y) 
{
   int z ;
   assert (x+10 != 0) ;
   int *t = (int *) malloc((x+10) * sizeof(int)) ;
   z = 2*y ;
   if (x == z) {
      assert (y <= x +10) ;
      assert (y > 0) ;
      t[y] = 0 ;
   }
}

