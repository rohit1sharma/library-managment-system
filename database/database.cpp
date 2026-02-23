#include"database.hpp"

database::database(const std::string& dbPath) {

    dbConfigInit(dbPath);
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
    //print_databases(conn);
}

database::~database() {
    mysql_close(conn);
    cout<<"Database connection closed."<<endl;
}

void database::dbConfigInit(const std::string& dbPath) {
    // Code for connecting to the database can be added here
    config.host = "localhost";
    config.user = "appuser";       
    config.password = "StrongPass123!"; // Replace with your actual password
    config.database = dbPath.c_str(); // Replace with your actual database name
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

vector<vector<string>> database::printResult()
{
    vector<vector<string>> result;
    MYSQL_RES* res = mysql_store_result(conn);

    if (res == nullptr)
    {
        std::cerr << "Store result failed: "
                  << mysql_error(conn) << std::endl;
        return result;
    }
    int num_fields = mysql_num_fields(res);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res)))
    {
        vector<string> row_data;
        for (int i = 0; i < num_fields; ++i) {
            row_data.push_back(row[i] ? row[i] : "NULL");
        }
        result.push_back(row_data);
    }

    mysql_free_result(res);
    return result;
}


status database::userCheck(std::string email,std::string password,user_type type)
{
    const char* query = nullptr;

    if (type == user_type::student) {
        query =
            "SELECT sc.password "
            "FROM student s "
            "JOIN student_login sc "
            "ON s.id = sc.student_id "
            "WHERE s.email = ?";
    }
    else if (type == user_type::librarian) {
        query =
            "SELECT llog.password "
            "FROM librarian lib "
            "JOIN librarian_login llog "
            "ON lib.id = llog.librarian_id "
            "WHERE lib.email = ?";
    }
    else {
        return status::failure;
    }

    MYSQL_STMT* stmt = mysql_stmt_init(conn);
    if (!stmt) {
        std::cerr << "Statement init failed\n";
        return status::failure;
    }

    if (mysql_stmt_prepare(stmt, query, strlen(query))) {
        std::cerr << "Prepare failed: "
                  << mysql_stmt_error(stmt) << std::endl;
        mysql_stmt_close(stmt);
        return status::failure;
    }

    // --------------------
    // Bind input parameter
    // --------------------
    MYSQL_BIND param[1];
    memset(param, 0, sizeof(param));

    param[0].buffer_type = MYSQL_TYPE_STRING;
    param[0].buffer = (void*)email.c_str();
    param[0].buffer_length = email.length();

    if (mysql_stmt_bind_param(stmt, param)) {
        std::cerr << "Bind param failed: "
                  << mysql_stmt_error(stmt) << std::endl;
        mysql_stmt_close(stmt);
        return status::failure;
    }

    if (mysql_stmt_execute(stmt)) {
        std::cerr << "Execute failed: "
                  << mysql_stmt_error(stmt) << std::endl;
        mysql_stmt_close(stmt);
        return status::failure;
    }

    // --------------------
    // Bind result
    // --------------------
    char stored_password[256];
    unsigned long length = 0;
    bool is_null = 0;

    MYSQL_BIND result[1];
    memset(result, 0, sizeof(result));

    result[0].buffer_type = MYSQL_TYPE_STRING;
    result[0].buffer = stored_password;
    result[0].buffer_length = sizeof(stored_password);
    result[0].length = &length;
    result[0].is_null = &is_null;

    if (mysql_stmt_bind_result(stmt, result)) {
        std::cerr << "Bind result failed: "
                  << mysql_stmt_error(stmt) << std::endl;
        mysql_stmt_close(stmt);
        return status::failure;
    }

    if (mysql_stmt_store_result(stmt)) {
        std::cerr << "Store result failed: "
                  << mysql_stmt_error(stmt) << std::endl;
        mysql_stmt_close(stmt);
        return status::failure;
    }

    int fetch_status = mysql_stmt_fetch(stmt);

    if (fetch_status == MYSQL_NO_DATA || is_null) {
        mysql_stmt_free_result(stmt);
        mysql_stmt_close(stmt);
        return status::failure;
    }

    // Ensure null termination safely
    if (length >= sizeof(stored_password))
        length = sizeof(stored_password) - 1;

    stored_password[length] = '\0';

    mysql_stmt_free_result(stmt);
    mysql_stmt_close(stmt);

    // --------------------
    // Compare password
    // --------------------
    if (verifyPassword(password, stored_password)) {
        printResult();
        return status::success;
    }

    printResult();
    return status::failure;
}

bool database::verifyPassword(const std::string& input,
                    const std::string& stored)
{
    return input == stored;  // Replace later with hash comparison
}

status database::execute(const string& query) { 
    // Code for executing a SQL query can be added here
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Query failed: "
                  << mysql_error(conn) << std::endl;
        return status::failure;
    }
    return status::success; // Return success or failure based on the execution result
}

vector<vector<string>> database::query(const string& query) {

    std::vector<std::vector<std::string>> result;

    if (mysql_query(conn, query.c_str())) {
        throw std::runtime_error(mysql_error(conn));
    }
    result = printResult();
    return result; // Return the fetched results as a vector of vectors of strings
}