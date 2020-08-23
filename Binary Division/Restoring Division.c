#include<stdio.h>
#include<math.h>

int q1=0;
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

//Function to left shift a,q
lshift(int ax[],int qx[])
{
	int i;
	for(i=0;i<=n-1;i++)
	{
		ax[i]=ax[i+1];
	}
	ax[n]=qx[0];
	for(i=0;i<=n-2;i++)
	{
		qx[i]=qx[i+1];
	}
	qx[n-1]=0;
	
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

//function to add a and m or mc i.e accumulator and multiplier or 2's complement of multiplier
add(int ax[],int mx[])
{
	int carry=0,i,at;
	for(i=n;i>=0;i--)
	{
		at=ax[i];
		ax[i]=ax[i]^mx[i]^carry;
		carry=(at^mx[i])*carry+at*mx[i];
	} 	
}


 int main()
 {
 	int i,a1,b1;
 	printf("\n-----------------------------------------------------------------------------------------------------------------------");
 	printf("\n_______________________________________________Non Restoring Division__________________________________________________\n");
 	printf("-----------------------------------------------------------------------------------------------------------------------\n");
 	//Getting multiplicand from user
 	printf("\nEnter the Dividend(Q)\n>");
 	labela1:
 	scanf("%d",&a1);
 	if(a1<0 || a1>2000000000)
 	{
 		printf("Invalid input.Enter again\n>");
 		goto labela1;
	}
 	n=findbit(a1);
	//printf("\n%d is a %d bit number.\n",a1,n);
	//
    	
	//Getting multiplier from user
 	printf("\nEnter the Divisor(M)\n>");
 	labelb1:
 	scanf("%d",&b1);
 	if(b1<0 || b1>2000000000)
 	{
 		printf("Invalid input.Enter again\n>");
 		goto labelb1;
	}
 	n1=findbit(b1);
 	//printf("\n%d is a %d bit number.\n",b1,n1);
	//
	
	
	int a[n+1]={0};
	int q[n]={0};
	int m[n+1]={0};
	int mc[n+1]={0};
	int one[n+1]={0};
	one[n]=1;
	count=n;
 	
 	
 	//Converting  Q and M to binary
 	tobin(q,a1,n);
 	tobin(m,b1,n+1);
 	
 	//print the Dividend i.e Q
 	printf("\nQ (%d) = ",a1);
 	printbin(q,n);
 	
 	//print the Divisor i.e M
 	printf("\n\nM (%d) = ",b1);
 	printbin(m,n+1);

 	//getting 2's complement of m
 	for(i=n;i>=0;i--)
	{
		mc[i]=!(m[i]);
	}
 	add(mc,one);
 	//

 	
 	//Flow Table START
 	printf("\n\nFLOW TABLE  :-");
 	
 	printf("\n");
 	
 	//Initial
 	printf("\nCounter=%d   ",count);
 	printf("  A=");
 	printbin(a,n+1);
 	printf("    Q=");
 	printbin(q,n);
 	//printf("    Q1=%d",q1);
  	printf("    Operation = Initial");
  	
  	//Next steps
  	for(count=count-1;count>=0;count--)
  	{
		//shift
		lshift(a,q);
		printf("\n\nCounter=%d   ",count);
		printf("  A=");
	 	printbin(a,n+1);
	 	printf("    Q=");
	 	printbin(q,n);
	 	printf("    Operation = Shift");
	 	//subtract
	 	add(a,mc);
	 	if(count<10)
			printf("\n            ");
		else
			printf("\n             ");
	 	printf("  A=");
	 	printbin(a,n+1);
	 	printf("    Q=");
	 	printbin(q,n);
	 	printf("    Operation = Subtract i.e A <- A-M");
		if(a[0]==1)
		{
			q[n-1]=!(a[0]);
			if(count<10)
			printf("\n            ");
			else
			printf("\n             ");
		 	printf("  A=");
		 	printbin(a,n+1);
		 	printf("    Q=");
		 	printbin(q,n);
		 	printf("    Operation = Set Q0 <- %d",q[n-1]);
			
			add(a,m);
			if(count<10)
			printf("\n            ");
			else
			printf("\n             ");
		 	printf("  A=");
		 	printbin(a,n+1);
		 	printf("    Q=");
		 	printbin(q,n);
		 	printf("    Operation = Add i.e A <- A+M");
		}
		else
		{
			q[n-1]=!(a[0]);
			if(count<10)
			printf("\n            ");
			else
			printf("\n             ");
		 	printf("  A=");
		 	printbin(a,n+1);
		 	printf("    Q=");
		 	printbin(q,n);
		 	printf("    Operation = Set Q0 <- %d",q[n-1]);
		}
	}
	//Flow Table END
	
	printf("\n\n----------------------------------------------------------------------------------------------------------------------");
	printf("\nQuotient obtained when %d is divided by %d in binary is ",a1,b1);
	printbin(q,n);
	printf("\nRemainder obtained when %d is divided by %d in binary is ",a1,b1);
	printbin(a,n+1);
	long long rem=0,quo=0;
	int j=0;
	for(i=n;i>=0;i--)
	{
		rem=rem+a[j]*pow(2,i);
		j++;
	}
	j=0;
	for(i=n-1;i>=0;i--)
	{
		quo=quo+q[j]*pow(2,i);
		j++;
	}
	printf("\n\nQuotient obtained when %d is divided by %d in decimal is %lld",a1,b1,quo);
	printf("\nRemainder obtained when %d is divided by %d in decimal is %lld",a1,b1,rem);
  	
}
