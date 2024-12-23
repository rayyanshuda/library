#include "lib.hpp"
#include "libUser.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

// Helper function to convert strings to lowercase for case-insensitive comparison
string toLower(const std::string& str) {
    string lower_str = str;
    transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return lower_str;
}

// Default constructor
Library::Library() {}

// Parametric constructor
Library::Library(const std::vector<Book*>& books) : books(books), is_borrowed(books.size(), false) {}

// Insert a book object pointer
bool Library::insertBook(Book* book) {
    for (const auto& b : books) {
        if (*b == *book) {
            return false; // Book already exists
        }
    }
    Book* newBook = new Book(*book); // Create a deep copy
    books.push_back(book);
    is_borrowed.push_back(false);
    return true;
}

// Remove a book object pointer
bool Library::removeBook(Book* book) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (*books[i] == *book) {
            delete books[i]; // Free memory
            books.erase(books.begin() + i);
            is_borrowed.erase(is_borrowed.begin() + i);
            return true;
        }
    }
    return false; // Book not found
}

// Advanced search
void Library::advancedSearch(const string& title_substr, const string& author_substr, const string& genre_substr) {
    bool found = false;
    for (const auto& book : books) {
        if ((toLower(book->getTitle()).find(toLower(title_substr)) != string::npos) &&
            (toLower(book->getAuthor()).find(toLower(author_substr)) != string::npos) &&
            (toLower(book->getGenre()).find(toLower(genre_substr)) != string::npos)) {
            book->print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No book found matching the search criteria." << endl;
    }
}

// Borrow a book
void Library::borrowBook(libUser& user, const string& title) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i]->getTitle() == title && !is_borrowed[i]) {
            if (user.get_borrowed_count() < user.get_borrow_limit()) {
                is_borrowed[i] = true;
                user.borrow(user.borrowed_count);
                cout << user.name << " borrowed \"" << title << "\"." << endl;
                return;
            } else {
                cout << "Borrowing limit reached for " << user.name << "." << endl;
                return;
            }
        }
    }
    cout << "Book \"" << title << "\" is either not available or already borrowed." << endl;
}

// Return a book
void Library::returnBook(libUser& user, const string& title) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i]->getTitle() == title && is_borrowed[i]) {
            is_borrowed[i] = false;
            user.return_book(user.borrowed_count);
            cout << user.name << " returned \"" << title << "\"." << endl;
            return;
        }
    }
    cout << "Book \"" << title << "\" was not borrowed or does not exist in the library." << endl;
}

// Print all books
void Library::print() const {
    for (size_t i = 0; i < books.size(); ++i) {
        cout << "[" << i << "] ";
        books[i]->print();
        cout << "Borrowed: " << (is_borrowed[i] ? "Yes" : "No") << endl;
    }
}
