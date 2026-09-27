#include <iostream>
#include <string>
using namespace std;

// Real-world example: Warehouse Inventory & Product Catalog Management
class Product{
    private:
        int productId;
        string productName;
        double price;
        int stockQuantity;
        // static member variable: shared count of products across all instances
        static int totalProduct;

    public:
        // Parameterized constructor increments static product count on creation
        Product(int id,string name,double p,int stock)
            :productId(id),productName(name),price(p),stockQuantity(stock){
                totalProduct++;
            }

        // inline and const getters: expanded inline without modifying object state
        inline int getId() const{return productId;}
        inline string getName() const {return productName;}
        inline double getPrice() const {return price;}

        // Member function definition to update inventory stock
        void updateStock(int quantity){
            stockQuantity = quantity;
        }

        // static member function: accessible without creating an object instance
        static int getTotalProduct(){
            return totalProduct;
        }

        // const member function definition for reporting product info
        void display() const{
            cout<<"ID:"<<productId<<"|Product: "<<productName<<"| Price:RS "<<price<<"|Stock: "<<stockQuantity<<endl;
        }

        // Destructor decrements static product counter when an object is destroyed
        ~Product(){
            totalProduct--;
        }

};

// Definition and initialization of static member variable outside class
int Product::totalProduct = 0;

int main()
{
    Product p1(1001,"Laptop",55000,15);
    Product p2(1002,"Mouse",450,50);
    Product p3(1003,"Keyboard",1200,30);

    cout<<"===Product Catalog==="<<endl;
    // Calling display member functions on individual objects
    p1.display();
    p2.display();
    p3.display();

    // Calling static member function using class scope resolution operator (::)
    cout<<"\n Total Products in Catalog: "<<Product::getTotalProduct()<<endl;
}
