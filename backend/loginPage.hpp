#include<iostream>
#include"student/student.hpp"
#include"librarian/librarian.hpp"
#include<memory>

using namespace std;

class loginpage {

   
    private:
        void display(int choice);


        unique_ptr<student> student_user;
        unique_ptr<librarian> librarian_user;

    public:
        loginpage(int choice);
       

};