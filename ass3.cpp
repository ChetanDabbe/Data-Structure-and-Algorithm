#include <iostream>
using namespace std;

struct node
{
public:
    int roll_no;
    string name;
    node *next;
};

class student
{
    int n;

public:
    node *ht[10];
    student()
    {
        cout << "\nEnter the number of elements you want to insert : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            ht[i] = new node;
            ht[i]->next = NULL;
        }
    }
    int hash(int);
    void insert(int, string);
    void del();
    void search();
    void display();
};
int student ::hash(int key)
{
    return key % n;
}
void student::insert(int r, string name1)
{
    int index;
    index = hash(r);

    node *curr;
    curr = new node();
    curr->roll_no = r;
    curr->name = name1;
    curr->next = ht[index]->next;
    ht[index]->next = curr;
}

void student ::del()
{
    int key;
    cout << "\nEnter the roll number you want to delete : ";
    cin >> key;
    int index = hash(key);
    // cout << "\nIndex : " << index << endl;
    int flag=0;
    node *curr;
    curr = ht[index]->next;
    if (curr->roll_no == key)
    {
        curr->roll_no = 0;
        curr->name = "0";
        cout << "\nRoll number deleted" << endl;
    }
    else
    {
        while (curr != NULL)
        {
            if (curr->roll_no == key)
            {
                curr->roll_no = 0;
                curr->name = "0";
                flag=1;
                break;
            }
            curr=curr->next;
        }
        if (flag==1)
        {
            cout << "\nRoll number deleted" << endl;
        }
        else{
            cout<<"\nRoll number is not present "<<endl;
        }
    }
}

void student ::search()
{
    int key;
    cout << "\nEnter the roll number you want to search : ";
    cin >> key;
    int index = hash(key);
    node *curr;
    curr = ht[index]->next;
    int flag = 0;
    
    if (curr->roll_no == key)
    {
        cout << "\nRoll number found" << endl;
        
    }
    else
    {
        while (curr != NULL)
        {
            if (curr->roll_no == key)
            {
                // cout << "\nRoll number found" << endl;
                flag=1;
                break;
            }
            curr=curr->next;
        }
        if (flag==1)
        {
            cout<<"\nRoll number found "<<endl;

        }
        else{
            cout<<"\nNot found "<<endl;
        }
    }
    
}

void student::display()
{
    node *curr;
    for (int i = 0; i < n; i++)
    {
        cout<<"\n" << i << "\t\t";
        curr = ht[i]->next;
        while (curr != NULL)
        {
            cout << curr->roll_no << "\t" << curr->name <<"\t , \t ";
            curr = curr->next;
        }
    }
}

int main()
{
    student s;

    int ch=0;
    int r1;
    string na1;
    while(ch<5)
    {
        cout<<"\n1.Insert \n2.Delete \n3.Display \n4.Search \n5.Exit"<<endl;
        cout<<"\nEnter the choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter the roll number : ";
                cin>>r1;
                cout<<"\nEnter the name : ";
                cin>>na1;
                s.insert(r1,na1);
                break;
            case 2:
                s.del();
                break;
            case 3:
                s.display();
                break;
            case 4:
                s.search();
                break;
            default:
                cout<<"\nInvalid choice "<<endl;
                break;
        }
    }
    
}