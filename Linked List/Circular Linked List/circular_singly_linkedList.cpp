#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};
struct Node *addToEmpty(int data){
    struct Node *temp=new Node;
    temp->data=data;
    temp->next=temp;
    return temp;
};
void printList(struct Node *tail){
    struct Node *p=tail->next;
    do{
        cout<<tail->next->data<<" ";
        tail=tail->next;
    }while(p!=tail->next);
}
struct Node *addAtBegg(struct Node *tail,int data){
    struct Node *newp=new Node;
    newp->data=data;
    newp->next=tail->next;
    tail->next=newp;
    return tail;
};
struct Node *addAtEnd(struct Node *tail,int data){
    struct Node *newp=new Node;
    newp->data=data;
    newp->next=tail->next;
    tail->next=newp;
    tail=tail->next;
    return tail;
};
struct Node *addAtPos(struct Node *tail,int data,int pos){
    struct Node *newp=new Node;
    newp->data=data;
    struct Node *temp=tail;
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    if(temp==tail){
        newp->next=tail->next;
        tail->next=newp;
        tail=tail->next;
    }
    else{
    newp->next=temp->next;
    temp->next=newp;
    }
    return tail;
};
struct Node * createList(struct Node *tail){
    int n,i,data;
    cout<<"Enter the Number of Nodes of Linked List:"<<endl;
    cin>>n;
    if(n==0)
        return tail;
    cout<<"Enter the data of Node 1:"<<endl;
    cin>>data;
    tail=addToEmpty(data);
    for(i=1;i<n;i++){
        cout<<"Enter the Element of Node "<<i+1<<endl;
        cin>>data;
        tail=addAtEnd(tail,data);
    }
    return tail;
};
struct Node *DelFNode(struct Node *tail){
    struct Node *temp=tail;
    temp=tail->next;
    tail->next=temp->next;
    free(temp);
    return tail;
};
struct Node *DelLNode(struct Node *tail){
    if(tail==NULL)
        return tail;
    struct Node *temp=tail->next;
    if(tail->next==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
    return tail;
};
struct Node *DelANode(struct Node *tail,int pos){
    if(tail==NULL)
        return tail;
    struct Node *temp=tail->next;
    if(tail->next==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    while(pos>2){
        temp=temp->next;
        pos--;
    }
    struct Node *temp2;
    temp2=temp->next;
    temp->next=temp2->next;
    if(temp2==tail)
        tail=temp;
    free(temp2);
    temp2=NULL;
    return tail;
};
//count the element
void count(struct Node *tail){
struct Node *temp=tail->next;
int c=0;
while(temp!=tail){
    c++;
    temp=temp->next;
}
c++;
cout<<"Number of Elements in List are:"<< c <<endl;
}
//search the Element
int SearchElements(struct Node *tail,int elememt){
    int index=0;
    struct Node *temp;
    if(tail==NULL)
        return -2;
        temp=tail->next;
    do{
        if(temp->data==elememt)
            return index;
        temp=temp->next;
        index++;
    }while(temp!=tail->next);
    return -1;
}
int main(){
    struct Node *tail;
    int pos,ele;
    /*tail=addToEmpty(34);
    printList(tail);
    cout<<endl;
    tail=addAtBegg(tail,45);
   printList(tail);
    cout<<endl;
    tail=addAtEnd(tail,8);
    printList(tail);
    cout<<endl;
    int pos;
    cout<<"Enter the position to delete Element"<<endl;
    cin>>pos;
    tail=addAtPos(tail,7,pos);
    printList(tail);*/
    tail=createList(tail);
    printList(tail);
    cout<<endl;
    cout<<"Delete first Node of List"<<endl;
    tail=DelFNode(tail);
    printList(tail);
    cout<<endl;
    cout<<"Delete Last Node of List"<<endl;
    tail=DelLNode(tail);
    printList(tail);
    cout<<endl;
    cout<<"Delete Node at any Position:"<<endl;
    /*cout<<"Enter the position to delete Element"<<endl;
    cin>>pos;
    tail=DelANode(tail,pos);
    printList(tail);*/
    cout<<"count the Number of Elements in list"<<endl;
    count(tail);
    cout<<endl;
    cout<<"Search the Element in lIst:"<<endl;
    cout<<"Enter the Element to Search in Linked List:"<<endl;
    cin>>ele;
    int index=SearchElements(tail,ele);
    if(index==-1)
        cout<<"Element Not Found."<<endl;
    else if(index==-2)
        cout<<"Linked List is Empty."<<endl;
    else
        cout<<"Element "<<ele<<" is at index "<<index+1<<endl;
    return 0;

}
