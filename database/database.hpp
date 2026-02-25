#include <mysql/mysql.h>
#include<string>
#include "../backend/user.hpp"
#include<iostream>
#include"utility.hpp"
#include<string>
#include<cstring>
#include<vector>
#include<memory>

#pragma once

using namespace std;



class database{
    private:
    db_config config;
    MYSQL* conn;
    int create_user(const user& user);
    void delete_user(const user& user);
    void update_user(const user& user);

    void dbConfigInit(const std::string& dbPath);
    vector<vector<string>> printResult();
    status execute(const string& query);
    
    bool verifyPassword(const std::string& input,const std::string& stored);

    public:
    database(const std::string& dbPath);
    status userCheck(string email, string password, user_type type);
    ~database();
    vector<vector<string>> query(const string& query);
    status getUserDetails(const shared_ptr<user>& user);

};