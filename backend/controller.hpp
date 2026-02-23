#include<iostream>
#include"loginPage.hpp"
#include"../database/database.hpp"
#include"student/student.hpp"
#include"librarian/librarian.hpp"
#include"user.hpp"
#include<memory>
#include<optional>

#pragma once

using namespace std;

class controller {
    private:
        unique_ptr<loginpage> login;
        unique_ptr<database> db;
        unique_ptr<user> student_user;
        unique_ptr<user> librarian_user;

    public:
        controller();
        void studentlogin();
        void librarianlogin();
        void setUserEmail(string email);
        optional<string> getUserEmail();
        void setUserPassword(string password);
        optional<string> getUserPassword();

        ~controller();

};