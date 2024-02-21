#include<iostream>
using namespace std;

class phonebook
{
    public : 
        long long phone[100];
        char name[100];
        int i,j,n;
        long long ele;
        char s[10];
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

        int hash(char []);
        void insert();
        void del();
        void search();
        void display();

};
int phonebook :: hash(char s[])
{
    int sum=0;
    for (i=0;s[i]!='\0';i++)
    {
        sum=sum+s[i];
    }
   // cout<<"\nSum of ascii of each character : "<<sum;
    int a;
    a=sum%n;
    return a;
}

void phonebook :: insert()
{
    cout<<"\nEnter the name : ";
    gets(s);
    cout<<"\nEnter the mobile number : ";
    cin>>ele;
    
    int index;
    index=hash(s);
    if (name[index]==NULL)
    {
        name[index]=s;
        phone[index]=ele;
        
    }
    else if (name[index]!=-1)
    {
        int cnt=1;
        for (j=index+1;j<=n;j=(j+1)%n)
        {
            if (name[j]==NULL)
            {
                name[j]=s;
                phone[j]=ele;
                
                break;
            }
            else if (name[j]!=NULL)
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
    char key[10];
    cout<<"\nEnter the name you want to delete from phonebook  : ";
    cin>>key;
    int index=hash(key);
    if (name[index]==key)
    {
        phone[index]=-1;
        name[index]=NULL;
    }
    else if (name[index]!=key)
    {
        for (j=index+1;j<=n;j=(j+1)%n)
        {
            if (name[j]==key)
            {
                name[j]=NULL;
                phone[j]=-1;
                
                break;
            }
        }
    }
}

void phonebook:: search()
{
    char key[10];
    cout<<"\nEnter the name you want to search : ";
    cin>>key;
    int index2=hash(key);
    int flag=0;
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
        }

    }
    
    if (flag=1)
    {
        cout<<"\nNumber if present at location "<<index2<<endl;
        cout<<"\nMobile number : "<<phone[index2];
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