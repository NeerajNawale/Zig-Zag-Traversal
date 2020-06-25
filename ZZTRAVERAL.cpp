#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using std::cout;
class node
{
	int data;
	node* left,*right;
	node(int d)
	{
		data=d;
		left=right=NULL;
	}
	friend class BT;
};
class Queue
{
		int front,rear;
		node** que;
	public:
		Queue(int n):front(-1),rear(-1)
		{
			que=new node*[n];
		}
		void push(node* e)
		{
			que[++rear]=e;
			if(front==-1)
				front++;
		}
		node* pop()
		{
			node* temp=que[front++];
			if(front>rear)
				front=rear=-1;
			return temp;
		}
		int isEmpty()
		{
			return front==-1;
		}
};
class Stack
{
		node** stack;
		int top;
	public:
		Stack(int n):top(-1)
		{
			stack=new node*[n];
		}
		void push(node* e)
		{
			stack[++top]=e;
		}
		node* pop()
		{
			return stack[top--];
		}
		int isEmpty()
		{
			return top==-1;
		}
};
class BT
{
		node* root;
	public:
		BT():root(NULL){}
		void create(int* arr,int n)
		{
			root=new node(arr[0]);
			node* temp=root;
			int i=1;
			Queue q(n);
			do
			{
				if(!temp->left || !temp->right)
				{
					node* p=new node(arr[i++]);
					if(!temp->left)
						temp->left=p;
					else
						temp->right=p;
					q.push(p);
				}
				else
					temp=q.pop();
			}while(i<n);
		}
		void ZigZagTraversal(char*msg,int n)
		{
			cout<<msg;
			Stack currS(n),nextS(n);
			currS.push(root);
			int height=1,i=1;
			node* value;
			do
			{
				for(;!currS.isEmpty() && height&1;i++)
				{
					value=currS.pop();
					cout<<value->data<<"\t";
					if(value->left)
						nextS.push(value->left);
					if(value->right)
						nextS.push(value->right);
				}
				++height;
				for(;!nextS.isEmpty() && !(height&1);i++)
				{
					value=nextS.pop();
					cout<<value->data<<"\t";
					if(value->right)
						currS.push(value->right);
					if(value->left)
						currS.push(value->left);
				}
				++height;
			}while(i<n);
		}
};
main()
{
	cout<<"\nHow Many Elements? --> ";
	int n;
	scanf("%d",&n);
	if(n<0)
	{
		cout<<"\nInvalid Input...\n";
		exit(1);
	}
	cout<<"\nEnter "<<n<<" Elements --> ";
	int* arr=new int[n];
	for(int i=0;i<n;i++)
		scanf("%i",arr+i);
	BT bt;
	bt.create(arr,n);
	bt.ZigZagTraversal("\nZig Zag Traversal of Given Binary Tree --> ",n);
}



