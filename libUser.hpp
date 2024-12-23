#ifndef LIBUSER_HPP
#define LIBUSER_HPP
#include <string>
using namespace std;
#include "lib.hpp"
#include "book.hpp"

class Book;
class Library;

class libUser {
public:
    string name;
    string userId;
    int borrowed_count;

    //default constructor for the class Book with no parameters
    libUser();
    //initializes the attributes title, author, year_published, and genre in a new object (to n/a)
    //INPUTS: no input
    //RETURNS: no output

    //constructor with all 3 parameters
    libUser(string name, string userId, int borrowed_count); 
    //initializes the attributes title, author, and date of publication in a new object
    //INPUTS: string inputs for title, author, and date of publication
    //RETURNS: no output

    //getter methods for title, author, and date_of_publication
    string get_name();
    //returns the name attribute of a library user object

    string get_user_id();
    //returns the user id attribute of a library user object

    int get_borrowed_count();
    //returns the borrowed count attribute of a library user object

    int borrow(int& borrowed_count);

    int return_book(int& borrowed_count);

    //function to print the book details
    void print_user();
    virtual int get_borrow_limit() const = 0;
};

    // Print user details
    //virtual void print_user();
    //virtual ~libUser() = default; // Ensure proper polymorphic behavior

// Derived class: Student
class Student : public libUser {
public:
    bool graduated;                     // Attribute specific to Student
    static const int borrow_limit = 5;  // Borrow limit for Students

    // Default constructor
    Student();

    // Parameterized constructor
    Student(string name, string userId, int borrowed_count, bool graduated);

    // Getter for borrow_limit
    int get_borrow_limit() const;

    // Override print method
    void print_user();
};

// Derived class: Teacher
class Teacher : public libUser {
public:
    static const int borrow_limit = 10; // Borrow limit for Teachers

    // Default constructor
    Teacher();

    // Parameterized constructor
    Teacher(string name, string userId, int borrowed_count);

    // Getter for borrow_limit
    int get_borrow_limit() const;

    // Add a book to the library
    void add_book_to_library(Library& library, Book book);

    // Update book details in the library
    bool update_book_details(Library& library, string title, string new_author, string new_genre, string new_year_published);

    // Override print method
    void print_user();
};

#endif

