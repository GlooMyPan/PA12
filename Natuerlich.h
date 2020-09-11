//
// Created by Xuantong Pan on 2020/9/11.
//
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Natuerlich {
    friend ostream &operator<<(ostream & cout, Natuerlich const& n);
public:
    /** Konstruktoren **/
    Natuerlich()
    {
        this->Resize(5);
    }
    Natuerlich(string const & str);
    Natuerlich(long long zahl);
    Natuerlich(Natuerlich const & nat);
    Natuerlich(int laenge, int val);
    ~Natuerlich();

    /** Rechnen **/
    Natuerlich operator+(Natuerlich const& nat) const;
    Natuerlich& operator=(Natuerlich const& nat);

    /** Methode **/
    void Push_back(int val);
    void Resize(int capacity);
    int getCapacity() const;
    int getSize() const;
    int& operator[](int index)const
    {
        return this->_value[index];
    }
private:
    explicit Natuerlich(size_t laenge)
    {
        this->Resize(laenge);
    }

    int * _value;
    int _capacity;
    int _size;
};
