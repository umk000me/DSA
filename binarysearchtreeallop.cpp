#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert a new node into BST
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Find height of BST (longest path from root)
int height(Node* root) {
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

// Find minimum value in BST
int findMin(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

// Mirror the BST (swap left and right)
void mirror(Node* root) {
    if (root == NULL)
        return;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

// Search for a value
bool search(Node* root, int key) {
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    Node* root = NULL;
    int n, val, choice;

    cout << "Enter number of nodes to insert initially: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    do {
        cout << "\n===== BST OPERATIONS MENU =====\n";
        cout << "1. Insert new node\n";
        cout << "2. Find height (longest path)\n";
        cout << "3. Find minimum value\n";
        cout << "4. Mirror the tree\n";
        cout << "5. Search a value\n";
        cout << "6. Display inorder traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insert(root, val);
            cout << "Node inserted.\n";
            break;

        case 2:
            cout << "Height of tree: " << height(root) << endl;
            break;

        case 3:
            cout << "Minimum value in tree: " << findMin(root) << endl;
            break;

        case 4:
            mirror(root);
            cout << "Tree mirrored successfully.\n";
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> val;
            if (search(root, val))
                cout << val << " found in the tree.\n";
            else
                cout << val << " not found in the tree.\n";
            break;

        case 6:
            cout << "Inorder traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 7:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
