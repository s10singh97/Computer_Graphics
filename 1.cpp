// Number of triangles possible from n points

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of points: ";
    cin>>n;
    if(n < 3)
    {
        cout<<"Number of points must be greater than 3!!\n";
        return 0;
    }
    int a[n][2];
    cout<<"Enter points\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            cin>>a[i][j];
    int count = 0;
    for(int i = 0; i < n-2; i++)
    {
        for(int j = i+1; j < n-1; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                float area = 0.5*(a[i][0]*(a[j][1] - a[k][1]) - a[j][0]*(a[i][1] - a[k][1]) + a[k][0]*(a[i][1] - a[j][1]));
                if(area != 0)
                    count++;
            }
        }
    }
    cout<<"No. of triangles possible are : "<<count<<"\n";
    return 0;
}