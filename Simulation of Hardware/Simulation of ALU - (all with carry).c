#include<stdio.h>
#include<stdlib.h>

 int a[4]={0,0,0,0};
 int b[4]={0,0,0,0};
 int s[4]={0,0,0,0};
 int r[4]={0,0,0,0};
 int r1[4]={0,0,0,0};
 int r2[4]={0,0,0,0};
 int r3[4]={0,0,0,0};
 int r4[4]={0,0,0,0};
 int one[4]={0,0,0,1};
 int zero[4]={0,0,0,0};
 int cr[4]={0,0};
 int n=0;
 
//LEFT SHIFT FUNCTION
  lshift(int res[],int x[])
  {
  	res[0]=x[1];
  	res[1]=x[2];
  	res[2]=x[3];
  	res[3]=0;
  }
  //
  
//EX-OR FUNCTION
binexor(int res[],int x[],int y[])
 {
 	int i;
 	for(i=3;i>=0;i--)
 	{
 		res[i]=x[i]^y[i];
	 }
 }
 //
 
 //OR FUNCTION
 binor(int res[],int x[],int y[])
 {
 	int i;
 	for(i=3;i>=0;i--)
 	{
 		res[i]=x[i]|y[i];
	 }
 }
 //
 
 //NEGATION OF SINGLE BIT
int neg(int x)
 {
 	if(x==0)
	{
		return(1);
	}
	if(x==1)
	{
		return(0);
	}
 }
 //
 

 //AND FUNCTION
 binand(int res[],int x[],int y[])
 {
 	int i;
 	for(i=3;i>=0;i--)
 	{
 		res[i]=x[i]&y[i];
	 }
 }
 //
 
 //NEGATION FUNCTION FOR 4 bit array
 binneg(int res[],int x[])
 {
 	int i;
 	for(i=3;i>=0;i--)
 	{
 		if(x[i]==0)
 		{
 			res[i]=1;
		}
		if(x[i]==1)
		{
			res[i]=0;
		}
	 }
 }
 //
 
 //TWO's COMPLEMENT
 twoscomp(int res[],int x[])
 {
 	int i,carry=0,tempres;
 	for(i=3;i>=0;i--)
 	{
 		if(x[i]==0)
 		{
 			res[i]=1;
		}
		if(x[i]==1)
		{
			res[i]=0;
		}
	}
	for(i=3;i>=0;i--)
	{
		tempres=res[i];
		res[i]=res[i]^one[i]^carry;
		carry=(tempres^one[i])*carry+tempres*one[i];
	}
 	
 }
 //
 
//DISPLAY BINARY
 printbin(int x[])
 {
 	int i=0;
 	while(i<=3)
 	{
 		printf("%d ",x[i++]);
	}
 }
 //
 
