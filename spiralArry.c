
#include <stdio.h>
#include <stdbool.h>

int a[4][5]={
      {1,2,3,4,5},
      {6,7,8,9,10},
      {11,12,13,14,15},
      {16,17,18,19,20}
};

void dumpA(int m, int n)
{
  int i, j;

  for (i=0; i<m; i++){
    for(j=0; j<n; j++)
      printf("%2d ", a[i][j]);
    printf("\n");
  }
}
void pp(int row, int col, int lc, int ur, int m, int n)
{
  printf("\n row(%2d) col(%2d) lc(%2d) ur(%2d) m(%2d) n(%2d)\n", row, col, lc, ur,m ,n);
}

void
spiral(int m, int n)
{

  int row=0, col=0;
  int Lc=0, Ur = 0;

  while ( m >Ur && n >Lc) {
    
    pp(row, col, Lc, Ur, m, n);
    for (; col < n; col++)
      printf("%2d ", a[row][col]);
    row++;
    Ur = row;
  
    pp(row, col, Lc, Ur, m, n);
    for (; row<m; row++)
      printf("%2d ", a[row][col-1]);
    col--;
   
    pp(row, col, Lc, Ur, m, n);
    for(; col>Lc; col--)
      printf("%2d ", a[row-1][col-1]);
    Lc++;

    row--;
    pp(row, col, Lc, Ur, m, n);
    for(;row > Ur; row--)
      printf("%2d ", a[row-1][col]);
    col++;

    //adjust to new dimension
    m=m-1;
    n=n-1;
  }

}

int main()
{
  dumpA(4,5);

  printf("=====\n");
  spiral(4,5);
  printf("\n\n=====\n");
  return 0;
}
