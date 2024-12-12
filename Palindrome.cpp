#include <iostream>
#include <string.h>
#define max 50
using namespace std;

class STACK {
private:
    char a[max];
    int top;

public:
    STACK() {
        top = -1;
    }

    void push(char c) {
        top++;
        a[top] = c;
        a[top + 1] = '\0';
    }

    void reverse() {
        char str[max];
        cout << "\n\nReverse string is: ";
        for (int i = top, j = 0; i >= 0; i--, j++) {
            cout << a[i];
            str[j] = a[i];
        }
        cout << endl;
    }

    void convert(char str[]) {
        int j, k, len = strlen(str);
        for (j = 0, k = 0; j < len; j++) {
            if ((str[j] >= 97 && str[j] <= 122) || (str[j] >= 65 && str[j] <= 90)) {
                if (str[j] <= 90) {
                    str[k] = (str[j] + 32);
                } else {
                    str[k] = str[j];
                }
                k++;
            }
        }
        str[k] = '\0';
        cout << "\nAfter removing spaces and converting all characters to lowercase: " << str << "\n";
    }

    void palindrome() {
        char str[max];
        int i, j;
        for (i = top, j = 0; i >= 0; i--, j++) {
            str[j] = a[i];
        }
        str[j] = '\0';

        if (strcmp(str, a) == 0) {
            cout << "\n\nString is a palindrome.";
        } else {
            cout << "\n\nString is not a palindrome.";
        }
    }
};

int main() {
    STACK stack;
    char str[max];
    int i = 0;

    cout << "\nEnter a string to reverse and check if it is a palindrome: ";
    cin.getline(str, 50);
    cout << "Original String is: " << str;
    stack.convert(str);

    while (str[i] != '\0') {
        stack.push(str[i]);
        i++;
    }

    stack.palindrome();
    stack.reverse();

    return 0;
}
