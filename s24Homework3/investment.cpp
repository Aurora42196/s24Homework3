//
//  investment.cpp
//  s24Homework3
//
//  Created by Cameron Maiden on 5/5/24.
//

#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////////
//  Function declarations
///////////////////////////////////////////////////////////////////////////
///
class Investment
{
public:
    Investment(string name, int pp);
    virtual ~Investment();
    // Accessors
    string name();
    int purchasePrice();
private:
    string m_name;
    int m_price;
};

class Painting : public Investment
{
public:
    Painting();
    virtual ~Painting();
    
private:
};

class Stock : public Investment
{
public:
    Stock();
    virtual ~Stock();
private:
};

class House : public Investment
{
public:
    House();
    virtual ~House();
private:
};

///////////////////////////////////////////////////////////////////////////
//  Function implementations
///////////////////////////////////////////////////////////////////////////
///
Investment::Investment(string name, int pp)
 :m_name(name), m_price(pp)
{
    
}

Investment::~Investment()
{
    
}

string Investment::name()
{
    return m_name;
}

int Investment::purchasePrice()
{
    return m_price;
}


///////////////////////////////////////////////////////////////////////////
//  main and display implementations (COMMENT OUT BEFORE TURNING IT IN!)
///////////////////////////////////////////////////////////////////////////

void display(const Investment* inv)
{
//    cout << inv->name();
//    if (inv->fungible())
//        cout << " (fungible)";
//    cout << ": " << inv->description() << " bought for $" << inv->purchasePrice() << endl;
}

int main()
{
//    Investment* portfolio[4];
//    portfolio[0] = new Painting("Salvator Mundi", 450300000);
//      // Stock holdings have a name, value, and ticker symbol
//    portfolio[1] = new Stock("Nvidia", 50000, "NVDA");
//    portfolio[2] = new Stock("Costco", 10000, "COST");
//    portfolio[3] = new House("4 Privet Drive", 670000);
//
//    for (int k = 0; k < 4; k++)
//        display(portfolio[k]);
//
//      // Clean up the investments before exiting
//    cout << "Cleaning up." << endl;
//    for (int k = 0; k < 4; k++)
//        delete portfolio[k];
}
