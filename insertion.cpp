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
        int temp=arr[j];
        int k=j-1;
        for (;k>=0;k--)
        {
            if (arr[k]>temp)
            {
                arr[k+1]=arr[k];
            }
            else{
                break;
            }
        }
        arr[k+1]=temp;
    }

    for(int l=0;l<n;l++)
    {
        cout<<endl<<arr[l];
    }
}