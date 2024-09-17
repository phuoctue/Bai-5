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

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

int Partition(int a[],int left,int right)
{
	int pivot=a[right];
	int vt=(left-1);
	for(int i=left;i<=right-1;i++)
		if(a[i]<pivot)
		{
			vt++;
			swap(a[vt],a[i]);
		}
	vt=vt+1;
	swap(a[vt],a[right]);
	return vt; 
}

void QuickSort(int a[],int left,int right)
{
	if(left<right)
	{
		int iPivot=Partition(a,left,right);
		QuickSort(a,left,iPivot-1);
		QuickSort(a,iPivot+1,right);
	}
}

main ()
{
	int a[100],n;
	scanf("%d",&n);
	nhap(a,n); 
	QuickSort(a,0,n-1); 
	xuat(a,n);  
}