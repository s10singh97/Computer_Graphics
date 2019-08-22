// DDA Algorithm

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cout<<"Enter the points: ";
    cin>>x1>>y1>>x2>>y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    float m = float((y2-y1))/(x2-x1);
    int comp = (y2-y1) - (x2-x1);
    if(comp < 1)
    {
        float x_curr = x1, y_curr = y1;
        while(x_curr != x2 && y_curr != y2)
        {
            x_curr += 1;
            y_curr += m;
            // y_curr = floor(y_curr);
            putpixel(x_curr, floor(y_curr), WHITE);
        }
    }
    else
    {
        float x_curr = x1, y_curr = y1;
        while(x_curr != x2 && y_curr != y2)
        {
            y_curr += 1;
            x_curr += (1/m);
            // x_curr = floor(x_curr);
            putpixel(floor(x_curr), y_curr, WHITE);
        }
    }
    delay(500000);
    closegraph();
    return 0;
}