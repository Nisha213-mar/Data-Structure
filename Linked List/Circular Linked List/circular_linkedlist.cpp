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
class circularLinkedList
{
public:
    Node* head;
    circularLinkedList()
    {
        head=NULL;
    }
    //1.Check if nodes exist in key value
    Node* nodeExists(int k)
    {
        Node* temp=NULL;
        Node*ptr=head;
        if(ptr==NULL)
        {
            return temp;
        }
        else
            {
            do
            {
                if(ptr->key==k)
                    {
                    temp=ptr;
                }
                ptr=ptr->next;
            }while(ptr!=head);
            return temp;
        }
    }
    //2.Append a node to the list
    void appendNode(Node*new_node)
    {
        if(nodeExists(new_node->key)!=NULL)
        {
            cout<<"Node is already exists."<<new_node->key<<"Append another node with different key value"<<endl;
        }
        else{
            if(head==NULL)
                {
                head=new_node;
                new_node->next=head;
                cout<<"Node Appended at first position."<<endl;
            }
            else{
                Node* ptr=head;
                while(ptr->next!=head)
                    {
                    ptr=ptr->next;
                }
                ptr->next=new_node;
                new_node->next=head;
                cout<<"Node appended."<<endl;
            }
        }
    }
    //3.prepend Node-Attach a node to the start
    void prependNode(Node* new_node)
    {
         if(nodeExists(new_node->key)!=NULL)
         {
           cout<<"Node is already exists."<<new_node->key<<"Append another node with different key value"<<endl;
         }
         else
            {
            Node* ptr=head;
            while(ptr->next!=head)
                {
            ptr=ptr->next;
         }
         ptr->next=new_node;
         new_node->next=head;
         head=new_node;
         cout<<"Node prepended."<<endl;
         }
    }
    //4.Insert a node after a particular node in list
    void insertNode(int k,Node *new_node )
    {
        Node* ptr=nodeExists(k);
        if(ptr==NULL){
            cout<<"No Node Exists the key value:"<<k<<endl;
        }
        else
            {
            if(nodeExists(new_node->key)!=NULL)
                {
                cout<<"Node already exists with key value :"<<new_node->key<<"Append another node with different key value"<<endl;
            }
            else
                {
                if(ptr->next==head)
                    {
                    new_node->next=head;
                    ptr->next=new_node;
                    cout<<"Node inserted at the end."<<endl;
                }
                else
                    {
                    new_node->next=ptr->next;
                    ptr->next=new_node;
                    cout<<"Node Inserted in between."<<endl;
                }
            }
        }
    }
    //5.Delete Node by Unique key
    void deleteNodeByKey(int k)
    {
        Node* ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"No node exists with key value of:"<<k<<endl;
        }
        else{
            if(ptr==head)
            {
                if(head->next==NULL)
                    {
                    head=NULL;
                    cout<<"Head node is unlinked and list is empty.";
                }
                else
                    {
                    Node* ptr1=head;
                    while(ptr->next!=head)
                        {
                        ptr1=ptr1->next;
                    }
                    ptr1->next=head->next;
                    head=head->next;
                    cout<<"Node unlinked with keys value:"<<k<<endl;
                }
            }
            else{
                Node* temp=NULL;
                Node* prevptr=head;
                Node* currentptr= head->next;
                while(currentptr!=NULL)
                    {
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
                prevptr->next=currentptr->next;
                cout<<"Node is unlinked with key value."<<k<<endl;
            }
        }
    }
    //6.Update Node
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
    //7th printing
    void printList()
    {
        if(head==NULL)
            {
            cout<<"No pointer exists in Linked List."<<endl;
        }
        else{
            cout<<"singly linked list value are:"<<endl;
            Node*temp=head;
            do
            {
                cout << "(" << temp -> key << "," << temp -> data << ") --> ";
                temp=temp->next;
            }while(temp!=head);
        }
    }

};
int main()
{
    circularLinkedList s;
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
            s.prependNode(n1);
            break;
         case 3:
            cout<<"Insert Node After operation \nEnter key of existing node after which you want to insert the new node"<<endl;
            cin>>k1;
            cout<<"Enter key and data of new node"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=k1;
            n1->data=data1;
            s.insertNode(k1,n1);
            break;
         case 4:
             cout<<"Delete Node By key operation-\nEnter key of node to be deleted:"<<endl;
             cin>>k1;
             s.deleteNodeByKey(k1);
             break;
         case 5:
            cout<<"Update Node By key operation -\n Enter key and new data to be updated"<<endl;
            cin>>key1;
            cin>>data1;
            s.UpdateNode(key1,data1);
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

