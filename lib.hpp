#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>
#include <string>
#include "book.hpp"
#include "libUser.hpp"
using namespace std;

class Library {
private:
    std::vector<Book*> books;  // Vector of Book object pointers
    std::vector<bool> is_borrowed; // Tracks if a book is borrowed

public:
    // Default constructor
    Library();

    // Parametric constructor
    Library(const vector<Book*>& books);

    // Insertion methods
    bool insertBook(Book* book);

    // Removal methods
    bool removeBook(Book* book);

    // Advanced search
    void advancedSearch(const string& title_substr, const string& author_substr, const string& genre_substr);

    // Borrow a book
    void borrowBook(libUser& user, const string& title);

    // Return a book
    void returnBook(libUser& user, const string& title);

    // Print all books in the library
    void print() const;

    vector<Book*>& getBooks() {
        return books;
    }

};

#endif // LIBRARY_HPP
