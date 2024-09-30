#include <iostream>
#include "functions.h"

using namespace std;

void displayMenu() {
    cout << "\nMenu Options:" << endl;
    cout << "1. Push to Stack" << endl;
    cout << "2. Pop from Stack" << endl;
    cout << "3. Peek Stack" << endl;
    cout << "4. Print Stack" << endl;
    cout << "5. Enqueue to Queue" << endl;
    cout << "6. Dequeue from Queue" << endl;
    cout << "7. Print Queue" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Stack stack;
    Queue queue;
    int choice, value;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:  // Push to Stack
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                cout << "Value pushed to stack." << endl;
                break;
            case 2:  // Pop from Stack
                stack.pop();
                cout << "Top value popped from stack." << endl;
                break;
            case 3:  // Peek Stack
                value = stack.peek();
                if (value != -1) {
                    cout << "Top value of stack: " << value << endl;
                }
                break;
            case 4:  // Print Stack
                cout << "Stack: ";
                stack.printStack();
                break;
            case 5:  // Enqueue to Queue
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                cout << "Value enqueued to queue." << endl;
                break;
            case 6:  // Dequeue from Queue
                queue.dequeue();
                cout << "Front value dequeued from queue." << endl;
                break;
            case 7:  // Print Queue
                cout << "Queue: ";
                queue.printQueue();
                break;
            case 8:  // Exit
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

