#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *link;
}*top=NULL;
int isEmpty(){
    if(top==NULL)
        return 1;
    else
        return 0;
}
void push(int data){
    struct Node *newNode=new Node;
    if(newNode==NULL){
        cout<<"Stack Overflow."<<endl;
        exit(1);
    }
    newNode->data=data;
    newNode->link=NULL;
    newNode->link=top;
    top=newNode;
}
void print(){
    struct Node *temp;
    temp=top;
    if(isEmpty()){
        cout<<"Stack Underflow."<<endl;
        exit(1);
    }
    cout<<"The Stacks Elements are:"<<endl;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}
int pop(){
    struct Node *temp;
    temp=top;
    if(isEmpty()){
        cout<<"Stack Underflow."<<endl;
        exit(1);
    }
    int val=temp->data;
    top=top->link;
    free(temp);
    temp=NULL;
    return val;
}
int peek(){
    if(isEmpty()){
        cout<<"Stack Underflow."<<endl;
        exit(1);
    }
    return top->data;
}
int main(){
    int choice,data;
    while(1){
        cout<<"1.Push"<<endl;
        cout<<"2.Print"<<endl;
        cout<<"3.Quit"<<endl;
        cout<<"4.pop"<<endl;
        cout<<"5. Print all the top Elements."<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"Enter Elements to be Pushed:"<<endl;
            cin>>data;
            push(data);
            break;
        case 2:
            print();
            break;
        case 3:
            exit(1);
        case 4:
            data=pop();
            cout<<"The Deleted Element is "<<data<<endl;
            break;
        case 5:
            cout<<"The Topmost Element of Stack is "<<peek()<<endl;
            break;
        default:
            cout<<"Wrong Choice."<<endl;
            break;
        }
    }
    return 0;
}
