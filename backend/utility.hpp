#pragma once

enum status
{
    success,
    failure
};

enum class user_type
{
    student,
    librarian
};

struct db_config {
    string host;
    string user;
    string password;
    string database;
    int port;
};

struct login_credentials {
    string email;
    string password;
};