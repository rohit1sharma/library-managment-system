#include"database.hpp"

database::database(const std::string& dbPath) {

    dbConfigInit();
    conn = mysql_init(nullptr);
    if (conn == nullptr) {
        cerr << "MySQL initialization failed" << endl;
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(conn, config.host.c_str(),
                            config.user.c_str(), 
                            config.password.c_str(),
                            config.database.c_str(),
                            config.port, 
                            nullptr,
                             0) == nullptr) 
       {
        cerr << "Connection to database failed: " << mysql_error(conn) << endl;
        mysql_close(conn);
        exit(EXIT_FAILURE);
    }

    cout<<"Connected to database successfully!"<<endl;
    std::cout << mysql_error(conn) << std::endl;
    print_databases(conn);
}

database::~database() {
    mysql_close(conn);
    cout<<"Database connection closed."<<endl;
}

void database::dbConfigInit() {
    // Code for connecting to the database can be added here
    config.host = "localhost";
    config.user = "appuser";       
    config.password = "StrongPass123!"; // Replace with your actual password
    config.database = "test"; // Replace with your actual database name
    config.port = 3306; // Default MySQL port

}

int database::create_user(const user& user) {
    // Code for creating a new user in the database can be added here
    return 0; // Return the ID of the newly created user
}

void database::delete_user(const user& user) {
    // Code for deleting a user from the database can be added here
}

void database::update_user(const user& user) {
    // Code for updating user information in the database can be added here
}

void database::print_databases(MYSQL* conn)
{
    if (mysql_query(conn, "SHOW DATABASES;"))
    {
        std::cerr << "Query failed: "
                  << mysql_error(conn) << std::endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(conn);

    if (result == nullptr)
    {
        std::cerr << "Store result failed: "
                  << mysql_error(conn) << std::endl;
        return;
    }

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)))
    {
        std::cout << row[0] << std::endl;
    }

    mysql_free_result(result);
}
