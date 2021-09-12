#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
    struct Node *link;
};
void printlist(Node *n){
    if(n==NULL){
        cout<<"Linked List is Empty."<<endl;
    }
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->link;
    }
}
void count_of_nodes(struct Node *head){
    int count=0;
    if(head==NULL)
        cout<<"Linked List is Empty."<<endl;
    struct Node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->link;
    }
    cout<<endl;
    cout<<"count:"<<count<<endl;
}
int add_at_end(struct Node *head,int data){
    cout<<"Insert at the End position."<<endl;
    struct Node *ptr,*temp;
    ptr=head;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link !=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;

}
int add_beg(struct Node* head,int d){
    cout<<"Insert at the beggining."<<endl;
    struct Node *ptr;
    ptr=new Node();
    ptr->data=d;
    ptr->link=NULL;
    ptr->link=head;
    head=ptr;
    while(ptr!=NULL){
        cout<< ptr->data<<" ";
        ptr=ptr->link;
    }
    return 0;
}
void add_at_pos(struct Node *head,int data,int pos){
    cout<<"Insert at any position."<<endl;
    struct Node *ptr=head;
    struct Node *ptr2;
    ptr2=(struct Node*)malloc(sizeof(struct Node));
    ptr2->data=data;
    ptr2->link=NULL;
    pos--;
    while(pos!=1){
        ptr=ptr->link;
        pos--;
    }
    ptr2->link=ptr->link;
    ptr->link=ptr2;
}
struct Node* del_first(struct Node *head){
    if(head==NULL)
        cout<<"List is already Empty"<<endl;
    else{
        struct Node *temp=head;
        head=head->link;
        free(temp);
        temp=NULL;
    }
    return head;
};
struct Node* del_last(struct Node *head){
    if(head==NULL){
        cout<<"List is already Empty."<<endl;
    }
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct Node *temp=head;
        struct Node *temp2=head;
        //using one pointer
        //while(temp->link->link!=NULL){
            //temp=temp->link;
        //}

        //free(temp->link);
       // temp->link=NULL;
       //using Two pointer
       while(temp->link!=NULL){
            temp2=temp;
        temp=temp->link;
       }
       free(temp->link);
       temp2->link=NULL;
    }
    return head;
};
void del_pos(struct Node **head,int position){
    struct Node *current=*head;
    struct Node *previous=*head;
    if(*head==NULL)
        cout<<"List is already Empty."<<endl;
    else if(position==1){
        *head=current->link;
        free(current);
        current=NULL;
    }
    else{
        while(position!=1){
            previous=current;
            current=current->link;
            position--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
    }
}
//Delete all Node code
struct Node *del_list(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        temp=temp->link;
        free(head);
        head=temp;
    }
    return head;
};
//Reverse the Linked List
struct Node *reverse(struct Node *head){
    struct Node *prev=NULL;
    struct Node *next=NULL;
    while(head!=NULL){
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
};
struct Node *insert(struct Node *head,int data){
    struct Node *temp;
    struct Node *newp=new Node;
    newp->data=data;
    newp->link=NULL;
    int key=data;
    if(head==NULL || key<head->data){
        newp->link=head;
        head=newp;
    }
    else{
        temp=head;
        while(temp->link!=NULL && temp->link->data<key){
            temp=temp->link;
        }
            newp->link=temp->link;
            temp->link=newp;
        }
        return head;

};

int main(){
    Node *head=NULL;
    Node *current=NULL;
    Node *current2=NULL;
    head=new Node();
    current=new Node();
    current2=new Node();
    //struct Node *head=malloc(sizeof(struct Node));
    head->data=45;
    head->link=current;
    //struct Node *current=malloc(sizeof(struct Node));
    current->data=78;
    current->link=current2;
    head->link=current;
    //current=malloc(sizeof(struct Node));
    current2->data=3;
    current2->link=NULL;
    //head->link->link=current;
   printlist(head);
   cout<<endl;
    count_of_nodes(head);
    add_at_end(head,67);
    printlist(head);
    cout<<endl;
    add_beg(head,9);
    cout<<endl;
    add_at_pos(head,34,3);
    printlist(head);
    cout<<endl;
    cout<<"Reverse The LInked list."<<endl;
    head=reverse(head);
    printlist(head);
    cout<<endl;
    cout<<"Delete from 1st position."<<endl;
    head=del_first(head);
    printlist(head);
    cout<<endl;
    cout<<"Delete from last position"<<endl;
    head=del_last(head);
    printlist(head);
    cout<<endl;
    cout<<"Delete at any position,"<<endl;
    del_pos(&head,2);
    printlist(head);
    //cout<<endl;
    //cout<<"Delete Whole List."<<endl;
   // head=del_list(head);
    //printlist(head);
    cout<<endl;
    cout<<"Insert Node"<<endl;
    head=insert(head,6);
    printlist(head);
    return 0;
}
