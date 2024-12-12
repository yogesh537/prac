#include <iostream>
#define SIZE 5
using namespace std;

class dequeue {
public:
    int a[SIZE], front, rear;

    // Constructor
    dequeue() {
        front = -1;
        rear = -1;
    }

    // Member functions
    int isempty() {
        return (front == -1 && rear == -1);
    }

    int isfull() {
        return (front == -1 && rear == SIZE - 1) || (rear == front - 1);
    }

    void enqueue_front(int item) {
        if (isfull()) {
            cout << "\nInsertion is not possible, overflow!!!";
        } else if (front == -1 && rear == -1) { // First element
            front = 0;
            rear = 0;
            a[front] = item;
        } else { // Regular case
            front = (front - 1 + SIZE) % SIZE;
            a[front] = item;
        }
    }

    void enqueue_rear(int item) {
        if (isfull()) {
            cout << "\nInsertion is not possible, overflow!!!";
        } else if (front == -1 && rear == -1) { // First element
            front = 0;
            rear = 0;
            a[rear] = item;
        } else { // Regular case
            rear = (rear + 1) % SIZE;
            a[rear] = item;
        }
    }

    void delete_fr_front() {
        if (isempty()) {
            cout << "Deletion is not possible: Dequeue is empty";
        } else if (front == rear) { // Single element
            cout << "The deleted element is " << a[front];
            front = rear = -1;
        } else { // Regular case
            cout << "The deleted element is " << a[front];
            front = (front + 1) % SIZE;
        }
    }

    void delete_fr_rear() {
        if (isempty()) {
            cout << "Deletion is not possible: Dequeue is empty";
        } else if (front == rear) { // Single element
            cout << "The deleted element is " << a[rear];
            front = rear = -1;
        } else { // Regular case
            cout << "The deleted element is " << a[rear];
            rear = (rear - 1 + SIZE) % SIZE;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty";
        } else {
            int i = front;
            cout << "Elements in deque are: ";
            while (true) {
                cout << a[i] << " ";
                if (i == rear) break;
                i = (i + 1) % SIZE;
            }
        }
    }
};

int main() {
    int c, item;
    dequeue d1;

    do {
        cout << "\n\n**** DEQUEUE OPERATION ****\n";
        cout << "\n1 - Insert at beginning";
        cout << "\n2 - Insert at end";
        cout << "\n3 - Display";
        cout << "\n4 - Deletion from front";
        cout << "\n5 - Deletion from rear";
        cout << "\n6 - Exit";
        cout << "\nEnter your choice: ";
        cin >> c;

        switch (c) {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> item;
                d1.enqueue_front(item);
                break;

            case 2:
                cout << "Enter the element to be inserted: ";
                cin >> item;
                d1.enqueue_rear(item);
                break;

            case 3:
                d1.display();
                break;

            case 4:
                d1.delete_fr_front();
                break;

            case 5:
                d1.delete_fr_rear();
                break;

            case 6:
                cout << "Exiting Program...";
                break;

            default:
                cout << "Invalid choice!";
                break;
        }
    } while (c != 6);

    return 0;
}
