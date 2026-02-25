#include "controller.hpp"

controller::controller()
{
    login = make_shared<loginpage>();
    db = make_shared<database>("libmang");

    switch (login->getUserChoice())
    {
    case 1:
        cout << "You have chosen to continue as a Student." << endl;
        current_user_type = user_type::student;
        user_credentials = login->get_user_credentials();
        student_user = make_shared<student>(user_credentials.email, user_credentials.password);
        if (userlogin(current_user_type) == status::success)
        {
            initstudentSession();
        }

        break;
    case 2:
        cout << "You have chosen to continue as a Librarian." << endl;
        current_user_type = user_type::librarian;
        user_credentials = login->get_user_credentials();
        librarian_user = make_shared<librarian>(user_credentials.email, user_credentials.password);
        if(userlogin(current_user_type) == status::success)
        {
            initlibrarianSession();
        }
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
    try
    {
    if (current_user_type == user_type::student)
    {
       db->getUserDetails(student_user);
    }
    else if (current_user_type == user_type::librarian)
    {
        db->getUserDetails(librarian_user);
    }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return status::failure;
    }
    return status::success;
}

