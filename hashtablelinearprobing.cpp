#include<iostream>
#include<string.h>
using namespace std;

#define size 10

struct Client {
    int key;
    char name[20];
    long phone;
};

Client table[size];

// Function to initialize hash table
void initialize() {
    for (int i = 0; i < size; i++) {
        table[i].key = -1;
        strcpy(table[i].name, "NULL");
        table[i].phone = 0;
    }
}

// Hash function
int hashfunction(int key) {
    return key % size;
}

// Function to insert record
void insertrecord() {
    int key;
    char name[20];
    long phone;    // ? corrected (was int before)

    cout << "\nEnter Client ID: ";
    cin >> key;
    cout << "Enter Client Name:";
    cin >> name;
    cout << "Enter Telephone Number: ";
    cin >> phone;

    int index = hashfunction(key);

    // Linear Probing
    for (int i = 0; i < size; i++) {
        int newindex = (index + i) % size;
        if (table[newindex].key == -1) {
            table[newindex].key = key;
            strcpy(table[newindex].name, name);
            table[newindex].phone = phone;
            cout << "Record inserted at index " << newindex << endl;
            return;
        }
    }
    cout << "Hash Table is full\n";
}

// Function to search record
void searchrecord() {
    int key;
    cout << "\nEnter Client ID to search: ";
    cin >> key;
    int index = hashfunction(key);

    for (int i = 0; i < size; i++) {
        int newindex = (index + i) % size;
        if (table[newindex].key == key) {
            cout << "Record found at index: " << newindex << endl;
            cout << "Name: " << table[newindex].name << endl;
            cout << "Telephone: " << table[newindex].phone << endl;
            return;
        }
    }
    cout << "Record not found\n";
}

// Function to display hash table
void display() {
    cout << "\nIndex\tKey\tName\tPhone\n";
    for (int i = 0; i < size; i++) {
        cout << i << "\t" << table[i].key << "\t" << table[i].name << "\t" << table[i].phone << endl;
    }
}

int main() {
    int choice;
    initialize();

    do {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Insert Record\n";
        cout << "2. Search Record\n";
        cout << "3. Display Record\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertrecord();
                break;
            case 2:
                searchrecord();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "\nExiting......\n";
                break;
            default:
                cout << "\nInvalid choice!\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
