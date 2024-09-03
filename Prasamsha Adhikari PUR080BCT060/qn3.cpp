/*Define a class library with booktitle,author and numberofcopies as data members.
 Implement methods to add new books, issue books and return books. 
Ensure that the number of copies is appropriately updated for each operation.
*/

#include <iostream>
#include <string>
using namespace std;

class Library {
private:
    string bookTitle[100];    
    string author[100];       
    int numberOfCopies[100];  

public:
   
    Library() {
        for (int i = 0; i < 100; i++) {
            numberOfCopies[i] = 0;  
        }
    }
    void add() {
        int index = 0; 
        while (index < 100 && !bookTitle[index].empty()) {
            index++;
        }

        if (index >= 100) {
            cout << "Library is full, cannot add more books." << endl;
            return;
        }

        int n;
        cout << "Enter the title of the book: ";
        cin >> bookTitle[index];  
        cout << "Enter the author of the book: ";
        cin >> author[index];
        cout << "Enter number of copies to be added:";
        cin >> n;
        numberOfCopies[index] = n; 
        cout << "Book added successfully!" << endl;
    }

    void issue() {
        string title;
        cout << "Enter the title of the book to issue: ";
        cin >> title; 
        for (int i = 0; i < 100; i++) {
            if (bookTitle[i] == title && numberOfCopies[i] > 0) {
                numberOfCopies[i]--;  
                cout << "Book issued successfully!" << endl;
                return;
            }
        }
        cout << "Book unavailable." << endl;
    }

    void returnb() {
        string title;
        cout << "Enter the title of the book to be returned: ";
        cin >> title; 
        for (int i = 0; i < 100; i++) {
            if (bookTitle[i] == title) {
                numberOfCopies[i]++; 
                cout << "Book returned successfully!" << endl;
                return;
            }
        }
        cout << "Book not found" << endl;
    }

    void display() {
        bool hasBooks = false;
        cout << "\nBooks available:" << endl;
        for (int i = 0; i < 100; i++) {
            if (!bookTitle[i].empty() && numberOfCopies[i] > 0) {
                cout << "Title: " << bookTitle[i] << ", Author: " << author[i]
                     << ", Copies: " << numberOfCopies[i] << endl;
                hasBooks = true;
            }
        }
        if (!hasBooks) {
            cout << "library has no books currently." << endl;
        }
    }
};

int main() {
    Library l;
    int choice = 0;

    while (choice != 5) {
        cout << "\nMenu" << endl;
        cout << "1. Add" << endl;
        cout << "2. Issue" << endl;
        cout << "3. Return" << endl;
        cout << "4. Display all" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                l.add();
                break;

            case 2:
                l.issue();
                break;

            case 3:
                l.returnb();
                break;

            case 4:
                l.display();
                break;

            case 5:
                cout << "Exiting Library " << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}