#include<stdio.h>
 
 int a[4]={0,0,0,0};
 int b[4]={0,0,0,0};
 int r[4]={0,0,0,0};
 int c1[4]={0,1,1,0};
 int r1[4]={0,0,0,0};
 
 ///function for converting decimal to binary
 tobin(int a3,int x[])
 {
 	int i=3;
 	while(i>=0)
 	{
 		x[i--]=a3%2;
 		a3=a3/2;
	}
 }///
 
 ///function to display a binary no.
 printbin(int x[])
 {
 	int i=0;
 	 	while(i<=3)
 	{
 		printf("%d ",x[i++]);
	}
 }///
 
 int main()
 {
 	int a1,b1,cin,i,j;
 	printf("\n             ______......______.....IMPLEMENTATION OF 4-BIT PARALLEL ADDER.....______......_______ \n\n");
 	printf("Enter value of A in decimal.\nP.S:-Input should be strictly from 0 to 15,0 & 15 inclusive.\n>");
 	labela:
	scanf("%d",&a1);
	if(a1>15 || a1<0)
	{
		printf("Input is invalid.\nEnter again\n>");
		goto labela;
	}
	printf("Enter value of B in decimal.\nP.S:-Input should be strictly from 0 to 15,0 & 15 inclusive.\n>");
	labelb:
	scanf("%d",&b1);
	if(b1>15 || b1<0)
	{
		printf("Input is invalid.\nEnter again\n>");
		goto labelb;
	}
	printf("Enter vale of Cin .\nP.S:-Input should be strictly either 0 or 1.\n>");
	labelc:
	scanf("%d",&cin);
	if(cin!=0 && cin!=1)
	{
		printf("Input is invalid.\nEnter again\n>");
		goto labelc;
	}
	int cin1=cin;
	tobin(a1,a);
	tobin(b1,b);
	printf("\nBinary of A is ");
	printbin(a);
	printf("\nBinary of B is ");
	printbin(b);
	printf("\n");
	
	for(i=3;i>=0;i--)
	{
		r[i]=a[i]^b[i]^cin;
		cin=(a[i]^b[i])*cin+a[i]*b[i];
	}
	
	if(a1+b1+cin<=15)
	{
		printf("\nBinary of result is ");
		printbin(r);
		printf("\nCarry is %d\n",cin);
	}
	else
	{
		printf("\nBinary of result is ");
		printbin(r);
		printf("\nCarry is %d\n",cin);
	}
	int k=0;
	int rtemp=0,rtemp1=0;
	if(a1+b1+cin1>9)
	{
		int ch,carry=0;
		printf("\nResult requires BCD correction.\nDo you want it to be performed?(1/0)\n");
		scanf("%d",&ch);
		
		if(cin==1)
			r1[3]=1;
			
		if(ch==1)
		{
			while( ((8*r[0]+4*r[1]+2*r[2]+1*r[3])!=(a1+b1+cin1)%10) ||  ((8*r1[0]+4*r1[1]+2*r1[2]+1*r1[3])!=(a1+b1+cin1)/10) )
			{
				carry=0;
				for(i=3;i>=0;i--)
				{
					rtemp=r[i];
					r[i]=r[i]^c1[i]^carry;
					carry=(rtemp^c1[i])*carry+rtemp*c1[i];
			//			printf("\nr[%d]=%d,c1[%d]=%d\n",i,r[i],i,c1[i]);
			//			printf("\ncarry=%d\n",carry);
				}
				for(j=3;j>=0;j--)
				{
					rtemp1=r1[j];
					r1[j]=r1[j]^0^carry;
					carry=(rtemp1+0)*carry+rtemp1*0;
				}
				
			}
			printf("\nAfter correction result is:-\n");
			printf("\nBCD:-      ");
			printbin(r1);
			printf("   ");
			printbin(r);
			printf("\n\t  --------------------");
			printf("\nDecimal:-  ");
			printf("   %d          %d",(8*r1[0]+4*r1[1]+2*r1[2]+1*r1[3]),(8*r[0]+4*r[1]+2*r[2]+1*r[3]));
		}	
		else
		{
			printf("Task complete");
		}
	}
	else
	printf("\nResult is already in BCD form\n");
 }
