// HTD

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

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

void my_circle(int x_centre, int y_centre, int r) 
{ 
    //First Pint
    int x=0,y=r;
    putpixel(x+x_centre,y+y_centre,WHITE);
    int p = 1-r;
    while(x<=y)
    {
        if(p<0)
        {
           x++;
       

            putpixel(x + x_centre ,-y + y_centre,WHITE);
            putpixel(y + x_centre ,x + y_centre,WHITE);
            // putpixel(-y + x_centre ,x + y_centre,WHITE);

            putpixel(x + x_centre,y + y_centre,WHITE);
            // putpixel(-x + x_centre,y + y_centre,WHITE);
            putpixel(x + x_centre,-y + y_centre,WHITE);
            // putpixel(-x + x_centre,-y + y_centre,WHITE);

            putpixel(y + x_centre, x + y_centre,WHITE);
            // putpixel(-y + x_centre, x + y_centre,WHITE);
            putpixel(y + x_centre, -x + y_centre,WHITE);
            // putpixel(-y + x_centre, -x + y_centre,WHITE);

           
           p=p+2*x+1;
        }
        else
        {
            x++;
            y--;

            putpixel(x + x_centre ,-y + y_centre,WHITE);
            putpixel(y + x_centre ,x + y_centre,WHITE);
            // putpixel(-y + x_centre ,x + y_centre,WHITE);

            putpixel(x + x_centre,y + y_centre,WHITE);
            // putpixel(-x + x_centre,y + y_centre,WHITE);
            putpixel(x + x_centre,-y + y_centre,WHITE);
            // putpixel(-x + x_centre,-y + y_centre,WHITE);

            putpixel(y + x_centre, x + y_centre,WHITE);
            // putpixel(-y + x_centre, x + y_centre,WHITE);
            putpixel(y + x_centre, -x + y_centre,WHITE);
            // putpixel(-y + x_centre, -x + y_centre,WHITE);

        
            p=p+2*x+1-2*y;
        }
    }

}

void flood_fill(int x, int y)
{
    putpixel(x, y, RED);
    if(getpixel(x+1, y) == BLACK)
        flood_fill(x+1, y);
    if(getpixel(x, y+1) == BLACK)
        flood_fill(x, y+1);
    if(getpixel(x, y-1) == BLACK)
        flood_fill(x, y-1);
    if(getpixel(x-1, y) == BLACK)
        flood_fill(x-1, y);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // H
    my_line(10, 0, 10, 50);    
    my_line(20, 0, 20, 20);
    my_line(20, 30, 20, 50);
    my_line(60, 0, 60, 20);
    my_line(60, 30, 60, 50);
    my_line(70, 0, 70, 50);
    my_line(20, 20, 60, 20);
    my_line(20, 30, 60, 30);
    my_line(10, 0, 20, 0);
    my_line(10, 50, 20, 50);
    my_line(60, 0, 70, 0);
    my_line(60, 50, 70, 50);

    //T
    my_line(80, 0, 80, 10);
    my_line(110, 10, 110, 50);
    my_line(120, 10, 120, 50);
    my_line(150, 0, 150, 10);
    my_line(80, 0, 150, 0);
    my_line(80, 10, 110, 10);
    my_line(120, 10, 150, 10);
    my_line(110, 50, 120, 50);

    //D
    my_line(170, 0, 170, 50);
    my_line(180, 10, 180, 40);
    my_circle(180, 25, 25);
    my_circle(180, 25, 15);
    putpixel(205, 25, WHITE);
    putpixel(195, 25, WHITE);
    my_line(170, 0, 180, 0);
    my_line(170, 50, 180, 50);

    flood_fill(11, 49);
    flood_fill(90, 5);
    flood_fill(175, 5);

    delay(500000);
    closegraph();
    return 0;
}