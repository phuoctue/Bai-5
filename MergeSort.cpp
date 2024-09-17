#include <stdio.h>
#include <math.h>

void nhap(int a[],int n)
{
	if(n==0)
		return;
	nhap(a,n-1);
	scanf("%d",&a[n-1]); 
}

void xuat(int a[],int n)
{
	if(n==0)
		return;
	xuat(a,n-1);
	printf("%d ",a[n-1]); 
}

void merge(int a[],int left,int mid,int right)
{
	int *temp=(int*)malloc((right-left+1)*sizeof(int));
	int m;
	int i=left;//Duyet khong gian con thu nhat tu left....mid
	int j=mid+1;//Duyet khong gian con thu hai tu mid+1....right
	m=0;
	while(!(i>mid && j>right))
	{
		if((i<=mid && j<=right && a[i]<a[j]) || j>right)
		
			temp[m++] = a[i++];
		else
			temp[m++] = a[j++];
	}
	for(int i=0;i<m;i++)
		a[left+i]=temp[i];
	free(temp);
}

void mergeSort(int a[],int left,int right)
{
	if(left<right)
	{
		int mid=(right+left)/2;
		mergeSort(a,left,mid);
		mergeSort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}
int main ()
{
	int a[100],n;
	scanf("%d",&n);
	nhap(a,n);
	mergeSort(a,0,n-1); 
	xuat(a,n);  
}