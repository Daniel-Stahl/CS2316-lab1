#include "largeIntegers.hpp"

largeIntegers::largeIntegers(){}
largeIntegers::largeIntegers(string newNum) {
    num = newNum;
}

ostream& operator<< (ostream& output, const largeIntegers& lgInt) {
    output << lgInt.num << "\n";
    return output;
}

istream& operator>> (istream& input, largeIntegers& lgInt) {
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
    int diffSize = 0;
    bool plusOne = false;
    int x = 0;
    char tempNum;
    int twoDigits = 0;
    int vecSize = 0;
    
    if (this->largeNum.size() > lgInt.largeNum.size()) {
        vecSize = this->largeNum.size();
    } else {
        vecSize = lgInt.largeNum.size();
    }
    
    while (x < vecSize) {
        if (this->largeNum.size() > x && lgInt.largeNum.size() > x) {
            if (plusOne) {
                tempNum = (this->largeNum.at(x) + lgInt.largeNum.at(x)) - '0';
                tempNum++;
            } else {
                tempNum = (this->largeNum.at(x) + lgInt.largeNum.at(x)) - '0';
            }
            
            if (tempNum <= '9') {
                retInt.largeNum.push_back(tempNum);
                plusOne = false;
            } else {
                twoDigits = (int)(tempNum);
                tempNum = DecimalConverter(twoDigits);
                retInt.largeNum.push_back(tempNum);
                plusOne = true;
            }
        } else if (this->largeNum.size() > x ) {
            tempNum = this->largeNum.at(x);
            if (plusOne) {
                tempNum++;
            }
            retInt.largeNum.push_back(tempNum);
            plusOne = false;
        } else {
            tempNum = lgInt.largeNum.at(x);
            if (plusOne) {
                tempNum++;
            }
            retInt.largeNum.push_back(tempNum);
            plusOne = false;
        }
        
        x++;
    }
    
    if (plusOne) {
        retInt.largeNum.push_back('1');
    }
    
    retInt.num.append(retInt.largeNum.rbegin(), retInt.largeNum.rend());
    cout << this->num + " + " + lgInt.num + " = " + retInt.num + "\n";
    
    return retInt;
}

largeIntegers largeIntegers::operator-(const largeIntegers& lgInt) {
    largeIntegers retInt;
    largeIntegers num1 = *this;
    largeIntegers num2 = lgInt;
    int vecSize, x = 0;
    char tempNum;
    int num1Size = this->largeNum.size();
    int num2Size = lgInt.largeNum.size();
    bool isNegative = false;
    
    if (num1Size > num2Size) {
        vecSize = this->largeNum.size();
    } else if (num1Size == num2Size) {
        bool isLarger = false;
        
        while (num1Size > x && !isLarger) {
            --num1Size;
            
            if (num1.largeNum.at(num1Size) > num2.largeNum.at(num1Size)) {
                isLarger = true;
            } else if (num1.largeNum.at(num1Size) == num2.largeNum.at(num1Size)) {
                isLarger = false;
            } else {
                isLarger = true;
                isNegative = true;
                num1 = lgInt;
                num2 = *this;
            }
        }
        
        
        
        vecSize = lgInt.largeNum.size();
        
    } else {
        vecSize = lgInt.largeNum.size();
    }
    
    
    
    while (x < vecSize) {
        if (this->largeNum.size() > x && lgInt.largeNum.size() > x) {
            if (num1Size == num2Size) {
                
            }
            
            
            tempNum = (this->largeNum.at(x) - lgInt.largeNum.at(x)) - '0';
        } else if (this->largeNum.size() > x ) {
            
        } else {
            
        }
        
        
        
    }
    
    
    return retInt;
}

largeIntegers largeIntegers::operator==(const largeIntegers& lgInt) {
    
    return largeIntegers();
}

largeIntegers largeIntegers::operator!=(const largeIntegers& lgInt) {
    
    return largeIntegers();
}

largeIntegers largeIntegers::operator>(const largeIntegers& lgInt) {
    
    return largeIntegers();
}

largeIntegers largeIntegers::operator>=(const largeIntegers& lgInt) {
    
    return largeIntegers();
}

largeIntegers largeIntegers::operator<(const largeIntegers& lgInt) {
    
    return largeIntegers();
}

largeIntegers largeIntegers::operator<=(const largeIntegers& lgInt) {
    
    return largeIntegers();
}



char largeIntegers::DecimalConverter(int decimal) {
    char c;
    int tempNum = 0;
    
    tempNum = (decimal - 48) - 10;
    c = '0' + tempNum;
    
    return c;
}

