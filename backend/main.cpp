#include<iostream>
#include"loginPage.hpp"
#include"../database/database.hpp"

using namespace std;

int main() {
    cout<<"this is a SQL crud application for c++"<<endl;

    cout<<"Library management system"<<endl;

    cout<<"This is a simple library management system that allows users to manage books, members, and borrowing records."<<endl;

    cout<<"The system provides functionalities such as adding new books, registering members, borrowing and returning books, and viewing records."<<endl;

    cout<<"The application is built using C++ and utilizes SQL for database management."<<endl;

    cout<<"please enter if you want to continue as \n 1. Student \n 2. Librarian \n 3. New User \n  4. Exit \n"<<endl;
    int choice;
    cin>>choice;
    
    unique_ptr<loginpage> login = make_unique<loginpage>(choice);

    database db("libmang"); // Replace with your actual database name
    
    
    return 0;
}