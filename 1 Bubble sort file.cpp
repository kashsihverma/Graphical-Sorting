#include<graphics.h>
#include<iostream>
#include <stdlib.h>
using namespace std;




int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    int maxix=getmaxx();
     bar(0,400,maxix,410);
     outtextxy(300,50,"Press any key to start");

	int c=600;

	int a[c];
	for(int i=0;i<c;i++)
	{
		a[i]=rand()%400;
       line(i,400,i,a[i]);

	}getch();
	for(int k=1;k<c;k++)
	{ int flag=0;
		for(int i=0;i<c-k;i++)
		{
			int t;
			if(a[i]>a[i+1])
			{
				swap(a[i],a[i+1]);
			//	line(i,400,i,a[i]);
				flag++;
			}

		}if(flag==0)
				{
				break;}
				int k1=30;
				if(k1%30==0)
				{
				    for(int i1=c-1;i1>0;i1--)
                        {
                            line(i1,400,i1,a[i1]);
                        }
                        cleardevice();
                        k1++;
				}
	}
	for(int i=0;i<c;i++)
	{
		cout<<a[i]<<"\t";
        line(i,400,i,a[i]);
	}
	outtextxy(300,50,"Bubble sort finish");
	    getch();
    closegraph();

}
