#include <iostream>

using namespace std;

void printOutput(int **m, int i, int j)
{
    if(i==j)
        cout<<" A"<<i+1<<" ";
    else
    {
        cout<<"(";
        printOutput(m,i,m[j][i]);
        printOutput(m,m[j][i]+1,j);
        cout<<")";
    }
}

matrixChain(int *p, int num)
{
	int n=num, q;

    int **m = new int*[n];
	for(int i = 0; i < n; i++)
    	m[i] = new int[n];

    for(int i=0; i<n; i++)
        m[i][i]=0;

    for(int chain=1; chain<n; chain++)
    {
        for(int i=0, j=chain; i<(n-chain), j<n; i++, j++)
        {
            m[i][j]=99999;
            for(int k=i; k<j; k++)
            {
                q=m[i][k]+m[k+1][j]+(p[i]*p[k+1]*p[j+1]);
                if(q<m[i][j])
                {
                   m[i][j]=q;
                   m[j][i]=k;
                }
            }
        }
    }

    cout<<"\nMinimal Cost for matrix multiplication is "<<m[0][n-1];
    cout<<"\nOrder of Multiplication is ";
    printOutput(m,0,n-1);
    cout<<endl;
}

int main()
{
	int num, row, col, dcount=0;

	cout<<"Enter the number of matrices you want to multiply: ";
	cin>>num;

	int *p = new int[num+1];

	cout<<"Enter the dimensions of each matrix, in the order of multiplication\n";

	do
	{

		cout<<"No of rows of matrix 1: ";
		cin>>row;
		p[dcount++]=row;

		cout<<"No of columns of matrix 1: ";
		cin>>col;

		for(int i=1; i<num ; i++)
		{
			cout<<"No of rows of matrix "<<i+1<<": ";
			cin>>row;

			if(row==col)
				p[dcount++]=row;
			else
			{
				cout<<"Matrices cannot be multiplied.\nEnter dimensions again.\n";
				dcount=0;
				break;
			}
			cout<<"No of columns of matrix "<<i+1<<": ";
			cin>>col;
		}
	}while(dcount==0);
	p[dcount++]=col;

    matrixChain(p,num);
}
