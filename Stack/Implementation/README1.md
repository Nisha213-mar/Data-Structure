<h1>Conversion :</h1>
<h1>Infix to postfix :-</h1>
<h2>Infix expressions are readable and solvable by humans. We can easily distinguish the order of operators, and also can use the parenthesis to solve that part first during solving mathematical expressions. The computer cannot differentiate the operators and parenthesis easily, that’s why postfix conversion is needed.

To convert infix expression to postfix expression, we will use the stack data structure. By scanning the infix expression from left to right, when we will get any operand, simply add them to the postfix form, and for the operator and parenthesis, add them in the stack maintaining the precedence of them.</h2>
<h3>Note: Here we will consider only {+, −,∗,/, ^} operators, other operators are neglected</h3>
<h1>Rules :</h1>
<h3>Begin</h3>
  <h3> initially push some special character say # into the stack</h3>
   <h3>for each character ch from infix expression, do</h3>
      <h3>if ch is alphanumeric character, then</h3>
         <h3>add ch to postfix expression</h3>
      <h3>else if ch = opening parenthesis (, then
         push ( into stack
      else if ch = ^, then            //exponential operator of higher precedence
         push ^ into the stack
      else if ch = closing parenthesis ), then
         while stack is not empty and stack top ≠ (,
            do pop and add item from stack to postfix expression
         done

         pop ( also from the stack) </h3>
      <h3>else
         while stack is not empty AND precedence of ch <= precedence of stack top element, do
            pop and add into postfix expression
         done

         push the newly coming character.
   done

   while the stack contains some remaining characters, do
      pop and add to the postfix expression
   done</h3>
   <h3>return postfix</h3>
<h3>End</h3>
<h1>Here is my Code</h1>
  <h4>https://github.com/Nisha213-mar/Data-Structure/blob/main/Stack/Implementation/stack1.cpp</h4>
<h1>Postfix to Infix :</h1>
<h2>Steps to Convert Postfix to Infix :</h2>
<h3>1. Read the symbol from the input . ...</h3>
<h3>2. If symbol is operand then push it into stack.</h3>
<h3>3. If symbol is operator then pop top 2 values from the stack.</h3>
<h3>4. this 2 popped value is our operand .</h3>
<h3>5. create a new string and put the operator between this operand in string.</h3>
<h3>6. push this string into stack.</h3>

```cpp
//Implementation of Postfix to Infix.
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
string PostfixToInfix(string postfix){
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
            s.push("("+ op2 +postfix[i]+ op1 + ")");
        }
    }
    return s.top();

}
int main(){
    string infix,postfix;
    cout<<"Enter a Postfix Expression:"<<endl;
    cin>>postfix;
    cout<<"Postfix Expression:"<<postfix<<endl;
    infix=PostfixToInfix(postfix);
    cout<<endl<<"Infix Expression:"<<infix;
    return 0;
}

```
