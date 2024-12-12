#include <iostream>
#include <string>
#define size 100
using namespace std;

class stack {
private:
    int top = -1;
    char array[size];

public:
    void push(char val) {
        if (top >= size - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            top++;
            array[top] = val;
        }
    }

    int pop() {
        if (top <= -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        } else {
            return array[top--];
        }
    }

    void display() {
        if (top >= 0) {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << array[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    char peek() {
        if (top >= 0) {
            return array[top];
        } else {
            return '\0'; // Return null character if stack is empty
        }
    }

    bool isempty() {
        return top == -1;
    }

    bool isBalanced(const string& str) {
        for (char ch : str) {
            if (ch == '(' || ch == '[' || ch == '{') {
                push(ch);
            } else if (ch == ')' || ch == ']' || ch == '}') {
                if (isempty()) {
                    return false;
                }

                char last_st = peek();
                if ((ch == ')' && last_st == '(') ||
                    (ch == '}' && last_st == '{') ||
                    (ch == ']' && last_st == '[')) {
                    pop();
                } else {
                    return false;
                }
            }
        }
        return isempty();
    }
};

int main() {
    stack s1;
    string str;

    cout << "Enter a string: ";
    cin >> str;

    if (s1.isBalanced(str)) {
        cout << "Parenthesis is Balanced." << endl;
    } else {
        cout << "Parenthesis is not Balanced." << endl;
    }

    return 0;
}
