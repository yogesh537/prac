#include <iostream>
using namespace std;

class cinemax {
public:
    int booked;
    cinemax *next, *prev;

    cinemax() {
        next = prev = NULL;
        booked = 0;
    }
} *head[10], *curr, *last;

void build_cinemax() {
    int i, j;
    for (i = 1; i <= 10; i++) {
        head[i] = NULL;
        for (j = 1; j <= 7; j++) {
            curr = new cinemax();
            if (head[i] == NULL) {
                head[i] = curr;
                last = curr;
            } else {
                last->next = curr;
                last = curr;
                last->next = head[i];
            }
        }
    }
}

void display() {
    int i, j;
    for (i = 1; i <= 10; i++) {
        curr = head[i];
        cout << "Row " << i << " ----> ";
        for (j = 1; j <= 7; j++) {
            cout << curr->booked << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }
}

void booking() {
    int row, col, count;
    count = 1;
    cout << "\nThere are 10 rows and 7 columns available.";
    cout << "\nEnter row number: ";
    cin >> row;
    cout << "\nEnter column number: ";
    cin >> col;

    curr = head[row];
    while (curr->next != NULL && count <= 7) {
        if (count == col) {
            if (curr->booked != 1) {
                curr->booked = 1;
                cout << "\nSeat is booked successfully.\n";
                display();
                break;
            } else {
                cout << "\nSeat is already booked.";
            }
        } else {
            curr = curr->next;
        }
        count++;
    }
}

void cancel() {
    int row, col, count;
    count = 1;
    cout << "\nEnter row number: ";
    cin >> row;
    cout << "\nEnter column number: ";
    cin >> col;

    curr = head[row];
    while (curr->next != NULL && count <= 7) {
        if (count == col) {
            if (curr->booked == 1) {
                curr->booked = 0;
                cout << "Seat has been canceled.\n";
                cout << "Current Seat Status: \n";
                display();
            } else {
                cout << "\nSeat is not booked, so it cannot be canceled.";
            }
            break;
        } else {
            curr = curr->next;
        }
        count++;
    }
}

int main() {
    int ch;

    build_cinemax();

    do {
        cout << "\n***** Welcome to Cinemax Booking System *****\n";
        cout << "\n1) Booking";
        cout << "\n2) Cancel Booking";
        cout << "\n3) Display";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            booking();
            break;
        case 2:
            cancel();
            break;
        case 3:
            display();
            break;
        default:
            cout << "\nInvalid choice!";
        }

    } while (ch < 4);

    return 0;
}
