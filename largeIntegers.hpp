#include <iostream>
#include <string>
#include <vector>

using namespace std;

class largeIntegers {
private:
    string num;
    vector<char>largeNum;
    
public:
    largeIntegers();
    largeIntegers(string newNum);
    friend ostream& operator<< (ostream& output, const largeIntegers& lgInt);
    friend istream& operator>> (istream& input, largeIntegers& lgInt);
    largeIntegers operator+(const largeIntegers& lgInt);
    largeIntegers operator-(const largeIntegers& lgInt);
    largeIntegers operator==(const largeIntegers& lgInt);
    largeIntegers operator!=(const largeIntegers& lgInt);
    largeIntegers operator>(const largeIntegers& lgInt);
    largeIntegers operator>=(const largeIntegers& lgInt);
    largeIntegers operator<(const largeIntegers& lgInt);
    largeIntegers operator<=(const largeIntegers& lgInt);
};
