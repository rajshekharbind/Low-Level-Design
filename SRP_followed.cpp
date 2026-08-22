#include<bits/stdc++.h>
using namespace std;

class Product {
    public:
    string name;
    double price;

    Product(string name,string price){
        this->name=name;
        this->price=stod(price);
    }
};

//1.ShoppingCart: Only responsible for cart related bussiness logic like adding product to cart, calculating total price, and getting products in the cart.
class ShoppingCart{
private:
    vector<Product*>products;

public:
    void addProduct(Product* p){
        products.push_back(p);
    }
    const vector<Product*>& getProducts(){
        return products;
    }
   

    //2. Calculate total price of products in the cart
    double calculateTotalPrice(){
        double total=0;
        for(auto p:products){
            total += p->price;
        }
        return total;
    }
};

//3. InvoicePrinter: Responsible for printing the invoice for the products in the cart.
class InvoicePrinter{
private:
    ShoppingCart* cart;
public:
    InvoicePrinter(ShoppingCart* cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout << "Invoice:" << endl;
        for(auto p:cart->getProducts()){
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total: $" << cart->calculateTotalPrice() << endl;
    }
};

//4. shoppingCartDB: Responsible for saving the cart to the database.
class ShoppingCartDB{
private:
    ShoppingCart* cart;
public:
    ShoppingCartDB(ShoppingCart* cart) : cart(cart) {}

    void saveToDB(){
        // Implementation for saving to database
        cout << "Saving cart to database..." << endl;
    }
};

int main(){
    ShoppingCart cart;
    Product* p1 = new Product("Laptop","1000");
    Product* p2 = new Product("Mouse","50");
    cart.addProduct(p1);
    cart.addProduct(p2);

    InvoicePrinter invoicePrinter(&cart);
    invoicePrinter.printInvoice();

    ShoppingCartDB cartDB(&cart);
    cartDB.saveToDB();

    delete p1;
    delete p2;

    return 0;
}