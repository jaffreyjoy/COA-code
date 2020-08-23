#include<stdio.h>
#include<math.h>

int q1=0;
int count;
int n;
int n1;
int max;

//bit pair recoding
bprec(int ax[],int bx[])
{
	int i,j=0;
	if(max%2==0)
	{
		for(i=0;i<max;i++)
		{
			ax[i]=2*bx[j]+bx[j+1];
			j=j+2;
		}
	}
	else
	{
		for(i=0;i<max-1;i++)
		{
			ax[i]=2*bx[j]+bx[j+1];
			j=j+2;
		}
		ax[max-1]=2*bx[n-1];
	}
	
}

//copyarray
copy(int resx[],int arr[],int nx)
{
	for(int i=0;i<nx;i++)
	{
		resx[i]=arr[i];
	}
}
//recode
recode(int ax[],int bx[])
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		if(bx[i]==bx[i+1])
			ax[i]=0;
		if(bx[i]==1 && bx[i+1]==0)
			ax[i]=-1;
		if(bx[i]==0 && bx[i+1]==1)
			ax[i]=1;
	}
	if(bx[n-1]==1)
		ax[i]=-1;
	else
		ax[i]=0;
}


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

//Function to left shift 
lshift(int ax[],int nx)
{
	int i,j;
	int k=2*n-1;
	for(j=0;j<nx;j++)
	{
		for(i=0;i<=2*n-1;i++)
		{
			ax[i]=ax[i+1];
		}
	}
	for(j=0;j<nx;j++)
	{
		ax[k]=0;
		k=k-1;
	}
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
add(int ax[],int bx[],int nx)
{
// 	printf("\none\n");
//	printbin(bx,2*n);
//	printf("\none\n");
	int carry=0,i,at;
//	printf("\nax here\n");
// 	printbin(ax,2*n);
// 	printf("\nbx here\n");
// 	printbin(bx,2*n);
// 	printf("\nm1c here\n");
	for(i=nx-1;i>=0;i--)
	{
		at=ax[i];
		ax[i]=ax[i]^bx[i]^carry;
		carry=(at^bx[i])*carry+at*bx[i];
	}
}


//getting 2's complement 
twoscomp(int x[],int y[],int o[],int nx)
{
	int i,x1;
	for(i=nx-1;i>=0;i--)
	{
		x1=y[i];
		x[i]=!(x1);
	}
// 	printf("\nm1c here\n");
// 	printbin(x,2*n);
// 	printf("\none here\n");
// 	printbin(o,2*n);
// 	printf("\nm1c here\n");
 	add(x,o,nx);
// 	printf("\nm1c add here\n");
// 	printbin(x,2*n);
// 	printf("\nm1c add here\n");
}
//

 int main()
 {
 	int i,a1,b1,a2,b2;
 	printf("\n-----------------------------------------------------------------------------------------------------------------------");
 	printf("\n_______________________________________Booth's  Multiplication(Recoding)_______________________________________________\n");
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
	int m1[2*n]={0};
	int m1c[2*n]={0};
	int one[n]={0};
	int one2[2*n]={0};
	int zero[2*n]={0};
	int rec[n]={0};
	int res[2*n]={0};
	int res1[2*n]={0};
	one[n-1]=1;
	one2[2*n-1]=1;
	count=n;

	if(n%2==0)
		max=n/2;
	else
		max=(n/2)+1;
 	
 	int bpr[max]={0};
 	
// 	printf("\none\n");
//	printbin(one2,2*n);
//	printf("\none\n");
 	
 	//Converting  Q and M to binary
 	
 	if(a1>0)
 	{
 		tobin(m,a2,n);
 		twoscomp(mc,m,one,n);
 		tobin(m1,a2,2*n);
// 		printf("\nhere\n");
// 		printbin(m1c,2*n);
// 		printf("\nhere\n");
 		twoscomp(m1c,m1,one2,2*n);
	}
 	else
 	{
	 //	printf("\nelse here\n");
 		tobin(mc,a2,n);
 		twoscomp(m,mc,one,n);
 		tobin(m1c,a2,2*n);
 		twoscomp(m1,m1c,one2,2*n);
	}
	
 	if(b1>0)
 	{
 		tobin(q,b2,n);
 		twoscomp(qc,q,one,n);
	}
 	else
 	{
 		tobin(qc,b2,n);
 		twoscomp(q,qc,one,n);
	}
 	
// 	printf("\nhere\n");
// 	printbin(m1,2*n);
 	
 	//print the Multiplicand i.e M
 	printf("\nM (%d) = ",a1);
 	printbin(m,n);
 	
 	//print the Multiplier i.e Q
 	printf("\n\nQ (%d) = ",b1);
 	printbin(q,n);
 	
//Multiplication process starts
 	recode(rec,q);
 	printf("\n\nBooth's RECODED bits : ");
 	printbin(rec,n);
	
	
	bprec(bpr,rec);
 	printf("\n\nBit-pair RECODED bits : ");
 	printbin(bpr,max);
 	
 	printf("\n\n");
 	printbin(m1,2*n);
 	printf("\nx ");
 	printbin(rec,n);
 	printf("\n------------------");
 	
// 	printf("\nhere\n");
// 	printbin(m1c,2*n);
// 	printf("\nhere\n");
 	
 	// 1)mult/shift  2)mult/shift  3)add
 	int l,k=0;
 	for(l=n-1;l>=0;l--)
 	{
 		printf("\n");
 		if(l==n-1)
 		{
	 		if(rec[l]==-1)
	 		{
	 			copy(res,m1c,2*n);
	 			printbin(res,2*n);
			}
			if(rec[l]==1)
	 		{
	 			copy(res,m1,2*n);
	 			printbin(res,2*n);
			}
			if(rec[l]==0)
	 		{
	 			copy(res,zero,2*n);
	 			printbin(res,2*n);
			}
		}
		else
		{
			if(rec[l]==-1)
	 		{
	 			copy(res1,m1c,2*n);
// 			 	printf("\nhere\n");
//			 	printbin(res1,2*n);
//			 	printf("\nhere\n");
	 			lshift(res1,k);
	 			printbin(res1,2*n);
	 			add(res,res1,2*n);
			}
			if(rec[l]==1)
	 		{
	 			copy(res1,m1,2*n);
	 			lshift(res1,k);
	 			printbin(res1,2*n);
	 			add(res,res1,2*n);
			}
			if(rec[l]==0)
	 		{
	 			copy(res1,zero,2*n);
	 			printbin(zero,2*n);
			}
		}
 		k++;
	}
	printf("\n-----------------------\n");
	printbin(res,2*n);
	
	printf("\n\n-------------------------------------------------------------------------");
	printf("\nProduct of %d & %d in binary",a1,b1);
	int carry=0,at;
	
	if((a1<0 && b1>0) || (a1>0 && b1<0))
	{
		printf("(two's complement form) is ");
	}
	else
	{
		printf(" is ");
	}
	
	printbin(res,2*n);
	printf("\n\nProduct of %d & %d in decimal is %d",a1,b1,a1*b1);
  	
}
