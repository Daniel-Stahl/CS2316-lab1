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
    
    int stringSize = lgInt.num.size();
    
    if (stringSize > 49 ) {
        lgInt.num = '0';
        lgInt.largeNum.push_back('0');
        
        cout << "This number has more than 50 digits. Number is set to 0\n";
    } else {
        stringSize--;
        
        while (stringSize >= 0) {
            lgInt.largeNum.push_back(lgInt.num.at(stringSize));
            stringSize--;
        }
    }
    
    return input;
}

largeIntegers largeIntegers::operator+(const largeIntegers& lgInt) {
    largeIntegers retNum;
    int diffSize = 0;
    bool plusOne, isNegative = false;
    int x = 0;
    char tempNum;
    int twoDigits = 0;
    int vecSize = 0;
    largeIntegers num1 = *this;
    largeIntegers num2 = lgInt;
    int num1Size = this->largeNum.size();
    int num2Size = lgInt.largeNum.size();
    //this->largeNum.at(num1Size - 1) == '-' && lgInt.largeNum.at(num2Size - 1) != '-'
    if (this->num < lgInt.num && this->largeNum.at(num1Size - 1) == '-') {
        num1.largeNum.pop_back();
        retNum = num1 - num2;
        
    }
    
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
                retNum.largeNum.push_back(tempNum);
                plusOne = false;
            } else {
                twoDigits = (int)(tempNum);
                tempNum = DecimalConverter(twoDigits);
                retNum.largeNum.push_back(tempNum);
                plusOne = true;
            }
        } else if (this->largeNum.size() > x ) {
            tempNum = this->largeNum.at(x);
            if (plusOne) {
                tempNum++;
            }
            retNum.largeNum.push_back(tempNum);
            plusOne = false;
        } else {
            tempNum = lgInt.largeNum.at(x);
            if (plusOne) {
                tempNum++;
            }
            retNum.largeNum.push_back(tempNum);
            plusOne = false;
        }
        
        x++;
    }
    
    if (plusOne) {
        retNum.largeNum.push_back('1');
    }
    
    retNum.num.append(retNum.largeNum.rbegin(), retNum.largeNum.rend());
    cout << "num1 + num2 = " << retNum;
    
    return retNum;
}

largeIntegers largeIntegers::operator-(const largeIntegers& lgInt) {
    largeIntegers retNum;
    largeIntegers num1 = *this;
    largeIntegers num2 = lgInt;
    int x = 0;
    char tempNum;
    int num1Size = this->largeNum.size();
    int num2Size = lgInt.largeNum.size();
    bool isNegative = false;
    
    if (num1.num == num2.num) {
        retNum.num.push_back('0');
    } else {
    
    if (num1Size == num2Size) {
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
        
        num1Size = num1.largeNum.size();
        
    } else if (num1Size < num2Size) {
        isNegative = true;
        num1 = lgInt;
        num2 = *this;
        num1Size = num1.largeNum.size();
        num2Size = num2.largeNum.size();
    }
    
    while (x < num1Size) {
        if (num1Size > x && num2Size > x) {
            if (num1.largeNum.at(x) < num2.largeNum.at(x)) {
                num1.largeNum.at(x+1)--;
                tempNum = num1.largeNum.at(x) + 10;
                tempNum = (tempNum - num2.largeNum.at(x)) + '0';
            } else {
                tempNum = (num1.largeNum.at(x) - num2.largeNum.at(x)) + '0';
            }
            
            retNum.largeNum.push_back(tempNum);
        } else {
            tempNum = num1.largeNum.at(x);
            retNum.largeNum.push_back(tempNum);
        }
        
        x++;
    }
    
    if (retNum.largeNum.at(x-1) == '0') {
        retNum.largeNum.pop_back();
    }
    
    if (isNegative) {
        retNum.largeNum.push_back('-');
    }
        
    retNum.num.append(retNum.largeNum.rbegin(), retNum.largeNum.rend());
        
    }
    
    cout << "num1 - num2 = " << retNum;
    
    return retNum;
}

largeIntegers largeIntegers::operator==(const largeIntegers& lgInt) {
    largeIntegers retNum;
    
    if (this->num == lgInt.num) {
        retNum.num.push_back('1');
    } else {
        retNum.num.push_back('0');
    }
    
    cout << "num1 == num2: " << retNum;
    
    return retNum;
}

largeIntegers largeIntegers::operator!=(const largeIntegers& lgInt) {
    largeIntegers retNum;
    
    if (this->num != lgInt.num) {
        retNum.num.push_back('1');
    } else {
        retNum.num.push_back('0');
    }
    
    cout << "num1 != num2: " << retNum;
    
    return retNum;
}

largeIntegers largeIntegers::operator>(const largeIntegers& lgInt) {
    largeIntegers retNum;
    
    if (this->num > lgInt.num) {
        retNum.num.push_back('1');
    } else {
        retNum.num.push_back('0');
    }
    
    cout << "num1 > num2: " << retNum;
    
    return retNum;
}

largeIntegers largeIntegers::operator>=(const largeIntegers& lgInt) {
    largeIntegers retNum;
    
    if (this->num >= lgInt.num) {
        retNum.num.push_back('1');
    } else {
        retNum.num.push_back('0');
    }
    
    cout << "num1 >= num2: " << retNum;
    
    return retNum;
}

largeIntegers largeIntegers::operator<(const largeIntegers& lgInt) {
    largeIntegers retNum;
    
    if (this->num < lgInt.num) {
        retNum.num.push_back('1');
    } else {
        retNum.num.push_back('0');
    }
    
    cout << "num1 < num2: " << retNum;
    
    return retNum;
}

largeIntegers largeIntegers::operator<=(const largeIntegers& lgInt) {
    largeIntegers retNum;
    
    if (this->num <= lgInt.num) {
        retNum.num.push_back('1');
    } else {
        retNum.num.push_back('0');
    }
    
    cout << "num1 <= num2: " << retNum;
    
    return retNum;
}

char largeIntegers::DecimalConverter(int decimal) {
    char c;
    int tempNum = 0;
    
    tempNum = (decimal - 48) - 10;
    c = '0' + tempNum;
    
    return c;
}

