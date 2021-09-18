#include<iostream>
using namespace std;
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *addToEmpty(int data){
    struct Node *temp=new Node;
    temp->data=data;
    temp->next=temp;
    temp->prev=temp;
    return temp;
};
struct Node *addAtBegg(struct Node* tail,int data){
    struct Node *newp=addToEmpty(data);
    if(tail==NULL)
        return newp;
    else{
    struct Node *temp=tail->next;
    newp->next=temp;
    newp->prev=tail;
    temp->prev=newp;
    tail->next=newp;
    return tail;
    }
};
struct Node *addAtEnd(struct Node *tail,int data){
    struct Node *newp=addToEmpty(data);
    if(tail==NULL){
        return newp;
    }
    else{
        struct Node *temp=tail->next;
        newp->next=temp;
        newp->prev=tail;
        tail->next=newp;
        temp->prev=newp;
        tail=newp;
        return tail;
    }
};
void print(struct Node *tail){
    if(tail==NULL)
        cout<<"No Element is present in List."<<endl;
    else{
        struct Node *temp=tail->next;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=tail->next);
    }
    cout<<endl;
}
struct Node *addAtPos(struct Node *tail,int data,int pos){
    struct Node *newp=addToEmpty(data);
    if(tail==NULL)
        return newp;
    struct Node *temp=tail->next;
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    newp->prev=temp;
    newp->next=temp->next;
    temp->next->prev=newp;
    temp->next=newp;
    if(temp==tail)
        tail=tail->next;
    return tail;
};
struct Node *delFNode(struct Node *tail){
    if(tail==NULL)
        return tail;
    struct Node *temp=tail->next;
    if(temp==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    tail->next=temp->next;
    temp->next->prev=tail;
    free(temp);
    return tail;
};
struct Node *DelLNode(struct Node *tail){
    if(tail==NULL)
        return tail;
    struct Node *temp=tail->prev;
    if(temp==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    temp->next=tail->next;
    tail->next->prev=temp;
    free(tail);
    tail=temp;
    return tail;
};
struct Node *DelANode(struct Node *tail,int pos){
    struct Node *temp=tail->next;
    struct Node *temp2;
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    if(temp==tail)
        tail=temp2;
    return tail;
};

};
int main(){
    int data=45;
    struct Node *tail;
    tail=addToEmpty(data);
    print(tail);
    cout<<endl;
    tail=addAtEnd(tail,67);
    print(tail);
    cout<<endl;
    tail=addAtBegg(tail,67);
    print(tail);
    cout<<endl;
    tail=addAtEnd(tail,5);
    print(tail);
    cout<<endl;
    tail=addAtPos(tail,8,2);
    print(tail);
    cout<<endl;
    cout<<"Delete From First Position."<<endl;
    tail=delFNode(tail);
    print(tail);
    cout<<endl;
    cout<<"Delete From Last Position."<<endl;
    tail=DelLNode(tail);
    print(tail);
    cout<<"Enter the Position to Delete."<<endl;
    int pos;
    cin>>pos;
    tail=DelANode(tail,pos);
    print(tail);


    return 0;
}
