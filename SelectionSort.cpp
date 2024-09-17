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

int hoanVi(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int SelectionSort(int a[],int n)
{
	for(int i=0;i<=n-2;i++)
	{
		int lc=i;
		for(int j=i;j<=n-1;j++)
			if(a[j]<a[lc])
				lc=j;
		hoanVi(a[i],a[lc]); 
	}
}
int main ()
{
	int n,a[100];
	scanf("%d",&n);
	nhap(a,n);
	SelectionSort(a,n);
	xuat(a,n);   
}