#include <iostream>
#include<fstream>
using namespace std;

class graph
{
public:
    int arr[10][10];
    int visited[10];
    string position[10];
    int n;
    graph()
    {
        cout << "\nEnter the number of vertices you want : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = 0;
            }
        }

        // cout<<"College campus"<<endl;
        position[0] = "Main Gate";
        position[1] = "Entrance";
        position[2] = "Engineering";
        position[3] = "Workshop";
        position[4] = "Pharmacy";
        position[5] = "Polytechnique";
        position[6] = "Gym-khana";
        position[7] = "Cantene";
    }
    void read();
    void read_file();
    void display();
    void is_available();
    void initvisited();
    void dfs(int);
};
void graph ::read()
{
    int v1, v2;
    char ch;
    cout << "\nDo you want to add the end vertices of edges(Y/N) : ";
    cin >> ch;
    while (ch == 'Y')
    {
        cout << "\nEnter the end vertex1 of edge : ";
        cin >> v1;
        cout << "\nEnter the end vertex2 of edge : ";
        cin >> v2;
        arr[v1][v2] = 1;
        cout << "\nDo you want to add more the end vertices of edges(Y/N) : ";
        cin >> ch;
    }
}

void graph :: read_file()
{
    ifstream in("graph.txt");
    cout<<"\nEnter the number of vertices : ";
    in>>n;
    int v1,v2,wt;
    for (int i=0;i<8;i++)
    {
        cout<<"\nEnter the end vertices of edge : ";
        in>>v1>>v2;
        cout<<"\nEnter weight : ";
        in>>wt;
        arr[v1][v2]=wt;
        arr[v2][v1]=wt;
    }
}
void graph ::display()
{
    // int ch = 1;
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "\t" << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
void graph ::is_available()
{
    int v1, v2;
    cout << "\nEnter the end vertices you want to check : ";
    cin >> v1 >> v2;
    if (arr[v1][v2] == 1)
    {
        cout << "\nEdge exists";
    }
    else
    {
        cout << "\nEdge not exists";
    }
}

void graph:: initvisited()
{

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
}
void graph ::dfs(int i)
{
    int j;
    visited[i] = 1;

    cout << position[i] << "   ";
    for (int k = 1; k <= n; k++)
    {
        if (arr[i, k] && !visited[k])
        {
            dfs(k);
        }
    }
}
int main()
{
    graph g;


    int ch=0;
    while (ch<6)
    {
        cout<<"\n1.Read the graph \n2.Read the graph file(n=8) \n3.Display \n4.Availability of edge \n5.DFS \n6.Exit"<<endl;
        cout<<"Enter the choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                g.read();
                break;
            case 2:
                g.read_file();
                break;
            case 3:
                g.display();
                break;
            case 4:
                g.is_available();
                break;
            case 5:
                g.dfs(0);
                break;
        }
    }
}