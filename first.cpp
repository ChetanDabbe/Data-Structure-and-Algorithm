#include<iostream>
using namespace std;

class Page{
    int arr[10];
    int arr2[10];
    int size;
    int n;
    public:
        Page()
        {
            cout<<"\nEnter the number of reference element you want to inesrt : ";
            cin>>n;
        }
        void accept();
        void first();
        void display();
        void display2();
};

void Page::accept()
{
    for (int i=0;i<n;i++)
    {
        cout<<"\nEnter the number "<<i+1<<" : ";
        cin>>arr[i];
    }
}

void Page :: first()
{
    
    cout<<"\nEnter the page size : ";
    cin>>size;
    for (int j=0;j<size ;j++)
    {
        arr2[j]=-2;
    }
    int k=0;
    while(k<n)
    {
        for (int l=0;l<size;l++)
        {
            if (arr2[l]==-2)
            {
                arr2[l]=arr[k];
                break;
            }
            else if (arr2[l]!=-2)
            {
                if (arr2[l]==arr[k])
                {
                    arr2[l]=arr[k];
                    cout<<"\nHit ";
                }
                else
                {
                    arr2[l]=arr[k];
                    cout<<"\nMiss";
                }
            }
        }
        cout<<"\nTable "<<k+1<<" : "<<endl;
        display2();
        k++;
    }


}
void Page :: display2()
{
    for (int i=0;i<size;i++)
    {
        cout<<arr2[i]<<endl;
    }
}
void Page :: display()
{
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" , ";
    }
}

int main()
{
    Page obj;
    obj.accept();
    obj.display();
    obj.first();
}