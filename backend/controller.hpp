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
        shared_ptr<loginpage> login;
        shared_ptr<database> db;
        shared_ptr<user> student_user;
        shared_ptr<user> librarian_user;
        user_type current_user_type;
        login_credentials user_credentials;

    public:
        controller();
        status userlogin(user_type type);
        void librarianlogin();
        status isStudentLoggedIn();
        status isLibrarianLoggedIn();
        status initstudentSession();
        status initlibrarianSession();
        status getuserDetails();

        ~controller();

};