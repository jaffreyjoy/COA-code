#include<stdio.h>
#include<math.h>
int a[100]={0};
int ae[100]={0};
int c=0,n;

int powerof2(int x)
{
  int val,i;
  for(i=0;i<7;i++)
  {
    if(x==pow(2,i))
    {
      val=1;
      break;
    }
    else
      val=0
  }
  return(val);
}

int main()
{
	printf("Enter mode of operation\n1.EVEN PARITY\n2.ODD PARITY\n>");
	labelc:
	scanf("%d",&c);
  printf("\nEnter the no. of bits\n");
  scanf("%d",&n);
	if(c==1 || c==2)
	{
    int p[100],e[100],i;
    printf("Enter value of data bits\n");
    for(i=n-1;i>=0;i--)
    {
      if(i==(powerof2(i)))
      printf("Enter value of D%d\n>",i+1);
	    scanf("%d",&a[i]);
    }
	}
	else
	{
		printf("Invalid Input.Enter again\n>");
		goto labelc;
	}
}
