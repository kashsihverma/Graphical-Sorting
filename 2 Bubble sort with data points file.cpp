/**

        Kashish verma       IIT ROORKEE
        kverma@ma.iitr.ac.in

**/
#include <cstdlib>
#include <iostream>
#include <graphics.h>
#include <windows.h>
#include <ctime>
#include <string>
#include <cmath>

const int WinX = 1024;
const int WinY = 768;
const int MAX = 1000;

using namespace std;

int randomNumber(int hi)
{
    const float scale = rand()/float(RAND_MAX);
    return int(scale*hi);
}


void plotDots(int posX, int posY, int color)
{
     if (color == 0)
     {
          putpixel(WinX - posX, WinY - posY, LIGHTGREEN);
     }
     else
     {
          putpixel(WinX - posX, WinY - posY, WHITE);
     }
}

void swapValue(int &x, int &y)
{
     x = x + y;
     y = x - y;
     x = x - y;
}

void iniRandomPlot(int(&arrayVal) [MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        arrayVal[i] = randomNumber(999);
        plotDots((WinX - arrayVal[i]),(WinY - (arrayVal[(i / 2)])),0);
        cout<< arrayVal[i];
        Sleep(1);
    }
}

void iniBubbleSort(int(&arrayVal) [MAX])
{
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (arrayVal[j] > arrayVal[(j+1)])
            {
               swapValue(arrayVal[j],arrayVal[(j+1)]);
            }

            cout<<arrayVal[j];
            //plotDots((WinX - arrayVal[j]),(WinY - (arrayVal[(j / 2)])),0);
            plotDots(arrayVal[j],(WinY - (arrayVal[(j/2)])),0);
        }
        cout << endl << endl;
        Sleep(1);

        if (i != MAX)
        {
           cleardevice();
        }
    }
}


int main(int argc, char *argv[])
{
    /*
    while ((MAX > 1000) || (MAX < 5))
    {
        cout << "Please enter the # of elements (5-1000): ";
        cin >> MAX;
    }
    */

    // array variable declaration
    int arrayVal[MAX];

    initwindow(1024,768);
    iniRandomPlot(arrayVal);

    cout << endl << endl << endl;
    outtextxy(10,6," Sorting Data points in 3 seconds... Please wait.");
    Sleep(3000);
    cleardevice();

    iniBubbleSort(arrayVal);

    outtextxy(10,6,"Sort Completed!");

    while(!kbhit());

    closegraph();
    return 0;
}
