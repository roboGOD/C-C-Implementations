#include<iostream>
#include<stdint.h>
using namespace std;


/*
	This problem was asked by Google.

	An XOR linked list is a more memory efficient doubly linked list. 
	Instead of each node holding next and prev fields, it holds a field named both, 
	which is an XOR of the next node and the previous node. Implement an XOR linked 
	list; it has an add(element) which adds the element to the end, and a get(index) 
	which returns the node at index.
	
*/


struct node
{
	int val;
	long long int npx;
};
node* Head = 0;

node* getNewNode(int value, node* prev)
{
	node* temp = new node;
	temp->val = value;
	temp->npx = (uintptr_t)prev;
	return temp;
}

void add(int value)
{
	node* temp = Head;
	long long int prev = 0;
	long long int prevPrev = 0;
	int count = 1;
	if(Head == 0)
	{
		Head = getNewNode(value, 0);
		return;
	}
	while(temp->npx != prev)
	{
		prevPrev = prev;
		prev = (uintptr_t)temp;
		temp = (node*)(prevPrev ^ (temp->npx));
		count += 1;
	}
	temp->npx = prev ^ (uintptr_t)(getNewNode(value, temp));
	//cout<<"\nAdded a node.\n Total Nodes: "<<count+1;
}

node* get(int index)
{
	node* temp = Head;
	long long int prev = 0;
	long long int prevPrev = 0;
	int count = 0;

	if(Head==0)
		return 0;
	if(count==index)
		return temp;
	while(temp->npx != prev)
	{
		prevPrev = prev;
		prev = (uintptr_t)temp;
		temp = (node*)(prevPrev ^ (temp->npx));
		count += 1;
		if(count == index)
			return temp;
	}
	return 0;
}

void displayList()
{
	node* temp = Head;
	long long int prev = 0;
	long long int prevPrev = 0;
	if(Head==0)
	{
		cout<<"\nNo elements in the list.";
		return;
	}
	cout<<"\nElements in the List: ";
	while(temp->npx != prev)
	{
		cout<<temp->val<<" ";
		prevPrev = prev;
		prev = (uintptr_t)temp;
		temp = (node*)(prevPrev ^ (temp->npx));
	}
	cout<<temp->val;
}

int main()
{
	int n;
	int flag=1;
	int op;
	int temp;
	node* tempNode = 0;
	cout<<"Enter the number of elements in the Linked List: ";
	cin>>n;
	cout<<"Enter elements: ";
	for(int i=0; i<n; i++)
	{	
		cin>>temp;
		add(temp);
	}

	while(flag)
	{
		cout<<"\n\nSelect!\n 1. Add Element.\n 2. Print List.\n 3. Get Element.\n99. Exit.\nEnter Option: ";
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"\nEnter element to add: ";
				cin>>temp;
				add(temp);
				break;
			case 2:
				displayList();
				break;
			case 3:
				cout<<"\nEnter the index of the element: ";
				cin>>temp;
				tempNode = get(temp);
				if(tempNode == 0)
					cout<<"\nElement doesn't exist!";
				else
					cout<<"\nValue of element is: "<<tempNode->val;
				break;
			case 99:
				flag=0;
				break;
			default:
				cout<<"\nPlease enter valid option.";
				break;
		}
	}
}	