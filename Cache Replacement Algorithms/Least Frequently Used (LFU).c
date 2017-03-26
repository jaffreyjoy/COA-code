
#include<stdio.h>
#include<math.h>
int fs;														// Frame size
int pgno;													// No of pages
int pgindex;
int pgindex1;
int flag=1;

struct frame
{
	int freq;
	int pgn;
};
struct frame f[100];

struct frame1
{
	int freq2;
	int pgn2;
};
struct frame1 f1[100];

struct framepat
{
	int freq1;
	int pgn1;
};
struct framepat fpat[100];


void copy(int d[],int s[])
{
	int i;
	for(i=0;i<fs;i++)
	{
		d[i]=s[i];
	}
}

void sort(int a[])
{
	int i,j;
	int temp;
	for(i=0;i<fs;i++)
	{
		for(j=0;j<fs;j++)
		{
			if(a[i]<a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

int searchfpat(int x)
{
	int i,res=0;
	for(i=0;i<=100;i++)
	{
		if(fpat[i].pgn1==x)
		{
			res=1;
			//pgindex=i;
			fpat[i].freq1++;
			//printf("\n   Frequency of %d is %d",fpat[i].pgn1,fpat[i].freq1);
			break;
		}	
	}
	return(res);
}

int searchf(int x)
{
	int i,res=0;
	for(i=0;i<=9;i++)
	{
		if(f[i].pgn==x)
		{
			res=1;
			pgindex=i;
			//f[i].freq++;
			//printf("\n   Frequency of %d is %d",f[i].pgn,f[i].freq);
			break;
		}	
	}
	return(res);
}

int searchf1(int x)
{
	int i,res=0;
	for(i=0;i<=9;i++)
	{
		if(f1[i].pgn2==x)
		{
			res=1;
			pgindex1=i;
			//f[i].freq++;
			//printf("\n   Frequency of %d is %d",f[i].pgn,f[i].freq);
			break;
		}	
	}
	return(res);
}
													
int search(int ar[],int x)
{
	int i,res=0;
	for(i=0;i<fs;i++)
	{
		if(ar[i]==x)
		{
			res=1;
			break;
		}	
	}
	return(res);
}

int replace1(int a[],int p[],int begin)
{
	int pos[fs];
	int i,j,min;
	int minelem;
	int rep_index; 								// index of array element to be replaced
	// storing position of pageno.s (i.e in the input array) in an array
	for(j=0;j<fs;j++)
	{
		for(i=begin;i>=0;i--)
		{
			if(a[i]==p[j])
			{
				pos[j]=i;
				break;
			}
		}
	}

//	for(j=0;j<fs;j++)
//	{
//		printf("\n pos[%d]=%d ",j,pos[j]);
//	}


	min=pos[0];
	for(j=1;j<fs;j++)
	{
		if(pos[j]<min)
			min=pos[j];
	}
	minelem=a[min];
//	printf("\nmin=%d minelem=%d \n",min,minelem);
	for(j=0;j<fs;j++)
	{
		if(p[j]==minelem)
			rep_index=j;
	}
//	printf("\n repindex=%d \n",rep_index);
	return(rep_index);
}

int replace(int a[])
{
	int k;
	int ax[fs],fr[fs];
	copy(ax,a);
//	printf("\n");
//	print(ax);
//	printf("\n");
	for(k=0;k<fs;k++)
	{
		searchf1(ax[k]);
		fr[k]=f1[pgindex1].freq2;
	}
	int i,j;
	int min=fr[0];
	int minindex=0;
	int same;
	
//	printf("\n");
//	print(fr);
//	printf("\n");
	
	for(i=1;i<fs;i++)
	{
		if(fr[i]<min)
		{
			min=fr[i];
			minindex=i;
		}
	}
	
	//printf("\nmin=%d   minindex=%d\n",min,minindex);
	same=0;
	for(i=0;i<fs;i++)
	{
		if(fr[i]==min && i!=minindex)
		{
			same++;
		//	printf("\nsame=%d\n",same);
		}
	}
//	printf("\nsame=%d\n",same);
	
	if(same>0)
	{
		flag=-1;
	}
	else
	{
		flag=1;
	}
		
//	printf("\nflag = %d\n",flag);
	
	return(minindex);	
}

print(int ar[])
{
	int i;
	printf("   Frame :  ");
	for(i=0;i<fs;i++)
	{
		if(ar[i]==-1)
			printf("_ ",ar[i]);
		else
			printf("%d ",ar[i]);
	}
}

int main()
{
	
	printf("\n-----------------------------------------------------------------------------------------------------------------------");
 	printf("\n___________________________________________LFU Replacement Algorithm___________________________________________________\n");
 	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	
	printf("\n\n   Enter frame size : ");
	scanf("%d",&fs);
	
	int page[fs];

	int i,j,k;
	
	//Initially filling array with dashes denoting empty frame
	for(i=0;i<fs;i++)
	{
		page[i]=-1;
	}
	
	
	
	printf("\n   Enter the no. of pages : ");
	scanf("%d",&pgno);
	
	for(i=0;i<pgno;i++)
	{
		f[i].freq=0;
		f[i].pgn=-1;
	}
	
	for(i=0;i<pgno;i++)
	{
		f1[i].freq2=0;
		f1[i].pgn2=-1;
	}
	
	for(i=0;i<pgno;i++)
	{
		fpat[i].freq1=1;
		fpat[i].pgn1=-1;
	}
	
	int pginp;
	
	int hits=0;
	int misses=0;
	int id=0;
	int n=0;
	int nf=0;
	int input[pgno];
	int ind=0;
	//taking input for n pages where n=frame size 
	for(i=0;i<pgno,n<pgno;i++)
	{
		if(page[fs-1]!=-1)
			break;
		printf("\n\n%d) Enter the page :  ",n+1);
		scanf(" %d",&pginp);
		input[n]=pginp;
		if(search(page,pginp))
		{
			printf("    Status:-Hit    ,  ");
			print(page);
			i--;
			hits++;
		}
		else
		{
			//printf("\n\nhere\n\n");
			printf("    Status:-Miss   ,  ");
			page[i]=pginp;
			print(page);
			misses++;
		}

		for(k=0;k<fs;k++)
		{
			if(!searchf(page[k]) && page[k]!=-1)
			{
				f[nf++].pgn=pginp;
				pgindex=nf-1;
			}
			if(page[k]!=-1)
				f[pgindex].freq++;
			//if(page[k]!=-1)
			//	printf("\nFrequency of %d is %d",page[k],f[pgindex].freq);
		}
		
		if(!searchf1(pginp))
		{
			f1[ind++].pgn2=pginp;
			f1[ind-1].freq2++;
		}
		else
		{
			f1[pgindex1].freq2++;
		}
			
		for(k=0;k<fs;k++)
		{
			searchf1(page[k]);
			if(page[k]!=-1)
				printf("\n    Frequency of %d is %d",page[k],f1[pgindex1].freq2);
		}
			
		n++;
	}
	
	int num=0,m;
	int dum[fs];
	int patindex=0;
	
	copy(dum,page);
	//printf("\n");
	//print(dum);
	//printf("\n");
	sort(dum);
	//printf("\n");
	//print(dum);
	//printf("\n");
	
	for(m=0;m<fs;m++)
	{
		num=num+dum[m]*pow(10,m);
	}
	//printf("\n  NUM  =  %d\n\n\n",num);
	if(!searchfpat(num))
		fpat[patindex++].pgn1=num;
	
	int repindex;
	int count=n+1;
	for(i=n;i<(pgno);i++)
	{
		printf("\n\n%d) Enter the page :  ",count);
		scanf(" %d",&pginp);
		input[i]=pginp;
		if(search(page,pginp))
		{
			printf("    Status:-Hit    ,  ");
			print(page);
			hits++;
		}
		else
		{
			//printf("\n\nhere\n\n");
			printf("    Status:-Miss   ,  ");
			replace(page);
			if(flag==-1)
			{
			//	printf("\n\nhere\n\n");
				id=replace1(input,page,i-1);
				searchf1(page[id]);
				f1[pgindex1].freq2=0;
			//	printf("\nid = %d\n",id);
				page[id]=pginp;
				print(page);
				misses++;
			}
			else
			{
			//	printf("\n\nhere\n\n");
				repindex=replace(page);
				searchf1(page[repindex]);
				f1[pgindex1].freq2=0;
				page[repindex]=pginp;
				print(page);
			}
			misses++;
		}
//		if(!searchf(pginp))
//		{
//			f[nf++].pgn=pginp;
//		}
		for(k=0;k<fs;k++)
		{
			if(!searchf(page[k]) && page[k]!=-1)
			{
				f[nf++].pgn=pginp;
				pgindex=nf-1;
			}
			if(page[k]!=-1)
				f[pgindex].freq++;
			//if(page[k]!=-1)
			//	printf("\nFrequency of %d is %d",page[k],f[pgindex].freq);
		}
		if(!searchf1(pginp))
		{
			f1[ind++].pgn2=pginp;
			f1[ind-1].freq2++;
		}
		else
		{
			f1[pgindex1].freq2++;
		}
			
		for(k=0;k<fs;k++)
		{
			searchf1(page[k]);
			if(page[k]!=-1)
				printf("\n    Frequency of %d is %d",page[k],f1[pgindex1].freq2);
		}
			
		copy(dum,page);
		//printf("\n");
		//print(dum);
		//printf("\n");
		sort(dum);
		//printf("\n");
		//print(dum);
		//printf("\n");
		num=0;
		for(m=0;m<fs;m++)
		{
			num=num+dum[m]*pow(10,m);
		}
		//printf("\n  NUM  =  %d\n\n\n",num);
		if(!searchfpat(num))
			fpat[patindex++].pgn1=num;
			
		count++;
	}
	float hitp=((float)hits*100)/pgno;
	float missp=((float)misses*100)/pgno;
	
	int max=f[0].freq;
	int max1=f[0].pgn;
	for(i=1;i<pgno;i++)
	{
		if(f[i].pgn!=-1)
		{
			if(f[i].freq>max)
			{
				max1=f[i].pgn;
				max=f[i].freq;
			}	
		}
	}
	
	int maxfarr[pgno];
	
	for(i=0;i<pgno;i++)
	{
		maxfarr[i]=-1;	
	}
	
	for(i=0;i<pgno;i++)
	{
		if(f[i].pgn!=-1 && f[i].pgn!=max1)
		{
			if(f[i].freq==max)
			{
				maxfarr[i]=f[i].pgn;	
			}
		}
	}
	
	
	int maxp=fpat[0].freq1;
	int max1p=fpat[0].pgn1;
	for(i=1;i<pgno;i++)
	{
		if(fpat[i].pgn1!=-1)
		{
			if(fpat[i].freq1>maxp)
			{
				max1p=fpat[i].pgn1;
				maxp=fpat[i].freq1;
			}	
		}
	}

	
	int maxpatarr[pgno];
	
	for(i=0;i<pgno;i++)
	{
		maxpatarr[i]=-1;	
	}
	
	for(i=0;i<pgno;i++)
	{
		if(fpat[i].pgn1!=-1 && fpat[i].pgn1!=max1p)
		{
			if(fpat[i].freq1==maxp)
			{
				maxpatarr[i]=fpat[i].pgn1;	
			}
		}
	}
	
	
//	printf("\n\tInput array : ",input[i]);
//	for(i=0;i<pgno;i++)
//	{
//		printf("%d  ",input[i]);
//	}
	

	
	printf("\n\n    Hits = %d  ,  Hit %% = %f %% ",hits,hitp);
	printf("\n    Misses = %d  ,  Misses %% = %f %% \n",misses,missp);


	printf("\n\tList of unique page nos. and their corresponding frequencies(in the cache):-");
	for(i=0;i<pgno;i++)
	{
		if(f[i].pgn!=-1)
		{
			printf("\n\tPgno = %d  ,  Frequency = %d ",f[i].pgn,f[i].freq);
		}
	}

	printf("\n\n\t'%d' ",max1);
	for(i=0;i<pgno;i++)
	{
		if(maxfarr[i]!=-1)
			printf("and '%d' ",maxfarr[i]);
	}
	printf("occured maximum no. of times i.e %d times.\n",max);

	printf("\n\tList of unique page patterns and their corresponding frequencies:-");
	int num1,pow1;
	for(i=0;i<pgno;i++)
	{
		if(fpat[i].pgn1!=-1)
		{
			printf("\n\tPgnos = " );
			num1=fpat[i].pgn1;
			for(j=fs-1;j>=0;j--)
			{
				pow1=pow(10,j);
				num=num1/pow1;
				num1=num1%pow1;
				printf(" %d ",num);
			}

			printf("  ,  Frequency = %d ",fpat[i].freq1);
		}
	}

	if(maxp!=1)
	{
		num1=max1p;
		
		printf("\n\n\tPattern ");
		for(j=fs-1;j>=0;j--)
		{
			pow1=pow(10,j);
			num=num1/pow1;
			num1=num1%pow1;
			printf(" %d ",num);
		}
		for(i=0;i<pgno;i++)
		{
			if(maxpatarr[i]!=-1)
			{
				printf(" and ");
				num1=maxpatarr[i];
				for(j=fs-1;j>=0;j--)
				{
					pow1=pow(10,j);
					num=num1/pow1;
					num1=num1%pow1;
					printf(" %d ",num);
				}
			}
		}
		printf("  occured maximum no. of times i.e %d times.\n",maxp);
	}
	else
		printf("\n\n\tNo pattern occurced more than once.  :(  \n");
	


//	for(i=fs;i<pgno;i++)
//	{
//		printf("Enter the page :  ");
//		scanf("%d",&pginp);
//
//		page[i]=pginp;
//		print(page);
//	}

//	int i,j,jk;
//	for(i=)
}
