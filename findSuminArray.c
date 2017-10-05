/*
 * given a sorted array find if there exists two number whose SUM equals 
 * the given values. If the array is not sorted then sort in increasing order first.
 * A variation of this problem is to provide find 3 numbers (or n) whose sum equals value
 */


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int a[] = {1, 2, 4, 7, 11, 15};

int findSum(int a[], int len, int val)
{
  int low=0,
      high= len-1;
  int found = 0;
  int sum = 0;

  /*
   * if sum(l+h) > val then h--
   * else if sum(l+h) < val then l++
   * else equal foud!
   */

  
  while (low < high ) {
   sum = a[low]+a[high];
   if (sum == val) {
     found = 1;
     break;
   } else if (sum > val) {
     high--;
   } else {
     low++;
   }
  }
  if (found) {
    printf("val(%2d) = %2d + %2d\n", val, a[low], a[high]);
    return 1;
  }

  return 0;
}

void main(){

  int n = sizeof(a)/sizeof(int);
  int ret;

  ret = findSum(a, n, 15);

}

