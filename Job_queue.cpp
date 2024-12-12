#include <iostream>
#define MAX 5
using namespace std;

class Queue {
public:
    int front = -1;
    int rear = -1;
    int arrayqueue[MAX];

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue is Full ";
        } else {
            rear++;
            arrayqueue[rear] = x;
        }
    }

    int delqueue() {
        if (front == rear) {
            cout << "Queue is Empty ";
            return -1; // Return a placeholder value if queue is empty
        }
        return arrayqueue[++front];
    }

    void display() {
        if (front == rear) {
            cout << "Queue is Empty ";
        } else {
            cout << "\n Elements in queue are: ";
            for (int i = front + 1; i <= rear; i++) {
                cout << arrayqueue[i] << " ";
            }
        }
    }
};

int main() {
    Queue obj;
    int ch, x;

    do {
        cout << "\n 1. Insert Job\n 2. Delete Job\n 3. Display\n 4. Exit\n Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\n Enter data: \n";
                cin >> x;
                obj.enqueue(x);
                cout << endl;
                break;

            case 2:
                cout << "\n Deleted Element = " << obj.delqueue() << endl;
                break;

            case 3:
                obj.display();
                break;

            case 4:
                cout << "\n Exiting Program.....";
                break;

            default:
                cout << "\n Invalid choice! Please try again.";
        }
    } while (ch != 4);

    return 0;
}
