//All Stacks implementation
#include<iostream>
#include<string.h>

using namespace std;
class stack{
private:
    int top;
    int arr[5];
public:
    stack(){
        top=-1;
        for(int i=0;i<5;i++){
            arr[i]=0;
        }
    }
    bool isempty(){
        if(top==-1)
            return true;
        else
            return false;
    }
    bool isfull(){
        if(top==4)
            return true;
        else
            return false;
    }
    void push(int val){
        if(isfull()){
            cout<<"Stack Overflow"<<"\n";
        }
        else{
            top++;
            arr[top]=val;
        }
    }
    int pop(){
        if(isempty()){
            cout<<"Stack Underflow"<<"\n";
            return 0;
        }
        else{
            int popvalue=arr[top];
            arr[top]=0;
            top--;
            return popvalue;
        }
    }
    int count(){
        return(top+1);
    }
    int peek(int pos){
        if(isempty()){
            cout<<"Stack underflow"<<"\n";
            return 0;
        }
        else{
            return arr[pos];
        }

    }
    void change(int pos,int val){
        arr[pos]=val;
        cout<<"The value change at location :"<<pos<<"\n";
    }
    void display(){
        cout<<"All values of stack are: "<<"\n";
        for(int i=0;i<5;i++){
            cout<<arr[i]<<"\n";
        }
    }
};
int main(){
    stack s1;
    int option,position,value;
    do{
        cout<<"What operation do you want to perform? select option number.Ebnter 0 to exit from code."<<"\n";
        cout<<"1. push"<<"\n";
        cout<<"2. pop"<<"\n";
        cout<<"3. isempty()"<<"\n";
        cout<<"4. isfull()"<<"\n";
        cout<<"5. peek()"<<"\n";
        cout<<"6. count()"<<"\n";
        cout<<"7. change()"<<"\n";
        cout<<"8. display()"<<"\n";
        cout<<"9. Clear screen"<<"\n";
        cin>>option;
        switch(option)
        {
        case 0:
            break;
        case 1:
            cout<<"Enter value to push in stack:"<<"\n";
            cin>>value;
            s1.push(value);
            break;
        case 2:
            cout<<"Pop function called - popped value: "<<s1.pop()<<"\n";
            break;
        case 3:
            if(s1.isempty())
                cout<<"Stack is Empty."<<"\n";
            else
                cout<<"Stack is not Empty."<<"\n";
            break;
        case 4:
            if(s1.isfull())
                cout<<"Stack is full."<<"\n";
            else
                cout<<"Stack is not full."<<"\n";
            break;
        case 5:
            cout<<"Enter the position of item want to peek: "<<"\n";
            cin>>position;
            cout<<"Peek function called -"<<"\n"<<s1.peek(position)<<"\n";
            break;
        case 6:
            cout<<"Count function called - Number of items in the stack are :"<<s1.count()<<"\n";
            break;
        case 7:
            cout<<"Change function is called-"<<"\n";
            cout<<"Enter the position of stack to change :"<<"\n";
            cin>>position;
            cout<<"Enter the value of stack to put there :"<<"\n";
            cin>>value;
            s1.change(position,value);
            break;
        case 8:
            cout<<"Display function is called -"<<"\n";
            s1.display();
            break;
        case 9:
            system("cls");
            break;
        default:
            cout<<"Enter proper option number "<<"\n";


        }


    }while(option!=0);
return 0;
}
