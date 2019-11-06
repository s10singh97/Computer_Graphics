// Cuboid & Cube

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

const double pi = acos(-1);

void my_line(int x1, int y1, int x2, int y2)
{
    float m = float((y2-y1))/(x2-x1);
    int comp = (y2-y1) - (x2-x1);
    if(x2-x1 == 0)
    {
        float x_curr = x1, y_curr = min(y1, y2);
        while(y_curr != max(y1, y2))
        {
            y_curr += 1;
            putpixel(x_curr, y_curr, WHITE);
        }
    }
    else if(y2 - y1 == 0)
    {
        float x_curr = x1, y_curr = y1;
        while(x_curr != x2)
        {
            x_curr += 1;
            y_curr += m;
            putpixel(x_curr, floor(y_curr), WHITE);
        }
    }
    else if(comp < 1)
    {
        float x_curr = x1, y_curr = y1;
        while(x_curr != x2 && y_curr != y2)
        {
            x_curr += 1;
            y_curr += m;
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
            putpixel(floor(x_curr), y_curr, WHITE);
        }
    }
}

void flood_fill(int x, int y)
{
    putpixel(x, y, WHITE);
    if(getpixel(x+1, y) == BLACK)
        flood_fill(x+1, y);
    if(getpixel(x, y+1) == BLACK)
        flood_fill(x, y+1);
    if(getpixel(x, y-1) == BLACK)
        flood_fill(x, y-1);
    if(getpixel(x-1, y) == BLACK)
        flood_fill(x-1, y);
}

void square()
{
    int x1 = 70, y1 = 70, x2 = 70, y2 = 120, x3 = 120, y3 = 70, x4 = 120, y4 = 120;
    my_line(x1, y1, x2, y2);
    my_line(x3, y3, x4, y4);
    my_line(x1, y1, x3, y3);
    my_line(x2, y2, x4, y4);
    flood_fill(x1+1, y1+1);
    int d = 1;
    while(d != (y2-y1)/2)   // For Cube by default for cuboid remove '/2' from '(y2-y1)/2'
    {
        my_line(x1+d, y1+d, x2+d, y2+d);
        my_line(x3+d, y3+d, x4+d, y4+d);
        my_line(x1+d, y1+d, x3+d, y3+d);
        my_line(x2+d, y2+d, x4+d, y4+d);
        flood_fill(x1+d+1, y1+d+1);
        d += 1;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    square();

    delay(500000);
    closegraph();
    return 0;
}