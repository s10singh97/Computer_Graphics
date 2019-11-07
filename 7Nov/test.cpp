// Ball falling from a height

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void draw_points(int x, int y, int x_centre, int y_centre)
{
    putpixel(x + x_centre ,-y + y_centre,WHITE);
    putpixel(y + x_centre ,x + y_centre,WHITE);
    putpixel(-y + x_centre ,x + y_centre,WHITE);

    putpixel(x + x_centre,y + y_centre,WHITE);
    putpixel(-x + x_centre,y + y_centre,WHITE);
    putpixel(x + x_centre,-y + y_centre,WHITE);
    putpixel(-x + x_centre,-y + y_centre,WHITE);

    putpixel(y + x_centre, x + y_centre,WHITE);
    putpixel(-y + x_centre, x + y_centre,WHITE);
    putpixel(y + x_centre, -x + y_centre,WHITE);
    putpixel(-y + x_centre, -x + y_centre,WHITE);
}


void my_circle(int x_centre, int y_centre, int r) 
{ 
    //Mid Point circle drawing algo
    int x = 0, y = r;
    putpixel(x + x_centre, y + y_centre,WHITE);
    putpixel(y + y_centre, x + x_centre,WHITE);
    putpixel(x + x_centre, -y + y_centre,WHITE);
    putpixel(-y + y_centre, x + x_centre,WHITE);
    int p = 1 - r;
    while(x <= y)
    {
        if(p < 0)
        {
            x++;
            draw_points(x, y, x_centre, y_centre);
            p = p + 2*x + 1;
        }
        else
        {
            x++;
            y--;
            draw_points(x, y, x_centre, y_centre);
            p=p + 2*x + 1 - 2*y;
        }
    }

    // Code for Sphere
    float phi;
    float theta;
    float i,j;
    for(phi = -1.57; phi<=0; phi += 0.1)
    {
        for(theta = -3.14; theta<=3.14; theta += 0.2)
        {
            x = r * cos(phi) * cos(theta);
            y = r * cos(phi) * sin(theta);
            draw_points(0, y, x_centre, y_centre);
            p = 1 - r;
            while(x <= y)
            {
                x++;
                if (p < 0)
                {
                    p += 2*x + 1;
                    draw_points(x, y, x_centre, y_centre);
                }
                else
                {
                    y--;
                    p += 2*x + 1 - 2*y;
                    draw_points(x, y, x_centre, y_centre);
                }
            }
        }
    }
}


// Code for line drawing using DDA
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

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    my_circle(50, 50, 25);
    float t = 1;
    float h = 100;
    float v = 10;
    float xx = v*t;
    float yy = (4.9*t*t);
    float tof = sqrt(2*h/9.8);
    float range = v*tof;
    while(t <= 4.2)
    {
        my_circle(50+xx, 50+yy, 25);
        t += 0.5;
        xx += v*t;
        yy += (4.9*t*t);
    }
    // code for bounce
    h = h/2;
    v = v/2;
    t = 1;
    float theta = 0.52;
    xx += v*cos(theta)*t;
    yy += (v*sin(theta)*t) - (4.9*t*t);
    tof = (2*v*sin(theta))/9.8;
    while(t != 3)
    {
        my_circle(50+xx, 50+yy-5, 25);
        t += 0.5;
        xx += v*cos(theta)*t;
        yy += (v*sin(theta)*t) - (4.9*t*t);
    }
    xx += 10;
    my_circle(50+xx, 50+yy, 25);
    xx += 10;
    my_circle(50+xx, 50+yy-5, 25);
    xx += 10;
    my_circle(50+xx, 50+yy, 25);

    t = 1;
    h = yy;
    xx += v*t;
    yy += (4.9*t*t);
    tof = sqrt(2*h/9.8);
    range = v*tof;
    while(t <= 2.5)
    {
        // putpixel(50+xx, 50+yy, WHITE);
        my_circle(50+xx, 50+yy, 25);
        t += 0.5;
        xx += v*t;
        yy += (4.9*t*t);
    }
    delay(500000);
    closegraph();
    return 0;
}