
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>


#define MAX 32
#define MAXWORD 32 

const char *str = "The sky is blue";

struct words {
  char *start; 
  char *end;
  int len;
} words[MAX];

const char SPACE=' ';
char buf[MAX];

int 
main(int argc, char *argv[])
{

  int i=0, j=0;
  bool blank = true; 
  char c, *p;

  p = (char *)str;

  //skip over begining whitespace
  while (*p == SPACE) 
    p++;
  
  for (i=0; *p ; p++){
    c=*p;
    if (c != SPACE ) {
      if (blank) {
        words[i].start = p;
        words[i].len = 1;
        blank = false;
      } else { //accumulate
        words[i].len++;
      }
    } else { 
      if (blank == false) {
        words[i].end = p;
        i++;
      }
      blank = true;
    }
  }//for

  printf("got %d words\n", i);

  // Got all my word, print it reverse way
  
  for (j=i; j >= 0; j--){
    memcpy((void *)buf, (void *)(words[j].start), words[j].len);
    buf[words[j].len] = 0;
    printf("%s ", buf);
  }
  printf("\n");

 
  return 0;
}

