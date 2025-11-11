#include <iostream>
using namespace std;

// Node structure representing a seat
struct Node {
    int seat_no;       // Seat number (1–7)
    int status;        // 0 = available, 1 = booked
    Node* prev;        // Pointer to previous seat
    Node* next;        // Pointer to next seat
};

// Class representing the entire Cinemax booking system
class Cinemax {
public:
    Node* row[11];     // Each row (1–10), 7 seats per row

    // Constructor – initialize all rows and seats
    Cinemax() {
        for (int i = 1; i <= 10; i++)
            row[i] = NULL;
        createSeats();
    }

    // Function to create all seats (10 rows × 7 seats)
    void createSeats() {
        for (int j = 1; j <= 10; j++) {
            Node* tail = NULL;
            for (int i = 1; i <= 7; i++) {
                Node* newSeat = new Node;
                newSeat->seat_no = i;
                newSeat->status = 0;
                newSeat->prev = NULL;
                newSeat->next = NULL;

                if (row[j] == NULL)
                    row[j] = newSeat;
                else {
                    tail->next = newSeat;
                    newSeat->prev = tail;
                }
                tail = newSeat;
            }
        }
    }

    // Display available seats
    void displayAvailable() {
        cout << "\n========== AVAILABLE SEATS ==========\n";
        for (int j = 1; j <= 10; j++) {
            Node* temp = row[j];
            cout << "Row " << j << ": ";
            while (temp != NULL) {
                if (temp->status == 0)
                    cout << temp->seat_no << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Display booked (occupied) seats
    void displayBooked() {
        cout << "\n========== BOOKED SEATS ==========\n";
        for (int j = 1; j <= 10; j++) {
            Node* temp = row[j];
            cout << "Row " << j << ": ";
            bool hasBooked = false;
            while (temp != NULL) {
                if (temp->status == 1) {
                    cout << temp->seat_no << " ";
                    hasBooked = true;
                }
                temp = temp->next;
            }
            if (!hasBooked) cout << "None";
            cout << endl;
        }
    }

    // Book a seat
    void bookSeat() {
        displayAvailable();
        int r, s;
        cout << "\nEnter row number (1–10): ";
        cin >> r;
        cout << "Enter seat number (1–7): ";
        cin >> s;

        Node* temp = row[r];
        while (temp != NULL && temp->seat_no != s)
            temp = temp->next;

        if (temp == NULL)
            cout << "Invalid seat!\n";
        else if (temp->status == 1)
            cout << "Seat already booked!\n";
        else {
            temp->status = 1;
            cout << "Seat " << s << " in Row " << r << " booked successfully.\n";
        }
    }

    // Cancel a booked seat
    void cancelSeat() {
        displayBooked();
        int r, s;
        cout << "\nEnter row number (1–10): ";
        cin >> r;
        cout << "Enter seat number (1–7): ";
        cin >> s;

        Node* temp = row[r];
        while (temp != NULL && temp->seat_no != s)
            temp = temp->next;

        if (temp == NULL)
            cout << "Invalid seat!\n";
        else if (temp->status == 0)
            cout << "This seat is not booked.\n";
        else {
            temp->status = 0;
            cout << "? Booking for Seat " << s << " in Row " << r << " has been cancelled.\n";
        }
    }
};

// Main function — menu-driven interface
int main() {
    Cinemax c;
    int choice;

    do {
        cout << "\n========== CINEMAX THEATRE MENU ==========\n";
        cout << "1. Show Available Seats\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Show Booked Seats\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            c.displayAvailable();
            break;
        case 2:
            c.bookSeat();
            break;
        case 3:
            c.cancelSeat();
            break;
        case 4:
            c.displayBooked();
            break;
        case 5:
            cout << "Program ended. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
