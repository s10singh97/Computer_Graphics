// Sorting through frequency

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first < b.first)
        return true;
    if(a.first == b.first && a.second < b.second)
        return true;
    return false;
}

int main()
{
    int n;
    cout<<"Enter number of elements to be sorted : ";
    cin>>n;
    int a[n];
    int hash[100] = {0};
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        hash[a[i]]++;
    }
    vector<pair<int, int> > v1;
    for(int i = 0; i < 100; i++)
        if(hash[i] > 0)
            v1.push_back(make_pair(hash[i], i));
    sort(v1.begin(), v1.end(), cmp);
    for(int i = 0; i < v1.size(); i++)
    {
        int t = v1[i].first;
        while(t--)
            cout<<v1[i].second<<" ";
    }
    cout<<"\n";
    return 0;
}