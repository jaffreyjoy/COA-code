#include<stdio.h>

int a[7]={0,0,0,0,0,0,0};
int ae[7]={0,0,0,0,0,0,0};

//Getting no. of ones for parity bit e1
int checkp1()
{
	int i=0;
	
	if(a[2]==1)
		i++;
	if(a[4]==1)
		i++;
	if(a[6]==1)
		i++;
	
	return(i);
}
//

//Getting no. of ones for parity bit e2
int checkp2()
{
	int i=0;
	
	if(a[2]==1)
		i++;
	if(a[5]==1)
		i++;
	if(a[6]==1)
		i++;
	
	return(i);
}
//

//Getting no. of ones for parity bit e4
int checkp4()
{
	int i=0;
	
	if(a[4]==1)
		i++;
	if(a[5]==1)
		i++;
	if(a[6]==1)
		i++;
	
	return(i);
}
//

//Getting no. of ones for error bit e1
int checke1()
{
	int i=0;
	
	if(ae[0]==1)
		i++;
	if(ae[2]==1)
		i++;
	if(ae[4]==1)
		i++;
	if(ae[6]==1)
		i++;
	
	return(i);
}
//

//Getting no. of ones for error bit e2
int checke2()
{
	int i=0;
	
	if(ae[1]==1)
		i++;
	if(ae[2]==1)
		i++;
	if(ae[5]==1)
		i++;
	if(ae[6]==1)
		i++;
	
	return(i);
}
//

//Getting no. of ones for error bit e4
int checke4()
{
	int i=0;
	
	if(ae[3]==1)
		i++;
	if(ae[4]==1)
		i++;
	if(ae[5]==1)
		i++;
	if(ae[6]==1)
		i++;
	
	return(i);
}
//

//EVEN PARITY 
evenpar()
{
	int p1,p2,p4,i,e1,e2,e4,ep;
	printf("Enter value of data bits\n");
	printf("Enter value of D7\n>");
	scanf("%d",&a[6]);
	printf("Enter value of D6\n>");
	scanf("%d",&a[5]);
	printf("Enter value of D5\n>");
	scanf("%d",&a[4]);
	printf("Enter value of D3\n>");
	scanf("%d",&a[2]);
	
	p1=checkp1();
	p2=checkp2();
	p4=checkp4();
	
	if(p1%2==0)
		a[0]=0;
	else
		a[0]=1;
		
	if(p2%2==0)
		a[1]=0;
	else
		a[1]=1;
		
	if(p4%2==0)
		a[3]=0;
	else
		a[3]=1;
		
	printf("\nParity bits are\n");
	printf("Value of P1 is %d\n",a[0]);
	printf("Value of P2 is %d\n",a[1]);
	printf("Value of P4 is %d\n",a[3]);
	
	printf("\n7-bit Hamming code is:-\n");
	printf("D7 D6 D5 P4 D3 P2 P1\n");
	for(i=6;i>=0;i--)
	{
		printf("%d  ",a[i]);
	}
	

	//Error detection
	printf("\n\nEnter the Hamming code with error at any position of your choice\n");
	printf("D7 D6 D5 P4 D3 P2 P1\n");
	for(i=6;i>=0;i--)
	{
		scanf("%d",&ae[i]);
	}
	
	
	e1=checke1();
	e2=checke2();
	e4=checke4();
	
	printf("\ne4=%d e2=%d e1=%d",e4,e2,e1);
	
	if(e1%2==0)
		e1=0;
	else
		e1=1;
		
	if(e2%2==0)
		e2=0;
	else
		e2=1;
		
	if(e4%2==0)
		e4=0;
	else
		e4=1;
		
	printf("\ne4=%d e2=%d e1=%d",e4,e2,e1);
	
	ep=(4*e4+2*e2+e1)-1;
	if(ep!=0)
	{
		printf("\nError was found at location %d",ep+1);
		
		if(ae[ep]==0)
			ae[ep]=1;
		else if(ae[ep]==1)
			ae[ep]=0;
		else{}
		
			
		printf("\n\nThe correct code is:-\n");
	
		for(i=6;i>=0;i--)
		{
			printf("%d  ",ae[i]);
		}
		
		printf("\n\nThe decoded data is:-\n");
		printf("%d %d %d %d",ae[6],ae[5],ae[4],ae[2]);
	}
	else
	{
			printf("\nNo error was found.");
	}
}
//


oddpar()
{
	int p1,p2,p4,i,e1,e2,e4,ep;
	printf("Enter value of data bits\n");
	printf("Enter value of D7\n>");
	scanf("%d",&a[6]);
	printf("Enter value of D6\n>");
	scanf("%d",&a[5]);
	printf("Enter value of D5\n>");
	scanf("%d",&a[4]);
	printf("Enter value of D3\n>");
	scanf("%d",&a[2]);
	
	p1=checkp1();
	p2=checkp2();
	p4=checkp4();
	
	if(p1%2==0)
		a[0]=1;
	else
		a[0]=0;
		
	if(p2%2==0)
		a[1]=1;
	else
		a[1]=0;
		
	if(p4%2==0)
		a[3]=1;
	else
		a[3]=0;
		
	printf("\nParity bits are\n");
	printf("Value of P1 is %d\n",a[0]);
	printf("Value of P2 is %d\n",a[1]);
	printf("Value of P4 is %d\n",a[3]);
	
	printf("\n7-bit Hamming code is:-\n");
	printf("D7 D6 D5 P4 D3 P2 P1\n");
	for(i=6;i>=0;i--)
	{
		printf("%d  ",a[i]);
	}
	

	//Error detection
	printf("\n\nEnter the Hamming code with error at any position of your choice\n");
	printf("D7 D6 D5 P4 D3 P2 P1\n");
	for(i=6;i>=0;i--)
	{
		scanf("%d",&ae[i]);
	}
	
	
	e1=checke1();
	e2=checke2();
	e4=checke4();
	
	printf("\ne4=%d e2=%d e1=%d",e4,e2,e1);
	
	if(e1%2==0)
		e1=1;
	else
		e1=0;
		
	if(e2%2==0)
		e2=1;
	else
		e2=0;
		
	if(e4%2==0)
		e4=1;
	else
		e4=0;
		
	printf("\ne4=%d e2=%d e1=%d",e4,e2,e1);
	
	ep=(4*e4+2*e2+e1)-1;
	if(ep!=0)
	{
		printf("\nError was found at location %d",ep+1);
		
		if(ae[ep]==0)
			ae[ep]=1;
		else if(ae[ep]==1)
			ae[ep]=0;
		else
		{}
		
		printf("\n\nThe correct code is:-\n");
	
		for(i=6;i>=0;i--)
		{
			printf("%d  ",ae[i]);
		}
		
		printf("\n\nThe decoded data is:-\n");
		printf("%d %d %d %d",ae[6],ae[5],ae[4],ae[2]);
	}
	else
	{
			printf("\nNo error was found.");
	}
}

int main()
{
	
	int c=0;
	printf("Enter mode of operation\n1.EVEN PARITY\n2.ODD PARITY\n>");
	labelc:
	scanf("%d",&c);
	if(c==1)
	{
		evenpar();
	}
	else if(c==2)
	{
		oddpar();
	}
	else
	{
		printf("Invalid Input.Enter again\n>");
		goto labelc;
	}
}

