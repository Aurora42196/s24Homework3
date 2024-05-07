//
//  investment.cpp
//  s24Homework3
//
//  Created by Cameron Maiden on 5/5/24.
//
// (COMMENT OUT #includes BEFORE TURNING IT IN!)
#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////////
//  Class/Function declarations
///////////////////////////////////////////////////////////////////////////
///
class Investment
{
public:
    Investment(string name, int pp);
    virtual ~Investment();
    virtual string description() const = 0;
    virtual bool fungible() const;
    
    // Accessors
    string name() const;
    int purchasePrice() const;
    
private:
    string m_name;
    int m_price;
};

class Painting : public Investment
{
public:
    Painting(string name, int pp);
    virtual ~Painting();
    virtual string description() const;
    
private:
};

class Stock : public Investment
{
public:
    Stock(string name, int pp, string ticker);
    virtual ~Stock();
    virtual string description() const;
    virtual bool fungible() const;

private:
    string m_ticker;
};

class House : public Investment
{
public:
    House(string address, int pp);
    virtual ~House();
    virtual string description() const;

private:
};

///////////////////////////////////////////////////////////////////////////
//  Function implementations
///////////////////////////////////////////////////////////////////////////
///
// Investment functions
Investment::Investment(string name, int pp)
 :m_name(name), m_price(pp)
{}

Investment::~Investment()
{}

string Investment::name() const
{
    return m_name;
}

int Investment::purchasePrice() const
{
    return m_price;
}

bool Investment::fungible() const
{
    return false;
}

// Painting functions
Painting::Painting(string name, int price)
 : Investment(name, price)
{
    
}

Painting::~Painting()
{
    cout << "Destroying " << name() << ", a painting" << endl;
}

string Painting::description() const
{
    return "painting";
}


// Stock functions
Stock::Stock(string name, int pp, string ticker)
 : Investment(name, pp), m_ticker(ticker)
{}

Stock::~Stock()
{
    cout << "Destroying " << name() << ", a stock holding" << endl;
}

string Stock::description() const
{
    return "stock trading as " + m_ticker;
}

bool Stock::fungible() const
{
    return true;
}

// House functions
House::House(string address, int pp)
 :Investment(address, pp)
{}

House::~House()
{
    cout << "Desroying the house " << name() << endl;
}

string House::description() const
{
    return "house";
}




///////////////////////////////////////////////////////////////////////////
//  main and display implementations (COMMENT OUT BEFORE TURNING IT IN!)
///////////////////////////////////////////////////////////////////////////

void display(const Investment* inv)
{
    cout << inv->name();
    if (inv->fungible())
        cout << " (fungible)";
    cout << ": " << inv->description() << " bought for $" << inv->purchasePrice() << endl;
}

int main()
{
//    Investment* ip = new Investment("name", 0);
    Investment* portfolio[4];
    portfolio[0] = new Painting("Salvator Mundi", 450300000);
      // Stock holdings have a name, value, and ticker symbol
    portfolio[1] = new Stock("Nvidia", 50000, "NVDA");
    portfolio[2] = new Stock("Costco", 10000, "COST");
    portfolio[3] = new House("4 Privet Drive", 670000);

    for (int k = 0; k < 4; k++)
        display(portfolio[k]);

      // Clean up the investments before exiting
    cout << "Cleaning up." << endl;
    for (int k = 0; k < 4; k++)
        delete portfolio[k];
}
