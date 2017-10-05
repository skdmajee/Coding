
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>


#define MAX 32
#define MAXWORD 32 

const char *str = "The sky is blue";

char word[MAXWORD][MAX];

int 
main(int argc, char *argv[])
{

  int i=0, j=0, k=0;
  bool ff = false;
  char c;
  const char BLANK=' ';

  for (i=0, j=0; (c=str[i]) ; i++){
    if (c != BLANK) {
      word[j][k++] = c;
      ff = true;
    } else {
    // New word
      if (ff) {
        word[j][k] = 0; 
        j++;
        k=0;
        ff = false;
      }
    }
  }

  printf("got %d words\n", j);

  // Got all my word, print it reverse way
  
  for (; j >= 0; j--){
    char *p = (char *)&word[j];
    //printf("%d-th word %s ", j, p);
    printf("%s ", (char *)&word[j]);
  }
  printf("\n");

 
  return 0;
}

