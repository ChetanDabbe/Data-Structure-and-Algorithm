#include <iostream>
using namespace std;

struct phonebook
{
public:
    long int mobile_no;
    string name;
};

class hashing
{

public:
    int n, i;
    phonebook ht[20];
    hashing()
    {
        cout << "\nEnter the size of phonebook  : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            ht[i].mobile_no = -1;
            ht[i].name = -1;
        }
    }
    int hash(long int key);
    void insert(long int, string);
    void del();
    void search();
    void insert2(long int, string);
    void del2();
    void search2();
    void display();
};

int hashing::hash(long int key)
{
    return key % n;
}

void hashing ::insert(long int ele, string name1)
{
    int cnt = 1;
    int index;
    index = hash(ele);
    if (ht[index].mobile_no == -1)
    {
        ht[index].mobile_no = ele;
        ht[index].name = name1;
    }
    else if (ht[index].mobile_no != -1)
    {
        for (i = (index + 1) % n; i < n; i = (i + 1) % n)
        {
            if (ht[i].mobile_no == -1)
            {
                ht[i].mobile_no = ele;
                ht[i].name = name1;
                break;
            }
            else if (ht[i].mobile_no != -1)
            {
                cnt = cnt + 1;
                if (cnt >= n)
                {
                    cout << "\n----------------------------" << endl;
                    cout << "\nHash table is overflow " << endl;
                    cout << "----------------------------" << endl;
                    break;
                }
            }
        }
    }
}
void hashing ::del()
{
    long int key1;
    cout << "\nEnter the mobile number you want to delete from phonebook : ";
    cin >> key1;

    int index = hash(key1);
    if (ht[index].mobile_no == key1)
    {
        cout << "\nMobile number deleted " << endl;

        ht[index].name = -1;
        ht[index].mobile_no = -1;
    }
    else if (ht[index].mobile_no != key1)
    {
        for (i = (index + 1) % n; (i % n) < n; i = (i + 1) % n)
        {
            if (ht[i].mobile_no == key1)
            {
                cout << "\nMobile number deleted " << endl;
                ht[i].mobile_no = -1;
                ht[i].name = -1;
                break;
            }
            else
            {
                cout << "\nRecord not found" << endl;
                break;
            }
        }
    }
}

void hashing ::search()
{
    long int key;
    cout << "\nEnter the mobile number you want to search : ";
    cin >> key;
    int index = hash(key);
    int flag = 0;
    int cnt = 1;
    if (ht[index].mobile_no == key)
    {
        cout << "\nMobile number found in phonebook at location " << index << endl;
    }
    else if (ht[index].mobile_no != key)
    {
        for (i = (index + 1) % n; i < n; i = (i + 1) % n)
        {
            if (ht[i].mobile_no == key)
            {
                flag = 1;
                break;
            }
            else
            {

                break;
            }
        }
        if (flag == 1)
        {
            cout << "\nNumber is present at location " << i << endl;
            cout << "\nName : " << ht[i].name;
        }
        else
        {
            cout << "\nNot found " << endl;
        }
    }
}

void hashing ::insert2(long int ele, string name1)
{
    int cnt = 1;
    int index;
    int j = 1;
    index = hash(ele);
    if (ht[index].mobile_no == -1)
    {
        ht[index].mobile_no = ele;
        ht[index].name = name1;
    }
    else if (ht[index].mobile_no != -1)
    {

        for (i = 0; i < n; i++)
        {
            int index2 = (index + (i * i)) % n;
            if (ht[index2].mobile_no == -1)
            {
                ht[index2].mobile_no = ele;
                ht[index2].name = name1;
                break;
            }
            else if (ht[index2].mobile_no != -1)
            {
                cnt = cnt + 1;
                if (cnt >= n)
                {
                    cout << "\n----------------------------" << endl;
                    cout << "\nHash table is overflow " << endl;
                    cout << "----------------------------" << endl;
                    break;
                }
            }
        }
    }
}
void hashing ::del2()
{
    long int key1;
    cout << "\nEnter the mobile number you want to delete from phonebook : ";
    cin >> key1;

    int index = hash(key1);
    if (ht[index].mobile_no == key1)
    {
        cout << "\nMobile number deleted " << endl;

        ht[index].name = -1;
        ht[index].mobile_no = -1;
    }
    else if (ht[index].mobile_no != key1)
    {
        for (i = 0; i < n; i++)
        {
            int index2 = (index + (i * i)) % n;
            if (ht[index2].mobile_no == key1)
            {
                cout << "\nMobile number deleted " << endl;
                ht[index2].mobile_no = -1;
                ht[index2].name = -1;
                break;
            }

            // else if (ht[index2].mobile_no != key1)
            // {
            //     cout<<"\nRecord not found "<<endl;

            //     break;
            // }
        }
    }
}

void hashing ::search2()
{
    long int key;
    cout << "\nEnter the mobile number you want to search : ";
    cin >> key;
    int index = hash(key);
    int flag = 0;
    int cnt = 1;
    if (ht[index].mobile_no == key)
    {
        cout << "\nMobile number found in phonebook at location " << index << endl;
    }
    else if (ht[index].mobile_no != key)
    {
        for (i = 0; i < n; i++)
        {
            int index2 = (index + (i * i)) % n;
            if (ht[index2].mobile_no == key)
            {
                flag = 1;
                break;
            }
            // else
            // {
            //     break;
            // }
        }
        if (flag == 1)
        {
            cout << "\nNumber is present at location " <<endl;
        }
        else
        {
            cout << "\nNot found " << endl;
        }
    }
}

void hashing ::display()
{
    cout << "\nIndex\t  Name\t\tMobile_no" << endl;
    for (i = 0; i < n; i++)
    {
        cout << i << "\t" << ht[i].name << "\t\t" << ht[i].mobile_no << endl;
    }
}
int main()
{
    hashing obj;
    long int key1;
    string name;
    int ch = 0;  // For operation which we want to perform
    int ch1 = 0; // For collision technique
    while (ch1 < 3)
    {
        cout << "\n1.Linear probing \n2.Quadratic probing \n3.Exit" << endl;
        cout << "\nEnter the choice : ";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
            while (ch < 5)
            {
                cout << "\n*****************LINEAR PROBING*****************";
                cout << "\n1.Insert \n2.Display \n3.Delete \n4.Search \n5.Exit" << endl;
                cout << "\nEnter the choice : ";
                cin >> ch;

                switch (ch)
                {
                case 1:

                    cout << "\nEnter the name : ";
                    cin >> name;
                    cout << "\nEnter the mobile number :  ";
                    cin >> key1;
                    obj.insert(key1, name);
                    break;
                case 2:
                    obj.display();
                    break;
                case 3:
                    obj.del();
                    break;
                case 4:
                    obj.search();
                    break;
                }
            }
            break;

        case 2:
            ch=0;
            while (ch < 5)
            {
                cout << "\n*****************QUADRATIC PROBING*****************";
                cout << "\n1.Insert \n2.Display \n3.Delete \n4.Search \n5.Exit" << endl;
                cout << "\nEnter the choice : ";
                cin >> ch;

                switch (ch)
                {
                case 1:

                    cout << "\nEnter the name : ";
                    cin >> name;
                    cout << "\nEnter the mobile number :  ";
                    cin >> key1;
                    obj.insert2(key1, name);
                    break;
                case 2:
                    obj.display();
                    break;
                case 3:
                    obj.del2();
                    break;
                case 4:
                    obj.search2();
                    break;
                }
            }
            break;
        }
    }
}

