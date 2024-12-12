#include <iostream>
using namespace std;

#define max1 4

class pizzaparlor {
public:
    int count;
    int q[50], x;
    int rear;
    int front;

    // Constructor
    pizzaparlor() {
        count = 0;
        front = 0;
        rear = -1;
    }

    // Member functions
    void insert() {
        if (count == max1) {
            cout << "\nOrders are full...";
        } else {
            cout << "\nEnter order id: ";
            cin >> x;
            rear = (rear + 1) % max1;
            q[rear] = x;
            count++;
            cout << "\nOrder is placed...";
        }
    }

    void display() {
        if (count == 0) {
            cout << "\nNo orders placed.";
        } else {
            int i = front;
            cout << "\nOrders are: ";
            do {
                cout << q[i] << " ";
                i = (i + 1) % max1;
            } while (i != (rear + 1) % max1);
        }
    }

    void deleteq() {
        if (count == 0) {
            cout << "\nNo order is placed...";
        } else {
            cout << "\nOrder " << q[front] << " is delivered.";
            front = (front + 1) % max1;
            count--;
        }
    }
};

int main() {
    pizzaparlor a;
    int ch;

    do {
        cout << "\n\n****** MENU ******\n";
        cout << "1) Place order\n";
        cout << "2) Pending orders\n";
        cout << "3) Deliver order\n";
        cout << "4) Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                a.insert();
                break;

            case 2:
                a.display();
                break;

            case 3:
                a.deleteq();
                break;

            case 4:
                cout << "\nExiting program...";
                break;

            default:
                cout << "\nInvalid choice!";
        }
    } while (ch != 4);

    return 0;
}
