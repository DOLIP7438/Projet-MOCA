#ifndef _DICO_H_
#define _DICO_H_

#include "dataStruct.h"
#include "globals.h"
#include "macro.h"
#include "charFunc.h"
#include "conversion.h"
#include "maillon.h"
#include "wordFunc.h"

dico* initDico();

void addToDico(dico* dictionary, char* word, unsigned int* line, unsigned int* colonne);

void displayDico(dico* dictionary);

void insertDico(dico* dictionary, mot_t* linkWord);

unsigned int getMask(int k);

#endif
