// N queen Problem
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **chess, int row, int col, int n)
{
    for(int i = 0; i < col; i++)
        if(chess[row][i])
            return false;
    for(int i = row,j = col; i >=0 && j >= 0; i--, j--)
        if(chess[i][j])
            return false;
    for(int i = row, j = col; j>=0 && i < n; i++, j--)
        if(chess[i][j])
            return false;

    return true;
}

bool NQ(int **chess, int col, int n)
{
    if(col >= n)
        return true;
    for(int i = 0; i < n; i++)
    {
        if(isSafe(chess, i, col, n))
        {
            chess[i][col] = 1;
            if(NQ(chess, col+1, n))
                return true;
            chess[i][col] = 0;
        }
    }
    return false;
}

void display(int **chess, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<chess[i][j]<<"\t";
        cout<<"\n";
    }
}

int main()
{
    cout<<"Enter number of queens to be placed in NxN matrix :";
    int n;
    cin>>n;
    int ** chess = new int*[n];
    for(int i = 0; i < n; i++)
        chess[i] = new int[n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            chess[i][j] = 0;
    
    if (NQ(chess, 0, n) == false) 
    { 
        cout<<"Solution does not exist\n"; 
        return false; 
    }
    display(chess, n); 
    return 0;
}