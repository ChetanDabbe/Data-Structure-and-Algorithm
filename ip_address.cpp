#include<iostream>
using namespace std;

class IP_address
{
    string ip;

    public:
        void accept();
        void check_validity();
        void check_class();
        void subnet();
        void display();
};

void IP_address :: accept()
{
    cout<<"\nEnter the IP address : ";
    cin>>ip;
}
//192.11.211.22

void IP_address :: check_validity()
{
    string a;
    int i=0;
    int cnt=0;
    int cnt1=0;
    int size=ip.length();
    cout<<"\nSize of IP address : "<<size;
    while(i<size)
    {
        if (ip[i]=='.')
        {
            cnt++;
        }
        i++;
    }
    cout<<"\nCount : "<<cnt;
    int j=0;
    while(i<size)
    {
        while (ip[j]!='.')
        {
            if (ip[j]=='.')
            {
                a="NULL";
            }
            else{
                a+=ip[j];
            }
            j++;
        }
        if (a>="0" && a<="255"  && a.length()<4)
        {
           cnt1++;
           cout<<"\nCount 1 : "<<cnt1;
        }
        i++;
    }
    if (cnt==3 && cnt1==4)
    {
        cout<<"\nvalid ";
    }
    else{
        cout<<"\nInvalid ";
    }
    // int j=0;
    // int cnt1=0;
    // int flag=0;
    // while (i<size)
    // {
    //     if (ip[i]=='.')
    //     {
    //         cnt++;
    //     }
    //     else 
    //     {
    //         // while(ip[j]!='.')
    //         // {
    //             a+=ip[j];
                
    //             // if (ip[j]=='.')
    //             // {
    //             //     if (a>="0" && a<="255" && cnt==3 && a.length()<4)
    //             //     {
    //             //         cnt1++;
    //             //     }
    //             // }
    //             // j++;
    //         // }
    //         // cout<<"\nValue of J : "<<j<<endl;
    //        // cout<<"\nString : "<<a;
    //         //cout<<"\nCOunt 1 : "<<cnt;
    //         if (a>="0" && a<="255"  && a.length()<4)
    //         {
    //             cnt1++;
            
    //         }
    //         // i=j;
    //     }
    //     i++;
    // }

    // label:    if (cnt==3 && flag==1)
    //     {
    //         cout<<"\nvalid IP address ";
    //     }
    //     else{
    //         cout<<"\nInvalid IP address ";
    //     }


    // if (a>="0" && a<="255" && cnt==3 && a.length()<4)
    // {
    //     cout<<"\nValid IP address ";
    //     cout<<"\nAfter the ip address : "<<a;
    // }
    // else
    // {
    //     cout<<"\nInvalid IP address ";
    // }
    
}

void IP_address :: display()
{
    cout<<"\nIP address : "<<ip;
}

int main()
{
    IP_address obj;
    obj.accept();
    obj.display();
    obj.check_validity();
}