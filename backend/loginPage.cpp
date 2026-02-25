#include"loginPage.hpp"

loginpage::loginpage()
    {
        cin>>user_choice;
        display(user_choice);
    }


void loginpage::display(int choice)
{
    //while(true)
    {
        switch(choice) 
        {
        case 1:
            cout<<"You have chosen to continue as a Student."<<endl;
            break;
        case 2:
            cout<<"You have chosen to continue as a Librarian."<<endl;
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

unique_ptr<student> loginpage::get_student_user() {
    return move(student_user);
}
unique_ptr<librarian> loginpage::get_librarian_user() {
    return move(librarian_user);
}

int loginpage::getUserChoice() {
    return user_choice;
}

status loginpage::userlogin(shared_ptr<database> db, user_type type)
{
    // Code for user login can be added here
    cout << "please enter email and password to login" << endl;
    if (student_user || librarian_user)
    {
        cin >> user_credentials.email;
        cin >> user_credentials.password;
        if (db->userCheck(user_credentials.email,user_credentials.password,type) == status::success)
        {
            cout << "Login successful!" << endl;
            return status::success;
            // Proceed with student functionalities
        }
    }
    else
    {
        cout << "Login failed. Please check your email and password." << endl;
        return status::failure;
    }
}

login_credentials loginpage::get_user_credentials() {
    return user_credentials;
}

// void loginpage::setUserEmail(string email)
// {
//     if (student_user)
//     {
//         student_user->set_email(email);
//     }
//     else if (librarian_user)
//     {
//         librarian_user->set_email(email);
//     }
// }

// void loginpage::setUserPassword(string password)
// {
//     if (student_user)
//     {
//         student_user->set_password(password);
//     }
//     else if (librarian_user)
//     {
//         librarian_user->set_password(password);
//     }
// }

// optional<string> loginpage::getUserEmail()
// {
//     if (student_user)
//     {
//         return student_user->get_email();
//     }
//     else if (librarian_user)
//     {
//         return librarian_user->get_email();
//     }
//     return nullopt;
// }

// optional<string> loginpage::getUserPassword()
// {
//     if (student_user)
//     {
//         return student_user->get_password();
//     }
//     else if (librarian_user)
//     {
//         return librarian_user->get_password();
//     }
//     return nullopt;
// }