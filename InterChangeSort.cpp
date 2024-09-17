#include <stdio.h>
#include <math.h>

void nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}

int swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int InterchangeSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i] > a[j])
				swap(a[i],a[j]); 
}

int main ()
{
	int a[100],n;
	scanf("%d",&n);
	nhap(a,n);
	InterchangeSort(a,n); 
	xuat(a,n);  
}