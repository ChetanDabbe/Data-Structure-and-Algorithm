#include<iostream>
using namespace std;

class hashing
{
    int arr[20];
    int n,i,ele;
    public:
        hashing()
        {
            cout<<"\nEnter the number of element you want to insert in hash table : ";
            cin>>n;
            for (i=0;i<n;i++)
            {
                arr[i]=-1;
            }
        }
        void insert();
        int hash(int);
        void display();
        void del();
        void search();
};

int hashing::hash(int ele)
{
    return ele%n;
}

void hashing:: insert()
{
    cout<<"\nEnter the element to insert : ";
    cin>>ele;
    int index=hash(ele);
    if (arr[index]==-1)
    {
        arr[index]=ele;
    }
    else if (arr[index]!=-1)
    {
        for (int j=index+1;j<=n;j=(j+1)%n)
        {
            if (arr[j]==-1)
            {
                arr[j]=ele;
                break;
            }

        }
    }
    else
    {
        for (int j=0;j<=n;j++)
        {
            if (arr[j]!=-1)
            {
                cout<<"\nHash table is overflow"<<endl;
                break;
            }
        }
    }
}

void hashing :: del()
{
    int key;
    cout<<"\nEnter the key to be deleted : ";
    cin>>key;
    int index=hash(key);
    if (arr[index]==key)
    {
        arr[index]=-1;
    }
    else if (arr[index]!=key)
    {
        for (int j=index+1;j<=n;j=(j+1)%n)
        {
            if (arr[j]==key)
            {
                arr[j]=-1;
                break;
            }
        }
    }

}

void hashing:: search()
{
    int key;
    cout<<"\nEnter the key to be searched : ";
    cin>>key;
    int flag=0;
    int index=hash(key);
    if (arr[index]==key)
    {
        flag=1;
    }
    else if (arr[index]!=key)
    {
        for (int j=index+1;j<=n;j=(j+1)%n)
        {
            if (arr[j]==key)
            {
                flag=1;
                break;
            }
        }
    }
    if (flag=1)
    {
        cout<<"\nElement is present in hash table "<<endl;
    }
    else
    {
        cout<<"\nElement is not present in hash table "<<endl;
    }
}

void hashing:: display()
{
    for (i=0;i<n;i++)
    {
        cout<<i<<" : "<<arr[i]<<endl;
    }
}
int main()
{
    hashing h;
    int ch=0;
    while(ch<5)
    {
        cout<<"\n1.Insert the element \n2.Display \n3.Delete \n4.Search \n5.Exit"<<endl;
        cout<<"\nEnter the choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                h.insert();
                break;
            case 2:
                h.display();
                break;
            case 3:
                h.del();
                break;
            case 4:
                h.search();
                break;
            default:
                cout<<"\nPlease enter correct choice "<<endl;
                break;
        }
    }
    // // return 0;
}