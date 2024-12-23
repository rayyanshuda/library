#include <iostream>
#include "book.hpp"
#include "lib.hpp"
#include "libUser.hpp"
#include <string>

using namespace std;

int main() {
    // Create a library
    Library library;

     // Add books to the library
    Book* book1 = new Book("The Great Gatsby", "F. Scott Fitzgerald", "1925", "Fiction");
    Book* book2 = new Book("1984", "George Orwell", "1949", "Dystopian");
    Book* book3 = new Book("To Kill a Mockingbird", "Harper Lee", "1960", "Fiction");
    Book* book4 = new Book("Moby-Dick", "Herman Melville", "1851", "Adventure");
    Book* book5 = new Book("Pride and Prejudice", "Jane Austen", "1813", "Romance");

    // Insert books into the library
    library.insertBook(book1);
    library.insertBook(book2);
    library.insertBook(book3);
    library.insertBook(book4);
    library.insertBook(book5);

    // Display the library contents
    cout << "Library initialized with 5 books:\n";
    library.print();

    // Remove a book
    cout << "\nRemoving 'Moby-Dick' from the library.\n";
    library.removeBook(book4);
    library.print();

    // Create a student and teacher users
    Student student("Alice", "S123", 0, false);  // Student with no borrowed books yet
    Teacher teacher("Dr. Smith", "T456", 0);  // Teacher with no borrowed books yet

    cout << "\nStudent and Teacher profiles:\n";
    student.print_user();
    teacher.print_user();

    // Borrow books for student and teacher
    cout << "\nAlice (Student) borrows '1984'.\n";
    library.borrowBook(student, "1984");
    student.print_user();

    cout << "\nDr. Smith (Teacher) borrows 'To Kill a Mockingbird'.\n";
    library.borrowBook(teacher, "To Kill a Mockingbird");
    teacher.print_user();

    // Alice attempts to borrow 'To Kill a Mockingbird' (already borrowed by Dr. Smith)
    cout << "\nAlice attempts to borrow 'To Kill a Mockingbird' (already borrowed by Dr. Smith).\n";
    library.borrowBook(student, "To Kill a Mockingbird");
    student.print_user();

    // Dr. Smith borrows more books
    cout << "\nDr. Smith borrows 'The Great Gatsby'.\n";
    library.borrowBook(teacher, "The Great Gatsby");
    teacher.print_user();

    // Attempting to borrow more than allowed for a student (if there's a limit, let's say 2 books)
    cout << "\nAlice attempts to borrow 'Pride and Prejudice'.\n";
    library.borrowBook(student, "Pride and Prejudice");
    student.print_user();  // This will show if the borrowing limit for the student is enforced

    // Return books
    cout << "\nDr. Smith returns 'To Kill a Mockingbird'.\n";
    library.returnBook(teacher, "To Kill a Mockingbird");
    teacher.print_user();

    cout << "\nAlice returns '1984'.\n";
    library.returnBook(student, "1984");
    student.print_user();

    // Update book details for a specific book
    cout << "\nDr. Smith updates details for 'Pride and Prejudice'.\n";
    teacher.update_book_details(library, "Pride and Prejudice", "Jane Austen (Updated)", "Historical Fiction", "1813");

    // Show the updated library
    cout << "\nLibrary after updating book details:\n";
    library.print();

    // Perform an advanced search
    cout << "\nPerforming an advanced search for books by 'George Orwell' with genre 'Dystopian'.\n";
    library.advancedSearch("George Orwell", "", "Dystopian");

    cout << "\nPerforming an advanced search for books with title 'Pride' and genre 'Historical Fiction'.\n";
    library.advancedSearch("Pride", "", "Historical Fiction");

    // End of the program
    cout << "\nProgram execution finished.\n";
    return 0;
}
