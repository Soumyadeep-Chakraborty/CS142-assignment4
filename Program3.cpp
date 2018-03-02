#include<iostream>

#include<string>

using namespace std;

// declaring a class node that shall contain only alphabet characters and pointer to the next node. The nodes will build up  
//the stack that would be used to check whether the name is palindrome or not

class snode{

    public:

    char alph;

    snode *next;

};

//declaring a class node which will contain a phone number, name and description as a string and a pointer to the next node. This nodes
//will build up the queue that shall contain all the above data.

class node{

public:

	int pho;

    string name,desc;

	node *next;

};

//declaring a class stack which contains elementary function of a stack

class Stack{

    public:

	snode *top;

public:

	Stack(){

		top =NULL;

	}
	//pushing a node to the stack
	void push(char a){

		snode *temp = new snode;

		temp->alph = a;

		temp->next = NULL;

		if(top!=NULL){

			temp->next = top;

		}

		top = temp;

	}
	//popping a node from the stack
	void pop(){

        if(top == NULL){

            cout<<"Nothing to pop\n";//no elements

        }

        else{

            top = top->next;

        }

    }   

};



// Function, not in a class
//boolean function that checks whether the user input name is a palindrome or not 

bool checkpal(string n){

    Stack b;

    for(int i=0;i < n.length();i++){

        b.push(n[i]); 		//creating a stcak that shall store the data of each element of the array as the data of nodes added to the stack 

    }

    for(int i=0;i < n.length();i++){

        if(n[i]!=b.top->alph){

            cout<<"not palindrome"; 

            return 0;

        }

        b.pop();

    }

    return 1;

}

//declaring a class queue conatining the elementary operation associated with a queue

class queue{

	node *head;

    node *tail;


public:
 //class constructor
	queue(){

		head = NULL;

        tail = NULL;

	}
	//adding element to a queue
	
	void inqueue(int num,string nam, string des){

		node *temp = new node;

		temp->pho = num;

        temp->name = nam;

        temp->desc = des;

		temp->next = NULL;

        if(checkpal(nam)==1){ //if the name is a palindrome it moves to the beginning as the very first node

            temp->next = head;

            head = temp;

        }

        else {

            if (head != NULL)

                tail->next = temp;

            else

                head = temp;

            tail = temp;

        }

        show();

	}
	//deleting element from the queue
	
	void dequeue(){

        if(head == NULL){

            cout<<"Queue doesn't exist";

        }

        else{

            head = head->next;

        }

	}
	//displaying elements of a queue
	
	void show(){

		node *curr = head;

		while (curr!=NULL){

			cout << curr->name << "\n";

            cout << curr->pho<<"\n";

            cout << curr->desc<<"\n";

			curr = curr->next;

		}

		cout << "end" <<endl;

    

	}

};





int main(){

 queue s;

    int choice;

    int x;

    string name,descrip;

    while(1)

    {

        cout<<"\n-----------------------------------------------------------";

        cout<<"\n\t\t Customer Care \n\n";

        cout<<"1:PUSH\n2:POP\n3:DISPLAY QUEUE\n4:EXIT";

        cout<<"\nEnter your choice(1-4): ";

        cin>>choice;

        switch(choice)

        {

            case 1:

            	cout << "Enter the number to push:";

            	cin >> x;

                cout<<"Enter name: ";

                cin >>name;

                cout<<"Enter Description:";

                cin>>descrip;

                s.inqueue(x,name,descrip);

                break;

            case 2:

                s.dequeue();

                break;

            case 3:

                s.show();

                break;

            case 4:

                return 0;

                break;

            default:

                cout<<"\nPlease enter correct choice(1-4)!!";

                break;

        }



    }

    return 0;

}
