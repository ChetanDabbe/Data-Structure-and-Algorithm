#include<iostream>
using namespace std;

struct node{
	int data;
	node *left,*right;

};

class BST
{
	public:
		node *root;
		BST(int d)
		{
			root->data=d;
			root->left=NULL;
			root->right=NULL;
		}
		void insert();
		void display();
		
};
void BST::insert()
{
	node *curr;
	node *temp;
	curr=new node;
	cout<<"Enter an  element which is to be insert in BST: ";
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
	
	while(1)
	{
		if (curr-> data < temp->data)
		{
			if (temp->left==NULL)
			{
				temp->left=curr;
				cout<<"\nLeft"<<endl;
				cout<<temp->data<<endl<<curr->data<<endl;
				break;
			}
			else
			
			{
				cout<<"\nLeft"<<endl;
				cout<<temp->data<<endl<<curr->data<<endl;
				temp=temp->left;
			}
		}
		else
		{
			if (temp->right==NULL)
			{
				temp->right=curr;
				cout<<"\nRight"<<endl;
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

void BST:: display()
{
	node *temp;
    temp=root;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
    }

}

int main()
{
	BST obj(10);
	int ch=0;
	while(ch<3)
	{
		cout<<"\n1.Insert \n2.Display \n3.Exit"<<endl;
		cout<<"\nEnter the choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.insert();
				break;
			case 2:
				obj.display();
				break;
			default:
				cout<<"\nInvalid choice "<<endl;
				break;	
		}
	}
}