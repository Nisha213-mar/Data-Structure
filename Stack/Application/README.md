<h1>1. Reversing of Stack :</h1>
<h2>Here is my code :</h2>

```cpp
//1.REversing of array Using Stack
#include<iostream>
#include<stack>
#include<string.h>
#define MAX 10
using namespace std;
void Reverse(char *c,int n){
    int i=0;
    stack<char> s;
    for(i=0;i<n;i++){
        s.push(c[i]);
    }
    for(i=0;i<n;i++){
        c[i]=s.top();
        s.pop();
    }
    //return c[i];
}
int main(){
    char c[20];
    cout<<"Input String :"<<endl;
    cin>>c;
    Reverse(c, strlen(c));
    cout<<"Output = "<<c<<endl;
}


```
<h1>2. Parenthesis Checking Through Stack :</h1>
<h2>Here is my code :</h2>

```cpp
//Parenthesis checking through stack
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
void Parenthesis_check(char *c,int n){
    int i=0;
    stack<char> s;
    for(i=0;i<n;i++){
        if(c[i]=='('||c[i]=='{'||c[i]=='['){
            s.push(c[i]);
           }
        else{
            if(c[i]==')'||'}'||']'){
                if(!s.empty() && s.top()=='('||'{'||'['){
                    s.pop();
                   }
                else{
                    cout<<"String is Not Balance. "<<endl;
                    break;
                }
            }
        }
    }
    if(!s.empty())
        cout<<"String is Not Balance."<<endl;
    else
        cout<<"String is Balance."<<endl;
}
int main(){
    char c[20];
    cout<<"Enter string :"<<endl;
    cin>>c;
    Parenthesis_check(c,strlen(c));
}

```