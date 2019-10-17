// Clipping algo 1 for a line

#include<bits/stdc++.h>
#include<string>
using namespace std;

int X_Min(vector<pair<int, int> >v)
{
    int m = INT_MAX;
    for(int i = 0; i < v.size(); i++)
        if(v[i].first < m)
            m = min(m, v[i].first);
    return m;
}

int X_Max(vector<pair<int, int> >v)
{
    int m = INT_MIN;
    for(int i = 0; i < v.size(); i++)
        if(v[i].first > m)
            m = max(m, v[i].first);
    return m;
}

int Y_Min(vector<pair<int, int> >v)
{
    int m = INT_MAX;
    for(int i = 0; i < v.size(); i++)
        if(v[i].second < m)
            m = min(m, v[i].second);
    return m;
}

int Y_Max(vector<pair<int, int> >v)
{
    int m = INT_MIN;
    for(int i = 0; i < v.size(); i++)
        if(v[i].second > m)
            m = max(m, v[i].second);
    return m;
}

string Dim(string res, int x_min, int x_max, int y_min, int y_max, int a, int b)
{
    if(a < x_max)
        res += "0";
    else
        res += "1";
    if(b < y_max)
        res += "0";
    else
        res += "1";
    if(b > y_min)
        res += "0";
    else
        res += "1";
    if(a < x_min)
        res += "1";
    else
        res += "0";
    return res;
}

int main()
{
    int a, b, c, d;
    cout<<"Enter starting point";
    cin>>a>>b;
    cout<<"Enter ending point";
    cin>>c>>d;
    vector<pair<int, int> >v;
    int k = 4;
    cout<<"Enter the coordinates of the rectangular window :\n";
    while(k--)
    {
        int m, n;
        cin>>m>>n;
        v.push_back(make_pair(m, n));
    }
    int x_min = X_Min(v);
    int x_max = X_Max(v);
    int y_min = Y_Min(v);
    int y_max = Y_Max(v);
    // cout<<x_min<<" "<<x_max<<" "<<y_min<<" "<<y_max<<"\n";
    
    string dim1 = Dim("", x_min, x_max, y_min, y_max, a, b);
    string dim2 = Dim("", x_min, x_max, y_min, y_max, c, d);
    
    bool accept = false;

    while(true)
    {
        if(dim1 == "0000" && dim2 == "0000")
        {
            accept = true;
            break;
        }
        else if(stoi(dim1) & stoi(dim2))
            break;
        else
        {
            float x, y;
            string out;
            if (stoi(dim1) != 0) 
                out = dim1; 
            else
                out = dim2;
            if(stoi(out) & 8)
            {
                x = a + (c - a) * (y_max - b) / (d - b); 
                y = y_max;
            }
            else if (stoi(out) & 4) 
            {
                x = a + (c - a) * (y_min - b) / (d - b); 
                y = y_min; 
            } 
            else if (stoi(out) & 2) 
            { 
                y = b + (d - b) * (x_max - a) / (c - a); 
                x = x_max; 
            } 
            else if (stoi(out) & 1) 
            {
                y = b + (d - b) * (x_min - a) / (c - a); 
                x = x_min; 
            }

            if(out == dim1)
            {
                a = x;
                b = y;
                dim1 = Dim("", x_min, x_max, y_min, y_max, a, b);
            }
            else
            {
                c = x;
                d = y;
                dim2 = Dim("", x_min, x_max, y_min, y_max, c, d);
            }   
        }  
    }

    if(accept)
        cout<<a<<" "<<b<<"\n"<<c<<" "<<d;
    else
        cout<<"Line is outside the window\n";
    

    // float a_f, b_f, c_f, d_f;
    // if(dim1 == "0000" && dim2 == "0000")
    // {
    //     a_f = a;    c_f = c;
    //     b_f = b;    d_f = d;
    // }
    // else if(dim1 != "0000" && dim2 != "0000")
    // {
    //     cout<<"Line is completely outside\n";
    // }
    // else
    // {
    //     float m = (float)(d-b)/(c-a);
    //     if(dim1 == "0000")
    //     {
    //         a_f = a, b_f = b;
    //         if(dim2 == "0101")
    //         {
    //             c_f = x_min;
    //             d_f = b + m*(x_min - a);
    //         }
    //         if(dim2 == "0100")
    //         {
    //             d_f = y_max;
    //             c_f = ((float)(y_max-b)/m) + a;
    //         }
    //         if(dim2 == "1100")
    //         {

    //         }
    //     }
    
    // }
    

    return 0;
}