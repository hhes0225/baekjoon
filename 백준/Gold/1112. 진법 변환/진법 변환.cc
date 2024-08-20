#include <iostream>
#include <vector>
#include <math.h>

int base_N;

class INT {
    int data;
    public:
    INT(int input){
        data = input;
    }
    void absolutize_data()
    {
        data = abs(data);
    }
    INT operator/ (INT &other)
    {
        return (INT((data - (*this % other)) / other.data));
    }
    int operator% (INT &other)
    {
        int r = data % abs(other.data);
        if (r < 0)
            r += abs(other.data);
        return (r);
    }
    INT operator= (int other)
    {
        data = other;
        return *this;
    }
    bool operator== (int other)
    {
        return (data == other);
    }
    bool operator< (int other)
    {
        return (data < other);
    }
    bool operator> (int other)
    {
        return (data > other);
    }
    bool operator!= (int other)
    {
        return (data != other);
    }
    friend std::istream& operator>> (std::istream &is, INT &p);
};

std::istream& operator>> (std::istream &is, INT &p)
{
    is >> p.data;
    return is;
}

int main()
{
    std::vector<int> change_digit;
    INT x(0);
    INT base(0);
    std::cin >> x >> base_N;
    if (x==0)
        std::cout << 0;
    base = base_N;
    bool isNeg = (base > 0 && x < 0);
    if (base > 0)
        x.absolutize_data();
    while (x != 0){
        change_digit.push_back(x % base);
        x = x / base;
    }
    if (isNeg)
        std::cout << '-';
    for (int i = change_digit.size()-1 ; i >= 0; i--)
    {
        std::cout << change_digit[i];
    }
}