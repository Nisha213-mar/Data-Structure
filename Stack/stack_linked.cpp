#include<iostream>
using namespace std;
class Node{
public:
    int key;
    int data;
    Node* next;
    Node(){
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k,int d){
        key=k;
        data=d;
    }
};
class stack{
public:
    Node* top;
    stack(){
   top=NULL;
    }
//Check if Node Exists
bool nodeExists(Node* n){
    Node *temp=top;
    bool exist=false;
    while(temp!=NULL){
        if(temp->key==n->key){
        exist=true;
        break;
    }
    temp=temp->next;
    }
    return exist;
    }
    //check stack is empty or not
    bool Empty(){
   if(top==NULL){
    return true;
   }
   else{
    return false;
   }
    }
    //push element on stack
    void push(Node* n){
   if(top==NULL){
    top=n;
   }
   else if(nodeExists(n)){
    cout<<"same key not allowed"<<endl;
   }
   else{
    Node *temp=top;
    top=n;
    n->next=temp;
    cout<<"Node Pushed"<<endl;
   }
    }
Node * pop(){
    Node* temp=NULL;
    if(Empty()){
        cout<<"Stack Underflow"<<endl;
        return temp;
    }
    else{
        temp=top;
        top=top->next;
        return temp;
    }
}
Node* peek(){
    Node* temp=NULL;
    if(Empty()){
        cout<<"Stack Underflow"<<endl;
        return temp;
    }
    else{
        return top;
    }
}
int count(){
    int count=0;
    Node*temp=top;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void display(){
    cout<<"All Values in Stack are:"<<endl;
    Node* temp=top;
    while(temp!=NULL){
        cout<<"("<<temp->key<<","<<temp->data<<")"<<"->"<<endl;
        temp=temp->next;
    }
    cout<<"Total number of Nodes in the stack:"<<count()<<endl;
    cout<<endl;
}
};
int main(){
    stack s1;
    int option,key,data;
    do{
        cout<<"What operation do you want to perform?"<<"Select option Number.Enter 0 to exit."<<endl;
        cout<<"1.Push()"<<endl;
        cout<<"2.pop()"<<endl;
        cout<<"3.isEmpty()"<<endl;
        cout<<"4.Peek()"<<endl;
        cout<<"5.count()"<<endl;
        cout<<"6.Display()"<<endl;
        cout<<"7.clear screen"<<endl;
        cin>>option;
        Node* new_node=new Node();
        switch(option){
        case 0:
            break;
        case 1:
            cout<<"Enter key and value of Node to push it into stack"<<endl;
            cin>>key;
            cin>>data;
            new_node->key=key;
            new_node->data=data;
            s1.push(new_node);
            break;
        case 2:
            cout<<"POP function called- Poped value:"<<endl;
            new_node=s1.pop();
            cout<<"Top of stack is: ("<<new_node->key<<","<<new_node->data<<")"<<endl;
            delete new_node;
            break;
        case 3:
            if(s1.Empty())
                cout<<"Stack is Empty"<<endl;
            else
                cout<<"Stack is not Empty"<<endl;
            break;
        case 4:
            if(s1.Empty()){
                cout<<"Stack is Empty"<<endl;
            }
            else{
                cout<<"PEEK Function called:"<<endl;
                new_node=s1.peek();
                cout<<"Top of stack is: ("<<new_node->key<<","<<new_node->data<<")"<<endl;
            }
            break;
        case 5:
            cout<<"Count Function called:"<<endl;
            cout<<"No of nodes in the stack:"<<s1.count()<<endl;
            break;
        case 6:
            cout<<"Display function is called-"<<endl;
            s1.display();
            cout<<endl;
            break;
        case 7:
            system("cls");
            break;
        default:
            cout<<"Enter proper option Number"<<endl;
        }
    }while(option!=0);
return 0;
}
