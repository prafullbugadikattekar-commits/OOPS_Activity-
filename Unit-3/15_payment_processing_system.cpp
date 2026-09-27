#include <iostream>
#include <string>

// Abstract base class representing payment methods
class Payment {
public:
    // Pure virtual function (= 0): interface for executing payment
    virtual void pay(double amount) const = 0;

    // Virtual destructor for safe polymorphic cleanup
    virtual ~Payment() = default;
};

class CardPayment : public Payment {
public:
    // override keyword marks implementation of pure virtual function
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using card\n";
    }
};

class UpiPayment : public Payment {
public:
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using UPI\n";
    }
};

class NetBankingPayment : public Payment {
public:
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using net banking\n";
    }
};

// Standalone function demonstrating dynamic polymorphism via const base reference (&)
// Const reference avoids copying concrete payment objects and invokes overridden methods
void processPayment(const Payment& payment, double amount) {
    payment.pay(amount);
}

int main() {
    CardPayment card;
    UpiPayment upi;
    NetBankingPayment netBanking;

    // Function calling passing derived instances polymorphically by reference (&)
    processPayment(card, 1250.0);
    processPayment(upi, 750.0);
    processPayment(netBanking, 500.0);

    return 0;
}
