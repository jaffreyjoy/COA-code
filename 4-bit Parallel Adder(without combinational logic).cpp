#include<stdio.h>
 
 int a[4]={0,0,0,0};
 int b[4]={0,0,0,0};
 int r[4]={0,0,0,0};
 int r1[4]={0,0,0,0};
 int r2[4]={0,0,0,0};
 int c1[4]={0,1,1,0};
 int r3[4]={0,0,0,0};
 int r4[4]={0,0,0,0};
 int c=0;
 
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
 
 ///function for adding two binary nos.
 int add(int an,int bn)
 {
 	if(an==1 && bn==1)
 	{
 		if(c==1)
 		{
 			c=1;
			return(1);
			
		 }
 		else
 		{
 			c=1;
			return(0);
		 }
		 
	}
	if((an==0 && bn==1)||(an==1 && bn==0))
	{
	 	if(c==1)
	 	{
	 		c=1;
			return(0);
	 	
		 }
		
		else
		{
			return(an+bn);
		}
		
	}
	if(an==0 && bn==0)
	{
		if(c==1)
	 	{
	 		c=0;
	 		return(1);
	 	
		 }
		 else
		 {
		 	return(0);
		 }
		
	}
 }///
 
 int main()
 {
 	int i=3,j=3;
 	int a1,b1,cin;
 	printf("\n             ______......______.....IMPLEMENTATION OF 4-BIT PARALLEL ADDER.....______......_______ \n\n");
 	printf("Enter value of A in decimal.\nP.S:-Input should be strictly from 0 to 15(for desirable result :P),0 & 15 inclusive.\n>");
	scanf("%d",&a1);
	printf("Enter value of B in decimal.\nP.S:-Input should be strictly from 0 to 15(for desirable result :P),0 & 15 inclusive.\n>");
	scanf("%d",&b1);
	printf("Enter vale of Cin .\nP.S:-Input should be strictly either 0 or 1(for desirable result :P).\n>");
	scanf("%d",&cin);
	tobin(a1,a);
	tobin(b1,b);
	printf("\nBinary of A is ");
	printbin(a);
	printf("\nBinary of B is ");
	printbin(b);
	printf("\n");
	while(i>=0)
	{
		r[i]=add(a[i],b[i]);
		i--;
	}
	
	///display A + B 
	printf("\nA + B = ");
	if(c==1)
	{
		printbin(r);
		printf("\nCarry is 1\n");
	}
	else
	{
		printbin(r);
		printf("\nNo carry was generated\n");
	}///
	
	
	int c0=c;
	c=0;
	
	///display A + B + Cin
	if(cin==1)
	{
		int cin1=cin;
		if(c0==1)
		{
			while(j>=0)
			{
				r1[j]=add(r[j],cin1);
				cin1=0;
				j--;
			}
			printf("\nA + B + Cin = ");
			printbin(r1);
			printf("\nCarry is 1\n");
			r3[3]=1;
		}
		else
		{
			while(j>=0)
			{
				r1[j]=add(r[j],cin1);
				cin1=0;
				j--;
			}
			printf("\nA + B + Cin = ");
			printbin(r1);
			printf("\nNo carry was generated\n");
		}
		
	}
	
	else
	{
		int m;
		if(c0==1)
		{
			for(m=0;m<=3;m++)
			{
				r1[m]=r[m];
			}
			printf("\nA + B + Cin = ");
			printbin(r1);
			printf("\nCarry is 1\n");
			r3[3]=1;
		}
		else
		{
			for(m=0;m<=3;m++)
			{
				r1[m]=r[m];
			}
			printf("\nA + B + Cin = ");
			printbin(r1);
			printf("\nNo carry was generated\n");
		}
		
	}///
	
	/// BCD  CORRECTION
	
	if(a1+b1+cin>9)
	{
		char ch;
		int k;
		int cz;
		label:
		printf("\nResult needs BCD correction\nDo you want it to be performed?(y/n)");
		printf("\nEnter EITHER ['y' or 'Y'] for YES /OR/ ['n' or 'N''] for NO(without the quotes)\n>");
		scanf("%c",&ch);
		scanf("%c",&ch);
		c=0;
		if(ch=='Y' || ch=='y')
		{
			
			k=3;
			while(k>=0)
			{
				r2[k]=add(r1[k],c1[k]);
				k--;
			}
			
			cz=c;
			c=0;
			k=3;
			
			while(k>=0)
			{
				r4[k]=add(r3[k],cz);
				cz=0;
				k--;
			}
	
			while( ((8*r2[0]+4*r2[1]+2*r2[2]+1*r2[3])!=(a1+b1+cin)%10) ||  ((8*r4[0]+4*r4[1]+2*r4[2]+1*r4[3])!=(a1+b1+cin)/10) )
			{
				k=3;
				while(k>=0)
				{
					r2[k]=add(r2[k],c1[k]);
					k--;
				}
				cz=c;
				c=0;
	
				k=3;
				while(k>=0)
				{
					r4[k]=add(r4[k],cz);
					cz=0;
					k--;
				}
			}
			
			printf("\nAfter correction result is:-\n");
			printf("\nBCD:-      ");
			printbin(r4);
			printf("   ");
			printbin(r2);
			printf("\n\t  --------------------");
			printf("\nDecimal:-  ");
			printf("   %d          %d",(8*r4[0]+4*r4[1]+2*r4[2]+1*r4[3]),(8*r2[0]+4*r2[1]+2*r2[2]+1*r2[3]));

		}
	
		else if(ch=='N' || ch=='n')
		{
			printf("\nTask Complete.");
		}
		else
		{
			printf("\nInvalid choice.");
			goto label;
		}
	}///
	
	else
	{
		printf("\nResult is in BCD form.");
	}
	
 }
