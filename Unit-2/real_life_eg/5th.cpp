#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Real-world example: Multi-Channel E-Commerce Payment Gateway
// Abstract base class representing any payment processor
class PaymentMethod{
    protected:
        string transactionId;
        double amount;

    public:
        // Parameterized constructor
        PaymentMethod(string Id,double amt)
            :transactionId(Id),amount(amt){}

        // Pure virtual function (= 0): every payment channel must implement its own processing logic
        virtual bool processPayment() const =0;

        // Virtual destructor for safe polymorphic deallocation through smart pointers
        virtual ~PaymentMethod() = default;
};

class CreditCardPayment: public PaymentMethod{
    private:
        string maskedCardNumber;

    public:
        CreditCardPayment(string tid,double amt,string card)
            : PaymentMethod(tid,amt),maskedCardNumber(card){}

        // override keyword: processes credit card transaction
        bool processPayment() const override{
            cout<<"Credit-card transaction "<<transactionId<<" for Rs. "<<amount<<" using "<<maskedCardNumber<<" completed."<<endl;
            return true;
        }
};

class UPIPayment: public PaymentMethod{
    private:
        string upiId;

    public:
        UPIPayment(string tid,double amt,string upi)
            : PaymentMethod(tid,amt),upiId(upi){}

        // Overrides processPayment() for instant UPI transfers
        bool processPayment() const override{
            cout<<"UPI transaction "<<transactionId<<" for Rs. "<<amount<<" using "<<upiId<<" completed."<<endl;
            return true;
        }
};

class NetBankingPayment: public PaymentMethod{
    private:
        string bankName;

    public:
        NetBankingPayment(string tid,double amt,string bank)
            : PaymentMethod(tid,amt),bankName(bank){}

        // Overrides processPayment() for net-banking authentication
        bool processPayment() const override{
            cout<<"Net-banking transaction "<<transactionId<<" for Rs. "<<amount<<" using "<<bankName<<" completed."<<endl;
            return true;
        }
};

int main(){
    // Storing polymorphic objects using smart pointers (unique_ptr) in a vector
    vector<unique_ptr<PaymentMethod>> Payments;
    Payments.push_back(make_unique<CreditCardPayment>("TXN001",2500,"XXXX-XXXX-1234"));
    Payments.push_back(make_unique<UPIPayment>("TX002",1200,"student@upi"));
    Payments.push_back(make_unique<NetBankingPayment>("TX003",5000,"Example Bank"));

    cout<<"===Payment Gateway==="<<endl;
    // Range-based for loop using const reference (&): avoids copying smart pointers
    for(const auto& payment:Payments){
        // Dynamic dispatch / runtime polymorphism: calls appropriate processPayment() for each derived type
        payment->processPayment();
    }
}
