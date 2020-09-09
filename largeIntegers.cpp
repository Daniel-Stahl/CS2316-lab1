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
    
    int stringSize = lgInt.num.size() - 1;
    while (stringSize >= 0) {
        lgInt.largeNum.push_back(lgInt.num.at(stringSize));
        stringSize--;
    }
    
    return input;
}

largeIntegers largeIntegers::operator+(const largeIntegers& lgInt) {
    largeIntegers retInt;
    
    int tempSize = 0;
    int diffSize = 0;
    int x = 0;
    
    if (this->largeNum.size() > lgInt.largeNum.size()) {
        diffSize = this->largeNum.size() - lgInt.largeNum.size();
        tempSize = this->largeNum.size() - diffSize;
        
        while (x < diffSize) {
            retInt.largeNum.push_back(this->largeNum.at(x));
            x++;
        }
        
        for (x = 0; x < lgInt.largeNum.size(); x++) {
            char tempNum = (this->largeNum.at(diffSize+x) + lgInt.largeNum.at(x)) - '0';
            
            if (tempNum < '9') {
                retInt.largeNum.push_back(tempNum);
            } else {
                
            }
        }
        
    } else {
        diffSize = lgInt.largeNum.size() - this->largeNum.size();
    }
    
    

    
    
    return retInt;
}

int largeIntegers::GetNumSize() const {
    return num.size();
}

