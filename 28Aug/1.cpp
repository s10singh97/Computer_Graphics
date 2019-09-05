// Circle

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int m_SIZE[] = {500, 500};
int m_ORIGIN[] = {m_SIZE[0]/2, m_SIZE[1]/2};

int main()
{
    int r;
    cout<<"Enter the radius : ";
    cin>>r;
    int x1, y1;
    cout<<"Enter center of the circle : ";
    cin>>x1>>y1;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    //First Pint
    int x=0,y=r;
    putpixel(x+x1,y+y1,WHITE);
    int p = 1-r;
    while(x<=y)
    {
        if(p<0)
        {
           x++;
       

            putpixel(x + x1 ,-y + y1,WHITE);
            putpixel(y + x1 ,x + y1,WHITE);
            putpixel(-y + x1 ,x + y1,WHITE);

            putpixel(x + x1,y + y1,WHITE);
            putpixel(-x + x1,y + y1,WHITE);
            putpixel(x + x1,-y + y1,WHITE);
            putpixel(-x + x1,-y + y1,WHITE);

            putpixel(y + x1, x + y1,WHITE);
            putpixel(-y + x1, x + y1,WHITE);
            putpixel(y + x1, -x + y1,WHITE);
            putpixel(-y + x1, -x + y1,WHITE);

           
           p=p+2*x+1;
        }
        else
        {
            x++;
            y--;

            putpixel(x + x1 ,-y + y1,WHITE);
            putpixel(y + x1 ,x + y1,WHITE);
            putpixel(-y + x1 ,x + y1,WHITE);

            putpixel(x + x1,y + y1,WHITE);
            putpixel(-x + x1,y + y1,WHITE);
            putpixel(x + x1,-y + y1,WHITE);
            putpixel(-x + x1,-y + y1,WHITE);

            putpixel(y + x1, x + y1,WHITE);
            putpixel(-y + x1, x + y1,WHITE);
            putpixel(y + x1, -x + y1,WHITE);
            putpixel(-y + x1, -x + y1,WHITE);

        
            p=p+2*x+1-2*y;
        }
    }

    delay(500000);
    closegraph();
    return 0;
}