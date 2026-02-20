#include<iostream>
#include"student/student.hpp"
#include"librarian/librarian.hpp"
#include<memory>

using namespace std;

class homepage {

   
    private:
        void display(int choice);


        unique_ptr<student> student_user;
        unique_ptr<librarian> librarian_user;

    public:

        homepage(int choice)
        {
            display(choice);
        }


};

void homepage::display(int choice)
{
    while(true)
    {
        switch(choice) 
        {
        case 1:
            cout<<"You have chosen to continue as a Student."<<endl;
            student_user = make_unique<student>();

            break;
        case 2:
            cout<<"You have chosen to continue as a Librarian."<<endl;
            librarian_user = make_unique<librarian>();
            break;
        case 3:
            cout<<"You have chosen to register as a New User."<<endl;
            // Code for new user registration can be added here
            break;
        case 4:
            cout<<"Exiting the application. Goodbye!"<<endl;
            return;
        default:
            cout<<"Invalid choice. Please enter 1 for Student, 2 for Librarian, or 3 for New User."<<endl;
        }
    }
}