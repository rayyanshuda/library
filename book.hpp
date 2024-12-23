#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    string year_published;
    string genre;

    //default constructor for the class Book with no parameters
    Book();
    //initializes the attributes title, author, year_published, and genre in a new object (to n/a)
    //INPUTS: no input
    //RETURNS: no output

    //constructor with all 4 parameters
    Book(string title, string author, string year_published, string genre); 
    //initializes the attributes title, author, and date of publication in a new object
    //INPUTS: string inputs for title, author, and date of publication
    //RETURNS: no output

    //constructor with 3 parameters
    Book(string title, string author, string year_published); 
    //initializes the attributes title, author, and date of publication in a new object
    //INPUTS: string inputs for title, author, and date of publication
    //RETURNS: no output

    //constructor with title and author as parameters
    Book(string title, string author); 
    //initializes the attributes title and author in a new object 
    //INPUTS: string inputs for title and author
    //RETURNS: no output

    //constructor with only title as the paramter
    Book(string title); 
    //initializes the attribute title in a new object
    //INPUTS: string input for title
    //RETURNS: no output

    //getter methods for title, author, and date_of_publication
    string getTitle();
    //returns the title attribute of a book object

    string getAuthor();
    //returns the author attribute of a book object

    string getyear_published();
    //returns the date of publication attribute of a book object

    string getGenre();

    string setTitle(string& newTitle);
    string setAuthor(string& newAuthor);
    string setYearPublished(string& newYearPublished);
    string setGenre(string& newGenre);

    // Overload equality operator
    bool operator==(const Book& other) const;

    //function to print the book details
    void print();
};

#endif