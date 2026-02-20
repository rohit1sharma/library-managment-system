#include "../user.hpp"

class librarian : public user {   

    private:
            void set_name(string name) override;
            void set_email(string email) override;
            void set_password(string password) override;


        int employee_number;
        string name;
        string email;
        int joining_year;

    public:
            //Convert to optional
        void checkBookAvailability();
        void addBook();
        void removeBook();
        void updateBookInfo();
        void viewBorrowingRecords();
        void manageMembers();
        void generateReports();
        void updateStudentProfile(); // balance update also
        void searchBooks();



};