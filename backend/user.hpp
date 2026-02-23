#include<string>
#include<optional>
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
        virtual ~user() = default;
        virtual optional<string> get_name() { return name!= "" ? optional<string>(name) : nullopt; }
        virtual optional<string> get_email() { return email!= "" ? optional<string>(email) : nullopt; }
        virtual optional<string> get_password() { return password!= "" ? optional<string>(password) : nullopt; }
        // user(const user&& other){
        //         name = other.name;
        //         email = other.email;
        //         password = other.password;
        //         other.set = nullptr
        //         other.email = "";
        //         other.password = "";
        // }
        user(user&& other) noexcept = default;
        user& operator=(user&& other) noexcept = default;
        user(const user& other) = default;
        user(string name, string email, string password) 
        : name(name), email(email), password(password) {};
        user() = default;
};