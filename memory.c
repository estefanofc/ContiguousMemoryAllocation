//
// Created by Estefano Felipa on 5/26/20.
//
#include <stdio.h>
#include <unistd.h>
#include <assert.h>     // assert
#include <fcntl.h>      // O_RDWR, O_CREAT
#include <stdbool.h>    // bool
#include <stdio.h>      // printf, getline
#include <stdlib.h>     // calloc
#include <string.h>     // strcmp
#include <unistd.h>     // execvp
#include <sys/wait.h>   // wait
#define MAX_LINE 80 /* The maximum length command*/
void bestFit() {

}

void firstFit() {

}

void worstFit() {

}

void allocate(char process, int size, char algo) {

}

void freeAllocations(char process) {

}

void showState() {

}

void readfile(char *line) {

}

void compact() {

}

int readline(char **buffer) {
  size_t len;
  int number_of_chars = getline(buffer, &len, stdin);
  if (number_of_chars > 0) {
    //get rid of \n
    (*buffer)[number_of_chars - 1] = '\0';
  }
  return number_of_chars;
}

int tokenize(char *line, char **tokens) {
  char *pch;
  pch = strtok(line, " ");
  int num = 0;
  while (pch != NULL) {
    tokens[num] = pch;
    num++;
    pch = strtok(NULL, " ");
  }
  return num;
}
