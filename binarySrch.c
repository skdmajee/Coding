#include <stdio.h>
#include <stdbool.h>


bool bsrch(int find, int a[], int n, int *pos);
#define MAX 20
int main(int argc, char *argv[])
{
  int a[MAX];
  int sz=0;
  int i, find, pos, ret;

  printf("\ninput values : array size ");
  scanf("%d", &sz);
  if (sz > MAX) return 1;
 
  printf("Input vals \n");
  for (i=0; i<sz; i++){
    scanf("%d", &a[i]);
  }
 
  while (true) {
    printf ("\nSearch val = ");
    scanf("%d", &find);

    ret = bsrch(find, a,sz, &pos);

    if (ret) 
        printf("Found %d at pos %d\n", find, pos);
    else
        printf("Not found\n");
  }
  return 0;
}

bool bsrch(int find, int a[], int n, int *pos)
{

  int mid, st, end;
  int i;

  *pos = -1;
  st=0;
  end=n-1;

  if (n < 1) return false;

  if (n == 1) {
    if (find == a[st]){
      *pos = st;
      return true;
    }else{
      return false;
    }
  }
 

  while (st <= end ) {

    mid = (end+st)/2;
    if (a[mid] == find) {                                                                   
      *pos = mid;
      return true;
    } else if (find < a[mid]) {
      end = mid -1;
    } else if (find > a[mid]){
      st = mid + 1;
    } else {
      printf("Very weird..st(%d) end(%d) mid(%d)\n", st,end,mid);
    }
  
    printf("st(%d) end(%d) pos(%d)\n", st, end, *pos);
    if ((end < 0) || (st > n))
      return false;
    if (st == end ){
      if (a[st] == find) {
        *pos = st;
        return true;
      } else 
        return false;
    }
  }//while

  return (false);
}
