#include <iostream>
#include <string.h>
using namespace std;

struct Node {
    int prn;
    char name[20];
    Node *next;
};

Node *head = NULL;

// Function to create President
void addPresident() {
    if (head != NULL) {
        cout << "\nPresident already exists!\n";
        return;
    }
    Node *newNode = new Node;
    cout << "Enter PRN of President: ";
    cin >> newNode->prn;
    cout << "Enter Name of President: ";
    cin >> newNode->name;
    newNode->next = NULL;
    head = newNode;
    cout << "President added successfully!\n";
}

// Function to add Secretary
void addSecretary() {
    if (head == NULL) {
        cout << "\nPlease add President first!\n";
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    Node *newNode = new Node;
    cout << "Enter PRN of Secretary: ";
    cin >> newNode->prn;
    cout << "Enter Name of Secretary: ";
    cin >> newNode->name;
    newNode->next = NULL;
    temp->next = newNode;

    cout << "Secretary added successfully!\n";
}

// Function to add a member (in between president and secretary)
void addMember() {
    if (head == NULL) {
        cout << "\nPlease add President first!\n";
        return;
    }

    Node *temp = head;

    // If only president exists (no secretary yet)
    if (temp->next == NULL) {
        cout << "\nPlease add Secretary first!\n";
        return;
    }

    Node *newNode = new Node;
    cout << "Enter PRN of Member: ";
    cin >> newNode->prn;
    cout << "Enter Name of Member: ";
    cin >> newNode->name;

    // insert before secretary (i.e., before last node)
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Member added successfully!\n";
}

// Function to count total members (including president & secretary)
int countMembers() {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to display club members
void display() {
    if (head == NULL) {
        cout << "\nClub has no members!\n";
        return;
    }

    Node *temp = head;
    cout << "\n---- Pinnacle Club Members ----\n";
    cout << "PRN\tName\t\tPosition\n";

    if (temp != NULL) {
        cout << temp->prn << "\t" << temp->name << "\t(President)\n";
        temp = temp->next;
    }

    while (temp != NULL) {
        if (temp->next == NULL)
            cout << temp->prn << "\t" << temp->name << "\t(Secretary)\n";
        else
            cout << temp->prn << "\t" << temp->name << "\t(Member)\n";
        temp = temp->next;
    }
}

// Main Function
int main() {
    int choice;
    do {
        cout << "\n------ Pinnacle Club Menu ------\n";
        cout << "1. Add President\n";
        cout << "2. Add Secretary\n";
        cout << "3. Add Member\n";
        cout << "4. Display Members\n";
        cout << "5. Total Number of Members\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPresident(); break;
            case 2: addSecretary(); break;
            case 3: addMember(); break;
            case 4: display(); break;
            case 5: cout << "\nTotal Members in Club: " << countMembers() << endl; break;
            case 6: cout << "\nExiting...\n"; break;
            default: cout << "\nInvalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
