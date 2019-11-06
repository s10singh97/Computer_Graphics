// Sphere

#include<bits/stdc++.h>
#include<graphics.h>

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
    //First Point
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

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    my_circle(200, 200, 120);
    delay(500000);
    closegraph();
    return 0;
}