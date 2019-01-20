/*
  Yousef Jarrar
  Student ID: 005845836
  CSE 330 - Murphy Summer 18
  Lab 1B
 Algorithim finding equivalent postfix expression Y

 (A-B)*C(D(J-D))
 SYMBOL     STACK      EXPRESSION
 (            (             -
 (            ((            -
 A            ((            A
 -            ((-           A
 B            ((-           AB
 )            (             AB-
 *            (*            AB-
 C            (*            AB-C
 (            (*(           AB-C
 D            (*(           AB-CD
 (            (*((          AB-CD
 J            (*((          AB-CDJ
 -            (*((-         AB-CDJ
 D            (*((-         AB-CDJD
 )            (*(           AB-CDJD-
 )            (*            AB-CDJD-
  )           -             AB-CDJD-*

 */
#include<iostream>
#include<stack>
#include<string>

using namespace std;

// Function to verify whether an operator has higher precedence over other
int hiPrecedence(char op1, char op2);

string InfixToPostfix(string expression);

// Function to verify whether a character is operator symbol or not.
bool Operator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
bool Operand(char C);

int main() {
  string expression;
  cout<<"Enter Infix Expression n: ";
string postfixY;
    getline(cin,expression);
    string postfix = InfixToPostfix(expression);
    cout<<"Output = "<<postfix << endl;

    return 0;
  }

// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression) {
    // Stack from Standard template library.
    stack<char> S;
    string postfix = " "; // Initialize postfix as empty string.
    for(int i = 0;i< expression.length();i++) {

      // Scanning each character from left.If character is a delimitter, keep going.
      if(expression[i] == ' ' || expression[i] == ',')
      continue;

// If character is operator, pop two elements from stack, perform operation and push the result back.
     else if(Operator(expression[i])) {
          while(!S.empty() && S.top() != '(' && hiPrecedence(S.top(),expression[i]))
              {

               postfix+= S.top();
                S.pop();
           }
            S.push(expression[i]);
        }

        // Else if character is an operand
        else if(Operand(expression[i])) {
            postfix +=expression[i];
        }

       else if (expression[i] == '(' ) {

            S.push(expression[i]);
        }

       else if(expression[i] == ')') {

            while(!S.empty() && S.top() != '(') {
                postfix += S.top();
                S.pop();
            }

            S.pop();
        }
    }

    while(!S.empty()) {

        postfix += S.top();

        S.pop();

    }

return postfix;

}

// Function to verify whether a character is letter or digit.
bool Operand(char C) {

   if(C >= '0' && C <= '9') return true;

  else if(C >= 'a' && C <= 'z') return true;

  else if(C >= 'A' && C <= 'Z') return true;

    else

    return false;
}

// Function to verify whether a character is operator symbol or not.
bool Operator(char C) {

    if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
    return true;

    else
    return false;
}

// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op) {

    if(op == '$') return true;

    else
    return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOpWeight(char op) {
    int weight = -1;

    switch(op) {
    case '+':
// Function to convert Infix expression to postfixstring InfixToPostfix(string exp);

    case '-':

        weight = 1;

    case '*':

    case '/':

        weight = 2;

    case '$':

        weight = 3;
    }

    return weight;

}

// Function to perform an operation and return output.
int hiPrecedence(char op1, char op2) {

    int op1Weight = GetOpWeight(op1);
    int op2Weight = GetOpWeight(op2);

// If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
     if(op1Weight == op2Weight) {

        if(IsRightAssociative(op1)) return false;

        else return true;
    }

    return (op1Weight > op2Weight ? true: false);
}
