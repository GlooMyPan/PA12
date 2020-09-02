//
// Created by Xuantong Pan on 2020/9/2.
//
#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Natuerlich {
    friend ostream &operator<<(ostream & cout, Natuerlich& n);
public:
    Natuerlich();
    Natuerlich(string const & str);
    Natuerlich(long long zahl);

    Natuerlich operator+(Natuerlich const& nat) const;

private:
    explicit Natuerlich(size_t laenge);
    vector<int> _value;
};

ostream &operator<<(ostream & cout, Natuerlich& n);
































