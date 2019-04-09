#include <stdlib.h>
#include<iostream>
#include<graphics.h>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{

		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		for(int i1=0;i1<210;i1++)
	{
	    bar(i1*3,arr[i1],(i1*3)-3,400);
	}
        delay(30);
	 cleardevice();
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);


		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void printArray(int arr[], int size)
{
	int i;
		for(int i1=0;i1<210;i1++)
	{
	    bar(i1*3,arr[i1],(i1*3)-3,400);
	}getch();
	for (i=0; i < size; i++)
		cout<< arr[i]<<"  ";

}


int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    int maxix=getmaxx();
     bar(0,400,maxix,410);
     outtextxy(300,50,"Press any key to start");

    int n=220;
	int arr[n] ;
	for(int i=0;i<n;i++)
	{
	    arr[i]=rand()%399;
	    bar(i*3,arr[i],(i*3)-3,400);
	}getch();
	quickSort(arr, 0, n-1);
	cout<<"Sorted array: ";
	outtextxy(300,50,"Quick sort finish");
	printArray(arr, n);
	    getch();
    closegraph();


	return 0;
}
