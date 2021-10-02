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
<h1>Here is my Code</h3>
