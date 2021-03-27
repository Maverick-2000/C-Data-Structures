#include<stdio.h>

void bubble(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{	
			if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
		}
	}
	printf("\n Resultant array: \n");
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
}
	
void insert(int a[],int n)
{
	int i,j,temp;
	i=1;
	for(i=1;i<n;i++)
	{	temp=a[i];
		j=i-1;
		while(temp<a[j]&&j>=0)
			{
				a[j+1]=a[j];
				j=j-1;
			}
		a[j+1]=temp;
	}	
	printf("\n Resultant array: \n");
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
}

void select(int a[],int n)
{
	int i,j,flag;
	i=0;
	int min,pos,temp;
	while(i<n-1)
	{
		min=a[i];
		flag=0;
		j=i+1;
		while(j<n)
		{	if(a[j]<min)
			{
				min=a[j];
				pos=j;
				flag=1;		
			}	
		j=j+1;	
		}		
		if(flag==1)
			{
				temp=a[i];	
				a[i]=a[pos];
				a[pos]=temp;
			}	
		
		i=i+1;
	}
	printf("\n Resultant array: \n");
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);

}

void quick(int a[], int start, int end)
{
	int left,right,key;
	int i,n,temp;
	n=end;
	left=start;
	right=end;
	key=a[(left+right)/2];
	while(left<=right)
	{	while(a[left]<key)
			left++;
		while(a[right]>key)
			right--;
	if(left<=right)
		{
			temp=a[left];	
			a[left]=a[right];
			a[right]=temp;
			left++;
			right--;
		}
	if(start<right)
			quick(a,start,right);
	if(left<end)
			quick(a,left,end);
	}
}
void mergesort(int a[], int beg, int mid, int end)
{
		int i,j,index,temp[100];
		i=beg;	
		j=mid+1;
		index=beg;
		while(i<=mid && j<=end)
		{
			if(a[i]<a[j])
			{	temp[index]=a[i];
				i++;			
				index++;
			}
			else 
				{
					temp[index]=a[j];
					j++;
					index++;
				}
		}
		while(i<=mid)
			{
				temp[index]=a[i];
				i++;
				index++;
			}
		while(j<=end)
			{
				temp[index]=a[j];
				j++;
				index++;
			}
		int k=0;
			while(k<index)
				{	a[k]=temp[k];
					k++;
				}
}

void merge(int a[],int beg,int end)
{
	int n,mid;
	if(beg<end)
	{	mid=(beg+end)/2;
		merge(a,beg,mid);	
		merge(a,mid+1,end);
		mergesort(a,beg,mid,end);
	}

}


void main()
{
	int a[20],ch,n,i;
	printf("enter the number of elements: \n");
	scanf("%d",&n);
	printf("enter the elements: \n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	do{printf("Enter choice \n");
	printf("1.Bubble sort\n");
	printf("2.Selection sort\n");
	printf("3.Insertion sort\n");
	printf("4.Quick sort \n");
	printf("5.Merge sort \n");
	printf("6.Enter new array\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: bubble(a,n);
			break;
		case 2: select(a,n);
			break;
		case 3: insert(a,n);
			break;
		case 4:	quick(a,0,n-1);
			printf("\n Resultant array: \n");
				for(i=0;i<n;i++)
				printf(" %d ",a[i]);
			break;
		case 5: merge(a,0,n-1);
			printf("\n Resultant array: \n");
				for(i=0;i<n;i++)
				printf(" %d ",a[i]);
			break;
		case 6: printf("enter the number of elements: \n");
			scanf("%d",&n);
			printf("enter the elements: \n");
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);
			break;
		default:	printf("\n Wrong Choice \n");
				break;
		}
	}while(ch!=0);		
}
