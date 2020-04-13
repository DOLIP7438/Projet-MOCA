#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "dico.h"

dico* initDico(){
  dico* dictionary = (dico*) malloc(sizeof(dico));
  dictionary->mot = initMot();
  dictionary->next = NULL;
  return dictionary;
}

unsigned int getMask(int k) {
  switch(k) {
  case 0:
    return 0x3E000000;
    break;
  case 1:
    return 0x01F00000;
    break;
  case 2:
    return 0x000F8000;
    break;
  case 3:
    return 0x00007C00;
    break;
  case 4:
    return 0x000003E0;
    break;
  case 5:
    return 0x0000001F;
    break;
  }
  return 0x00000000;
}

void insertDico(dico* dictionary, mot_t* linkWord) {
  dico* newDictionary = (dico*) malloc(sizeof(dico));
  dico* newDictionaryPrevious = (dico*) malloc(sizeof(dico));
  newDictionary = dictionary;
  newDictionaryPrevious = newDictionary;
  int cmpword=compareWord(newDictionary->mot,linkWord);
  while(cmpword<0 && newDictionary != NULL) {
    if (newDictionary->next == NULL) {
      addTailWord(newDictionary,linkWord);
      return;
    } else {
      newDictionaryPrevious = newDictionary;
      newDictionary = newDictionary->next;
    }
    cmpword=compareWord(newDictionary->mot,linkWord);
  }
  if (cmpword==0) { 
    incWord(newDictionary->mot->queue_liste,linkWord->tete_liste->line,linkWord->tete_liste->colonne);
  } else { //
    if (newDictionary == dictionary) {
      addHeadWord(newDictionary,linkWord);
    } else {
      addTailWord(newDictionaryPrevious,linkWord);
    }
  }
}

void addToDico(dico* dictionary, char* word, unsigned int* line, unsigned int* colonne) {
  mot_t* newLinkWord = generateMot_t (word, line, colonne);
  if (dictionary == NULL) {
    dico *newDictionary = (dico*) malloc(sizeof(dico));

    newDictionary->mot = newLinkWord;
    newDictionary->next = NULL;
    dictionary = newDictionary;

  } else if (dictionary->mot == NULL) {
    dictionary->mot = newLinkWord;
  } else {
    insertDico(dictionary,newLinkWord);
  }
}

void displayDico(dico* dictionary) {
  FILE *f = NULL;
  f = fopen(DICORES, "w+");
  if (f == NULL){
	fprintf(stderr,"Le fichier n'existe pas ou n'a pas pu être ouvert en mode lecture/ecriture!!!!!!!!!!!!\n");
	exit(0);
  }
  if (!feof(f))
    printf("Resultat existant dans le fichier resultat, on ecrase\n");
  if (dictionary == NULL) {
    printf("displayDico : NULL\n");
  } else {
    fprintf(f, "Contenu dictionnaire pour %s : \n", TEXTE);
    dico* tempDico = (dico*) malloc(sizeof(dico));
    tempDico = dictionary;
    while(tempDico != NULL) {
      displayWord(tempDico->mot,f);
      fprintf(f, "\n");
      tempDico = tempDico->next;
    }
    free(tempDico);
  }
}

