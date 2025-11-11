#include<iostream>
#include<string.h>
using namespace std;

struct Node {
    int prn;
    char name[20];
    Node *next;
};

// Function to create a new node
Node* createNode() {
    Node *temp = new Node;
    cout << "Enter PRN: ";
    cin >> temp->prn;
    cout << "Enter Name: ";
    cin >> temp->name;
    temp->next = NULL;
    return temp;
}

// Function to create a list (President, Members, Secretary)
Node* createList() {
    Node *head = NULL, *temp = NULL, *newnode;
    int n, i;
    cout << "\nEnter number of members how many members (including President & Secretary): ";
    cin >> n;

    for(i = 1; i <= n; i++) {
        newnode = createNode();
        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = temp->next;
        }
    }
    return head;
}

// Function to display members
void display(Node *head) {
    if(head == NULL) {
        cout << "\nNo members in this division!\n";
        return;
    }

    Node *temp = head;
    int i = 1;
    cout << "\nPRN\tName\t\tPosition\n";
    while(temp != NULL) {
        if(i == 1)
            cout << temp->prn << "\t" << temp->name << "\t(President)\n";
        else if(temp->next == NULL)
            cout << temp->prn << "\t" << temp->name << "\t(Secretary)\n";
        else
            cout << temp->prn << "\t" << temp->name << "\t(Member)\n";

        temp = temp->next;
        i++;
    }
}

// Function to count total members
int countMembers(Node *head) {
    int count = 0;
    Node *temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to concatenate two lists (Division A + Division B)
Node* concatenate(Node *head1, Node *head2) {
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    Node *temp = head1;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    Node *divA = NULL, *divB = NULL, *combined = NULL;
    int ch;

    do {
        cout << "\n------ Pinnacle Club (Two Divisions) ------\n";
        cout << "1. Create Division A List\n";
        cout << "2. Create Division B List\n";
        cout << "3. Display Division A\n";
        cout << "4. Display Division B\n";
        cout << "5. Count Members (A & B)\n";
        cout << "6. Concatenate A and B\n";
        cout << "7. Display Combined List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                divA = createList();
                break;
            case 2:
                divB = createList();
                break;
            case 3:
                cout << "\n--- Division A Members ---\n";
                display(divA);
                break;
            case 4:
                cout << "\n--- Division B Members ---\n";
                display(divB);
                break;
            case 5:
                cout << "\nTotal Members in Division A: " << countMembers(divA);
                cout << "\nTotal Members in Division B: " << countMembers(divB) << endl;
                break;
            case 6:
                combined = concatenate(divA, divB);
                cout << "\nTwo divisions concatenated successfully!\n";
                break;
            case 7:
                cout << "\n--- Combined Division Members ---\n";
                display(combined);
                cout << "\nTotal Combined Members: " << countMembers(combined) << endl;
                break;
            case 8:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "\nInvalid choice!\n";
        }
    } while(ch != 8);

    return 0;
}
