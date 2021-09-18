/*#include<iostream>
#define MAX 18
using namespace std;
int stack_arr[MAX];
int top=-1;
int isFULL(){
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(int data){
    int i;
    top +=1;
    if(isFULL()){
            cout<<"stack Overflow."<<endl;
           exit(1);
    }
    for(i=top;i>0;i--)
        stack_arr[i]=stack_arr[i-1];
    stack_arr[0]=data;
}
int pop(){
    int value;
    if(isEmpty()){
        cout<<"Stack Underflow."<<endl;
        exit(1);
    }
    value=stack_arr[top];
    top=top-1;
    return value;
}
void print(){
    int i;
    if(top==-1){
        cout<<"stack Underflow."<<endl;
        return ;
    }
    for(i=top;i>=0;i--)
        cout<<stack_arr[i]<<" ";
    cout<<endl;
}
void prime_fact(int num){
    int i=2;
    while(num!=1){
        while(num%i==0){
            push(i);
            num=num/i;
        }
        i++;
    }
    cout<<"Prime Factors of the number in descending order are follows:"<<endl;
    while(top!=-1){
        cout<<pop()<<" ";
    }
}
void dec2bin(int n){
while(n!=0){
    push(n%2);
    n=n/2;
}
}

int main(){
    /*int data;
    push(1);
    push(7);
    data=pop();
    print();
    cout<<"Enter a Positive Integer."<<endl;
    cin>>data;
    cout<<"Prime factors of this number are:"<<endl;
    prime_fact(data);
    int dec;
    cout<<"Enter the decimal Number: "<<endl;
    cin>>dec;
    dec2bin(dec);
    print();
    return 0;
}*/
#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node *link;
};
struct Node *temp=NULL;
void push(){
    struct Node *temp;
    temp=new Node;
    cout<<"Enter Node data:"<<endl;
    cin>>temp->data;
    temp->link=top;
    top=temp;
}
