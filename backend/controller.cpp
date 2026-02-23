#include "controller.hpp"

controller::controller()
{
    login = make_shared<loginpage>();
    db = make_shared<database>("libmang");

    // if (login->get_student_user()) {
    //     student_user = make_unique<student>(move(*login->get_student_user()));
    // }
    // else if (login->get_librarian_user()) {
    //     librarian_user = make_unique<librarian>(move(*login->get_librarian_user()));
    // }

    switch (login->getUserChoice())
    {
    case 1:
        cout << "You have chosen to continue as a Student." << endl;
        current_user_type = user_type::student;
        student_user = make_shared<student>();
        if (userlogin(current_user_type) == status::success)
        {
            initstudentSession();
        }

        break;
    case 2:
        cout << "You have chosen to continue as a Librarian." << endl;
        current_user_type = user_type::librarian;
        librarian_user = make_shared<librarian>();
        break;

    default:
        cout << "Invalid choice. Please enter 1 for Student, 2 for Librarian, or 3 for New User." << endl;
    }

    cout << "Controller initialized successfully!" << endl;
}

controller::~controller()
{
    // Destructor code can be added here if needed
}

void controller::librarianlogin()
{
    // Code for librarian login can be added here
}

status controller::userlogin(user_type type)
{
    // Code for user login can be added here
    status login_status;
    try
    {
        /* code */
        login_status = login->userlogin(db, type);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return login_status;
}

status controller::initstudentSession()
{
    // Code for initializing student session can be added here

    return status::success;
}

status controller::initlibrarianSession()
{
    // Code for initializing librarian session can be added here

    return status::success;
}

status controller::isStudentLoggedIn()
{
    // Code for checking if a student is logged in can be added here

    return status::success;
}

status controller::isLibrarianLoggedIn()
{
    // Code for checking if a librarian is logged in can be added here

    return status::success;
}

status controller::getuserDetails()
{
    // Code for getting user details can be added here
    if (current_user_type == user_type::student)
    {
        
    }

    return status::success;
}

