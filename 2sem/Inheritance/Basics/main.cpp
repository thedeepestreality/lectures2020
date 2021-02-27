#include <iostream>

class Base
{
private:
    int _b_priv;
public:
    int _b_publ;
protected:
    int _b_prot;
    int get_priv()
    {
        return _b_priv;
    }
};

class PublicChild : public Base
{
public:
    void check_fields()
    {
        _b_publ = 1;
        _b_prot = 2;
        //_b_priv = 3;
    }
};

class ProtectedChild : protected Base
{
public:
    void check_fields()
    {
        _b_publ = 1;
        _b_prot = 2;
        //_b_priv = 3;
    }
};

class PrivateChild : private Base
{
public:
    void check_fields()
    {
        _b_publ = 1;
        _b_prot = 2;
        //_b_priv = 3;
    }
};

class ProtectedChildPublicChild : public ProtectedChild
{
public:
    void check_fields()
    {
        _b_publ = 1;
        _b_prot = 2;
        //_b_priv = 3;
    }
};

class PrivateChildPublicChild : public PrivateChild
{
public:
    void check_fields()
    {
        //_b_publ = 1;
        //_b_prot = 2;
        //_b_priv = 3;
    }
};

int main()
{
    Base b;
    PublicChild c_publ;
    c_publ._b_publ = 2;
   // c._b_prot = 3;
    ProtectedChild c_prot;
    //c_prot._b_publ = 3;
    return 0;
}