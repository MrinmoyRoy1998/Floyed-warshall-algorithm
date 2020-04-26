#include <bits/stdc++.h>
#define inf 999999
#define neg -1

using namespace std;

void printfun(int source, int des, vector< vector<int> >path)
{
    if(path[source][des]==-1)
    {
        cout<<"No path found."<<endl;
        return;
    }

    if(path[source][des]==source)
        cout<<source<<" ";

    if(path[source][des]!=source)
    {
        printfun(source,path[source][des],path);
        cout<<path[source][des]<<" ";
    }


}

int main()
{
    int node, edge;
    cout<<"How many nodes: ";
    cin>>node;
    cout<< "How many edges: ";
    cin>>edge;

    vector< vector<int> >distance(node,vector<int>(node));

    vector< vector<int> >path(node,vector<int>(node));

    for(int i=0; i<node; i++)
        for(int j=0; j<node; j++)
            distance[i][j]=inf;

    for(int i=0; i<node; i++)
        for(int j=0; j<node; j++)
            path[i][j]=neg;

    for(int i=0; i<node; i++)
        for(int j=0; j<node; j++)
            if(i==j)
            {
                distance[i][j]=0;
                path[i][j]=i;
            }

    cout<<"Edge information (u,v,w)"<<endl;
    for(int i=0; i<edge; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        distance[u][v]=w;
        path[u][v]=u;
    }

    for(int k=0; k<node; k++)
        for(int i=0; i<node; i++)
            for(int j=0; j<node; j++)
                if(distance[i][j]>distance[i][k]+distance[k][j])
                {
                    distance[i][j]=distance[i][k]+distance[k][j];
                    path[i][j]=k;
                }

    cout<<"distance matrix:"<<endl;
    for(int i=0; i<node; i++)
    {
        for(int j=0; j<node; j++)
        {
            cout<<distance[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"path matrix:"<<endl;
    for(int i=0; i<node; i++)
    {
        for(int j=0; j<node; j++)
        {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Source vertex: ";
    int source, des;
    cin>>source;
    cout<< "Destination vertex: ";
    cin>>des;

    cout<<"distance between "<<source<<" and "<<des<<" is : "<<distance[source][des]<<endl;
    cout<<"Path : ";
    printfun(source, des, path);
    cout<<des<<endl;


    for(int i=0; i<node; i++)
    {
        for(int j=0; j<node; j++)
        {
            if(distance[i][j]<0 && i==j)
            {
                cout<<"the graph has negative cycle"<<endl;
                return 0;
            }
            else
            {
                cout<<"This Graph does not contain any negative cycle"<<endl;
                return 0;
            }

        }
    }

}



