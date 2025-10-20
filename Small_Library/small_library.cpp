#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    int id;
    string title;
    string author;
};

int main() {
    Book library[MAX_BOOKS];
    int choice, count = 0;

    while (true) {
        cout << "\n=== Library Management System ===" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count < MAX_BOOKS) {
                cout << "Enter Book ID: ";
                cin >> library[count].id;
                cin.ignore();  // To clear input buffer
                cout << "Enter Book Title: ";
                getline(cin, library[count].title);
                cout << "Enter Author Name: ";
                getline(cin, library[count].author);
                count++;
                cout << "Book added successfully!" << endl;
            } else {
                cout << "Library is full!" << endl;
            }
        } else if (choice == 2) {
            if (count == 0) {
                cout << "No books in the library." << endl;
            } else {
                cout << "\n--- List of Books ---" << endl;
                for (int i = 0; i < count; i++) {
                    cout << "ID: " << library[i].id << endl;
                    cout << "Title: " << library[i].title << endl;
                    cout << "Author: " << library[i].author << endl;
                    cout << "------------------------" << endl;
                }
            }
        } else if (choice == 3) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
