//program to implement a queue using two stacks


#include<iostream>

using namespace std;

class node{                //creating a node using class and declaring its components

	public:

	float data; 

	node* next;

};

class stackll{             //creating stack using linked lists and declaring its components

	public:

	node* bottom, *top; 

//using class constructor to make the top and bottom point to null
	stackll(){

		bottom = NULL;				

		top = NULL;

	}
//declaring various functions
	void push(float data);

	void pop();

	void show();

	void mkqu(node* bottom);

	void dlt();

};
//creating queue containing two stacks using classes 

class queue{        

	stackll stack1, stack2;
//declaring various functions
	public:

	void push();

	void pop();

	void show();

};

int main(){

	queue one;

	cout<<"//Program to implement queue using two stack ~ "<<endl;

	one.push();

	one.show();

	one.pop();

	one.show();

	return 0; 

} 
//delacring a function to insert a node containing data at the beginning of the linked list
void stackll::push(float data){

	node* temp =new node;

	temp ->data = data;

	temp->next=NULL;

	if (bottom ==NULL){

		bottom =temp ;

		top =temp;

	}	

	else {

		temp->next=bottom;

		bottom =temp;

	}

}
//creating a function to pop out a node from a stack
void stackll::pop(){
//check whether the stack is empty
	if (bottom==NULL){

		cout<<"Error!!-Stack is empty "<<endl;

	}

	else if(bottom==top){

		node* temp =bottom;

		delete temp;

		bottom =NULL;

		top= NULL;

	}

	else {

		node* temp=bottom;

		bottom=bottom->next;

		delete temp;

	}

}
//creating a function to display the elements of a stack
void stackll::show(){

	node* temp =bottom;
//check whether the stack is empty
	if(bottom==NULL){

	cout<<"Error!!-Nothing To Show "<<endl;

	}

	else {

		while(temp!=top){

		cout<<temp->data<<"\t------->\t";

		temp=temp->next;	

		}

		cout<<temp->data<<endl;

	}

}
//pushing into another stack in reverse order
void stackll::mkqu(node* bottom){                                  

		node* temp =bottom;

		if(bottom!=NULL){

			while(temp->next!=NULL){

				push(temp->data);

				temp=temp->next;

			}

			push(temp->data);

		}

}	
//popping out nodes from stack
void stackll::dlt(){

	while(bottom!=NULL){

		pop();

	}	

}
//delcaring function to push elements into the queue
void queue::push(){

	cout<<"\nPlease Enter The Number oF Elements : "<<endl;

	int num,data;

	cin>>num;

	for(int i=0; i<num; i++){

		cout<<"Enter Data ["<<i+1<<"] :";

		cin>>data;

		stack1.push(data);

	}

	stack2.dlt();

	stack2.mkqu(stack1.bottom);

}	
//delcaring functions to pop elements out of the queue
void queue::pop(){

	cout<<"Enter the number of elements you want to delete:"<<endl;

	int num;

	cin>>num;

	for(int i=0; i<num; i++){

		stack2.pop();

	}

	stack1.dlt();

	stack1.mkqu(stack2.bottom);

}	
//declaring a function to display the elements of the queue
void queue::show(){

	stack1.show();

}

