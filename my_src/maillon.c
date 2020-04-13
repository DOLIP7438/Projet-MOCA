#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "maillon.h"
#include "charFunc.h"

maillon_t* initMaillon(){
  maillon_t* m = (maillon_t*) malloc(sizeof(maillon_t));
  m->elem = 0;
  m->next = NULL;
  return m;
}

int getSizeMaillon(maillon_t* link) {
  if (link == NULL) {
	  return 0;
  } else {
    int i = 0,res = 0;
    maillon_t* useLink = link;
    while(useLink != NULL) {
      for(i=0;i<=5;i++) {
	if  (isAvailable(getCharnum(useLink,i)) == 0) {break;}
	res++;
      }
      useLink = useLink->next;
    }
    free(useLink);
    //On a oublié de retourner le résultat
    return res;
  }
}
