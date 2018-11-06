#include<iostream>
using namespace std;

#define N 8

int board[N][N];
int colcheck[N];
int d1check[N+3];
int d2check[N+3];

void print()
{
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int row, int col)
{
    if(colcheck[col]!=0) return false;
    if (d1check[row+col]!=0)  return false;
    if(d2check[row-col+N-1]!=0)return false;
    return true;
}


void solve(int r)
{
    if(r==N)
   {    print();
        return ;
   }

    for(int c=0;c<N;c++)
    {
        if(isSafe(r,c))
            { board[r][c]= 1;

              colcheck[c]=1;
              d1check[r+c]=1;
              d2check[r-c+N-1]=1;

              solve(r+1);

              board[r][c]=0;
              colcheck[c]=0;
              d1check[r+c]=0;
              d2check[r-c+N-1]=0;

            }

    }
}

int main()
{
    cout<<"NQueen's Problem";
    cout<<"\nValue of n is "<<N<<endl;
    cout<<"All possible solutions are \n";
    solve(0);
}


