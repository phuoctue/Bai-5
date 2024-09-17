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

void Swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void BubbleSort(int a[],int n)
{
	for(int i=0; i<=n-2; i++)
		for(int j=n-1; j>=i+1; j--)
			if(a[j]<a[j-1])
				Swap(a[j],a[j-1]); 
}

int main ()
{
	int a[100],n;
	scanf("%d",&n);
	nhap(a,n);
	BubbleSort(a,n); 
	xuat(a,n);  
}