#include "libUser.hpp"
#include "lib.hpp"
#include "book.hpp"
#include <iostream>
#include <string>
using namespace std;

//default constructor (no parameters)
libUser::libUser() { 
    name = "n/a";
    userId = "n/a";
    borrowed_count = 0;
}

//constructor with all 4 parameters
libUser::libUser(string name, string userId, int borrowed_count) {
    this->name = name;
    this->userId = userId;
    this->borrowed_count = borrowed_count;
}

//function to get title
string libUser::get_name() {
    return name;
}

//function to get author
string libUser::get_user_id() {
    return userId;
}

//function to get date_of_publication
int libUser::get_borrowed_count() {
    return borrowed_count;
}

int libUser::borrow(int& borrowed_count) {
    return ++borrowed_count;
}

int libUser::return_book(int& borrowed_count) {
    if (borrowed_count > 0) {
        return --borrowed_count;
    }
    cout << "No books to return." << endl;
    return 0;
}

//function to printing book details
void libUser::print_user() {
    cout << "Name: " << name << endl; 
    cout << "User ID: " << userId << endl;
    cout << "Borrowed Count: " << borrowed_count << endl;
}

// ========================== Student Implementation ==========================
// Student Implementation
Student::Student() : libUser(), graduated(false) {}

Student::Student(string name, string userId, int borrowed_count, bool graduated)
    : libUser(name, userId, borrowed_count), graduated(graduated) {}

int Student::get_borrow_limit() const {
    return borrow_limit;
}

void Student::print_user() {
    cout << "Student Information:" << endl;
    libUser::print_user();
    cout << "Graduated: " << (graduated ? "Yes" : "No") << endl;
    cout << "Borrow Limit: " << borrow_limit << endl;
}

// ========================== Teacher Implementation ==========================
// Teacher Implementation
Teacher::Teacher() : libUser() {}

Teacher::Teacher(string name, string userId, int borrowed_count)
    : libUser(name, userId, borrowed_count) {}

int Teacher::get_borrow_limit() const {
    return borrow_limit;
}

void Teacher::add_book_to_library(Library& library, Book book) {
    Book* bookPtr = new Book(book); // Dynamically allocate memory for the book
    if (library.insertBook(bookPtr)) {
        cout << "Book added successfully by " << name << " (Teacher)." << endl;
    } else {
        cout << "Failed to add book. The book already exists in the library." << endl;
    }
}




void Teacher::print_user() {
    cout << "Teacher Information:\n";
    libUser::print_user();
    cout << "Borrow Limit: " << borrow_limit << endl;
}


