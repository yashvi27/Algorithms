
#include <iostream>

using namespace std;

class Dijikstra
{
    int *dis;
    int *pi;
    int dsize;
    int capacity;

    public:
    Dijikstra(int);
    int extractMin();
    void initialize(int);
    void dijikstra(int **);
};

Dijikstra::Dijikstra(int cap)
{
    dsize = cap;
    capacity = cap;

    dis = new int[capacity];
    pi = new int[capacity];
}

void Dijikstra::initialize(int s)
{
    for(int i=0; i<capacity; i++)
    {
        dis[i]=9999;
        pi[i]=0;
    }
    dis[s]=0;
}

int Dijikstra::extractMin()
{
    int minIdx, min=999;
    for(int i=0; i<capacity; i++)
    {
        if(dis[i]<min)
        {
           min=dis[i];
           minIdx=i;
        }
    }
    dsize--;
    return minIdx;
}

void Dijikstra::dijikstra(int **adj)
{
    int u, j;
    int *p=new int[capacity];
    int vCount=0;

    while(dsize > 0)
    {
        u=extractMin();
        p[vCount++]=u+1;

        for(int i=0; i<capacity; i++)
        {

            if(adj[u][i]!=0)
            {
                if(dis[i] > dis[u]+adj[u][i])
                {
                    dis[i] = dis[u]+adj[u][i];
                    pi[i] = u;
                }
            }
        }
        dis[u]=9999;
    }

    cout<<"\nOptimal path of the graph is: ";
    {
        for(int i=0; i<capacity-1; i++)
            cout<<p[i]<<" --> ";
        cout<<p[capacity-1];
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

    Dijikstra d(v);
    d.initialize(strt-1);
    d.dijikstra(adj);

    return 0;
}
