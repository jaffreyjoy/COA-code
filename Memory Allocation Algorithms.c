#include<stdio.h>

int sz=6;
int flag=0;
int bfindex;
int wfindex;
int nfindex;

struct memory
{
	char type;
	int no;
	int size;
}mem[100];

cascade(int x,int siz)
{
	int i;
	for(i=sz;i>=x;i--)
	{
		if(i==x)
		{
			mem[i].type=mem[i-1].type;
			mem[i].no=mem[i-1].no;
			mem[i].size=siz;
		}
		else
		{
			mem[i].type=mem[i-1].type;
			mem[i].no=mem[i-1].no;
			mem[i].size=mem[i-1].size;	
		}
	}
}

worstf(int x[])
{
	int i,id,max=x[0];
	wfindex=0;
	for(i=1;i<sz;i++)
	{
		if(x[i]>max)
		{
			max=x[i];
			wfindex=i;
		}
	}
	if(max==-1)
		id=0;
	else
		id=1;
		
	return(id);
}

worstfit(int n,int s)
{
	int i,j,k;
	int wfid=0;
	int wf[sz];
	for(i=0;i<sz;i++)
	{
		if(mem[i].type=='f' && mem[i].size>=s)
		{
			wf[i]=mem[i].size;
		}
		else
		{
			wf[i]=-1;
		}
	}
	
	wfid=worstf(wf);
	
	if(wfid==1)
	{
		if(mem[wfindex].size-s>0)
		{
			sz++;
			cascade(wfindex+1,mem[wfindex].size-s);
		}
	
		mem[wfindex].type='p';
		mem[wfindex].no=n;
		mem[wfindex].size=s;
		flag=1;
	}
	else
	{
		flag=0;
	}

}

bestf(int x[])
{
	int i,id,min=x[0];
	bfindex=0;
	for(i=1;i<sz;i++)
	{
		if(x[i]<min)
		{
			min=x[i];
			bfindex=i;
		}
	}
	if(min==99999)
		id=0;
	else
		id=1;
		
	return(id);
}

bestfit(int n,int s)
{
	int i,j,k;
	int bfid=0;
	int bf[sz];
	for(i=0;i<sz;i++)
	{
		if(mem[i].type=='f' && mem[i].size>=s)
		{
			bf[i]=mem[i].size;
		}
		else
		{
			bf[i]=99999;
		}
	}
	
	bfid=bestf(bf);
	
	if(bfid==1)
	{
		if(mem[bfindex].size-s>0)
		{
			sz++;
			cascade(bfindex+1,mem[bfindex].size-s);
		}
	
		mem[bfindex].type='p';
		mem[bfindex].no=n;
		mem[bfindex].size=s;
		flag=1;
	}
	else
	{
		flag=0;
	}

}

nextfit(int n,int s)
{
	int i,j,k;
	for(i=0,j=nfindex;i<sz;i++)
	{
		if(mem[j].type=='f' && mem[j].size>=s)
		{
			if(mem[j].size-s>0)
			{
				sz++;
				cascade(j+1,mem[j].size-s);
			}
			mem[j].type='p';
			mem[j].no=n;
			mem[j].size=s;
			flag=1;
			break;
		}
		if(j==sz-1)
			j=0;
		else
			j++;
	}
}

firstfit(int n,int s)
{
	int i,j,k;
	for(i=0;i<sz;i++)
	{
		if(mem[i].type=='f' && mem[i].size>=s)
		{
			if(mem[i].size-s>0)
			{
				sz++;
				cascade(i+1,mem[i].size-s);
			}
				
			mem[i].type='p';
			mem[i].no=n;
			mem[i].size=s;
			flag=1;
			break;
		}
	}
}

userinitmem()
{
	int num,i,typ;
	printf("\nEnter the total inputs  :  ");
	scanf("%d",&num);
	sz=num;
//	printf("Enter custom memory structure  :-\n");
	for(i=0;i<num;i++)
	{
		printf("\nEnter the type of memory content :  ");
		scanf(" %c",&mem[i].type);
		printf("Enter the Process/Free space no.  :  ");
		scanf("%d",&mem[i].no);
		printf("Enter the size  :  ");
		scanf("%d",&mem[i].size);
		printf("\n");
		if(mem[i].type=='f')
			nfindex=i;
	}
}

initmem()
{
	//Process P1
	mem[0].type='p';mem[0].no =1;
	mem[0].size =2;
	
	//Free Space F1
	mem[1].type='f';mem[1].no =1;
	mem[1].size =4;
	
	//Process P2
	mem[2].type='p';mem[2].no =2;
	mem[2].size =6;

	//Free Space F2
	mem[3].type='f';mem[3].no =2;
	mem[3].size =3;
	
	//Process P3
	mem[4].type='p';mem[4].no =3;
	mem[4].size =1;

	//Free Space F3
	mem[5].type='f';mem[5].no =3;
	mem[5].size =2;
	
}

print()
{
	int i;
	printf("\nMemory Structure  :-");
	printf("\n---------------------\n\n");
	printf("\n\t--------------------------------------------\n");
	printf("\t   Memory Content       |   Size in memory   ");
	printf("\n\t--------------------------------------------\n");
	for(i=0;i<sz;i++)
	{
		if(mem[i].type=='p')
		{
			printf("         Process    = %c%d\t|        %d\n\n",mem[i].type,mem[i].no,mem[i].size);
		}
		
		else if(mem[i].type=='f')
		{
			printf("         Free Space = %c%d\t|        %d\n\n",mem[i].type,mem[i].no,mem[i].size);
		}
		
	}
	printf("\n-----------------------------------------------------\n\n");
}

int main()
{
	int ch,ch1;
	int n1,s1;
	
	printf("\n------------------------------------------------------------------------------------------------------------------------");
 	printf("\n_________________________________________Memory Allocation Policies_____________________________________________________\n");
 	printf("------------------------------------------------------------------------------------------------------------------------\n\n");
	
	printf("Options :-\n");
	printf("1.Ready-made memory model\n2.Custom memory model\n");
	printf("Enter your choice  :  ");
	scanf("%d",&ch1);
	
	if(ch1==1)
	{
		initmem();
		nfindex=sz-1;
	}
	else
		userinitmem();
		
	print();
	
	printf("Options:-\n");
	printf("1.First Fit\n2.Best Fit\n3.Next Fit\n4.Worst Fit\n");
	printf("Enter your choice  :  ");
	scanf("%d",&ch);
	
	printf("\nEnter the Process no.  :  ");
	scanf("%d",&n1);
	printf("Enter the size  :  ");
	scanf("%d",&s1);
	
	if(ch==1)
		firstfit(n1,s1);
	if(ch==2)
		bestfit(n1,s1);
	if(ch==3)
		nextfit(n1,s1);
	if(ch==4)
		worstfit(n1,s1);
	
	if(flag==1)
		print();
	else
	{
		printf("\n-----------------------------------------------------\n\n");
		printf("Memory size of entered process is too high to allocate amongst available free space   :( \nSwapping would be required.Process terminated.");
	}
		
}













