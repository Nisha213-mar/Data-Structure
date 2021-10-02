#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *link;
};
struct Node *front=NULL;
struct Node *rear=NULL;
void enqueue(int x){
    struct Node *newNode=new Node;
    newNode->data=x;
    newNode->link=NULL;

if(front==0 && rear==0){
    front=rear=newNode;
}
else{
    rear->link=newNode;
    rear=newNode;
}
}
void display(){
    struct Node *temp;
    if(front==0 && rear==0)
        cout<<"Node is Empty."<<endl;
    else{
        temp=front;
        while(temp!=NULL){
            cout<<temp->data <<" ";
            temp=temp->link;
        }
    }
}
void dequeue(){
    struct Node *temp;
    temp=front;
    if(front==0 && rear==0)
        cout<<"Node is Empty."<<endl;
    else{
        cout<<front->data <<endl;
        front=front->link;
        free(temp);
    }
}
void peek(){
    if(front==0 && rear==0)
        cout<<"Node is Empty."<<endl;
    else{
        cout<<front->data<<" ";
    }
}
int main(){
    int choice,data;
    while(1){
        cout<<"1.eneque"<<endl;
        cout<<"2.display"<<endl;
        cout<<"3.dequeue"<<endl;
        cout<<"4.peek"<<endl;
        //cout<<"5. Print all the top Elements."<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"Enter Elements to be Pushed:"<<endl;
            cin>>data;
            enqueue(data);
            break;
        case 2:
            display();
            break;
        //case 3:
           // exit(1);
        case 3:
            dequeue();
            //cout<<"The Deleted Element is "<<data<<endl;
            break;
       // case 5:
           // cout<<"The Topmost Element of Stack is "<<peek()<<endl;
           // break;
        case 4:
            cout<<"Delete the 1st element of list."<<endl;
            peek();
            break;
        default:
            cout<<"Wrong Choice."<<endl;
            break;
        }
    }
    return 0;
}


