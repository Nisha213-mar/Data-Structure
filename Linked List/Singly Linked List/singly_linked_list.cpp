#include<iostream>
using namespace std;
class Node
{
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
class SinglyLinkedList {
  public:
    Node * head;

  SinglyLinkedList() {
    head = NULL;
  }
  SinglyLinkedList(Node * n) {
    head = n;
  }

    //1.Check if node exist using key value
    Node* nodeExists(int k)
    {
        Node*temp=NULL;
        Node*ptr=head;
        while(ptr!=NULL){
            if(ptr->key==k){
                temp=ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }
    //2.Append the node to the list
    void appended(Node*n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node is already exists."<<n->key<<"Append another node with different key value"<<endl;
        }
        else if(head==NULL){
            head=n;
            cout<<"Node is appended."<<endl;
        }
        else{
            Node*ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=n;
            cout<<"Node is appended."<<endl;
        }
    }
    //3.Prepend Node - Attach one Node at the start
    void prepend(Node*n)
    {
         if(nodeExists(n->key)!=NULL)
         {
           cout<<"Node is already exists."<<n->key<<"Append another node with different key value"<<endl;
         }
         else
            n->next=head;
            head=n;
            cout<<"Node is prepended."<<endl;
    }
    //4.Insert a Node after a particular node in  the list
    void insertNOdeAfter(int k,Node*n)
    {
        Node* ptr=nodeExists(k);
        if(ptr==NULL){
            cout<<"NO node exists with this key value."<<k<<endl;
        }
        else{
            if(nodeExists(n->key)!=NULL){
                cout<<"Node alreay exists with key value:"<<n->key<<"Append another node with differennt key value."<<endl;

            }
            else{
                n->next=ptr->next;
                ptr->next=n;
            }
        }
    }
    //5.Delete Node by Unique key
    void deletenodekey(int k)
    {
        if(head==NULL)
            {
            cout<<"singly linked list is already empty.can't deleted"<<endl;
        }
        else if(head!=NULL)
        {
            if(head->key==k){
                head=head->next;
                cout<<"Node Unlinked with key value:"<<k<<endl;
            }
            else{
                Node* temp=NULL;
                Node* prevptr=head;
                Node* currentptr=head->next;
                while(currentptr!=NULL){
                    if(currentptr->key==k)
                    {
                        temp=currentptr;
                        currentptr=NULL;
                    }
                    else
                    {
                        prevptr=prevptr->next;
                        currentptr=currentptr->next;
                    }
                }
                if(temp!=NULL)
                {
                    prevptr->next=temp->next;
                    cout<<"Node unlinked with key value: "<<k<<endl;
                    }
                    else{
                        cout<<"Node doesn't exit with key value:"<<k<<endl;
                    }
            }
        }
    }
    //6UPdate NOde By key
    void UpdateNodeBykey(int k,int d)
    {
        Node*ptr=nodeExists(k);
        if(ptr!=NULL){
            ptr->data=d;
            cout<<"Node data updated successfully"<<endl;
        }
        else{
            cout<<"Node doesn't exists with key value:"<<endl;
        }
    }
    //7.Printing
    void printlist()
    {
        if(head==NULL)
            {
            cout<<"No pointer exists in Linked List."<<endl;
        }
        else{
            cout<<"Singly linked list value are:"<<endl;
            Node*temp=head;
            while(temp!=NULL)
            {
                cout << "(" << temp -> key << "," << temp -> data << ") --> ";
                temp=temp->next;
            }
        }
    }
};
int main(){
    SinglyLinkedList s;
    int option;
    int key1,k1,data1;
    do{
        cout<<"\nThe operation you want to perform in list?select option no enter 0 to exit."<<"\n";
        cout<<"1. appedNode()"<<endl;
         cout<<"2. PrependNode()"<<endl;
         cout<<"3. insertNodeAfter()"<<endl;
         cout<<"4. deleteNodeBykey()"<<endl;
         cout<<"5. UpdateNodeBykey()"<<endl;
         cout<<"6. print()"<<endl;
         cout<<"7. clear screen"<<endl;
         cin>>option;
         Node* n1=new Node();
         //Node n1;
         switch(option)
         {
         case 0:
            break;
         case 1:
            cout<<"Appended Node operation\nEnter key and data of node to be appended"<<endl;
            cin >>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.appended(n1);
            break;
         case 2:
             cout<<"prepend Node operation\nEnter key and data of node to be appended"<<endl;
            cin >>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.prepend(n1);
            break;
         case 3:
            cout<<"Insert Node After operation \nEnter key of existing node after which you want to insert the new node"<<endl;
            cin>>k1;
            cout<<"Enter key and data of new node"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=k1;
            n1->data=data1;
            s.insertNOdeAfter(k1,n1);
            break;
         case 4:
             cout<<"Delete Node By key operation-\nEnter key of node to be deleted:"<<endl;
             cin>>k1;
             s.deletenodekey(k1);
             break;
         case 5:
            cout<<"Update Node By key operation -\n Enter key and new data to be updated"<<endl;
            cin>>key1;
            cin>>data1;
            s.UpdateNodeBykey(key1,data1);
            break;
         case 6:
            s.printlist();
            break;
         case 7:
            system("cls");
            break;
         default:
            cout<<"Enter proper option number:"<<endl;
         }

         }while(option!=0);
         return 0;

}


