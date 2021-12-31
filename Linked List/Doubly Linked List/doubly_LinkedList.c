//Implementation of Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}Node;
Node *head=NULL;
Node *tail=NULL;
Node *createElement(int data){
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    if(head==NULL){
        head=tail=temp;
        tail->next=NULL;
        head->prev=NULL;
        printf("Inserted successfully.\n");
    }
    else{
        tail->next=temp;
        temp->next=NULL;
        temp->prev=tail;
        tail=temp;
        printf("Successfully Inserted.\n");
    }

}
Node *CreateAtFirst(int data){
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    if(head==NULL){
        head=tail=temp;
        tail->next=NULL;
        head->prev=NULL;
        printf("Inserted successfully.\n");
    }
    else{
        temp->next=head;
        head->prev=temp;
        temp->prev=NULL;
        head=temp;
        printf("Successfully Inserted.\n");
    }

}
void DisplayForward(){
    Node *dhead=head;
    if(head==NULL)
        printf("List is Empty.\n");
    else{
    while(dhead!=NULL){
        printf("%d->",dhead->data);
        dhead=dhead->next;
    }
    }
}
void DisplayBackward(){
    Node *dtail=tail;
    if(tail==NULL)
        printf("List is Empty.\n");
    else{
        while(dtail!=NULL){
            printf("%d->",dtail->data);
            dtail=dtail->prev;
        }
    }
}
Node *InserAtAnyPOs(int data,int item){
    Node *temp=(Node *)malloc(sizeof(Node));
    Node *dhead=head;
    int flag=0;
    while(dhead!=NULL){
        if(dhead->data==item){
            flag=1;
            break;
        }
        dhead=dhead->next;
    }
    if(flag==0)
        printf("Item Not Found");
    temp->data=data;
    temp->next=dhead->next;
    if(dhead->next!=NULL){
        dhead->next->prev=temp;
    }
    else
        tail=temp;
    dhead->next=temp;
    temp->prev=dhead;
}
Node *Delete(int data){
    Node* temp=(Node*)malloc(sizeof(Node));
    Node *dhead=head;
    int flag=0;
    while(dhead!=NULL){
        if(dhead->data==data){
            flag=1;
            break;
        }
        dhead=dhead->next;
    }
    if(flag==0)
        printf("Item Not Found");
    temp=dhead;
    if(temp->prev!=NULL)
        temp->prev->next=temp->next;
    else
        head=head->next;
    if(temp->next!=NULL)
        temp->next->prev=temp->prev;
    else
        tail=tail->prev;
    if(head!=NULL)
        head->prev=NULL;
    if(tail!=NULL)
        tail->next=NULL;
    free(temp);
}
int main(){
    int data,option,item;
    do{
       printf("\nThe operation you want to perform in list?select option no enter 0 to exit\n");
        printf("1.Insert at Last.\n");
        printf("2.Insert at First.\n");
        printf("3.Forward Traversal.\n");
        printf("4.Backward Traversal.\n");
        printf("5.Insert at any position.\n");
        printf("6.Delete Element.\n");
        printf("7.Count.\n");
        printf("8. Element.\n");
        scanf("%d",&option);
        switch(option){
        case 0:
            break;
        case 1:
            printf("Enter data to Insert at last:\n");
            scanf("%d",&data);
            createElement(data);
            break;
        case 2:
            printf("Enter data to Insert at first:\n");
            scanf("%d",&data);
            CreateAtFirst(data);
            break;
        case 3:
            DisplayForward();
            break;
        case 4:
            DisplayBackward();
            break;
        case 5:
            printf("Enter the data you want to Insert.\n");
            scanf("%d",&data);
            printf("Enter the data after which you want to insert.\n");
            scanf("%d",&item);
            InserAtAnyPOs(data,item);
            break;
        case 6:
            printf("Enter the data you want to delete:\n");
            scanf("%d",&data);
            Delete(data);
            break;
        default:
            printf("Invalid Option.\n");

        }
    }while(option!=0);
    return 0;

}