int main()
{
	int ch1;
	int a1,b1,s1,m,i,j,cin;
	int valid;
	int c1=0,c2=0,c3=0,carry=0;
	int bor=0;
	//TAKING USER I/P FOR A
	labelinp:
 	printf("Enter value of A (4-bit binary).\n>");
 	labela:
	scanf("%d",&a1);
	
	a[0]=a1/1000;
	a1=a1%1000;
	a[1]=a1/100;
	a1=a1%100;
	a[2]=a1/10;
	a[3]=a1%10;
	//
	
	//CHECKING FOR VALID I/P OF A
	for(i=0;i<=3;i++)
	{
		if(a[i]!=0 && a[i]!=1)
		{
			valid=0;
			break;
		}
		else
		{
			valid=1;
		}
	}
//	if(a1>1111)
//	{
//		valid=0;
//	}
	if(valid==0)
	{
		printf("Invalid input was entered.\nEnter again\n>");
		goto labela;
	}
	
	//
	
	//TAKING USER I/P FOR B
	printf("Enter value of B (4-bit binary).\n>");
	labelb:
	scanf("%d",&b1);
	
	b[0]=b1/1000;
	b1=b1%1000;
	b[1]=b1/100;
	b1=b1%100;
	b[2]=b1/10;
	b[3]=b1%10;
	//
	
	//CHECKING FOR VALID I/P OF B	
	for(i=0;i<=3;i++)
	{
		if(b[i]!=0 && b[i]!=1)
		{
			valid=0;
			break;
		}
		else
		{
			valid=1;
		}
	}
//	if(b1>1111)
//	{
//		valid=0;
//	}
	if(valid==0)
	{
		printf("Invalid input was entered.\nEnter again\n>");
		goto labelb;
	}
	//
	
	
	
	//TAKING SELECT INPUT FROM USER
	labels:
	printf("\nEnter Select inputs (0 or 1)\n");
	for(i=3;i>=0;i--)
	{
		printf("\nEnter select input S[%d]: ",i);
		labelx:
		scanf("%d",&s[i]);
		if(s[i]!=0 && s[i]!=1)
		{
			printf("Invalid input was entered.\nEnter again\n");
			goto labelx;
		}
	}
	//

	//TAKING CHOICE OF OPERATION FROM USER
	labelop:
	printf("Enter a choice.\n1.LOGIC\n2.ARITHMETIC\n>");
	labelm:
	scanf("%d",&m);
	if(m!=1 && m!=2)
	{
		printf("Invalid input was entered.\nEnter again\n>");
		goto labelm;
	}
	//
	
	//LOGIC FUNCTIONS
	if(m==1)
	{
		carry=0;
		
		//FOR   0000
		if( s[3]==0 && s[2]==0 && s[1]==0 && s[0]==0 )
		{
			binneg(r,a);
			printf("\nF = ");
			printbin(r);
		}
		//
		
		//FOR   0001
		if( s[3]==0 && s[2]==0 && s[1]==0 && s[0]==1 )
		{
			binand(r,a,b);
			binneg(r1,r);
			printf("\nF = ");
			printbin(r1);
		}
		//
		
		//FOR   0010
		if( s[3]==0 && s[2]==0 && s[1]==1 && s[0]==0 )
		{
			binneg(r,a);
			binor(r1,r,b);
			printf("\nF = ");
			printbin(r1);
		}
		//
		
		//FOR   0011
		if( s[3]==0 && s[2]==0 && s[1]==1 && s[0]==1 )
		{
			printf("\nF = ");
			printbin(one);
		}
		//
		
		//FOR   0100
		if( s[3]==0 && s[2]==1 && s[1]==0 && s[0]==0 )
		{
			binor(r,a,b);
			binneg(r1,r);
			printf("\nF = ");
			printbin(r1);
		}
		//
		
		//FOR   0101
		if( s[3]==0 && s[2]==1 && s[1]==0 && s[0]==1 )
		{
			binneg(r,b);
			printf("\nF = ");
			printbin(r);
		}
		//
		
		//FOR   0110
		if( s[3]==0 && s[2]==1 && s[1]==1 && s[0]==0 )
		{
			binexor(r,a,b);
			binneg(r1,r);
			printf("\nF = ");
			printbin(r1);
		}
		//
		
		//FOR   0111
		if( s[3]==0 && s[2]==1 && s[1]==1 && s[0]==1 )
		{
			binneg(r,b);
			binor(r1,a,r);
			printf("\nF = ");
			printbin(r1);
		}
		//
		
		//FOR   1000
		if( s[3]==1 && s[2]==0 && s[1]==0 && s[0]==0 )
		{
			binneg(r,a);
			binand(r1,r,b);
			printf("\nF = ");
			printbin(r1);
		}
		//
		
		//FOR   1001
		if( s[3]==1 && s[2]==0 && s[1]==0 && s[0]==1 )
		{
			binexor(r,a,b);
			printf("\nF = ");
			printbin(r);
		}
		//
			
		//FOR   1010
		if( s[3]==1 && s[2]==0 && s[1]==1 && s[0]==0 )
		{
			printf("\nF = ");
			printbin(b);
		}
		//
		
		//FOR   1011
		if( s[3]==1 && s[2]==0 && s[1]==1 && s[0]==1 )
		{
			binor(r,a,b);
			printf("\nF = ");
			printbin(r);
		}
		//
		
		//FOR   1100
		if( s[3]==1 && s[2]==1 && s[1]==0 && s[0]==0 )
		{
			printf("\nF = ");
			printbin(zero);
		}
		//
		
		//FOR   1101
		if( s[3]==1 && s[2]==1 && s[1]==0 && s[0]==1 )
		{
			binneg(r,b);
			binand(r1,a,r);
			printf("\nF = ");
			printbin(r1);
		}
		//
		
		//FOR   1110
		if( s[3]==1 && s[2]==1 && s[1]==1 && s[0]==0 )
		{
			binand(r,a,b);
			printf("\nF = ");
			printbin(r);
		}
		//
		
		//FOR   1111
		if( s[3]==1 && s[2]==1 && s[1]==1 && s[0]==1 )
		{
			printf("\nF = ");
			printbin(a);
		}
		//
		
	}
	//
	
	
	//ARITHMETIC FUNCTIONS
	if(m==2)
	{
		printf("Enter vale of Cn .\nP.S:-Input should be strictly either 0 or 1.\n>");
		labelc:
		scanf("%d",&cin);
		if(cin!=0 && cin!=1)
		{
			printf("Invalid input was entered.\nEnter again\n");
			goto labelc;
		}
		
		//FOR Cn = 0 or L
		if(cin==0)
		{
			bor=0;
			carry=0;
		
			//FOR   0000
			if( s[3]==0 && s[2]==0 && s[1]==0 && s[0]==0 )
			{
				for(i=3;i>=0;i--)
				{
					r[i]=a[i]^one[i]^bor;
					bor=neg(a[i])*bor+neg(a[i])*one[i]+one[i]*bor;
				}
				printf("\nF = ");
				printbin(r);
			}
			//
			
			//FOR   0001
			if( s[3]==0 && s[2]==0 && s[1]==0 && s[0]==1 )
			{
				binand(r,a,b);
				for(i=3;i>=0;i--)
				{
					r1[i]=r[i]^one[i]^bor;
					bor=neg(r[i])*bor+neg(r[i])*one[i]+one[i]*bor;
				}
				printf("\nF = ");
				printbin(r1);
			}
			//
			
			//FOR   0010
			if( s[3]==0 && s[2]==0 && s[1]==1 && s[0]==0 )
			{
				binneg(r,b);
				binand(r1,a,r);
				for(i=3;i>=0;i--)
				{
					r2[i]=r1[i]^one[i]^bor;
					bor=neg(r1[i])*bor+neg(r1[i])*one[i]+one[i]*bor;
				}
				printf("\nF = ");
				printbin(r2);
			}
			//
			
			//FOR   0011
			if( s[3]==0 && s[2]==0 && s[1]==1 && s[0]==1 )
			{
				twoscomp(r,one);
				printf("\nF = ");
				printbin(r);
			}
			//
			
			//FOR   0100
			if( s[3]==0 && s[2]==1 && s[1]==0 && s[0]==0 )
			{
				binneg(r,b);
				for(i=3;i>=0;i--)
				{
					r1[i]=a[i]^r[i]^carry;
					carry=(a[i]^r[i])*carry+a[i]*r[i];
				}
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r2[i]=a[i]^r1[i]^carry;
					carry=(a[i]^r1[i])*carry+a[i]*r1[i];
				}
				c2=carry;
				carry=0;
				
				cr[1]=c1^c2^carry;
				carry=(c1^c2)*carry+c1*c2;
				cr[0]=carry;
				
				printf("\nF = ");
				printbin(r2);
				
				if(c1!=0 || c2!=0)
				printf("\nCarry is %d%d",cr[0],cr[1]);
				else
				printf("\nNo carry was generated");
			}
			//
			
			//FOR   0101
			if( s[3]==0 && s[2]==1 && s[1]==0 && s[0]==1 )
			{
				binneg(r,b);
				for(i=3;i>=0;i--)
				{
					r1[i]=a[i]^r[i]^carry;
					carry=(a[i]^r[i])*carry+a[i]*r[i];
				}
				c1=carry;
				binand(r2,a,b);
				carry=0;
				for(i=3;i>=0;i--)
				{
					r3[i]=r1[i]^r2[i]^carry;
					carry=(r1[i]^r2[i])*carry+r1[i]*r2[i];
				}
				c2=carry;
				carry=0;
				
				cr[1]=c1^c2^carry;
				carry=(c1^c2)*carry+c1*c2;
				cr[0]=carry;
				
				printf("\nF = ");
				printbin(r3);
				
				if(c1!=0 || c2!=0)
				printf("\nCarry is %d%d",cr[0],cr[1]);
				else
				printf("\nNo carry was generated");
			}
			//
			
			//FOR   0110
			if( s[3]==0 && s[2]==1 && s[1]==1 && s[0]==0 )
			{
				for(i=3;i>=0;i--)
				{
					r[i]=a[i]^b[i]^bor;
					bor=neg(a[i])*bor+neg(a[i])*b[i]+b[i]*bor;
				}
				bor=0;
				for(i=3;i>=0;i--)
				{
					r1[i]=r[i]^one[i]^bor;
					bor=neg(r[i])*bor+neg(r[i])*one[i]+one[i]*bor;
				}
				printf("\nF = ");
				printbin(r1);
			}
			//
			
			//FOR   0111
			if( s[3]==0 && s[2]==1 && s[1]==1 && s[0]==1 )
			{
				binneg(r,b);
				for(i=3;i>=0;i--)
				{
					r1[i]=a[i]^r[i]^carry;
					carry=(a[i]^r[i])*carry+a[i]*r[i];
				}
				printf("\nF = ");
				printbin(r1);
				if(carry==1)
					printf("\nCarry is 1");
				else
					printf("\nNo carry was generated");
			}
			//
			
			//FOR   1000
			if( s[3]==1 && s[2]==0 && s[1]==0 && s[0]==0 )
			{
				for(i=3;i>=0;i--)
				{
					r[i]=a[i]^b[i]^carry;
					carry=(a[i]^b[i])*carry+a[i]*b[i];
				}
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r1[i]=a[i]^r[i]^carry;
					carry=(a[i]^r[i])*carry+a[i]*r[i];
				}
				c2=carry;
				carry=0;
				
				cr[1]=c1^c2^carry;
				carry=(c1^c2)*carry+c1*c2;
				cr[0]=carry;
				
				printf("\nF = ");
				printbin(r1);
				
				if(c1!=0 || c2!=0)
				printf("\nCarry is %d%d",cr[0],cr[1]);
				else
				printf("\nNo carry was generated");

			}
			//
			
			//FOR   1001
			if( s[3]==1 && s[2]==0 && s[1]==0 && s[0]==1 )
			{
				for(i=3;i>=0;i--)
				{
					r[i]=a[i]^b[i]^carry;
					carry=(a[i]^b[i])*carry+a[i]*b[i];
				}
				printf("\nF = ");
				printbin(r);
				if(carry==1)
					printf("\nCarry is 1");
				else
					printf("\nNo carry was generated");
			}
			//
		
			//FOR   1010
			if( s[3]==1 && s[2]==0 && s[1]==1 && s[0]==0 )
			{
				binneg(r,b);
				binand(r1,a,r);
				for(i=3;i>=0;i--)
				{
					r2[i]=a[i]^b[i]^carry;
					carry=(a[i]^b[i])*carry+a[i]*b[i];
				}
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r3[i]=r1[i]^r2[i]^carry;
					carry=(r1[i]^r2[i])*carry+r1[i]*r2[i];
				}
				c2=carry;
				carry=0;
				
				cr[1]=c1^c2^carry;
				carry=(c1^c2)*carry+c1*c2;
				cr[0]=carry;
				
				printf("\nF = ");
				printbin(r3);
				
				if(c1!=0 || c2!=0)
				printf("\nCarry is %d%d",cr[0],cr[1]);
				else
				printf("\nNo carry was generated");
			}
			//
			
				
			//FOR   1011
			if( s[3]==1 && s[2]==0 && s[1]==1 && s[0]==1 )
			{
				for(i=3;i>=0;i--)
				{
					r[i]=a[i]^b[i]^carry;
					carry=(a[i]^b[i])*carry+a[i]*b[i];
				}
				printf("\nF = ");
				printbin(r);
				if(carry==1)
					printf("\nCarry is 1");
				else
					printf("\nNo carry was generated");
			}
			//
			
			//FOR   1100
			if( s[3]==1 && s[2]==1 && s[1]==0 && s[0]==0 )
			{
				lshift(r,a);
				for(i=3;i>=0;i--)
				{
					r1[i]=a[i]^r[i]^carry;
					carry=(a[i]^r[i])*carry+a[i]*r[i];
				}
				printf("\nF = ");
				printbin(r1);
				if(carry==1)
					printf("\nCarry is 1");
				else
					printf("\nNo carry was generated");
			}
			//
			
			//FOR   1101
			if( s[3]==1 && s[2]==1 && s[1]==0 && s[0]==1 )
			{
				binand(r,a,b);
				for(i=3;i>=0;i--)
				{
					r1[i]=a[i]^r[i]^carry;
					carry=(a[i]^r[i])*carry+a[i]*r[i];
				}
				printf("\nF = ");
				printbin(r1);
				if(carry==1)
					printf("\nCarry is 1");
				else
					printf("\nNo carry was generated");
			}
			//
			
			//FOR   1110
			if( s[3]==1 && s[2]==1 && s[1]==1 && s[0]==0 )
			{
				binneg(r,b);
				binand(r1,a,r);
				for(i=3;i>=0;i--)
				{
					r2[i]=a[i]^r1[i]^carry;
					carry=(a[i]^r1[i])*carry+a[i]*r1[i];
				}
				printf("\nF = ");
				printbin(r2);
				if(carry==1)
					printf("\nCarry is 1");
				else
					printf("\nNo carry was generated");
			}
			//
			
			//FOR   1111
			if( s[3]==1 && s[2]==1 && s[1]==1 && s[0]==1 )
			{
				printf("\nF = ");
				printbin(a);
			}
			//
			
		}
		//
		
		//FOR Cn = 1 or H
		if(cin==1)
		{
			bor=0;
			carry=0;
		
			//FOR   0000
			if( s[3]==0 && s[2]==0 && s[1]==0 && s[0]==0 )
			{
				printf("\nF = ");
				printbin(a);
			}
			//
			
			
			//FOR   0001
			if( s[3]==0 && s[2]==0 && s[1]==0 && s[0]==1 )
			{
				binand(r,a,b);
				printf("\nF = ");
				printbin(r);
			}
			//
			
			//FOR   0010
			if( s[3]==0 && s[2]==0 && s[1]==0 && s[0]==1 )
			{
				binneg(r,b);
				binand(r1,a,r);
				printf("\nF = ");
				printbin(r1);
			}
			//
			
			//FOR   0011
			if( s[3]==0 && s[2]==0 && s[1]==1 && s[0]==1 )
			{
				printf("\nF = ");
				printbin(zero);
			}
			//
			
			//FOR   0100
			if( s[3]==0 && s[2]==1 && s[1]==0 && s[0]==0 )
			{
				binneg(r,b);
				for(i=3;i>=0;i--)
				{
					r1[i]=a[i]^r[i]^carry;
					carry=(a[i]^r[i])*carry+a[i]*r[i];
				}
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r2[i]=a[i]^r1[i]^carry;
					carry=(a[i]^r1[i])*carry+a[i]*r1[i];
				}
				c2=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r3[i]=r2[i]^one[i]^carry;
					carry=(r2[i]^one[i])*carry+r2[i]*one[i];
				}
				c3=carry;
				carry=0;
				
				cr[1]=c1^c2^c3;
				carry=(c1^c2)*c3+c1*c2;
				cr[0]=carry;
				
				printf("\nF = ");
				printbin(r3);
				
				if(c1!=0 || c2!=0 || c3!=0)
				printf("\nCarry is %d%d",cr[0],cr[1]);
				else
				printf("\nNo carry was generated");
			}
			//
			
			//FOR   0101
			if( s[3]==0 && s[2]==1 && s[1]==0 && s[0]==1 )
			{
				binneg(r,b);
				for(i=3;i>=0;i--)
				{
					r1[i]=a[i]^r[i]^carry;
					carry=(a[i]^r[i])*carry+a[i]*r[i];
				}
				binand(r2,a,b);
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r3[i]=r1[i]^r2[i]^carry;
					carry=(r1[i]^r2[i])*carry+r1[i]*r2[i];
				}
				c2=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r4[i]=r3[i]^one[i]^carry;
					carry=(r3[i]^one[i])*carry+r3[i]*one[i];
				}
				c3=carry;
				carry=0;
				
				cr[1]=c1^c2^c3;
				carry=(c1^c2)*c3+c1*c2;
				cr[0]=carry;
				
				printf("\nF = ");
				printbin(r4);
				
				if(c1!=0 || c2!=0 || c3!=0)
				printf("\nCarry is %d%d",cr[0],cr[1]);
				else
				printf("\nNo carry was generated");

			}
			//
			
			//FOR   0110
			if( s[3]==0 && s[2]==1 && s[1]==1 && s[0]==0 )
			{
				for(i=3;i>=0;i--)
				{
					r[i]=a[i]^b[i]^bor;
					bor=neg(a[i])*bor+neg(a[i])*b[i]+b[i]*bor;
				}
				printf("\nF = ");
				printbin(r);
			}
			//
			
			//FOR   0111
			if( s[3]==0 && s[2]==1 && s[1]==1 && s[0]==1 )
			{
				binneg(r,b);
				for(i=3;i>=0;i--)
				{
					r1[i]=a[i]^r[i]^carry;
					carry=(a[i]^r[i])*carry+a[i]*r[i];
				}
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r2[i]=r1[i]^one[i]^carry;
					carry=(r1[i]^one[i])*carry+r1[i]*one[i];
				}
				c2=carry;
				
				printf("\nF = ");
				printbin(r2);
				
				if(c1!=0 || c2!=0)
				printf("\nCarry is 1");
				else
				printf("\nNo carry was generated");
			}
			//
			
			//FOR   1000
			if( s[3]==1 && s[2]==0 && s[1]==0 && s[0]==0 )
			{
				for(i=3;i>=0;i--)
				{
					r[i]=a[i]^b[i]^carry;
					carry=(a[i]^b[i])*carry+a[i]*b[i];
				}
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r1[i]=a[i]^r[i]^carry;
					carry=(a[i]^r[i])*carry+a[i]*r[i];
				}
				c2=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r2[i]=r1[i]^one[i]^carry;
					carry=(r1[i]^one[i])*carry+r1[i]*one[i];
				}
				c3=carry;
				carry=0;
				
				cr[1]=c1^c2^c3;
				carry=(c1^c2)*c3+c1*c2;
				cr[0]=carry;
			
				printf("\nF = ");
				printbin(r2);
			
				if(c1!=0 || c2!=0 || c3!=0)
				printf("\nCarry is %d%d",cr[0],cr[1]);
				else
				printf("\nNo carry was generated");

			}
			//
			
			//FOR   1001
			if( s[3]==1 && s[2]==0 && s[1]==0 && s[0]==1 )
			{
				for(i=3;i>=0;i--)
				{
					r[i]=a[i]^b[i]^carry;
					carry=(a[i]^b[i])*carry+a[i]*b[i];
				}
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r1[i]=r[i]^one[i]^carry;
					carry=(r[i]^one[i])*carry+r[i]*one[i];
				}
				c2=carry;
				
				printf("\nF = ");
				printbin(r1);
				
				if(c1!=0 || c2!=0)
				printf("\nCarry is 1");
				else
				printf("\nNo carry was generated");
			}
			//
		
			//FOR   1010
			if( s[3]==1 && s[2]==0 && s[1]==1 && s[0]==0 )
			{
				binneg(r,b);
				binand(r1,a,r);
				for(i=3;i>=0;i--)
				{
					r2[i]=a[i]^b[i]^carry;
					carry=(a[i]^b[i])*carry+a[i]*b[i];
				}
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r3[i]=r1[i]^r2[i]^carry;
					carry=(r1[i]^r2[i])*carry+r1[i]*r2[i];
				}
				c2=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r4[i]=r3[i]^one[i]^carry;
					carry=(r3[i]^one[i])*carry+r3[i]*one[i];
				}
				c3=carry;
				carry=0;
				
				cr[1]=c1^c2^c3;
				carry=(c1^c2)*c3+c1*c2;
				cr[0]=carry;
				
				printf("\nF = ");
				printbin(r4);
				
				if(c1!=0 || c2!=0 || c3!=0)
				printf("\nCarry is %d%d",cr[0],cr[1]);
				else
				printf("\nNo carry was generated");
			}
			//
			
				
			//FOR   1011
			if( s[3]==1 && s[2]==0 && s[1]==1 && s[0]==1 )
			{
				for(i=3;i>=0;i--)
				{
					r[i]=a[i]^b[i]^carry;
					carry=(a[i]^b[i])*carry+a[i]*b[i];
				}
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r1[i]=r[i]^one[i]^carry;
					carry=(r[i]^one[i])*carry+r[i]*one[i];
				}
				c2=carry;
				
				printf("\nF = ");
				printbin(r1);
				
				if(c1!=0 || c2!=0)
				printf("\nCarry is 1");
				else
				printf("\nNo carry was generated");
				
				printf("\nF = ");
				printbin(r1);
			}
			//
			
			//FOR   1100
			if( s[3]==1 && s[2]==1 && s[1]==0 && s[0]==0 )
			{
				for(i=3;i>=0;i--)
				{
					r[i]=a[i]^a[i]^carry;
					carry=(a[i]^a[i])*carry+a[i]*a[i];
				}
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r1[i]=r[i]^one[i]^carry;
					carry=(r[i]^one[i])*carry+r[i]*one[i];
				}
				c2=carry;
				
				printf("\nF = ");
				printbin(r1);
				
				if(c1!=0 || c2!=0)
				printf("\nCarry is 1");
				else
				printf("\nNo carry was generated");
				
				printf("\nF = ");
				printbin(r1);
			}
			//
			
			//FOR   1101
			if( s[3]==1 && s[2]==1 && s[1]==0 && s[0]==1 )
			{
				binand(r,a,b);
				for(i=3;i>=0;i--)
				{
					r1[i]=a[i]^r[i]^carry;
					carry=(a[i]^r[i])*carry+a[i]*r[i];
				}
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r2[i]=r1[i]^one[i]^carry;
					carry=(r1[i]^one[i])*carry+r1[i]*one[i];
				}
				c2=carry;
				
				printf("\nF = ");
				printbin(r1);
				
				if(c1!=0 || c2!=0)
				printf("\nCarry is 1");
				else
				printf("\nNo carry was generated");
				
				printf("\nF = ");
				printbin(r2);
			}
			//
			
			//FOR   1110
			if( s[3]==1 && s[2]==1 && s[1]==1 && s[0]==0 )
			{
				binneg(r,b);
				binand(r1,a,r);
				for(i=3;i>=0;i--)
				{
					r2[i]=a[i]^r1[i]^carry;
					carry=(a[i]^r1[i])*carry+a[i]*r1[i];
				}
				c1=carry;
				carry=0;
				for(i=3;i>=0;i--)
				{
					r3[i]=r2[i]^one[i]^carry;
					carry=(r2[i]^one[i])*carry+r2[i]*one[i];
				}
				c2=carry;
				
				printf("\nF = ");
				printbin(r3);
				
				if(c1!=0 || c2!=0)
				printf("\nCarry is 1");
				else
				printf("\nNo carry was generated");
			}
			//
			
			//FOR   1111
			if( s[3]==1 && s[2]==1 && s[1]==1 && s[0]==1 )
			{
				for(i=3;i>=0;i--)
				{
					r[i]=a[i]^one[i]^carry;
					carry=(a[i]^one[i])*carry+a[i]*one[i];
				}
				printf("\nF = ");
				printbin(r);
				if(carry==1)
				printf("\nCarry is 1");
				else
				printf("\nNo carry was generated");
			}
			//
				
		}
		//
	}
	//
	printf("\n\nMenu:\n1.Enter new Operation (for same i/p values)\n2.Enter new Select lines(for same i/p values)\n3.Enter new input values  i.e A & B.\n4.Exit\n");
	printf("\nEnter your choice:- \n");
	labelch:
	scanf("%d",&ch1);
	if(ch1==1)
		goto labelop;
	else if(ch1==2)
		goto labels;
	else if(ch1==3)
		goto labelinp;
	else if(ch1==4)
		exit(0);
	else
	{
		printf("Invalid input.Enter again\n>");
	    goto labelch;
	}
	    
	 
	
}
