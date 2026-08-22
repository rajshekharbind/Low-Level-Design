#include<bits/stdc++.h>
using namespace std;
// Precondition Rule :
// A subclass should not strengthen the preconditions of the parent class.
class User {
    public:
        virtual void setPassword(string password) {
              if(password.length() < 8) {
                throw invalid_argument("Password must be at least 8 characters long");  
        }
        cout << "Password set successfully" << endl;
}
};

class AdminUser : public User {
    public:
    // Precondition: Admin password must be at least 6 characters long.
        void setPassword(string password) override {
            if(password.length() < 6) {
                throw invalid_argument("Admin password must be at least 6 characters long");  
            }
            cout << "Admin password set successfully" << endl;
        }
};

int main() {
    User* user = new User();
    user->setPassword("password123"); // Valid password
    User* admin = new AdminUser();
    admin->setPassword("admin"); // This should not be allowed, but it is due to violation of LSP
    return 0;
}