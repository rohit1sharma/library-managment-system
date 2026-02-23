#include"controller.hpp"

controller::controller()
{
    login = make_unique<loginpage>();
    db = make_unique<database>("libmang");

    // if (login->get_student_user()) {
    //     student_user = make_unique<student>(move(*login->get_student_user()));
    // }
    // else if (login->get_librarian_user()) {
    //     librarian_user = make_unique<librarian>(move(*login->get_librarian_user()));
    // }

    switch(login->getUserChoice()) {
        case 1:
            cout<<"You have chosen to continue as a Student."<<endl;
            student_user = make_unique<student>();
            try
            {
                /* code */
                studentlogin();
            }
            catch(const std::exception& e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        case 2:
            cout<<"You have chosen to continue as a Librarian."<<endl;
            librarian_user = make_unique<librarian>();
            break;

        default:
            cout<<"Invalid choice. Please enter 1 for Student, 2 for Librarian, or 3 for New User."<<endl;
    }


    cout<<"Controller initialized successfully!"<<endl;
    

}

controller::~controller() {
    // Destructor code can be added here if needed
}

void controller::studentlogin() {
    // Code for student login can be added here
    cout<<"please enter email and password to login"<<endl;
    if(student_user) 
    {
    string email, password;
    cin>>email;
    setUserEmail(email);
    cin>>password;
    setUserPassword(password);
    if (db->studentCheck(student_user->get_email().value(), student_user->get_password().value()) == status::success) {
        cout << "Login successful!" << endl;
        // Proceed with student functionalities
    } 
}
    else {
        cout << "Login failed. Please check your email and password." << endl;
    }

}

void controller::setUserEmail(string email) {
    if (student_user) {
        student_user->set_email(email);
    } else if (librarian_user) {
        librarian_user->set_email(email);
    }
}

void controller::setUserPassword(string password) {
    if (student_user) {
        student_user->set_password(password);
    } else if (librarian_user) {
        librarian_user->set_password(password);
    }
}

optional<string> controller::getUserEmail() {
    if (student_user) {
        return student_user->get_email();
    } else if (librarian_user) {
        return librarian_user->get_email();
    }
    return nullopt;
}

optional<string> controller::getUserPassword() {
    if (student_user) {
        return student_user->get_password();
    } else if (librarian_user) {
        return librarian_user->get_password();
    }
    return nullopt;
}

void controller::librarianlogin() {
    // Code for librarian login can be added here
}