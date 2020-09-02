//
// Created by Xuantong Pan on 2020/9/2.
//

#include "Natuerlich.h"
#include <algorithm>

Natuerlich::Natuerlich() {
    this->_value.push_back(0);
}

Natuerlich::Natuerlich(long long zahl) {
    while (zahl) {
        this->_value.push_back(zahl % 10);
        zahl /= 10;
    }
}

Natuerlich::Natuerlich(string const & str) {
    int i = str.find_first_not_of('0');
    for (; i < str.size(); ++i) {
        char c = str[i];
        if (c >= '0' && c <= '9')
            this->_value.push_back(c - '0');
    }
    if (this->_value.empty())
        this->_value.push_back(0);
    reverse(this->_value.begin(), this->_value.end());
}

Natuerlich Natuerlich::operator+(const Natuerlich &nat) const {
    int tSize = this->_value.size();
    vector<int> v1 = nat._value;
    vector<int> v2 = this->_value;
    int nSize = v1.size();
    int maxSize = max(tSize, nSize);
    tSize < nSize ? v2.resize(maxSize) : v1.resize(maxSize);
    vector<int> temp(maxSize + 1, 0);
    for (int i = 0; i < maxSize; ++i) {
        int _sum = v2[i] + v1[i];
        if (temp[i] + _sum > 9) {
            temp[i] += _sum - 10;
            ++temp[i + 1];
            int m = 1;
            while (temp[i + m] == 10) {
                temp[i + m++] = 0;
                ++temp[i + m];
            }
        } else
            temp[i] += _sum;
    }
    Natuerlich newClass;
    newClass._value = temp;
    return newClass;
}

ostream &operator<<(ostream &cout, Natuerlich &n) {
    int i = n._value.size() - 1;
    for (int j = n._value.size()-1; j > 0; --j)
        if (n._value[j] == 0)
            --i;
        else
            break;
    for (; ~i; --i)
        cout << n._value[i];
    return cout;
}

Natuerlich::Natuerlich(size_t laenge) {
    this->_value.resize(laenge);
}
