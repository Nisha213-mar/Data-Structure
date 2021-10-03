<h1>Infix to Prefix :</h1>
<h2>We use the same to convert Infix to Prefix.</h2>
<h3>Step 1: Reverse the infix expression i.e A+B*C will become C*B+A. Note while reversing each '(' will become ')' and each ')' becomes '('.</h3>
<h3>Step 2: Obtain the “nearly” postfix expression of the modified expression i.e CB*A+.</h3>
<h3>Step 3: Reverse the postfix expression.</h3>
<h2>Here is my code :</h2>

```cpp
//Implementation of Infix to prefix
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
bool isOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
        return true;
    }
    else{
        return false;
    }
}
int precedence(char c){
    if(c=='^')
        return 3;
    else if(c == '*' || c== '/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}
string INfixToPrefix(stack<char> s,string infix){
    string prefix;
    reverse(infix.begin(),infix.end());
    for(int i=0;i<infix.length();i++){
        if(infix[i]=='('){
            infix[i]=')';
           }
        else if(infix[i]==')'){
            infix[i]='(';
        }
    }
    for(int i=0;i<infix.length();i++){
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z')){
            prefix+=infix[i];
        }
        else if(infix[i]=='('){
                    s.push(infix[i]);
                }
        else if(infix[i]==')'){
            while((s.top()!='(') && (!s.empty())){
                    prefix+=s.top();
                    s.pop();
                  }
                  if(s.top()=='('){
                        s.pop();
                     }
        }
        else if(isOperator(infix[i])){
            if(s.empty()){
                s.push(infix[i]);
            }
            else{
             if(precedence(infix[i])>precedence(s.top())){
                s.push(infix[i]);
             }
             else if(precedence(infix[i])==precedence(s.top())&&(infix[i]=='^')){
                    while(precedence(infix[i])==precedence(s.top())&&(infix[i]=='^')){
                        prefix+=s.top();
                        s.pop();
                    }
                    s.push(infix[i]);

             }
             else if(infix[i]==precedence(s.top())){
                s.push(infix[i]);
             }
             else{
                while((!s.empty())&&(precedence(infix[i])<precedence(s.top()))){
                    prefix+=s.top();
                    s.pop();
                }
                s.push(infix[i]);
             }
             }

        }
        }
        while(!s.empty()){
            prefix+=s.top();
            s.pop();
        }
        reverse(prefix.begin(),prefix.end());

    return prefix;
}
int main(){
    string infix,prefix;
    cout<<"Enter a Infix expression:"<<endl;
    cin>>infix;
    stack<char> stack;
    cout<<"Infix Expression:"<<infix<<endl;
    prefix=INfixToPrefix(stack,infix);
    cout<<endl<<"Prefix Expression:"<<prefix;
    return 0;
}

```
<h1>Prefix to Infix</h1>
<h2>Algorithm for Prefix to Infix:</h2>
<h3>1. Read the Prefix expression in reverse order (from right to left)</h3>
<h3>2 . If the symbol is an operand, then push it onto the Stack.</h3>
<h3>3. If the symbol is an operator, then pop two operands from the Stack. ...</h3>
<h3>4. Repeat the above steps until end of Prefix expression.</h3>
<h2>Here is my code:</h2>

```cpp
//Implementation of prefix to Infix
#include<iostream>
#include<stack>
using namespace std;
bool isOperand(char c){
    if((c>='a'&& c<='z')||(c>='A' && c<='Z')){
        return true;
    }
    else{
        return false;
    }
}
string PrefixToInfix(string prefix){
    stack<string> s;
    for(int i=prefix.length()-1;i>=0;i--){
        if(isOperand(prefix[i])){
            string op(1,prefix[i]);
            s.push(op);
        }
        else{
            string op1=s.top();
            s.pop();
            string op2=s.top();
            s.pop();
            s.push("("+ op1 +prefix[i]+ op2+")");
        }
    }
    return s.top();
}
int main(){
    string infix,prefix;
    cout<<"Enter Prefix Expression:"<<endl;
    cin>>prefix;
    cout<<"Prefix Expression:"<<prefix<<endl;
    infix=PrefixToInfix(prefix);
    cout<<endl<<"Infix Expression:"<<infix;
    return 0;
}

```