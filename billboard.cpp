#include<iostream>
#include<math.h>

using namespace std;

void printRes(int *mr, int *x, int m, int n)
{
    int *res=new int[n];
    int cnt=0;

    for(int i=m; i>=0; i--)
    {
        if(mr[i]!=mr[i-1])
        {
           res[cnt++]=i;
           i=i-5;
        }
    }

    cout<<"\n\nBillboards should be placed at positions: ";
    for(int i=cnt-2; i>0; i--)
        cout<<res[i]<<", ";
    cout<<res[0]<<endl;
}

void buildBillBoard(int *mr, int *x, int *r, int m, int n)
{
    int next=0;
    for(int i=1; i<=m; i++)
    {
        if(x[next]==i)
        {
            mr[i]=max(mr[i-1], mr[i-6]+r[next]);
            next++;
        }
        else
            mr[i]=mr[i-1];
    }

    cout<<"\n\nMiles array looks like\n";
    for(int i=0; i<=m; i++)
        cout<<mr[i]<<"  ";

    cout<<"\n\nOptimal Solution is "<<mr[m];

    printRes(mr, x, m, n);   //print the result, from array mr
}

int main()
{
    int m, n, flag;

    cout<<"Enter the length of the road(in miles): ";
    cin>>m;

    int *mr = new int[m+1];
    for(int i=0; i<=m; i++)
        mr[i]=0;

    cout<<"\nEnter the number of available billboards: ";
    cin>>n;

    int *x = new int[n];
    int *r = new int[n];

    do
    {
        flag=0;
        cout<<"\nEnter the position of each billboard and the revenue associated with it.\n";
        for(int i=0; i<n; i++)
        {
            cout<<"\nPosition: ";
            cin>>x[i];
            if(x[i]<x[i-1] && i>0)
            {
               cout<<"\nWrong Input. Enter again.";   //input to be entered in sorted order only
               flag=1;
               break;
            }

            cout<<"Revenue: ";
            cin>>r[i];
        }
    }while(flag==1);

    cout<<"\nPosition:\t";
    for(int i=0; i<n; i++)
    {
        cout<<x[i]<<"\t";
    }

    cout<<"\nRevenue:\t";
    for(int i=0; i<n; i++)
    {
        cout<<r[i]<<"\t";
    }

    buildBillBoard(mr, x, r, m, n);  //function to find the optimal solution

    return 0;
}
