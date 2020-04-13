#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "charFunc.h"
#include "conversion.h"
#include "dico.h"
#include "globals.h"
#include "macro.h"
#include "maillon.h"
#include "wordFunc.h"

mot_t* initMot(){
  mot_t* mot = (mot_t*) malloc(sizeof(mot_t));
  mot->tete_mot = initMaillon();
  mot->queue_mot = initMaillon();
  mot->tete_liste = initEmplacement();
  mot->queue_liste = initEmplacement();
  return mot;
}

mot_t* generateMot_t(char* word, unsigned int* line, unsigned int* colonne) {
  mot_t* newLinkWord = (mot_t*)malloc(sizeof(mot_t));
  emplacement_t* location = (emplacement_t*)malloc(sizeof(emplacement_t));
  newLinkWord->tete_mot = stringToMaillon(word);
  newLinkWord->queue_mot = newLinkWord->tete_mot;
  location->line = *line;
  location->colonne = *colonne;
  newLinkWord->tete_liste = location;
  newLinkWord->queue_liste = location;
  return newLinkWord;
}

void displayWord(mot_t* word, FILE* filedes) {
  if (word == NULL) {
  } else {
    maillon_t* link = word->tete_mot;
    emplacement_t* list = word->tete_liste;
    if (link != NULL) {
      fprintf(filedes, "%s", maillonToString(link));
      fflush(stdout);
    }
    while (list != NULL) {
      fprintf(filedes, " (%i,%i)", list->line, list->colonne);
      list = list->next;
    }
    free(link);
    free(list);
  }
}

char* next_word(FILE* f, unsigned int* nblin, unsigned int* nbcol) {
  char s[100];
  char* res;
  unsigned int i = 0, startl = current_line, startc = current_col;
  char sep;
  //int bad_char = 0;
  sep = fgetc(f);
  while (strchr(separators, sep) != NULL || sep == '\n') {
    startc++;
    if (sep == '\n') {
      startl++;
      startc = 1;
    }
    sep = fgetc(f);
  }
  ungetc(sep, f);
  if (nblin != NULL) *nblin = startl;
  if (nbcol != NULL) *nbcol = startc;
  while ((strchr(separators, s[i] = fgetc(f)) == NULL) && s[i] != '\n') {
    //printf("char : %c\n",s[i]);
    if (!islower(s[i])) {
      //bad_char = 1;
      fprintf(stderr, "Mauvais caractère lu %c\n",s[i]);
      exit(1);
    }
    i++;
    startc++;
  }
  sep = s[i];
  s[i] = '\0';
  res = (char*)malloc(strlen(s) + 1);
  strcpy(res, s);
  while (strchr(separators, sep) != NULL || sep == '\n') {
    startc++;
    if (sep == '\n') {
      startl++;
      startc = 1;
    }
    sep = fgetc(f);
  }
  ungetc(sep, f);
  current_line = startl;
  current_col = startc;
  //if (bad_char) return NULL;
  return res;
}

int compareWord(mot_t* w1, mot_t* w2) {
  if (w1 == NULL) {
    return 1;
  } else if (w2 == NULL) {
    return -1;
  } else {
    char* word1 = maillonToString(w1->tete_mot);
    char* word2 = maillonToString(w2->tete_mot);
    int minSize = (strlen(word1) < strlen(word2)) ? strlen(word1) : strlen(word2);
    int i = 0;  //,j = 0;
    int pos = 0;
    while (i < minSize && pos == 0) {
      pos = (word1[i] < word2[i]) ? -1 : (word1[i] > word2[i]) ? 1 : 0;
      i++;
    }
    return (pos == 0 && strlen(word1) < strlen(word2)) ? -1 : (pos == 0 && strlen(word1) > strlen(word2)) ? 1 : pos;
  }
}

void addTailWord(dico* dictionary, mot_t* linkWord) {
  dico* newDictionary = (dico*)malloc(sizeof(dico));
  newDictionary->mot = linkWord;
  newDictionary->next = NULL;
  if (dictionary->next == NULL) {
    dictionary->next = newDictionary;
  } else {
    newDictionary->next = dictionary->next;
    dictionary->next = newDictionary;
  }
}

void addHeadWord(dico* dictionary, mot_t* linkWord) {
  dico* newDictionary = (dico*)malloc(sizeof(dico));
  newDictionary->mot = linkWord;
  newDictionary->next = dictionary;
  dictionary = newDictionary;
}

void incWord(emplacement_t* location, unsigned int line, unsigned int colonne) {
  emplacement_t* newLocation = (emplacement_t*)malloc(sizeof(emplacement_t));
  emplacement_t* tempLocation = (emplacement_t*)malloc(sizeof(emplacement_t));
  tempLocation = location;
  newLocation->next = NULL;
  newLocation->line = line;
  newLocation->colonne = colonne;
  while (tempLocation->next != NULL) {
    tempLocation = tempLocation->next;
  }
  tempLocation->next = newLocation;
  //free(newLocation);
  //free(tempLocation);
}
