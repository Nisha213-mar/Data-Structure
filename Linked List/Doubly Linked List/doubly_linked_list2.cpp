//Doubly Linked List With Structure
#include<iostream>
using namespace std;
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
//Add Elements to Empty List
struct Node* addToEmpty(struct Node *head,int data){
    struct Node *temp=new Node;
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
};
//Add the Element at Beggining
struct Node *addAtBegg(struct Node *head,int data){
    struct Node *temp=new Node;
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
};
//Add the Element at the End
struct Node *addAtEnd(struct Node *head,int data){
    struct Node *temp=new Node;
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    struct Node *tp=new Node;
    tp=head;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
};
//Add the Element at any position
struct Node *addAtPos(struct Node *head,int data,int pos){
    struct Node *nwNode=NULL;
    struct Node *temp=head;
    struct Node *temp2=NULL;
    nwNode=addToEmpty(nwNode,data);
    while(pos!=1){
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL){
        temp->next=nwNode;
        nwNode->prev=temp;
    }
    else{
    temp2=temp->next;
    nwNode->prev=temp;
    nwNode->next=temp2;
    temp->next=nwNode;
    temp2->prev=nwNode;
    return head;
    }
};
//Create the list of data Elements
struct Node *createList(struct Node *head){
    int data,n,i;
    cout<<"Enter the Number of Nodes:"<<endl;
    cin>>n;
    if(n==0)
        return head;
    cout<<"Enter the data of node 1"<<endl;
    cin>>data;
    head=addToEmpty(head,data);
    for(i=1;i<n;i++){
        cout<<"Enter the data for node "<<i+1<<endl;
        cin>>data;
        head=addAtEnd(head,data);
    }
    return head;

};
//Delete first Node of linked list
struct Node *DelFNode(struct Node *head){
    head=head->next;
    free(head->prev);
    head->prev=NULL;
    return head;
};
struct Node *DelLNode(struct Node *head){
    struct Node *temp=head;
    struct Node *temp2;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    return head;
};
void Printlist(struct Node *head){
    struct Node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
struct Node *DelANode(struct Node *head,int pos){
    struct Node *temp=head;
    struct Node *temp2;
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    return head;
};
//Reverse the Linked List
struct Node *ReverseNode(struct Node *head){
    struct Node *ptr1=head;
    struct Node *ptr2=ptr1->next;
    ptr1->next=NULL;
    ptr1->prev=ptr2;
    while(ptr2!=NULL){
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
    return head;
};
int main(){
    struct Node *head=NULL;
    int pos;
    //int pos=2;
    //head=addToEmpty(head,45);
    //head=addAtBegg(head,56);
    //head=addAtEnd(head,8);
    //head=addAtPos(head,23,pos);
    head=createList(head);
    cout<<endl;
    cout<<"The Elements in Linked List are:"<<endl;
     Printlist(head);
     cout<<endl;
     cout<<"Delete First Element of linked List"<<endl;
    head=DelFNode(head);
    Printlist(head);
    cout<<endl;
    cout<<"Delete Last Element of Linked List."<<endl;
    head=DelLNode(head);
    Printlist(head);
    cout<<endl;
    cout<<"Reverse of Linked List are:"<<endl;
    //cout<<"Delete Node from any Position:"<<endl;
    //cout<<"Enter the position to delete The Node:"<<endl;
    //cin>>pos;
    //head=DelANode(head,pos);
    //Printlist(head);
    head=ReverseNode(head);
    Printlist(head);


    return  0;
}
