//
// Created by Xuantong Pan on 2020/9/11.
//

#include "Natuerlich.h"

Natuerlich::Natuerlich(string const & str)
{
    this->Resize(str.size());
    string str2 = str.substr(str.find_first_not_of('0'));  // z.B 000111 -> 111
    for (int i = str2.size() - 1; ~i; --i)
    {
        if (str2[i] >= '0' && str2[i] <= '9') // nur wenn c eine Zahl ist.
            this->Push_back(str2[i] - '0');
    }
    if (!this->getSize())
        this->Push_back(0); // wenn str empty ist, denn _value ist [0]
}

/**
 * die Zahl 123456 ist in _value:
 * [6, 5, 4, 3, 2, 1]
 */


Natuerlich::Natuerlich(long long zahl)
{
    this->Resize(5);
    if (zahl == 0)
        this->Push_back(0);

    else
        while (zahl != 0)
        {
            this->Push_back(zahl % 10);
            zahl /= 10;
        }
}

Natuerlich::Natuerlich(const Natuerlich &nat)
{
    this->_capacity = nat._capacity;
    this->_size = nat._size;

    this->_value = new int[nat._capacity];

    for (int i = 0; i < this->_size; ++i)
        this->_value[i] = nat._value[i];

}


Natuerlich::Natuerlich(int laenge, int val)
{
    this->Resize(laenge);
    this->_size = this->getCapacity();
    for (int i = 0; i < this->_size; ++i)
        this->_value[i] = val;
}

void Natuerlich::Push_back(int val)
{
    if (this->_value)
    {
        if (this->_size == this->_capacity)
            this->Resize(this->_capacity + 2);
        this->_value[this->_size++] = val;
    }
}

void Natuerlich::Resize(int capacity)
{
    if (this->getCapacity() >= capacity)
        return;
    if (this->getSize() > 0)
    {
        int * temp = new int[capacity];
        for (int i = 0; i < this->_size; ++i)
            temp[i] = this->_value[i];

        delete [] this->_value;
        this->_value = temp;
        this->_capacity = capacity;
    }
    else
    {
        this->_value = new int[capacity];
        this->_capacity = capacity;
        this->_size = 0;
    }
}

int Natuerlich::getCapacity() const
{
    if (this->_capacity)
        return this->_capacity; // nur wenn _capacity > 0 ist.
    else
        return 0;
}

int Natuerlich::getSize() const
{
    if (this->_size)
        return this->_size; // nur wenn _size > 0 ist.
    else
        return 0;
}


Natuerlich Natuerlich::operator+(const Natuerlich &nat) const
{
    int tSize = this->getSize();
    Natuerlich n1 = nat;
    Natuerlich n2 = *this;
    int nSize = n1.getSize();
    int maxSize = max(tSize, nSize);
    tSize < nSize ? n2.Resize(maxSize) : n1.Resize(maxSize);
    Natuerlich ans(maxSize + 1, 0);
    for (int i = 0; i < maxSize; ++i)
    {
        if (n2[i] < 0)
            n2[i] = 0;

        if (n1[i] < 0)
            n1[i] = 0;
        int _sum = n2[i] + n1[i];
        if (ans[i] + _sum > 9)
        {
            ans[i] += _sum - 10;
            ++ans[i+1];

            int m = 1;
            while (ans[i+m] == 10)
            {
                ans[i+m++] = 0;
                ++ans[i+m];
            }
        } else
            ans[i] += _sum;
    }
    return ans;
}

Natuerlich& Natuerlich::operator=(const Natuerlich &nat)
{
    if (this->_value)
    {
        delete [] this->_value;
        this->_value = nullptr;
        this->_capacity = 0;
        this->_size = 0;
    }

    this->_capacity = nat._capacity;
    this->_size = nat._size;
    this->_value = new int[nat._capacity];
    for (int i = 0; i < this->_size; ++i)
        this->_value[i] = nat._value[i];

    return *this; // damit a = b = c funktioniert
}

ostream &operator<<(ostream &cout, Natuerlich const &n)
{
    if (n.getSize() == 1 && n[0] == 0)
        cout << 0;
    else
    {
        int i = n.getSize() - 1;
        for (int j = n.getSize() - 1; j > 0; --j)
            if (n[j] == 0)
                --i;
            else
                break;

        for (; ~i; --i)
            cout << n[i];
    }
    return cout;
}



Natuerlich::~Natuerlich()
{
    if (this->_value)
    {
        delete[] this->_value;
        this->_value = nullptr;
        this->_capacity = 0;
        this->_size = 0;
    }
}
