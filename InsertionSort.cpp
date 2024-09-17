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

void insertSort(int a[],int n)
{
	int k=1;
	while(k<=n-1)
	{
		int x=a[k];
		int vt;
		for(vt = k-1; vt>=0 && a[vt]>x;vt--)
			a[vt+1]=a[vt];
		a[vt+1]=x;
		k++;
	}
}

int main ()
{
	int a[100],n;
	scanf("%d",&n);
	nhap(a,n);
	insertSort(a,n); 
	xuat(a,n);  
}