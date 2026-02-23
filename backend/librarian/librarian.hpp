#include "../user.hpp"

#pragma once

class librarian : public user {   

    private:
            void set_name(string name) override;
            void set_email(string email) override;
            void set_password(string password) override;


        int employee_number;
        string name;
        string email;
        int joining_year;

    public:
            //Convert to optional
        void checkBookAvailability();
        void addBook();
        void removeBook();
        void updateBookInfo();
        void viewBorrowingRecords();
        void manageMembers();
        void generateReports();
        void updateStudentProfile(); // balance update also
        void searchBooks();
        optional<string> get_name() override { return name!= "" ? optional<string>(name) : nullopt;  }
        optional<string> get_email() override { return email!= "" ? optional<string>(email) : nullopt; }
        optional<string> get_password() override { return password!= "" ? optional<string>(password) : nullopt; }
        int get_employee_number();
        int get_joining_year();
        librarian(user& other) : user(other) {}
        librarian() = default;  

};