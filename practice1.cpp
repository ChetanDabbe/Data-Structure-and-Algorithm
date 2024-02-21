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
            cout<<"\nHow many names you want to insert in phonebook : "<<endl;
            cin>>n;
            for (i=0;i<n;i++)
            {
                phone[i]=-1;
                
            }
            for (j=0;j<n;j++)
            {
                name[i]=" ";
            }
        }

        int hash(string);
        void insert();
        void del();
        void search();
        void display();

};
int phonebook :: hash(string s)
{
    int x=0;
    for (i=0;i<s.size();i++)
    {
        x=x+(int)s[i];
    }
    return x%n;
}

void phonebook :: insert()
{
    cout<<"\nEnter the name : ";
    cin>>s;
    cout<<"\nEnter the mobile number : ";
    cin>>ele;
    
    int index=hash(s);
    if (name[index]==" ")
    {
        name[index]=s;
        phone[index]=ele;
        
    }
    else if (name[index]!=" ")
    {
        int cnt=1;
        for (j=index+1;j<=n;j=(j+1)%n)
        {
            if (name[j]==" ")
            {
                name[j]=s;
                phone[j]=ele;
                
                break;
            }
            else if (name[j]!=" ")
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
    string key;
    cout<<"\nEnter the name you want to delete from phonebook  : ";
    cin>>key;
    int index=hash(key);
    int cnt=1;
    if (name[index]==key)
    {
        name[index]=-1;
        phone[index]=-1;
        
    }
    else if (name[index]!=key)
    {
        for (j=index+1;j<=n;j=(j+1)%n)
        {
            if (name[j]==key)
            {
                name[j]=-1;
                phone[j]=-1;
                
                break;
            }
            else if (name[j]==" ")
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
    string key;
    cout<<"\nEnter the number you want to search : ";
    cin>>key;
    int index2=hash(key);
    int flag=0;
    int cnt=1;
    if (name[index2]==key)
    {
        flag=1;
    }
    else if (name[index2]!=key)
    {
        for (j=index2+1;j<=n;j=(j+1)%n)
        {
            if (name[j]==key)
            {
                flag=1;
                break;
            }
            else if (name[j]==" ")
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
        cout<<i<<" : "<<name[i]<<" : "<<phone[i]<<endl;
    }
}
int main()
{
    phonebook p;
    int ch=0;
    while(ch<5)
    {
        cout<<"\n1.Insert the name \n2.Display \n3.Delete \n4.Search \n5.Exit"<<endl;
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