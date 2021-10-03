<h1>Prefix To Postfix :</h1>
<h2>Algorithm for Prefix to Postfix:</h2>
<h3>1. Read the Prefix expression in reverse order (from right to left)</h3>
<h3>2. If the symbol is an operand, then push it onto the Stack.</h3>
<h3>3. If the symbol is an operator, then pop two operands from the Stack. ...</h3>
<h3>4. Repeat the above steps until end of Prefix expression.</h3>
<h2>Here is my code :</h2>

```cpp
//Implementation of Prefix to Postfix
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
string PrefixToPostfix(string prefix){
    stack <string> s;
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
            s.push(op1+op2+prefix[i]);
        }
    }
    return s.top();
}
int main(){
    string prefix,postfix;
    cout<<"Enter a Prefix Expression:"<<endl;
    cin>>prefix;
    cout<<"Prefix Expression:"<<prefix<<endl;
    postfix=PrefixToPostfix(prefix);
    cout<<endl<<"Postfix Expression:"<<postfix;
    return 0;
}

```
<h1>Postfix To Prefix :</h1>
<h2>Algorithm for Postfix to Prefix:</h2>
<h3>1. Read the Postfix expression from left to right.</h3>
<h3>2. If the symbol is an operand, then push it onto the Stack.</h3>
<h3>3. If the symbol is an operator, then pop two operands from the Stack. ...</h3>
<h3>4. Repeat the above steps until end of Prefix expression.</h3>
<h2>Here is my code :</h2>

```cpp
//Implementation of postfix to prefix Expression
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
string PostfixToPrefix(string postfix){
    stack<string> s;
    for(int i=0;i<postfix.length();i++){
        if(isOperand(postfix[i])){
            string op(1,postfix[i]);
            s.push(op);
        }
        else{
            string op1=s.top();
            s.pop();
            string op2=s.top();
            s.pop();
            s.push(postfix[i]+ op2+ op1);
        }
    }
    return s.top();
}
int main(){
    string prefix,postfix;
    cout<<"Enter a Postfix Expression:"<<endl;
    cin>>postfix;
    cout<<"Postfix Expression :"<<postfix<<endl;
    prefix=PostfixToPrefix(postfix);
    cout<<"Prefix Expression:"<<prefix<<endl;
    return 0;
}

```