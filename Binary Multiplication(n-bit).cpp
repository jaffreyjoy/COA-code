#include<stdio.h>
#include<math.h>

int c=0;
int count;
int n;
int n1;

//function to find no. of bits
int findbit(int x)
{
	int i;
	for(i=0;i<=30;i++)
	{
		if(x>=pow(2,i) && x<pow(2,i+1))
		{
			return(i+1);
		//	break;
		}
	}
}

//Function to right shift c,a,q
rshift(int ax[],int qx[])
{
	int i;
	for(i=n1-1;i>=1;i--)
	{
		qx[i]=qx[i-1];
	}
	qx[0]=ax[n-1];
	for(i=n-1;i>=1;i--)
	{
		ax[i]=ax[i-1];
	}
	ax[0]=c;
	c=0;
}

//Convert decimal to binary
tobin(int x[],int x1,int x2)
{
	int i;
	for(i=x2-1;i>=0;i--)
	{
		if(x1%2==0)
			x[i]=0;
		else
			x[i]=1;
	    
	    x1=x1/2;
	//    printf("x1=%d  x=%d  ",x1,x[i]);
	}
}

//Print binary no
printbin(int x[],int x1)
{
	int i;
	for(i=0;i<=x1-1;i++)
	{
		printf("%d",x[i]);
	}
}

//function to add a and m i.e accumulator and multiplier
add(int ax[],int mx[])
{
	int carry=0,i,at;
	for(i=n-1;i>=0;i--)
	{
		at=ax[i];
		ax[i]=ax[i]^mx[i]^carry;
		carry=(at^mx[i])*carry+at*mx[i];
	}
	c=carry;
}


 int main()
 {
 	int i,a1,b1;
 	printf("\n-----------------------------------------------------------------------------------------------------------------------");
 	printf("\n__________________________________________n-bit Unsigned Multiplication________________________________________________\n");
 	printf("-----------------------------------------------------------------------------------------------------------------------\n");
 	//Getting multiplicand from user
 	printf("\nEnter the Multiplicand(M)\n>");
 	labela1:
 	scanf("%d",&a1);
 	if(a1<0 || a1>2000000000)
 	{
 		printf("Invalid input.Enter again\n>");
 		goto labela1;
	}
 	n=findbit(a1);
	printf("\n%d is a %d bit number.\n",a1,n);
	//
    	
	//Getting multiplier from user
 	printf("\nEnter the Multiplier(Q)\n>");
 	labelb1:
 	scanf("%d",&b1);
 	if(b1<0 || b1>2000000000)
 	{
 		printf("Invalid input.Enter again\n>");
 		goto labelb1;
	}
 	n1=findbit(b1);
 	printf("\n%d is a %d bit number.\n",b1,n1);
	//
	
	int a[n]={0};
	int q[n1]={0};
	int m[n]={0};
	
	count=n1;
 	
 	//Converting  Q and M to binary
 	tobin(m,a1,n);
 	tobin(q,b1,n1);
 	
 	//print the Multiplicand i.e M
 	printf("\nM (%d) = ",a1);
 	printbin(m,n);
 	
 	//print the Multiplier i.e Q
 	printf("\n\nQ (%d) = ",b1);
 	printbin(q,n1);
 	
 	//Flow Table START
 	printf("\n\nFLOW TABLE  :-");
 	
 	printf("\n");
 	
 	//Initial
 	printf("\nCounter=%d   C=%d ",count,c);
 	printf("  A=");
 	printbin(a,n);
 	printf("  Q=");
 	printbin(q,n1);
  	printf("  Operation=Initial\n");
  	
  	//Next steps
  	for(count=count-1;count>=0;count--)
  	{
  		int qtemp=q[n1-1];
  		if(q[n1-1]==1)
  		{
  			//add 
  			add(a,m);
  			printf("\nCounter=%d   C=%d ",count,c);
		 	printf("  A=");
		 	printbin(a,n);
		 	printf("  Q=");
		 	printbin(q,n1);
		 	printf("  Operation=Add");
		 	//shift
  			rshift(a,q);
  			if(count<10)
  				printf("\n            C=%d ",c);
  			else
  				printf("\n             C=%d ",c);
		 	printf("  A=");
		 	printbin(a,n);
		 	printf("  Q=");
		 	printbin(q,n1);
		 	printf("  Operation=Shift\n");
		}
		else
		{
			//shift
			rshift(a,q);
			printf("\nCounter=%d   C=%d ",count,c);
		 	printf("  A=");
		 	printbin(a,n);
		 	printf("  Q=");
		 	printbin(q,n1);
		 	printf("  Operation=Shift\n");
		}

	}
	//Flow Table END
	
	printf("---------------------------------------------------");
	printf("\nProduct of %d & %d in binary is ",a1,b1);
	printbin(a,n);
	printbin(q,n1);
	long long p1=0,p2=0;
	int j=0;
	for(i=(n+n1)-1;i>=n1;i--)
	{
		p1=p1+a[j]*pow(2,i);
		j++;
	}
	j=0;
	for(i=n1-1;i>=0;i--)
	{
		p2=p2+q[j]*pow(2,i);
		j++;
	}
	printf("\n\nProduct of %d & %d in decimal is %lld",a1,b1,p1+p2);
  	
}
