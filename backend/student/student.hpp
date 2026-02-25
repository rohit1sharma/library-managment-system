#include "../user.hpp"

#pragma once

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
    optional<string> get_name() override { return name!= "" ? optional<string>(name) : nullopt;  }
    optional<string> get_email() override { return email!= "" ? optional<string>(email) : nullopt; }
    optional<string> get_password() override { return password!= "" ? optional<string>(password) : nullopt; }

public:
    double get_student_id();
    int get_enrollment_year();
    int get_books_borrowed();
    int get_balance();
    student(user& other) : user(other) {}
    student()=  default;
    student(string email, string password) : user("", email, password) {}

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