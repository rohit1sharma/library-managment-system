#include "../user.hpp"

class student : public user
{

private:
    double student_id;
    int enrollment_year;
    int books_borrowed;
    int balance;

    void set_name(string name) override;

    void set_email(string email) override;

    void set_password(string password) override;

public:
    double get_student_id();
    int get_enrollment_year();
    int get_books_borrowed();
    int get_balance();

protected:
    void borrow_book();
    void return_book();
    void view_borrowing_history();
    void view_balance();
    void pay_fine();
    void update_profile();
    void search_books();
    void view_available_books();
};