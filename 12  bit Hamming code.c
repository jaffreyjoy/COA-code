#include<stdio.h>
int c=0;
int a[12]={0};
int ae[12]={0};

//Getting no. of ones for parity bit p1
int checkp1()
{
	int i=0;
	
	if(a[2]==1)
		i++;
	if(a[4]==1)
		i++;
	if(a[6]==1)
		i++;
	if(a[8]==1)
		i++;
	if(a[10]==1)
		i++;
	
	return(i);
}
//

//Getting no. of ones for parity bit p2
int checkp2()
{
	int i=0;
	
	if(a[2]==1)
		i++;
	if(a[5]==1)
		i++;
	if(a[6]==1)
		i++;
	if(a[9]==1)
		i++;
	if(a[10]==1)
		i++;
	
	return(i);
}
//

//Getting no. of ones for parity bit p4
int checkp4()
{
	int i=0;
	
	if(a[4]==1)
		i++;
	if(a[5]==1)
		i++;
	if(a[6]==1)
		i++;
	if(a[11]==1)
		i++;
	
	return(i);
}
//

//Getting no. of ones for parity bit p8
int checkp8()
{
	int i=0;
	
	if(a[8]==1)
		i++;
	if(a[9]==1)
		i++;
	if(a[10]==1)
		i++;
	if(a[11]==1)
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
	if(ae[8]==1)
		i++;
	if(ae[10]==1)
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
	if(ae[9]==1)
		i++;
	if(ae[10]==1)
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
	if(ae[11]==1)
		i++;
	
	return(i);
}
//

//Getting no. of ones for error bit e4
int checke8()
{
	int i=0;
	
	if(ae[7]==1)
		i++;
	if(ae[8]==1)
		i++;
	if(ae[9]==1)
		i++;
	if(ae[10]==1)
		i++;
	if(ae[11]==1)
		i++;
	
	return(i);
}
//

oddevenpar()
{
	int p1,p2,p4,p8,i,e1,e2,e4,e8,ep;
	printf("Enter value of data bits\n");
	printf("Enter value of D12\n>");
	scanf("%d",&a[11]);
	printf("Enter value of D11\n>");
	scanf("%d",&a[10]);
	printf("Enter value of D10\n>");
	scanf("%d",&a[9]);
	printf("Enter value of D9\n>");
	scanf("%d",&a[8]);
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
	p8=checkp8();
	
	if(c==1)                                    //even parity
	{
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
			
		if(p8%2==0)
			a[7]=0;
		else
			a[7]=1;
	}
	
	if(c==2)                                    //odd parity
	{
		if(p1%2!=0)
			a[0]=0;
		else
			a[0]=1;
			
		if(p2%2!=0)
			a[1]=0;
		else
			a[1]=1;
			
		if(p4%2!=0)
			a[3]=0;
		else
			a[3]=1;
			
		if(p8%2!=0)
			a[7]=0;
		else
			a[7]=1;
	}

		
	printf("\nParity bits are\n");
	printf("Value of P1 is %d\n",a[0]);
	printf("Value of P2 is %d\n",a[1]);
	printf("Value of P4 is %d\n",a[3]);
	printf("Value of P8 is %d\n",a[7]);
	
	printf("\n12-bit Hamming code is:-\n");
	printf("D12 D11 D10 D9  P8  D7  D6  D5  P4  D3  P2  P1\n");
	for(i=11;i>=0;i--)
	{
		printf("%d   ",a[i]);
	}
	

	//Error detection
	printf("\n\nEnter the Hamming code with error at any position of your choice\n");
	//printf("D7 D6 D5 P4 D3 P2 P1\n");
	for(i=11;i>=0;i--)
	{
		scanf("%d",&ae[i]);
	}
	
	
	e1=checke1();
	e2=checke2();
	e4=checke4();
	e8=checke8();
	
	printf("\ne8=%d e4=%d e2=%d e1=%d",e8,e4,e2,e1);
	
	if(c==1)                      //even parity
	{
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
		
		if(e8%2==0)
			e8=0;
		else
			e8=1;
	}
	if(c==2)                          //odd parity
	{
		if(e1%2!=0)
			e1=0;
		else
			e1=1;
			
		if(e2%2!=0)
			e2=0;
		else
			e2=1;
			
		if(e4%2!=0)
			e4=0;
		else
			e4=1;
		
		if(e8%2!=0)
			e8=0;
		else
			e8=1;
	}

	
	
	printf("\ne8=%d e4=%d e2=%d e1=%d",e8,e4,e2,e1);
	
	ep=(8*e8+4*e4+2*e2+e1)-1;
	if(ep!=0)
	{
		printf("\nError was found at location %d",ep+1);
		
		if(ae[ep]==0)
			ae[ep]=1;
		else if(ae[ep]==1)
			ae[ep]=0;
		else{}
		
			
		printf("\n\nThe correct code is:-\n");
	
		for(i=11;i>=0;i--)
		{
			printf("%d  ",ae[i]);
		}
		
		printf("\n\nThe decoded data is:-\n");
		printf("%d %d %d %d %d %d %d %d",ae[11],ae[10],ae[9],ae[8],ae[6],ae[5],ae[4],ae[2]);
	}
	else
	{
			printf("\nNo error was found.");
	}
}
//


int main()
{
	
	
	printf("Enter mode of operation\n1.EVEN PARITY\n2.ODD PARITY\n>");
	labelc:
	scanf("%d",&c);
	if(c==1 || c==2)
	{
		oddevenpar();
	}
	else
	{
		printf("Invalid Input.Enter again\n>");
		goto labelc;
	}
}

