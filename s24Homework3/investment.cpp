//
//  investment.cpp
//  s24Homework3
//
//  Created by Cameron Maiden on 5/5/24.
//

// What you'll turn in for this problem will be a file named investment.cpp containing the definitions and implementations of the four classes, and nothing more.
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Investment functions
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Painting functions
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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Stock functions
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  House functions
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
