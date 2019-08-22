// BresenHams

#include<bits/stdc++.h>
#include<graphics.h>
#include<X11/Xlib.h>
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
        int x_curr = x1, y_curr = y1;
        int pk = 2*(y2-y1) - (x2-x1);
        putpixel(x_curr, y_curr, WHITE);
        while(x_curr != x2 && y_curr != y2)
        {
            if(pk < 0)
                x_curr += 1;
            else
            {
                x_curr += 1;
                y_curr += 1;
            }
            cout<<x_curr<<"\t"<<y_curr<<"\n";
            putpixel(x_curr, y_curr, WHITE);
            if(pk < 0)
                pk = pk + 2*(y2 - y_curr);
            else
                pk = pk + 2*(y2-y_curr) - 2*(x2-x_curr);
        }
    }
    else
    {
        int x_curr = x1, y_curr = y1;
        int pk = 2*(y2-y1) - (x2-x1);
        putpixel(x_curr, y_curr, WHITE);
        while(x_curr != x2 && y_curr != y2)
        {
            if(pk < 0)
                y_curr += 1;
            else
            {
                x_curr += 1;
                y_curr += 1;
            }
            putpixel(x_curr, y_curr, WHITE);
            if(pk < 0)
                pk = pk + 2*(y2 - y_curr);
            else
                pk = pk + 2*(y2-y_curr) - 2*(x2-x_curr);
        }
    }
    
    delay(500000);
    getch();
    closegraph();
    return 0;
}