#include <iostream>
using namespace std;

#define SIZE 5

class JobQueue {
    int jobs[SIZE];
    int front, rear;

public:
    JobQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void addJob(int job) {
        if (isFull()) {
            cout << "Queue is full! Cannot add job.\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        jobs[rear] = job;
        cout << "Job " << job << " added to the queue.\n";
    }

    void deleteJob() {
        if (isEmpty()) {
            cout << "Queue is empty! No job to delete.\n";
            return;
        }
        cout << "Job " << jobs[front] << " deleted from the queue.\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Jobs in queue: ";
        for (int i = front; i <= rear; i++)
            cout << jobs[i] << " ";
        cout << endl;
    }
};

int main() {
    JobQueue q;
    int choice, job;

    do {
        cout << "\n==== Job Queue Menu ====\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter job ID: ";
            cin >> job;
            q.addJob(job);
            break;
        case 2:
            q.deleteJob();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Program ended.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
