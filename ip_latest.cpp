/*Take an Ip address as an input from user and do the following operations
1. Identify whether it is valid or invalid address
2. Identify class of address
3. Identify and display subnet mask
*/

#include <iostream>
#include <string.h>
#include<math.h>
using namespace std;

class IP_address
{
    string ip;
    int ip_len;
    string a;

public:
    void accept();
    void display();
    int validity();
    void class_check();
};
void IP_address ::accept()
{
    int ch=0;
    int digit=0;
    int l=0;
    while (ch<3)
    {
        cout<<"\n******************************";
        cout<<"\n1.Binary number \n2.Decimal number \n3.Exit";
        cout<<"\n******************************";
        cout<<"\nEnter the choice : ";
        cin>>ch;
        if (ch==1)
        {
            ip="";
            cout << "\nEnter the IP address : ";
            cin >> ip;
            ip_len = ip.size();
            cout<<"\nSize : "<<ip_len;
            for (int k=ip_len;k>=0;k--)
            {
                if (ip[k]=='.')
                {
                    continue;
                }
                if (ip[k]==1)
                {
                    int digit=digit+pow(2,l);
                }
                l++;
            }   
            cout<<"\nAfter conversion : "<<digit;     
        }
        else if (ch==2)
        {
            ip="";
            cout << "\nEnter the IP address : ";
            cin >> ip;
            ip_len = ip.size();
        }
        else{
            break;
        }
        ch++;
    }
    
}
int IP_address ::validity()
{
    //accept();
    int i = 0;
    cout<<"\nTotal ip size : "<<ip_len;
    int dot_count = 0;
    for (int j = 0; j < ip_len; j++)
    {
        if (ip[j] == '.')
        {
            dot_count += 1;
        }
    }
    
    int flag=0;
    if (ip[0]!='.')
    {
    while (i<ip_len)
    {
        if  (ip[i]!='.')
        {
            a+=ip[i];
        }
        else if (ip[i]=='.')
        {
            if (stoi(a) <= 255 && stoi(a) >= 0 && dot_count==3)
            {
                flag++;
                a="";
            }
            else{
                cout<<"\nInvalid ";
                return 0;
                break;
            }
           
        }
        if (i==ip_len-1)
        {
            if (stoi(a) <= 255 && stoi(a) >= 0 && dot_count==3)
            {
                flag++;
                a="";
            }
            else{
                cout<<"\nInvalid ";
                return 0;
                break;
                
            }
            
        }
        if (flag==4)
        {
            cout<<"\nValid ";
            return 1;
            break;  
        }
        i++;
    }
    }
    else
    {
        cout<<"\nInvalid ";
        return 0;
    }
}

void IP_address :: class_check()
{
    int j=0;
    string b;
    int val=validity();
    cout<<"\nValue of validity : "<<val;
    if (val==1)
    {
        while(j<ip_len){
            //cout<<"\nHI";
            if (ip[j]!='.')
            {
                b+=ip[j];
            }
            else{
                break;
            }
            j++;
        }
        if (stoi(b)>=0 && stoi(b)<=127)
        {
            cout<<"\nClass A";
            cout<<"\nSubnet mask : 255.0.0.0";
        }
        else if (stoi(b)>=128 && stoi(b)<=191)
        {
            cout<<"\nClass B";
            cout<<"\nSubnet mask : 255.255.0.0";
        }
        else if (stoi(b)>=192 && stoi(b)<=223)
        {
            cout<<"\nClass C";
            cout<<"\nSubnet mask : 255.255.255.0";
        }
        else if (stoi(b)>=224 && stoi(b)<=239)
        {
            cout<<"\nClass D";
            cout<<"\nSubnet mask : 255.255.255.255";
        }    
        else if(stoi(b)>=240 && stoi(b)<=255)
        {
            cout<<"\nClass E";
        }
    }
    else{
        cout<<"\nDue to invalid IP address there is no class";
    }
}
void IP_address::display()
{
    cout << "\nIP address : " << ip;
}

int main()
{
    IP_address obj;
    obj.accept();
    //obj.validity();
    obj.display();
    
    obj.class_check();
}