//
// Created by Xuantong Pan on 2020/9/2.
//

#include "Natuerlich.h"
#include <algorithm> // reverse()

Natuerlich::Natuerlich() {
    this->_value.push_back(0);
}

Natuerlich::Natuerlich(long long zahl) {
    while (zahl) {
        this->_value.push_back(zahl % 10);
        zahl /= 10;
    }
}

/**
 * die Zahl 123456 ist in _value:
 * [6, 5, 4, 3, 2, 1]
 */

Natuerlich::Natuerlich(string const & str) {
    int i = str.find_first_not_of('0'); // z.B 000111 -> 111
    for (; i < str.size(); ++i) {
        char c = str[i];
        if (c >= '0' && c <= '9')
            this->_value.push_back(c - '0'); // nur wenn c eine Zahl ist.
    }
    if (this->_value.empty())
        this->_value.push_back(0); // wenn str empty ist, denn _value ist [0]

    reverse(this->_value.begin(), this->_value.end());
}

Natuerlich Natuerlich::operator+(const Natuerlich &nat) const {
    int tSize = this->_value.size();
    vector<int> v1 = nat._value;
    vector<int> v2 = this->_value;
    int nSize = v1.size(); // size() von nat._value
    int maxSize = max(tSize, nSize);
    tSize < nSize ? v2.resize(maxSize) : v1.resize(maxSize); // resize die beide Vectoren zum maxSize
    vector<int> ans(maxSize + 1, 0); // die Summe von v1 und v2
    for (int i = 0; i < maxSize; ++i) {
        int _sum = v2[i] + v1[i];
        if (ans[i] + _sum > 9) {
            ans[i] += _sum - 10;
            ++ans[i + 1];
            int m = 1;
            while (ans[i + m] == 10) {
                ans[i + m++] = 0;
                ++ans[i + m];
            }
        } else
            ans[i] += _sum;
    }
    Natuerlich newClass;
    newClass._value = ans;
    return newClass;
}

ostream &operator<<(ostream &cout, Natuerlich &n) {
    if (n._value == vector<int>(1, 0))
        cout << 0;
    else {
        int i = n._value.size() - 1;
        for (int j = n._value.size()-1; j > 0; --j)
            if (n._value[j] == 0)
                --i;
            else
                break;
        for (; ~i; --i)
            cout << n._value[i];
    }

    return cout;
}

Natuerlich::Natuerlich(size_t laenge) {
    this->_value.resize(laenge);
}
