#include <mysql/mysql.h>
#include<string>
#include "../backend/user.hpp"
#include<iostream>
#include<string>


using namespace std;

struct db_config {
    string host;
    string user;
    string password;
    string database;
    int port;
};

class database{
    private:
    db_config config;
        MYSQL* conn;
        int create_user(const user& user);
        void delete_user(const user& user);
        void update_user(const user& user);
        void dbConfigInit();
        void print_databases(MYSQL* conn);


    public:
     database(const std::string& dbPath);
    ~database();


};