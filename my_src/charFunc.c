#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "charFunc.h"

emplacement_t* initEmplacement(){
  emplacement_t* em = (emplacement_t*) malloc(sizeof(emplacement_t));
  em->line = 0;
  em->colonne = 0;
  em->next = NULL;
  return em;
}

void setCharnum(maillon_t* link, int k, char c) {
  if (link == NULL) {
    printf("setCharnum : link null\n");
  } else {
    link->elem = (link->elem & ~getMask(k)) + ((unsigned int)CHARTONUM(c) << (5*(5-k)));
  }
}


/*
 *
 * */
char getCharnum(maillon_t* link, int k) {
  if (link == NULL) {
    printf("getCharnum : link null\n");
    return '#';
  } else {
    return NUMTOCHAR((link->elem & getMask(k)) >> (5*(5-k)));
  }
}


/* Renvoi 1 si la lettre est comprise entre
 * a et z
 * */
int isAvailable(char c) {
  if (c < 'a' || c > 'z') {
    return 0;
  } else {
    return 1;
  }
}
