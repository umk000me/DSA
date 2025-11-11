#include<iostream>
#include<string.h>
using namespace std;

struct Node {
    int prn;
    char name[20];
    Node *next;
};

Node *head = NULL;

// Add President
void addPresident() {
    if(head != NULL) {
        cout << "\nPresident already exists!\n";
        return;
    }
    Node *p = new Node;
    cout << "Enter PRN of President: ";
    cin >> p->prn;
    cout << "Enter Name of President: ";
    cin >> p->name;
    p->next = NULL;
    head = p;
    cout << "President added.\n";
}

// Add Secretary
void addSecretary() {
    if(head == NULL) {
        cout << "\nAdd President first!\n";
        return;
    }
    Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    Node *s = new Node;
    cout << "Enter PRN of Secretary: ";
    cin >> s->prn;
    cout << "Enter Name of Secretary: ";
    cin >> s->name;
    s->next = NULL;
    temp->next = s;
    cout << "Secretary added.\n";
}

// Add Member
void addMember() {
    if(head == NULL || head->next == NULL) {
        cout << "\nAdd President and Secretary first!\n";
        return;
    }
    Node *m = new Node;
    cout << "Enter PRN of Member: ";
    cin >> m->prn;
    cout << "Enter Name of Member: ";
    cin >> m->name;

    Node *temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;

    m->next = temp->next;
    temp->next = m;
    cout << "Member added.\n";
}

// Display Members
void display() {
    if(head == NULL) {
        cout << "\nNo members in club!\n";
        return;
    }

    Node *temp = head;
    cout << "\nPRN\tName\t\tPosition\n";
    cout << temp->prn << "\t" << temp->name << "\t(President)\n";
    temp = temp->next;

    while(temp != NULL) {
        if(temp->next == NULL)
            cout << temp->prn << "\t" << temp->name << "\t(Secretary)\n";
        else
            cout << temp->prn << "\t" << temp->name << "\t(Member)\n";
        temp = temp->next;
    }
}

// Count Members
void totalMembers() {
    int count = 0;
    Node *temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout << "\nTotal Members in Club: " << count << endl;
}

// Delete President
void deletePresident() {
    if(head == NULL) {
        cout << "\nNo members to delete!\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    cout << "President deleted.\n";
}

// Delete Secretary
void deleteSecretary() {
    if(head == NULL || head->next == NULL) {
        cout << "\nNo Secretary to delete!\n";
        return;
    }
    Node *temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;

    Node *sec = temp->next;
    temp->next = NULL;
    delete sec;
    cout << "Secretary deleted.\n";
}

// Delete Member (by PRN)
void deleteMember() {
    if(head == NULL || head->next == NULL) {
        cout << "\nAdd more members first!\n";
        return;
    }
    int p;
    cout << "Enter PRN of Member to delete: ";
    cin >> p;

    Node *temp = head;
    while(temp->next != NULL && temp->next->prn != p)
        temp = temp->next;

    if(temp->next == NULL || temp->next->next == NULL) {
        cout << "No such member found or cannot delete president/secretary.\n";
        return;
    }

    Node *m = temp->next;
    temp->next = m->next;
    delete m;
    cout << "Member deleted.\n";
}

int main() {
    int ch;
    do {
        cout << "\n------ Pinnacle Club Menu ------\n";
        cout << "1. Add President\n2. Add Secretary\n3. Add Member\n";
        cout << "4. Display Members\n5. Total Members\n";
        cout << "6. Delete President\n7. Delete Member\n8. Delete Secretary\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1: addPresident(); break;
            case 2: addSecretary(); break;
            case 3: addMember(); break;
            case 4: display(); break;
            case 5: totalMembers(); break;
            case 6: deletePresident(); break;
            case 7: deleteMember(); break;
            case 8: deleteSecretary(); break;
            case 9: cout << "\nExiting...\n"; break;
            default: cout << "\nInvalid Choice!\n";
        }
    } while(ch != 9);

    return 0;
}

