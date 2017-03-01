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

//Function to right shift c,a,q
rshift(int ax[],int qx[])
{
	int i;
	q1=qx[n-1];
	for(i=n-1;i>=1;i--)
	{
		qx[i]=qx[i-1];
	}
	qx[0]=ax[n-1];
	for(i=n-1;i>=1;i--)
	{
		ax[i]=ax[i-1];
	}
	ax[0]=ax[1];
	
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

//function to add two binary nos.
add(int ax[],int mx[])
{
	int carry=0,i,at;
	for(i=n-1;i>=0;i--)
	{
		at=ax[i];
		ax[i]=ax[i]^mx[i]^carry;
		carry=(at^mx[i])*carry+at*mx[i];
	}
}


//getting 2's complement 
twoscomp(int x[],int y[],int o[])
{
	int i,x1;
	for(i=n-1;i>=0;i--)
	{
		x1=y[i];
		x[i]=!(x1);
	}
 	add(x,o);
}
//

 int main()
 {
 	int i,a1,b1,a2,b2;
 	printf("\n-----------------------------------------------------------------------------------------------------------------------");
 	printf("\n________________________________________Booth's Unsigned Multiplication________________________________________________\n");
 	printf("-----------------------------------------------------------------------------------------------------------------------\n");
 	//Getting multiplicand from user
 	printf("\nEnter the Multiplicand(M)\n>");
 	labela1:
 	scanf("%d",&a1);
 	a2=abs(a1);
 	if(a1<-15 || a1>15)														//comment the if case to increase range
 	{
 		printf("Invalid input.Enter again\n>");
 		goto labela1;
	}
 	n=findbit(a2);
	//printf("\n%d is a %d bit number.\n",a1,n);
	//
    	
	//Getting multiplier from user
 	printf("\nEnter the Multiplier(Q)\n>");
 	labelb1:
 	scanf("%d",&b1);
 	b2=abs(b1);
 	if(b1<-15 || b1>15)														//comment the if case to increase range
 	{
 		printf("Invalid input.Enter again\n>");
 		goto labelb1;
	}
 	n1=findbit(b2);
 	//printf("\n%d is a %d bit number.\n",b1,n1);
	//
	
	if(n>n1)
		n=n;
	else
		n=n1;
		
	n=n+1;
	
	int a[n]={0};
	int q[n]={0};
	int qc[n]={0};
	int m[n]={0};
	int mc[n]={0};
	int one[n]={0};
	int zero[n]={0};
	one[n-1]=1;
	count=n;
 	
 	
 	//Converting  Q and M to binary
 	
 	if(a1>0)
 	{
 		tobin(m,a2,n);
 		twoscomp(mc,m,one);
	}
 	else
 	{
 		tobin(mc,a2,n);
 		twoscomp(m,mc,one);
	}
	
 	if(b1>0)
 	{
 		tobin(q,b2,n);
 		twoscomp(qc,q,one);
	}
 	else
 	{
 		tobin(qc,b2,n);
 		twoscomp(q,qc,one);
	}
 	
 	
 	
// 	//getting 2's complement of m
// 	for(i=n-1;i>=0;i--)
//	{
//		mc[i]=!(m[i]);
//	}
// 	add(mc,one);
// 	//
// 	
// 	//getting 2's complement of q
// 	for(i=n-1;i>=0;i--)
//	{
//		qc[i]=!(q[i]);
//	}
// 	add(qc,one);
// 	//
 	
 	//print the Multiplicand i.e M
 	printf("\nM (%d) = ",a1);
 	printbin(m,n);
 	
 	//print the Multiplier i.e Q
 	printf("\n\nQ (%d) = ",b1);
 	printbin(q,n);
 	
 	//Flow Table START
 	printf("\n\nFLOW TABLE  :-");
 	
 	printf("\n");
 	
 	//Initial
 	printf("\nCounter=%d   ",count);
 	printf("  A=");
 	printbin(a,n);
 	printf("    Q=");
 	printbin(q,n);
 	printf("    Q1=%d",q1);
  	printf("    Operation = Initial\n");
  	
  	//Next steps
  	for(count=count-1;count>=0;count--)
  	{
  		int qtemp=q[n-1];
  		if(q[n-1]==0 && q1==1)
  		{
  			//add 
  			add(a,m);
  			printf("\nCounter=%d   ",count);
		 	printf("  A=");
		 	printbin(a,n);
		 	printf("    Q=");
		 	printbin(q,n);
		 	printf("    Q1=%d",q1);
		 	printf("    Operation = Add i.e A -> A+M");
		 	//shift
  			rshift(a,q);
  			if(count<10)
  				printf("\n            ");
  			else
  				printf("\n             ");
		 	printf("  A=");
		 	printbin(a,n);
		 	printf("    Q=");
		 	printbin(q,n);
		 	printf("    Q1=%d",q1);
		 	printf("    Operation = Shift\n");
		}
		else if(q[n-1]==1 && q1==0)
  		{
  			//subtract 
  			add(a,mc);
  			printf("\nCounter=%d   ",count);
		 	printf("  A=");
		 	printbin(a,n);
		 	printf("    Q=");
		 	printbin(q,n);
		 	printf("    Q1=%d",q1);
		 	printf("    Operation = Subtract i.e A -> A-M");
		 	//shift
  			rshift(a,q);
  			if(count<10)
  				printf("\n            ");
  			else
  				printf("\n             ");
		 	printf("  A=");
		 	printbin(a,n);
		 	printf("    Q=");
		 	printbin(q,n);
		 	printf("    Q1=%d",q1);
		 	printf("    Operation = Shift\n");
		}
		else
		{
			//shift
			rshift(a,q);
			printf("\nCounter=%d   ",count);
		 	printf("  A=");
		 	printbin(a,n);
		 	printf("    Q=");
		 	printbin(q,n);
		 	printf("    Q1=%d",q1);
		 	printf("    Operation = Shift\n");
		}

	}
	//Flow Table END
	
	printf("-------------------------------------------------------------------------");
	printf("\nProduct of %d & %d in binary",a1,b1);
	int carry=0,at;
	
	if((a1<0 && b1>0) || (a1>0 && b1<0))
	{
		printf("(two's complement form) is ");
//		for(i=n-1;i>=0;i--)
//		{
//			a[i]=!a[i];
//		}
//		for(i=n-1;i>=0;i--)
//		{
//			q[i]=!q[i];
//		}
//		for(i=n-1;i>=0;i--)
//		{
//			at=q[i];
//			q[i]=q[i]^one[i]^carry;
//			carry=(at^one[i])*carry+at*one[i];
//		}
//		for(i=n-1;i>=0;i--)
//		{
//			at=a[i];
//			a[i]=a[i]^zero[i]^carry;
//			carry=(at^zero[i])*carry+at*zero[i];
//		}
	}
	else
	{
		printf(" is ");
	}
	
	
	printbin(a,n);
	printbin(q,n);
	int p1=0,p2=0;
	int j=0;
	for(i=(2*n)-1;i>=n;i--)
	{
		p1=p1+a[j]*pow(2,i);
		j++;
	}
	j=0;
	for(i=n-1;i>=0;i--)
	{
		p2=p2+q[j]*pow(2,i);
		j++;
	}
	printf("\n\nProduct of %d & %d in decimal is %d",a1,b1,a1*b1);
  	
}
