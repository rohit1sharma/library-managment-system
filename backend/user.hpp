#include<string>
using namespace std;
#pragma once

class user {

protected:
        string name;
        string email;
        string password;

public:
        virtual void set_name(string name)=0;
        virtual void set_email(string email)=0;
        virtual void set_password(string password)=0;

};