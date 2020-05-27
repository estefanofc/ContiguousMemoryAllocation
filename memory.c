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
#define MEM_SIZE 80 /* The maximum length command*/

char *memory;

void bestFit() {

}

void firstFit(char process, int size) {
  if (size > MEM_SIZE)
    return;
  int count = 0;
  int start = 0;
  for (int i = 0; i < MEM_SIZE; ++i) {
    if (memory[i] == '.') {
      start = i;
      int j = i;
      while (memory[j] == '.') {
        count++;
        j++;
      }
      if (count >= size)
        break;
      count = 0;
      i = j - 1;
    }
  }
  if (count < size)
    return;
  for (int i = start; i < start + size; ++i) {
    if (memory[i] == '.')
      memory[i] = process;
  }
}

void worstFit() {

}

void allocate(char process, int size, char algo) {
//  printf("%c", process);
//  printf("%d", size);
//  printf("%c", algo);
  switch (algo) {
  case 'F':firstFit(process, size);
    printf("Allocated %d for process %c\n", size, process);
    break;
  case 'B':bestFit();
    printf("Allocated %d for process %c\n", size, process);
    break;
  case 'W':worstFit();
    printf("Allocated %d for process %c\n", size, process);
    break;
  default:printf("Invalid algorithm\n");
    break;
  }
}

void freeAllocations(char process) {
  printf("Freeing process: %c\n", process);
  bool found = false;
  for (int i = 0; i < MEM_SIZE; ++i) {
    if (memory[i] == process) {
      memory[i] = '.';
      found = true;
    }
  }
  if (!found)
    printf("Process %c not in memory\n", process);
}

void showState() {
  printf("Showing state of the memory pool\n");
  for (int i = 0; i < MEM_SIZE; ++i) {
    printf("%c", memory[i]);
  }
  printf("\n");
}

void readfile(char *line) {
  printf(line);
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

void execute() {

}

int main() {
  memory = (char *) malloc(MEM_SIZE * sizeof(char));
  for (int i = 0; i < MEM_SIZE; ++i)
    memory[i] = '.';
  char *args[MAX_LINE / 2 + 1];/* command line arguments */
  char *cmdLine = (char *) malloc(MAX_LINE * sizeof(char));
  for (int i = 0; i < MAX_LINE / 2 + 1; ++i)
    args[i] = NULL;
  while (1) {
    fflush(stdout);
    int len = readline(&cmdLine);
    if (len <= 0)
      break;
    if (strcmp(cmdLine, "") == 0)
      continue;
    if (strcmp(cmdLine, "E") == 0)
      break;
    if (strcmp(cmdLine, "S") == 0) {
      showState();
      continue;
    }
    if (strcmp(cmdLine, "C") == 0) {
      printf("C");
      compact();
      continue;
    }
    int num_of_tokens = tokenize(cmdLine, args);
    if (strcmp(args[0], "A") == 0) {
      allocate(args[1][0], atoi(args[2]), args[3][0]);
      continue;
    }
    if (strcmp(args[0], "F") == 0) {
      freeAllocations(args[1][0]);
      continue;
    }
    if (strcmp(args[0], "R") == 0) {
      readfile(args[1]);
      continue;
    }
    for (int i = 0; i <= num_of_tokens; ++i)
      args[i] = NULL;
  }
  printf("Exiting \n");
  return 0;
}




