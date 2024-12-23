# Class Library

## Objective of the Class Library

The class Library stores books and methods for managing books.

### Attributes

Vector of `Book Object Pointers` 

Vector of `Is_Borrowed`

### Constructors
- **Default Constructor:**
  The default constructor with no parameters implicitly initializes the vector attribute.
  
- **Parameterized Constructors:**  
  The parametric constructor takes a vector of Book objects pointer and stores the Book values from that vector into the vector attribute.

## Methods

### Insertion

- **Insertion (Book pointer):**  
  This method takes a pointer to a `Book` object and stores it in the library's vector. The `is_borrowed` vector is adjusted accordingly.
  - **Checks:**
    The method will check if a book with the exact same details (title, author, genre, year published) already exists in the library using the overloaded equality operator (`operator==`).  
    - If a match is found, the insertion is rejected.
    - If the insertion succeeds, the method returns `true`.  
    - If it fails, it returns `false`.

- **Insertion (Book details as values):**  
  This method accepts the book's title, author, genre, and year published as input values. The book is then added to the library with the `is_borrowed` vector being adjusted.  
  - **Checks:**  
    Similar to the previous insertion method, it checks for existing books with the same details using the overloaded equality operator. If a match is found, insertion is rejected and the method returns `false`. Otherwise, it returns `true`.

### Removal

- **Removal (Book pointer):**  
  This method accepts a pointer to a `Book` object and removes the corresponding book from the library.
  - If the book is found and removed, the method returns `true` and adjusts the `is_borrowed` vector.
  - If the book is not found, it returns `false`.

- **Removal (Book details as values):**  
  This method allows the removal of a book by passing its title, author, genre, and year published as input values.
  - If a matching book is found and removed, the method returns `true` and adjusts the `is_borrowed` vector.
  - If no match is found, it returns `false`.

### Advanced Search

- **Advanced Search (Substring Match):**  
  This method searches for books in the library based on substrings of title, author, and genre. It takes input strings for title, author, and genre, which can be partial matches.
  - If a match is found, the book information is printed using the `book->print()` method.
  - If no match is found, a message indicating that the book is not in the library is printed.
  - The search is case-insensitive.

### Borrow Book

- **Borrow Book:**  
  This method allows a `LibraryUser` to borrow a book from the library. It takes the user's object and the title of the book to be borrowed as input.
  - **Conditions:**  
    - The book must not already be borrowed.
    - The user's `borrow_count` must be smaller than their `borrow_limit`.
  - If all conditions are met, the `is_borrowed` value of the book is updated, and the user's `borrow()` method is called. A message is printed indicating the user and book title.
  - If the conditions are not met, a message indicating the issue is printed.

### Return Book

- **Return Book:**  
  This method allows a `LibraryUser` to return a borrowed book to the library. It takes the user's object and the title of the book being returned.
  - **Conditions:**  
    - The book must be marked as borrowed.
  - If the book is borrowed, the `is_borrowed` value is updated, and the user's `return()` method is called. A message is printed indicating the user and book title.
  - If the conditions are not met, a message indicating the issue is printed.

### Print

- **Print:**  
  This method prints all the books stored in the library. For each book, it prints the index in the vector followed by the details of the book, which are obtained using `book->print()`.
