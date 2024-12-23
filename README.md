# Library System

This project is a comprehensive implementation of a Library System written in C++. The system is designed to manage books, library users, and their interactions through an intuitive driver code that serves as the user interface. It provides an adequate foundation for managing a library's operations and can be extended with additional features.

## Features - Components Overview

### Book Class

Represents individual books in the library.

Stores book-related information such as title, author, and ISBN.

### Library Class

Maintains a collection of books.

Includes methods for managing books, such as adding, removing, and searching for books.

### LibraryUser Class

Represents a user of the library.

Stores user-related information, such as name and user ID.

Serves as the base class for specific user types.

### Teacher Class (inherits from LibraryUser)

Represents teachers who use the library.

Includes special attributes and methods unique to teachers.

### Student Class (inherits from LibraryUser)

Represents students who use the library.

Includes special attributes and methods unique to students.

### Driver Code (Main Function)

Serves as the user interface.

Allows interaction with the library system's classes and methods.


# How to Run

Compile the code using a C++ compiler (I used g++):


Run the Executable:



