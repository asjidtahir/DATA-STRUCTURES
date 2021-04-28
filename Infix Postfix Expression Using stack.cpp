#include<iostream>
#include<stack>
#include<string>
using namespace std;
string InfixToPostfix(string expression);    // Infix expression to postfix
int Precedence(char operator1, char operator2);      // check  higher precedence over other

bool IsOperator(char ch);                        // check character is operator symbol or not.
bool IsOperand(char ch);                  //check character is letter or numeric digit or not.

string InfixToPostfix(string expression)

{

    stack<char> St;   // stack liberary

    string postfix = " ";

    for (int i = 0; i < expression.length(); i++) 
    {





        if (expression[i] == ' ' || expression[i] == ',')

            continue;





        else if (IsOperator(expression[i]))

        {

            while (!St.empty() && St.top() != '(' && Precedence(St.top(), expression[i]))

            {

                postfix += St.top();

                St.pop();

            }

            St.push(expression[i]);

        }



        else if (IsOperand(expression[i]))

        {

            postfix += expression[i];

        }



        else if (expression[i] == '(')

        {

            St.push(expression[i]);

        }



        else if (expression[i] == ')')

        {

            while (!St.empty() && St.top() != '(') {

                postfix += St.top();

                St.pop();

            }

            St.pop();

        }

    }



    while (!St.empty()) {

        postfix += St.top();

        St.pop();

    }



    return postfix;



}





bool IsOperand(char ch)

{

    if (ch >= '0' && ch <= '9') return true;

    if (ch >= 'a' && ch <= 'z') return true;

    if (ch >= 'A' && ch <= 'Z') return true;

    return false;

}





bool IsOperator(char ch)

{

    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$')

        return true;



    return false;

}



// Function to verify whether an operator is right associative or not.

int rightassociative(char oprand)

{

    if (oprand == '$') return true;

    return false;

}





int Weightcheck(char oprand)     // check weight of an operator.Higher weight will have higher precedence.

{

    int weight = -1;

    switch (oprand)

    {

    case '+':

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





int Precedence(char oprand1, char oprand2)

{

    int oprand1Weight = Weightcheck(oprand1);

    int oprand2Weight = Weightcheck(oprand2);





    if (oprand1Weight == oprand2Weight)

    {

        if (rightassociative(oprand1)) return false;

        else return true;

    }

    return oprand1Weight > oprand2Weight ? true : false;

}



int main()

{

    string expression;

    cout << "Enter Infix Expression \n";

    getline(cin, expression);

    string postfix = InfixToPostfix(expression);



    cout << "converted expression is : " << postfix << "\n";





}