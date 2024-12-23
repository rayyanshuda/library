# Class Book

## Objective of the Class Book

The class Book stores information about individual books with the following information:

## Attributes

`Title`, `Author`, `Genre`, `Year_Published`

## Methods

### Constructors
- **Default Constructor:**  
  The default constructor sets all three attributes (title, author, genre) to `"n/a"`.
  
- **Parameterized Constructors:**  
  Initializes one, two, or more attributes (title, author, genre, and year published) using the following constructors. Any attributes not initialized will be set to `"n/a"`.

### `get_title()`
- **Description:**  
  Returns the title of the book.

### `get_author()`
- **Description:**  
  Returns the author of the book.

### `get_genre()`
- **Description:**  
  Returns the genre of the book.

### `get_year_published()`
- **Description:**  
  Returns the year the book was published.

### `operator==`
- **Description:**  
  Implements equality operator overloading to compare two `Book` objects.  
  Two books are considered equal if their attributes (title, author, genre, year published) are the same.

### `print()`
- **Description:**  
  Outputs the current values stored inside the `Book` object.

