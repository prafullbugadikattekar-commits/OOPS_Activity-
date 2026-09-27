#include <iostream>

class Account{
    private:
        double balance;

        // friend class declaration: gives Auditor full access to private members of Account
        friend class Auditor;

    public:
        // explicit constructor: prevents implicit double-to-Account conversion
        explicit Account(double initialBalance): balance(initialBalance){}
};

class Auditor{
    public:
        // Pass by const reference (&): avoids copying Account and prevents mutation
        void inspect(const Account& account)const{
            // Directly accesses private member 'balance' because Auditor is a friend class
            std::cout<<"Account Balance: "<<account.balance<<'\n';
        }
};

int main(){
    Account account(5000.0);
    Auditor auditor;

    // Calling friend class method to inspect account
    auditor.inspect(account);

    return 0;
}
