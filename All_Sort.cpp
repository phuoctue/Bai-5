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

void selectionSort(int a[],int n)
{
	for(int i = 0;i <= n - 2;i++)
	{
		int lc = i;
		for(int j = i;j <= n - 1;j++)
			if(a[j] < a[lc])
				lc = j;
		swap(a[i],a[lc]); 
	}
}

void bubbleSort(int a[],int n)
{
	for(int i = 0;i <= n - 2;i++)
		for(int j = n - 1;j >= i + 1;j--)
			if(a[j] < a[j-1])
				swap(a[j],a[j-1]); 
}

void inserttionSort(int a[],int n)
{
	int k = 1;
	while(k <= n-1)
	{
		int x = a[k];
		int vt;
		for(vt = k - 1; vt >= 0 && a[vt] > x;vt--)
			a[vt + 1] = a[vt];
		a[vt+1] = x;
		k++;
	}
}

void Merge(int a[],int left,int mid,int right)
{
	int *temp = (int*)malloc((right-left+1)*sizeof(int));
	int m;
	int i = left;
	int j = mid + 1;
	m = 0;
	while(!(i>mid && j>right))
	{
		if((i<=mid && j<=right && a[i] < a[j]) || j>right)
			temp[m++] = a[i++];
		else
			temp[m++] = a[j++];
	}
	for(int i=0;i<m;i++)
		a[left+i] = temp[i];
	free(temp);
}

void MergeSort(int a[],int left,int right)
{
	if(left < right)
	{
		int mid = (left+right)/2;
		MergeSort(a,left,mid);
		MergeSort(a,mid+1,right);
		Merge(a,left,mid,right); 
	}
}

int Partition(int a[],int left,int right)
{
	int pivot = a[right];
	int vt = (left - 1);
	for(int i=0; i<=right-1;i++)
		if(a[i] < pivot)
		{
			vt++;
			swap(a[vt],a[i]); 
		}
	vt++;
	swap(a[vt],a[right]);
	return vt; 
}

void QuickSort(int a[],int left,int right)
{
	if(left < right)
	{
		int ipivot = Partition(a,left,right);
		QuickSort(a,left,ipivot-1);
		QuickSort(a,ipivot+1,right);    
	}	
}

int main ()
{
	int a[100],n;
	scanf("%d",&n);
	nhap(a,n); 
	int lc;
	do
	{
		printf("\t\t\t\t\t ============MENU==========\n");
		printf("\t\t\t\t\t |1.Sap xep chon           |\n");
		printf("\t\t\t\t\t |2.Sap xep noi bot        |\n");
		printf("\t\t\t\t\t |3.Sap xep chen           |\n");
		printf("\t\t\t\t\t |4.Sap xep tron           |\n");
		printf("\t\t\t\t\t |5.Sap xep nhanh          |\n");
		printf("\t\t\t\t\t |0.Thoat                  |\n");
		printf("\t\t\t\t\t ==========================\n");
		printf("Nhap lua chon: ");
		scanf("%d",&lc);
		switch(lc)
		{
			case 1: 
				selectionSort(a,n); 
				xuat(a,n); 
				printf("\n");
				break;
			case 2:
				bubbleSort(a,n);
				xuat(a,n);  
				printf("\n");
				break; 
			case 3: 
				inserttionSort(a,n);
				xuat(a,n);
				printf("\n");  
				break;
			case 4:
				MergeSort(a,0,n-1);
				xuat(a,n);
				printf("\n");
				break; 
			case 5:
				QuickSort(a,0,n-1);
				xuat(a,n);
				printf("\n");  
				break;
		}
	}while(lc!=0);
	 
}