#include<iostream>
#include<string>  


using namespace std;

class book {
    private:
        string title;
        string author;
        // string isbn;
        int publication_year;
        int available_copies;

    public:
        void set_title(string title);
        void set_author(string author);
        // void set_isbn(string isbn);
        void set_publication_year(int year);
        void set_available_copies(int copies);

        string get_title();
        string get_author();
        // string get_isbn();
        int get_publication_year();
        int get_available_copies();

};