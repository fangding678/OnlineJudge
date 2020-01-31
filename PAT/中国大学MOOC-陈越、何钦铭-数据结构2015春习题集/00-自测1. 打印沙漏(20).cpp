#include<stdio.h>
#include<math.h>
int main()
{
  int n,k,i,j,t;
  char c;
  scanf("%d",&n);
  getchar();
  scanf("%c",&c);
  k=sqrt((n+1)/2);
  for(i=0;i<k;i++)
  {
    t=2*k-2*i-1;
    for(j=0;j<i;j++) printf(" ");
    for(j=0;j<t;j++) printf("%c",c);
    printf("\n");
  }
  for(i=k-2;i>=0;i--)
  {
    t=2*k-2*i-1;
    for(j=0;j<i;j++) printf(" ");
    for(j=0;j<t;j++) printf("%c",c);
    printf("\n");
  }
  printf("%d\n",n+1-2*k*k);
  return 0;
}
