#include<stdio.h>
#include<math.h>

int c=0,n=0,np2=0;

//Function to find whether parameter passed is a power of 2 or not
int powerof2(int x)
{
  int val,i;
  for(i=0;i<n;i++)
  {
    if(x==pow(2,i))
    {
    //  printf("\n%d is a power of 2\n",x);
      val=1;
      np2++;
      break;
    }
    else
      val=0;
  }
  //printf("\nval=%d\n",val);
  return(val);
}

int main()
{
	int ch;
	printf("Enter mode of operation\n1.EVEN PARITY\n2.ODD PARITY\n>");
	labelc:
	scanf("%d",&ch);
	if(ch!=1 && ch!=2)
	{
		printf("\nInvalid choice.Enter again\n>");
		goto labelc;
	}
		
	
	
	printf("\nEnter the no. of bits\n");
	scanf("%d",&n);
	
	int d[n]={0};
	int np[n]={0};
	int p[n]={0};
	int e[n];
	int de[n]={0};
	
	int i;
	printf("Enter value of data bits\n");
	for(i=n;i>=1;i--)
	{
	if(!powerof2(i))
	{
	    printf("Enter value of D%d\n>",i);
	    scanf("%d",&d[i]);
	}
	else{}
	}
	
	for(i=n;i>=1;i--)
	{
	  printf("D%d=%d\n",i,d[i]);
	}
	
	//finding the no of parity bits(n2)
	//  int n2=0;
	//  for(i=1;i<=n;i++)
	//  {
	//    if(powerof2(i))
	//    	n2++;
	//  }
	
	//  printf("\n np2=%d ",np2);
	
	int j=0,k,l=1,m,par,count;
	i=1;
	while(i<=np2)                   
	{
	  count=0;
	  par=pow(2,j);
	  for(k=par;k<n;k++)
	  {
		np[l]=np[l]+d[k];                  // formula for checking correct data bits to calculate parity
		count++;
		if(count==par)
		{
			k=k+par;						// k is getting incremented in the for loop so no need of k=k+par(+1)
			count=0;                        
		}
		else{}                            // k is getting incremented in the for loop so no need to it increament here
	  }
	  i++;
	  j++;
	  l++;
	}
	
	if(ch==1)
	{
		for(i=1;i<=np2;i++)
		{
			if(np[i]%2==0)
				p[i]=1;
			else
				p[i]=0;
		}
	}
	else
	{
		for(i=1;i<=np2;i++)
		{
			if(np[i]%2==0)
			  p[i]=0;
			else
			  p[i]=1;
		}
	}
	
	printf("\nParity bits are:-\n",n);
	int power;
	for(i=1;i<=np2;i++)
	{
		power=pow(2,i-1);
		printf("\nValue of P%d=%d\n",power,p[i]);
	}
	
	l=1;
	for(i=1;i<=n;i++)
	{
		if(powerof2(i))
		{
			d[i]=p[l];
			l++;
		}
	}

	
	printf("\n\n%d-bit Hamming code is:-\n\n",n);
	for(i=n;i>=1;i--)
	{
 		printf("D%d=%d\t",i,d[i]);
	}
	

	// else
	// {
	// 	printf("Invalid Input.Enter again\n>");
	// 	goto labelc;
	// }
}
