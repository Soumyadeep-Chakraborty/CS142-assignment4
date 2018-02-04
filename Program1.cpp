//Implementing a stack and a queue using linked lists and Arrays

#include <iostream>

using namespace std;

//constructing a node using classes and declaring its elements
class Node    
{
  public:
  int data;
  Node* next;
  Node()
  {
    data=0;
    next=NULL;
  }
};

//Constructing A stack as linked lists using Class
class StackLL
{
  public:
  Node* head;
  StackLL()
  {
    head=NULL;
  }
  void push(int num);
  void pop();
  void display();
};

//Constructing a stack as arrays using class
class StackArr 
{
 int stk[30];
 int top;
 public:
 StackArr(){
   top=-1;
 }

//function to push an element into a stack of array elements 
void push(int x) {
	if(top >  29){
  cout <<"\nERROR - STACK OVERFLOW !!!";
return;
}
stk[++top]=x;
cout <<"\nElement Has Been Inserted " <<x<<endl;
}

//function to pop out an element out of a stack of array elements
void pop()
{
if(top <0){
cout <<"\n \nERROR - STACK UNDERFLOW !!!";
return;
}
cout <<"\nElement Has Been Deleted " <<stk[top--]<<endl;
}

//function to display array elements
void display(){
cout<<"\n \n";
if(top<0){
cout <<"ERROR - STACK IS EMPTY !!!!";
return;
}
for(int i=top;i>=0;i--)
cout <<stk[i] <<" -> ";
cout<<"NULL";
}
};

//Implementation of Queue Using Arrays
class QueueArr 
{
int queue1[20];
int rear,front;
public:
QueueArr(){
rear=-1;
front=-1;
}

//function to push an element into a queue of array elements
void pushqueue(int x){
if(rear >  29)
{
cout <<"\nERROR - QUEUE OVERFLOW !!!";
front=rear=-1;
return;
}
queue1[++rear]=x;
cout <<"\nElement Has Been Inserted " <<x<<endl;
}

//function to pop out an element from a queue of array elements
void popqueue(){
if(front==rear){
cout <<"\nERROR - QUEUE UNDERFLOW !!!";
return;
}
cout <<"\nElement Has Been Deleted " <<queue1[++front];
}

//function to display array elements
void display()
{
cout<<"\n";
if(rear==front)
{cout <<"\nQUEUE IS EMPTY !!!!";
return;
}
for(int i=front+1;i<=rear;i++)
cout <<queue1[i]<<" -> ";
cout<<"NULL";
}
};

//Implementing A Queue Via Linked Lists
class QueueLL
{
  public:
  Node* head;
  Node* tail;
  QueueLL()
{
    head=NULL;
    tail=NULL;
  }
  void pushqueue(int num);
  void popqueue();
  void display();
};

//pushing a element as node into a stack
void StackLL::push(int num) 
{
  Node* temp=new Node;
  temp->data=num;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
    return;
  }
  temp->next=head;
  head=temp;
}

//popping an element from a stack
void StackLL::pop()  
{
  Node* temp;
  if(head==NULL)
  { 
   cout<<"\n ERROR - The stack is empty ";
   return;
  }
  temp=head;
  head=head->next;
  temp->next=NULL;
  delete temp;
}

//display all elements of a stack
void StackLL::display()
{
  Node *curr = head;
  cout<<"\n";
  while (curr!=NULL)
  {
    cout << curr->data << "\t----->\t" ;
    curr = curr->next;
  }
  cout << "NULL" <<endl;
}

//inserting an element into a queue
void QueueLL::pushqueue(int num)
{
  Node *temp=new Node;
  temp->data=num;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp; 
  }
  else
  {
    tail->next=temp;
  }
  tail=temp;
}

//deleting an element from a queue
void QueueLL::popqueue()
{
  Node* temp;
  if(head==NULL)
  {
   cout<<"\nERROR - Queue is empty !!!";
   return;
  }
  temp=head;
  head=head->next;
  temp->next=NULL;
  delete temp;
}

//displaying a queue
void QueueLL::display()

 {
  Node *curr = head;
  cout<<"\n";
  while (curr!=NULL)
  {
    cout << curr->data << "\t---->\t" ;
    curr = curr->next;
  }
  cout << "NULL" <<endl;
 }


int main()
{
  StackLL SLList;
  QueueLL QLList;
  StackArr SArr;
  QueueArr QArr;
  //Creating a stack and a queue and performing various functions on it using linked lists :
  SLList.push(50); 
  SLList.push(60);
  SLList.push(70);
  SLList.push(80);
  SLList.display();
  SLList.pop();
  SLList.display();
  QLList.pushqueue(10);
  QLList.pushqueue(20);
  QLList.pushqueue(30);
  QLList.pushqueue(40);
  QLList.display();
  QLList.popqueue();
  QLList.display();
  //Creating a stack and a queue and performing various functions on it using arrays :
  SArr.push(10);  
  SArr.push(20);
  SArr.push(30);
  SArr.push(40);
  SArr.display();
  SArr.pop();
  SArr.display();
  QArr.pushqueue(60);
  QArr.pushqueue(70);
  QArr.pushqueue(80);
  QArr.pushqueue(90);
  QArr.display();
  QArr.popqueue();
  QArr.display();
  return 0;
}
