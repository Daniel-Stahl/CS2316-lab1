#include "largeIntegers.hpp"
#include <cmath>

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
    bool plusOne, isNegative = false;
    int x = 0;
    char tempNum;
    int twoDigits = 0;
    int vecSize = 0;
    largeIntegers num1 = *this;
    largeIntegers num2 = lgInt;
    int num1Size = this->largeNum.size();
    int num2Size = lgInt.largeNum.size();

    if (num1.largeNum.at(num1Size - 1) == '-' && num2.largeNum.at(num2Size - 1) != '-') {
        num1.largeNum.pop_back();
        num2 = num1;
        num1 = lgInt;
        retNum = num1 - num2;
    } else if (num1.largeNum.at(num1Size - 1) != '-' && num2.largeNum.at(num2Size - 1) == '-') {
        num2.largeNum.pop_back();
        num1 = num2;
        num2 = *this;
        retNum = num1 - num2;
        
        twoDigits = abs(stoi(num1.num));
        
        if (twoDigits > stoi(num2.num)) {
            retNum.largeNum.push_back('-');
        } else {
            retNum.largeNum.pop_back();
        }
    } else {
        if (num1.largeNum.at(num1Size - 1) == '-' && num2.largeNum.at(num2Size - 1) == '-') {
            isNegative = true;
            num1.largeNum.pop_back();
            num2.largeNum.pop_back();
            num1Size--;
            num2Size--;
        }
        
        if (num1Size > num2Size) {
            vecSize = num1Size;
        } else {
            vecSize = num2Size;
        }
        
        while (x < vecSize) {
            if (num1Size > x && num2Size > x) {
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
                    tempNum = tempNum - 10;
                    retNum.largeNum.push_back(tempNum);
                    plusOne = true;
                }
            } else if (num1Size > x ) {
                tempNum = num1.largeNum.at(x);
                if (plusOne) {
                    tempNum++;
                }
                retNum.largeNum.push_back(tempNum);
                plusOne = false;
            } else {
                tempNum = num2.largeNum.at(x);
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
        
        if (isNegative) {
            retNum.largeNum.push_back('-');
        }
    }
    
    retNum.num.clear();
    retNum.num.append(retNum.largeNum.rbegin(), retNum.largeNum.rend());
    
    return retNum;
}

largeIntegers largeIntegers::operator-(const largeIntegers& lgInt) {
    largeIntegers retNum;
    largeIntegers num1 = *this;
    largeIntegers num2 = lgInt;
    largeIntegers tempObj;
    int x = 0;
    char tempNum;
    int num1Size = this->largeNum.size();
    int num2Size = lgInt.largeNum.size();
    bool isNegative, doubleNeg, isLarger = false;
    
    if (num1.num == num2.num) {
        retNum.num.push_back('0');
        return retNum;
    } else if (num1.largeNum.at(num1Size - 1) == '-' && num2.largeNum.at(num2Size - 1) != '-') {
        num1.largeNum.pop_back();
        retNum = num1 + num2;
        retNum.largeNum.push_back('-');
    } else if (num1.largeNum.at(num1Size - 1) != '-' && num2.largeNum.at(num2Size - 1) == '-') {
        num2.largeNum.pop_back();
        retNum = num1 + num2;
    } else {
        if (num1.largeNum.at(num1Size - 1) == '-' && num2.largeNum.at(num2Size - 1) == '-') {
            num1.largeNum.pop_back();
            num2.largeNum.pop_back();
            num1Size--;
            num2Size--;
            doubleNeg = true;
        }
        
        if (num1Size == num2Size) {
            while (num1Size > x && !isLarger) {
                num1Size--;
                
                if (num1.largeNum.at(num1Size) > num2.largeNum.at(num1Size)) {
                    isLarger = true;
                } else if (num1.largeNum.at(num1Size) == num2.largeNum.at(num1Size)) {
                    isLarger = false;
                } else {
                    isLarger = true;
                    isNegative = true;
                    tempObj = num1;
                    num1 = num2;
                    num2 = tempObj;
                    num1Size = num1.largeNum.size();
                    num2Size = num2.largeNum.size();
                }
            }
            
            num1Size = num1.largeNum.size();
            
        } else if (num1Size < num2Size) {
            isNegative = true;
            tempObj = num1;
            num1 = num2;
            num2 = tempObj;
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
        
        if ((this->num.at(0) != '-' && lgInt.num.at(0) != '-' && isLarger) || ((this->num.at(0) == '-' && lgInt.num.at(0) == '-') && !isLarger) || (this->num.at(0) == '-' && lgInt.num.at(0) != '-') ) {
            retNum.largeNum.push_back('-');
        }
    }
    
    retNum.num.clear();
    retNum.num.append(retNum.largeNum.rbegin(), retNum.largeNum.rend());
    
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
