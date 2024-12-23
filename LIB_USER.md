# Class Library_User

## Objective of the Class Library_User

The class Library_User stores user information and methods of interacting with the library. It is the parent class for the two types of users:
- The class `Student` inherits from the class Library_User and has some special attributes and methods.
- The class `Teacher` inherits from the class Library_User and has some special attributes and methods.



### Attributes

`name`, `user_id`, `borrowed_count`


### Constructors
- **Default Constructor:**
  The default constructor sets the attributes `name` and `user_id` to `"n/a"`, and `borrowed_count` to 0.
  
- **Parameterized Constructors:**  
  Initializes all attributes (name, user_id, and borrowed_count) using the parametric constructors.

## Methods

### `get_name()`
- **Description:**  
  Returns the `name` attribute of the user.

### `get_user_id()`
- **Description:**  
Returns the `user_id` attribute of the user.

### `get_borrowed_count()`
- **Description:**  
Returns the `borrowed_count` attribute of the user (number of the books borrowed).

### `borrow()`
- **Description:**  
Increments the `borrowed_count` attribute of the user.

### `return()`
- **Description:**  
Decrements the `borrowed_count` attribute of the user.

### `print()`
- **Description:**  
  Print the current values of the user attributes.

# LibraryUser Subclass: Student & Teacher

The `LibraryUser` class serves as a base class for both `Student` and `Teacher` subclasses, managing attributes and methods common to all users of the library. The `Student` and `Teacher` classes inherit from `LibraryUser` and each add unique features such as borrowing limits and additional functionalities for teachers (e.g., adding and updating books in the library).


### Student Class Methods (Inherits from LibraryUser)

- **Attributes:**
  - `graduated`: Indicates whether the student has graduated (True/False).
  - `borrow_limit` (const int): The maximum number of books a student can borrow. The borrow limit for students is typically lower than that for teachers.

- **Constructors:**
  - **Default Constructor:**  
    Initializes the `graduated` attribute to `False` and `borrow_limit` to the default value specific to students.
  - **Parameterized Constructor:**  
    Initializes the `borrow_limit` and attributes from `LibraryUser` by calling the parameterized constructor of `LibraryUser`.

- **Methods:**
  - `get_borrow_limit()`:  
    Returns the `borrow_limit` specific to the student.

  - `print()`:  
    Prints details about the student, including whether they are a student, their name, borrow count, and the graduated status.

### Teacher Class (Inherits from LibraryUser)

- **Attributes:**
  - `borrow_limit` (const int): The maximum number of books a teacher can borrow. This value is typically higher than that of a student.

- **Constructors:**
  - **Default Constructor:**  
    Initializes the `borrow_limit` to the default value specific to teachers.
  - **Parameterized Constructor:**  
    Initializes the `borrow_limit` and attributes from `LibraryUser` by calling the parameterized constructor of `LibraryUser`.

- **Methods:**
  - `get_borrow_limit()`:  
    Returns the `borrow_limit` specific to the teacher.

  - `add_book_to_library()`:  
    Adds a `Book` pointer to a `Library` object. This method is only available to teachers, as they are allowed to add books to the library.

  - `update_book_details()`:  
    Updates the details (author, genre, year published) of an existing book in the library, if the title matches. This method is only available to teachers.

  - `print()`:  
    Prints details about the teacher, including whether they are a teacher, their name, borrow count, and the borrow limit.

