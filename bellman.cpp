#include<iostream>

using namespace std;

class Bellman
{
    int *dis;
    int *pi;
    int capacity;

    public:
    Bellman(int);
    void initialize(int);
    void bFord(int **);
};

Bellman::Bellman(int cap)
{
    capacity = cap;

    dis = new int[capacity];
    pi = new int[capacity];
}

void Bellman::initialize(int s)
{
    for(int i=0; i<capacity; i++)
    {
        dis[i]=9999;
        pi[i]=0;
    }
    dis[s]=0;
}

void Bellman::bFord(int **adj)
{
    int u, j, flag=0;

    for(int k=0; k<capacity; k++)
    {
        for(int i=0; i<capacity; i++)
        {
            for(int j=0; j<capacity; j++)
            {

                if(adj[i][j]!=0)
                {
                    if(dis[j] > dis[i]+adj[i][j])
                    {
                        dis[j] = dis[i]+adj[i][j];
                        pi[j] = i;
                    }
                }
            }
        }
    }

    for(int i=0; i<capacity; i++)
    {
        for(int j=0; j<capacity; j++)
        {
            if(adj[i][j]!=0)
            {
                if(dis[j] > dis[i]+adj[i][j])
                {
                        flag=1;
                        cout<<"\nNo solution exists.";
                }
            }
        }
    }

    if(flag==0)
    {
        cout<<"\nSolution is";
        for(int i=0; i<capacity; i++)
            cout<<"\nVertex "<<i+1<<", distance: "<<dis[i];
    }
}

int main()
{
    int v, e, src, dest, cost, strt;

    cout<<"Enter the no. of vertices in the graph: ";
    cin>>v;

    int **adj = new int*[v];
    for(int i=0; i<v; i++)
        adj[i]= new int[v];

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
            adj[i][j]=0;
    }

    cout<<"\nEnter the no. of edges in the graph: ";
    cin>>e;

    cout<<"\nEnter the edges with the cost of each edge\n";
    for(int i=0; i<e; i++)
    {
        cout<<"\nSource Vertex: ";
        cin>>src;
        cout<<"Destination Vertex: ";
        cin>>dest;
        cout<<"Cost: ";
        cin>>cost;
        adj[src-1][dest-1]=cost;
    }

    cout<<"\nAdjacency Matrix\n";
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }

    cout<<"\nEnter starting vertex: ";
    cin>>strt;

    Bellman b(v);
    b.initialize(strt-1);
    b.bFord(adj);

    return 0;
}
