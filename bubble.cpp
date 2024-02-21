#include<iostream>
using namespace std;
int main()
{
    int n;
    int arr[10];
    cout<<"\nSize : ";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for (int j=1;j<n;j++)
    {
        for (int k=0;k<n-j;k++)
        {
            if (arr[k]>arr[k+1])
            {
                int temp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=temp;
            }
        }
    }
    for (int l=0;l<n;l++)
    {
        cout<<arr[l];
    }
}