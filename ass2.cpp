#include<iostream>
using namespace std;

class phonebook
{
    public : 
        long long phone[100];
        string name[100];
        int i,j,n;
        long long ele;
        string s;
        phonebook()
        {
            cout<<"\nHow many numbers you want to insert in phonebook : "<<endl;
            cin>>n;
            for (i=0;i<n;i++)
            {
                phone[i]=-1;
                
            }
            for (j=0;j<n;j++)
            {
                name[i]=-1;
            }
        }

        int hash(long long ele);
        void insert();
        void del();
        void search();
        void display();

};
int phonebook :: hash(long long ele)
{
    return ele%n;
}

void phonebook :: insert()
{
    cout<<"\nEnter the mobile number : ";
    cin>>ele;
    cout<<"\nEnter the name : ";
    cin>>s;
    int index=hash(ele);
    if (phone[index]==-1)
    {
        phone[index]=ele;
        name[index]=s;
    }
    else if (phone[index]!=-1)
    {
        int cnt=1;
        for (j=index+1;j<=n;j=(j+1)%n)
        {
            if (phone[j]==-1)
            {
                phone[j]=ele;
                name[j]=s;
                break;
            }
            else if (phone[j]!=-1)
            {
                cnt=cnt+1;
                if (cnt>=n)
                {
                    cout<<"\n----------------------------"<<endl;
                    cout<<"\nHash table is overflow "<<endl;
                    cout<<"----------------------------"<<endl;
                    break;
                }
            }
        }
    }

}

void phonebook::del()
{
    long long key;
    cout<<"\nEnter the number you want to delete from phonebook  : ";
    cin>>key;
    int index=hash(key);
    int cnt=1;
    if (phone[index]==key)
    {
        phone[index]=-1;
        name[index]=-1;
    }
    else if (phone[index]!=key)
    {
        for (j=index+1;j<=n;j=(j+1)%n)
        {
            if (phone[j]==key)
            {
                phone[j]=-1;
                name[j]=-1;
                break;
            }
            else if (phone[j]==-1)
            {
                cnt=cnt+1;
                if (cnt>=n)
                {
                    cout<<"\n----------------------------"<<endl;
                    cout<<"\nHash table is empty "<<endl;
                    cout<<"----------------------------"<<endl;
                    break;
                }
            }
        }
    }

}

void phonebook:: search()
{
    long long key;
    cout<<"\nEnter the number you want to search : ";
    cin>>key;
    int cnt=0;
    int index2=hash(key);
    int flag=0;
    if (phone[index2]==key)
    {
        flag=1;
    }
    else if (phone[index2]!=key)
    {
        for (j=index2+1;j<=n;j=(j+1)%n)
        {
            if (phone[j]==key)
            {
                flag=1;
                break;
            }
            else if (phone[j]==-1)
            {
                cnt=cnt+1;
                if (cnt>=n)
                {
                    cout<<"\n----------------------------"<<endl;
                    cout<<"\nHash table is empty "<<endl;
                    cout<<"----------------------------"<<endl;
                    break;
                }
            }
        }

    }
    
    if (flag=1)
    {
        cout<<"\nNumber if present at location "<<index2<<endl;
        cout<<"\nName : "<<name[index2];
    }
    else
    {
        cout<<"\nNot found "<<endl;
    }
}

void phonebook:: display()
{
    //cout<<"\nLocation \tMobile number \t\tName"
    for (i=0;i<n;i++)
    {
        cout<<i<<" : "<<phone[i]<<" : "<<name[i]<<endl;
    }
}
int main()
{
    phonebook p;
    int ch=0;
    while(ch<5)
    {
        cout<<"\n1.Insert the number \n2.Display \n3.Delete \n4.Search \n5.Exit"<<endl;
        cout<<"\nEnter the choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                p.insert();
                break;
            case 2:
                p.display();
                break;
            case 3:
                p.del();
                break;
            case 4:
                p.search();
                break;
        }
    }
}