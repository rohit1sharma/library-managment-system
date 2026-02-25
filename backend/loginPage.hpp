#include<iostream>
#include"student/student.hpp"
#include"librarian/librarian.hpp"
#include"user.hpp"
#include<memory>
#include"utility.hpp"
#include"../database/database.hpp"

#pragma once

using namespace std;

class loginpage {

   
    private:
    int user_choice;
    void display(int choice);
    unique_ptr<student> student_user;
    unique_ptr<librarian> librarian_user;
    login_credentials user_credentials;

    public:
        loginpage();
        unique_ptr<student> get_student_user();
        unique_ptr<librarian> get_librarian_user();
        int getUserChoice();
        status userlogin(shared_ptr<database> db, user_type type);
        login_credentials get_user_credentials();
        // void setUserEmail(string email);
        // optional<string> getUserEmail();
        // void setUserPassword(string password);
        // optional<string> getUserPassword();

};

