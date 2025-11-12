#include <iostream>
using namespace std;

// Recursive function for Fibonacci
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// Non-recursive (iterative) Fibonacci
void nonfib(int n) {
    int n1 = 0, n2 = 1, n3;

    if (n <= 0) {
        cout << "Please enter a positive number." << endl;
        return;
    }

    cout << "Fibonacci Series: ";
    if (n == 1) {
        cout << n1 << endl;
        return;
    }

    cout << n1 << " " << n2 << " ";
    for (int i = 2; i < n; ++i) {
        n3 = n1 + n2;
        cout << n3 << " ";
        n1 = n2;
        n2 = n3;
    }
    cout << endl;
}

int main() {
    int choice, n;

    cout << "========= Fibonacci Program =========" << endl;
    cout << "1. Non-Recursive (Iterative) Approach" << endl;
    cout << "2. Recursive Approach" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Enter the number of elements: ";
            cin >> n;
            nonfib(n);
            break;
        }

        case 2: {
            cout << "Enter the position of Fibonacci number: ";
            cin >> n;
            cout << n << "th Fibonacci Number: " << fib(n - 1) << endl;
            break;
        }

        default:
            cout << "Invalid choice! Please enter 1 or 2." << endl;
    }

    return 0;
}
