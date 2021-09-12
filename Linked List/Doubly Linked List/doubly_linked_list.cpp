//Implement Doubly linked list
#include<iostream>
using namespace std;
class Node
{
public:
    int key;
    int data;
    Node* next;
    Node* previous;
    Node()
    {
     key=0;
     data=0;
     next=NULL;
     previous=NULL;
    }
    Node(int k,int d)
    {
        key=k;
        data=d;
    }
};
class DoublyLinkedList
{
    public:
        Node* head;
    DoublyLinkedList()
    {
      head=NULL;
    }
    DoublyLinkedList(Node* n)
    {
        head=n;
    }
    //1. Check if Node exists key value
    Node* nodeExists(int k)
    {
        Node* temp=NULL;
        Node* ptr=head;
        while(ptr!=NULL){
            if(ptr->key==k){
                temp=ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }
    //2.Append node to the linked list
    void appendNode(Node* n)
    {
        if(nodeExists(n->key)!=NULL)
            {
            cout<<"Node is already exists."<<n->key<<"Append another node with different key value"<<endl;
        }
        else
            {
                if(head==NULL)
                    {
                    head=n;
                    cout<<"Node is appended."<<endl;
                }
                else{
                    Node* ptr=head;
                    while(ptr->next!=NULL)
                    {
                        ptr=ptr->next;
                    }
                    ptr->next=n;
                    n->previous=ptr;
                    cout<<"Node Appended"<<endl;
                }

        }
    }
    //Prepend node in linked list
    void prepend(Node* n)
    {
        if(nodeExists(n->key)!=NULL)
         {
           cout<<"Node is already exists."<<n->key<<"Append another node with different key value"<<endl;
         }
         else{
            head->previous=n;
            n->next=head;
            head=n;
            cout<<"Node is prepended"<<endl;
         }
    }
    //Insert Node after in linked list
    void InsertNodeAfter(int k,Node* n)
    {
        Node* ptr=nodeExists(k);
        if(ptr==NULL)
            {
            cout<<"No Node Exists the key value:"<<k<<endl;
        }
        else{
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node already exists the key value:"<<n->key<<"Append another node with different key value";
            }
            else
                {
                Node* nextNode=ptr->next;
                //NOde inserted at the end
                if(nextNode==NULL)
                {
                    ptr->next=n;
                    n->previous=ptr;
                    cout<<"Node Inserted at the end."<<endl;
                }
                //Node Inserted at the between
                else{
                 n->next=nextNode;
                 nextNode->previous=n;
                 n->previous=ptr;
                 ptr->next=n;
                 cout<<"Node Inserted at the between."<<endl;
                }
            }
        }
    }
    //Delete Node by key
    void deleteNode(int k){
    Node* ptr=nodeExists(k);
    if(ptr==NULL){
        cout<<"NO Node exists with key value"<<k<<endl;

    }
    else{
        if(head==NULL)
            {
            cout<<"Doubly Linked list is already empty.can't delete"<<endl;
        }
        else if(head!=NULL)
            {
            if(head->key==k)
                {
                head=head->next;
                cout<<"Node UNLINKED with key value"<<k<<endl;
            }
            else
                {
                Node* nextNode=ptr->next;
                Node* prevNode=ptr->previous;
                //deleting at the end
                if(nextNode==NULL)
                {
                    prevNode->next=NULL;
                    cout<<"Node deleted at the end"<<endl;
                }
                //deleting at the between
                else
                    {
                    prevNode->next=nextNode;
                    nextNode->previous=prevNode;
                    cout<<"Node deleted in between."<<endl;
                }
            }
        }
    }
    }
    //6. Update Node
    void UpdateNode(int k,int d)
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
    //7.printing
    void printList()
    {
        if(head==NULL)
            {
            cout<<"No pointer exists in Linked List."<<endl;
        }
        else{
            cout<<"Doubly linked list value are:"<<endl;
            Node*temp=head;
            while(temp!=NULL)
            {
                cout << "(" << temp -> key << "," << temp -> data << ") --> ";
                temp=temp->next;
            }
        }
    }

};
int main()
{
    DoublyLinkedList s;
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
            s.appendNode(n1);
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
            s.InsertNodeAfter(k1,n1);
            break;
         case 4:
             cout<<"Delete Node By key operation-\nEnter key of node to be deleted:"<<endl;
             cin>>k1;
             s.deleteNode(k1);
             break;
         case 5:
            cout<<"Update Node By key operation -\n Enter key and new data to be updated"<<endl;
            cin>>key1;
            cin>>data1;
            s.UpdateNode (key1,data1);
            break;
         case 6:
            s.printList();
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
