#include<iostream>
using namespace std;

void toLowerCase()
{
    char ch;
    cout<<"\nEnter the character : ";
    cin>>ch;
    if (ch>='a' && ch<='z')
    {
        cout<<"\nLower Case : "<<ch;
    }
    else
    {
        char temp=ch-'A'+'a';
        cout<<"\nTemp : "<<temp;
    }
}
void toUpperCase()
{
    char ch;
    cout<<"\nEnter the character : ";
    cin>>ch;
    if (ch>='A' && ch<='Z')
    {
        cout<<"\nCharacter : "<<ch;
    }
    else 
    {
        char temp;
        temp=ch-'a'+'A';
        cout<<"\nTemp : "<<temp;
    }
}
int main()
{
    toLowerCase();
    toUpperCase();
}