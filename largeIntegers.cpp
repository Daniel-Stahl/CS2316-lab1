#include "largeIntegers.hpp"

largeIntegers::largeIntegers(){};
largeIntegers::largeIntegers(char newNum) {
    num = newNum;
}

ostream& operator<< (ostream& output, const largeIntegers& lgInt) {
    return output;
}

istream& operator>> (istream& input, largeIntegers& lgInt) {
    cout << "Enter an integer of at most 50 digits:";
    
    do {
        input >> lgInt.num;
        lgInt.num1.push_back(lgInt.num);
    } while (!input.eof());
    
    
    return input;
}


