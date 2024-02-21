#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter the number : ";
    cin>>n;
    int ans=0;
    int i=0;
    while(n!=0)
    {
        int bit=n & 1;
        cout<<"\nBit : "<<bit;
        ans=(bit* pow(10,i))+ans;
        
        n=n>>1;
        i=i+1;
    }
    cout<<"\nAnswer : "<<ans;


    cout<<"\nBinary to decimal"<<endl;
    int n1;
    cout<<"\nEnter the binary number : ";
    cin>>n1;
    int ans1=0;
    int i1=0;
    while (n1!=0)
    {
        int digit=n1%10;
        if (digit==1)
        {
            ans1+=pow(2,i1);
        }
        n1=n1/10;
        i1++;
    }
    cout<<"\nDecimal number : "<<ans1;

}