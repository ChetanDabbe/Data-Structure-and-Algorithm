#include<iostream>
#include<queue>
using namespace std;

queue<int>q;

class graph
{
    int n;
    int visited[10];
    string vertices[10];
    int arr[10][10];
    public:
        graph()
        {
            cout<<"\nEnter the total number of vertices : ";
            cin>>n;
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<n;j++)
                {
                    arr[i][j]=0;
                }
            }
        }
        void initvisited()
        {
            for (int i=0;i<n;i++)
            {
                visited[i]=0;
            }
        }
        void accept();
        void path();
        void display();
        void dfs(int);
        void bfs(int);
};

void graph:: accept()
{
    for (int i=0;i<n;i++)
    {
       cout<<"\nEnter the label for vertex "<<i+1<<" : ";
       cin>>vertices[i];

    }
}

void graph :: path()
{
    string v1,v2;
    int pos1=-1,pos2=-1;
    cout<<"\nEnter the vertex 1 : ";
    cin>>v1;
    cout<<"\nEnter the vertex 2 : ";
    cin>>v2;
    for (int i=0;i<n;i++)
    {
        if (vertices[i]==v1)
        {
            pos1=i;
        }
        if (vertices[i]==v2)
        {
            pos2=i;
        }
    }
    if (pos1 !=-1 && pos2!=-1)
    {
        arr[pos1][pos2]=1;
        arr[pos2][pos1]=1;
    }
    else
    {
        cout<<"\nIncorrect choice ";
    }
}

void graph :: display()
{
    for (int i=0;i<n;i++)
    {
        cout<<"\t"<<vertices[i];
    }
    cout<<"\n";
    for (int i=0;i<n;i++)
    {
        cout<<vertices[i]<<"\t";
        for (int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
void graph :: dfs(int i)
{
    visited[i]=1;
    cout<<vertices[i]<<"   ";
    for (int k=0;k<n;k++)
    {
        if (arr[i][k]==1 && visited[k]==0)
        {
            dfs(k);
        }
    }
}

void graph:: bfs(int s)
{
    q.push(s);
    visited[s]=1;
    while(!q.empty())
    {
        int v=q.front();
        cout<<vertices[v]<<"  ";
        q.pop();
        for (int k=0;k<n;k++)
        {
            if (arr[v][k]==1 && visited[k]==0)
            {
                q.push(k);
                visited[k]=1;
            }
        }
    }
}
int main()
{
    graph obj;
    int ch=0;
    int a;
    while(ch<6)
    {
        cout<<"\n1.Enter name for vertices \n2.Connect the vertices \n3.Display \n4.DFS \n5.BFS \n6.Exit";
        cout<<"\nEnter the choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                obj.accept();
                break;
            case 2:
                obj.path();
                break;
            case 3:
                obj.display();
                break;
            case 4:
                cout<<"\nEnter the starting vertex : ";
                cin>>a;
                obj.initvisited();
                obj.dfs(a);
                break;
            case 5:
                cout<<"\nEnter the starting vertex : ";
                cin>>a;
                obj.initvisited();
                obj.bfs(a);
                break;
        }
    }
}