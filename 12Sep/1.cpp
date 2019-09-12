// Mid Point Ellipse Drawing Algo

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void dawellipse(int a, int b, int x_c, int y_c)
{
    float x_cur, y_cur;
    x_cur = 0;
    y_cur = b;
    // Region 1 
    float pk = pow(b, 2)+(1/4)*pow(a, 2)-pow(a, 2)*b;
    while(2*pow(b, 2)*x_cur >= 2*pow(a, 2)*y_cur)
    {
        putpixel(x_cur + x_c, y_cur + y_c, WHITE);
        putpixel(-x_cur + x_c, y_cur + y_c, WHITE);
        putpixel(x_cur + x_c, -y_cur + y_c, WHITE);
        putpixel(-x_cur + x_c, -y_cur + y_c, WHITE);
        if(pk < 0)
        {
            x_cur += 1;
            pk = pk + 2*pow(b, 2)*x_cur + pow(b, 2);
        }
        else
        {
            x_cur += 1;
            y_cur -= 1;
            pk = pk + 2*pow(b, 2)*x_cur - 2*pow(a, 2)*y_cur + pow(b, 2);
        }
    }
    // Region 2
    pk = pow(b, 2)*pow((x_cur + 0.5), 2) + pow(a, 2)*pow((y_cur-1), 2) - pow(a, 2)*pow(b, 2);
    while(y_cur >= 0)
    {
        putpixel(x_cur + x_c, y_cur + y_c, WHITE);
        putpixel(-x_cur + x_c, y_cur + y_c, WHITE);
        putpixel(x_cur + x_c, -y_cur + y_c, WHITE);
        putpixel(-x_cur + x_c, -y_cur + y_c, WHITE);
        if(pk < 0)
        {
            y_cur -= 1;
            pk = pk - 2*pow(a, 2)*y_cur + pow(a, 2);
        }
        else
        {
            x_cur += 1;
            y_cur -= 1;
            pk = pk + 2*pow(b, 2)*x_cur - 2*pow(a, 2)*y_cur + pow(a, 2);
        }    
    }
}

void drawellipse(int a, int b, int xc, int yc) 
{ 
    float dx, dy, d1, d2, x, y; 
    x = 0; 
    y = b; 
    d1 = (b * b) - (a * a * b) +  (0.25 * a * a); 
    dx = 2 * b * b * x; 
    dy = 2 * a * a * y; 
    while (dx < dy)  
    {
        putpixel(x + xc, y + yc, WHITE);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(x + xc, -y + yc, WHITE);
        putpixel(-x + xc, -y + yc, WHITE); 
        if (d1 < 0) 
        { 
            x++; 
            dx = dx + (2 * b * b); 
            d1 = d1 + dx + (b * b); 
        } 
        else 
        { 
            x++; 
            y--; 
            dx = dx + (2 * b * b); 
            dy = dy - (2 * a * a); 
            d1 = d1 + dx - dy + (b * b); 
        } 
    } 
    d2 = ((b * b) * ((x + 0.5) * (x + 0.5))) + ((a * a) * ((y - 1) * (y - 1))) - (a * a * b * b);
    while (y >= 0) 
    { 
        putpixel(x + xc, y + yc, WHITE);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(x + xc, -y + yc, WHITE);
        putpixel(-x + xc, -y + yc, WHITE);
        if (d2 > 0)  
        { 
            y--; 
            dy = dy - (2 * a * a); 
            d2 = d2 + (a * a) - dy; 
        } 
        else 
        { 
            y--; 
            x++; 
            dx = dx + (2 * b * b); 
            dy = dy - (2 * a * a); 
            d2 = d2 + dx - dy + (a * a); 
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
    int a, b;
    cout<<"Enter the a and b of ellipse: ";
    cin>>a>>b;
    cout<<"Enter the center of the ellipse : ";
    int x_c, y_c;
    cin>>x_c>>y_c;
    cout<<"Enter the width : ";
    int w;
    cin>>w;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    drawellipse(a, b, x_c, y_c);
    drawellipse(a+w, b+w, x_c, y_c);
    flood_fill(x_c+a+(w/2), y_c);
    delay(500000);
    closegraph();
    return 0;
}