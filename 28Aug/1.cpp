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
    int p = int((float(5)/4) - r);
    int x_curr = 0, y_curr = r;
    putpixel(x_curr, y_curr, WHITE);
    while(x_curr != y_curr)
    {
        if(p < 0)
        {
            x_curr += 1;
            p = p + (2*x_curr) + 1;
            putpixel(x_curr + x1, -y_curr + y1, WHITE);
            putpixel(y_curr + x1, x_curr + y1, WHITE);
            putpixel(-y_curr + x1, x_curr + y1, WHITE);

            putpixel(x_curr + x1, y_curr + y1, WHITE);
            putpixel(-x_curr + x1, y_curr + y1, WHITE);
            putpixel(x_curr + x1, -y_curr + y1, WHITE);
            putpixel(-x_curr + x1, -y_curr + y1, WHITE);

            putpixel(y_curr + x1, x_curr + y1, WHITE);
            putpixel(-y_curr + x1, x_curr + y1, WHITE);
            putpixel(y_curr + x1, -x_curr + y1, WHITE);
            putpixel(-y_curr + x1, -x_curr + y1, WHITE);
            
            
            // putpixel(x_curr, y_curr, WHITE);
            // putpixel(y_curr, x_curr, WHITE);
            // putpixel(x_curr, -y_curr, WHITE);
            // putpixel(-x_curr, y_curr, WHITE);
        }
        else
        {
            x_curr += 1;
            y_curr -= 1;
            p = p + (2*x_curr) + 1 - (2*y_curr);
            putpixel(x_curr + x1, -y_curr + y1, WHITE);
            putpixel(y_curr + x1, x_curr + y1, WHITE);
            putpixel(-y_curr + x1, x_curr + y1, WHITE);

            putpixel(x_curr + x1, y_curr + y1, WHITE);
            putpixel(-x_curr + x1, y_curr + y1, WHITE);
            putpixel(x_curr + x1, -y_curr + y1, WHITE);
            putpixel(-x_curr + x1, -y_curr + y1, WHITE);

            putpixel(y_curr + x1, x_curr + y1, WHITE);
            putpixel(-y_curr + x1, x_curr + y1, WHITE);
            putpixel(y_curr + x1, -x_curr + y1, WHITE);
            putpixel(-y_curr + x1, -x_curr + y1, WHITE);
            
            // putpixel(x_curr, y_curr, WHITE);
            // putpixel(y_curr, x_curr, WHITE);
            // putpixel(x_curr, -y_curr, WHITE);
            // putpixel(-x_curr, y_curr, WHITE);
        }
    }

    delay(500000);
    closegraph();
    return 0;
}