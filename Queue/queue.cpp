//All Queue Implementation
#include<iostream>
using namespace std;
class Queue{
private:
    int front;
    int rear;
    int arr[5];
public:
    Queue(){
        int rear = -1;
        int front= -1;
        for(int i=0;i<5;i++){
            arr[i]=0;
        }
    }
    bool isempty(){
        if(front==-1 && rear==-1)
            return true;
        else
            return false;
    }
    bool isfull(){
        if(rear==4)
            return true;
        else
            return false;
    }
    bool Enqueue(int val){
        if(isfull()){
            cout<<"Queue is full."<<"\n";
            return 0;
        }
        else if(isempty())
            {
            rear=front=0;
        }
        else{
            rear++;
        }
        arr[rear]=val;
    }
    bool Dequeue(){
        int x=0;
        if(isempty()){
            cout<<"Queue is Empty."<<"\n";
            return 0;
        }
        else if(rear==front){
            x=arr[front];
            arr[front]=0;
            rear=front=-1;
        }
        else{
            x=arr[front];
            arr[front]=0;
            front++;
        }
        return x;
    }
    bool count(){
        return(rear-front+1);
    }
    bool display(){
        cout<<"All values of Queue are :"<<"\n";
        for(int i=0;i<5;i++){
            cout<<arr[i]<<"\n";
        }
    }
};
int main()
{
    Queue q1;
    int value,option;
        do{
        cout<<"\nThe operation you want to perform in Queue?select option no enter 0 to exit."<<"\n";
        cout<<"1. Enqueue()"<<endl;
         cout<<"2. Dequeue()"<<endl;
         cout<<"3. isempty()"<<endl;
         cout<<"4. isfull()"<<endl;
         cout<<"5. count()"<<endl;
         cout<<"6. display()"<<endl;
         cout<<"7. clear screen"<<endl;
         cin>>option;
         switch(option){
         case 0:
            break;
         case 1:
             cout<<"Enter the value to add in Queue:"<<"\n";
             cin>>value;
             q1.Enqueue(value);
            break;
         case 2:
             cout<<"Dequeue function called - Dequeue value:"<<q1.Dequeue()<<"\n";
            break;
         case 3:
             if(q1.isempty())
                cout<<"Queue is Empty."<<"\n";
             else
                cout<<"Queue is not Empty."<<"\n";
            break;
         case 4:
             if(q1.isfull())
                cout<<"Queue if full."<<"\n";
             else
                cout<<"Queue is not full."<<"\n";
            break;
         case 5:
             cout<<"Count function is called- No of item in queue are:"<<q1.count()<<"\n";
            break;
         case 6:
             cout<<"Display function is called:"<<"\n";
             q1.display();
            break;
         case 7:
             system("cls");
            break;
         default:
            cout<<"Enter proper number."<<"\n";
         }

    }while(option!=0);
    return 0;
}
