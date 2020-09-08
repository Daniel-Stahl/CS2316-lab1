#include "largeIntegers.hpp"

largeIntegers::largeIntegers(){};
largeIntegers::largeIntegers(string newNum) {
    num = newNum;
}

ostream& operator<< (ostream& output, const largeIntegers& lgInt) {
    output << lgInt.num;
    return output;
}

istream& operator>> (istream& input, largeIntegers& lgInt) {
    int x = 0;
    
    cout << "Enter an integer of at most 50 digits: ";
    
    input >> lgInt.num;
    
    int stringSize = lgInt.num.size();
    while (x < stringSize) {
        lgInt.largeNum.push_back(lgInt.num.at(x));
        x++;
    }
    
    return input;
}

largeIntegers operator+(const largeIntegers& lgInt) {
    largeIntegers largeInt;
    
    
    
    return largeInt;
};

