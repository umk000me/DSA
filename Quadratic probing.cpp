#include <iostream>
#include <string.h>
using namespace std;

#define SIZE 10

struct Client {
    int key;
    char name[20];
    long phone;
};

Client table[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        table[i].key = -1;
        strcpy(table[i].name, "NULL");
        table[i].phone = 0;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insertRecord() {
    int key;
    char name[20];
    long phone;

    cout << "\nEnter Client ID: ";
    cin >> key;
    cout << "Enter Client Name: ";
    cin >> name;
    cout << "Enter Telephone Number: ";
    cin >> phone;

    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;
        if (table[newIndex].key == -1) {
            table[newIndex].key = key;
            strcpy(table[newIndex].name, name);
            table[newIndex].phone = phone;
            cout << "Record inserted at index " << newIndex << endl;
            return;
        }
    }

    cout << "Hash Table is full!\n";
}

void searchRecord() {
    int key;
    cout << "\nEnter Client ID to search: ";
    cin >> key;

    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;
        if (table[newIndex].key == key) {
            cout << "Record found at index " << newIndex << endl;
            cout << "Name: " << table[newIndex].name << endl;
            cout << "Phone: " << table[newIndex].phone << endl;
            return;
        }
    }

    cout << "Record not found!\n";
}

void display() {
    cout << "\nIndex\tKey\tName\tPhone\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << "\t" << table[i].key << "\t" << table[i].name << "\t" << table[i].phone << endl;
    }
}

int main() {
    int choice;
    initialize();

    do {
        cout << "\n------ MENU (Quadratic Probing) ------\n";
        cout << "1. Insert Record\n";
        cout << "2. Search Record\n";
        cout << "3. Display Table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertRecord(); break;
            case 2: searchRecord(); break;
            case 3: display(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
