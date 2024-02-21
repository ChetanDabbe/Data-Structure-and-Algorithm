#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};

class BST{
    public:
        node *root;
        node *curr;
        BST(int d)
        {
            root =new node;
            root->data=d;
            root->left=NULL;
            root->right=NULL;
        }

        void insert();
        void display(node *root);
        void longest();
        void minimum();
        void change_tree();
};
void BST:: insert()
{
    
    node *temp;
    curr=new node;
    cout<<"\nEnter the element which is to be inserted : ";
    cin>>curr->data;
    curr->left=NULL;
    curr->right=NULL;
    if (root==NULL)
    {
        root=curr;
    }
    else
    {
        temp=root;

    }

    while (1)
    {
        if (curr->data < temp->data)            //new value is compared with root value(Temp)
        {
            if (temp->left==NULL)
            {
                temp->left=curr;
                cout<<"\nLeft "<<endl;
                cout<<temp->data<<endl<<curr->data<<endl;
                break;
            }
            else
            {
                cout<<"\nLeft "<<endl;
                cout<<temp->data<<endl<<curr->data<<endl;
                temp=temp->left;
            }
        }
        else
        {
            if (temp->right==NULL)
            {
                temp->right=curr;
                cout<<"\nRight "<<endl;
                cout<<temp->data<<endl<<curr->data<<endl;
                break;
            }
            else
            {
                cout<<"\nRight"<<endl;
                cout<<temp->data<<endl<<curr->data<<endl;
                temp=temp->right;
            }
        }
    }
}

void BST :: display(node *curr)
{
    // if (root!=NULL)
    // {
    //     node *temp;
    //     temp=root;
    //     //cout<<"*******ROOT NODE**********"<<endl<<curr->data<<endl;
    //     while(temp!=NULL)
    //     {
    //         if (temp->left!=NULL)
    //         {
    //             cout<<"\nRoot node : ";
    //             cout<<temp->data<<endl<<curr->data<<endl;
    //             // <<curr->data<<endl;
    //         }
    //         else 
    //         {
    //             cout<<temp->data<<endl<<curr->data<<endl;
    //             // <<curr->data<<endl;
    //         }
    //         temp=temp->left;
    //     }
    //     while(temp!=NULL)
    //     {
    //         if (temp->left!=NULL)
    //         {
    //             cout<<"\nRoot node : ";
    //             cout<<temp->data<<endl<<curr->data<<endl;
    //         }
    //         else 
    //         {
    //             cout<<temp->data<<endl<<curr->data<<endl;
    //             // <<curr->data<<endl;
    //         }
    //         temp=temp->right;
    //     }
    // }
    // else
    // {
    //     cout<<"\nNo binary search tree "<<endl;
    // }

    
	if(curr!=NULL)
	{
		display(curr->left);
		cout<<curr->data<<" ";
		display(curr->right);
	}

}
int main()
{
    int n;
    cout<<"\nEnter the root of binary search tree : ";
    cin>>n;
    BST obj(n);
    int ch=0;
    while (ch<6)
    {
        cout<<"\n1.Insert the new node \n2.Display the tree \n3.Find the number of nodes in longest path from root \n4.Minimum data value \n5.Change a tree "<<endl;
        cout<<"\nEnter the choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                obj.insert();
                break;
            case 2:
                obj.display(root);
                break;

        }

    }
}