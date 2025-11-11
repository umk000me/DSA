#include<iostream>
using namespace std;

int main() {
    int i, j, pass, size;
    cout << "How many students:\n  ";
    cin >> size;
    float b[20], temp;
    cout << "\nEnter Percentage of students:\n";
    for(i = 0; i < size; i++) {
        cin >> b[i];
    }

    cout << "\nBubble sort:\n";
    for(i = 0; i < size; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    for(pass = 1; pass < size; pass++) {
        int comparisons = 0;
        int swap = 0;
        for(j = 0; j < size - pass; j++) {   
            comparisons++;
            if(b[j] > b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                swap = 1;
            }
        }
        cout << "\nPass: " << pass << "\nComparisons: " << comparisons << "\nArray: ";
        for(i = 0; i < size; i++) {
            cout << b[i] << "   ";
        }
        if(swap == 0) {
            break;
        }
    }

    char ch;
    cout << "\nPress any key to exit...";
    cin >> ch;
    return 0;
}
