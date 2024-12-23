#include "book.hpp"
#include <iostream>
#include <string>
using namespace std;

//default constructor (no parameters)
Book::Book() { 
    title = "n/a";
    author = "n/a";
    year_published = "n/a";
    genre = "n/a";
}

//constructor with all 4 parameters
Book::Book(string title, string author, string year_published, string genre) {
    this->title = title;
    this->author = author;
    this->year_published = year_published;
    this->genre = genre;
}

Book::Book(string title, string author, string year_published) {
    this->title = title;
    this->author = author;
    this->year_published = year_published;
}

//constructor with title and author as parameters
Book::Book(string title, string author) {
    this->title = title;
    this->author = author;
    this->year_published = "n/a";
}

//constructor with only title as parameter
Book::Book(string title) {
    this->title = title;
    this->author = "n/a";
    this->year_published = "n/a";
}

//function to get title
string Book::getTitle() {
    return title;
}

//function to get author
string Book::getAuthor() {
    return author;
}

//function to get date_of_publication
string Book::getyear_published() {
    return year_published;
}

string Book::getGenre() {
    return genre;
}

// Setters
string Book::setTitle(string& newTitle) {
    title = newTitle;
    return title;
}

string Book::setAuthor(string& newAuthor) {
    author = newAuthor;
    return author;
}

string Book::setGenre(string& newGenre) {
    genre = newGenre;
    return genre;
}

string Book::setYearPublished(string& newYearPublished) {
    year_published = newYearPublished;
    return year_published;
}

// Overloaded equality operator
bool Book::operator==(const Book& other) const {
    bool is_equal;
    is_equal = (title == other.title) && (author == other.author) && (year_published == other.year_published) && (genre == other.genre);
    return is_equal;
}

//function to printing book details
void Book::print() {
    cout << "Title: " << title << endl << "Author: " << author << endl << "Date of Publication: " << year_published << endl << "Genre: " << genre << endl;
}



