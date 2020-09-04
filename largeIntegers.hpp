#include <iostream>
#include <string>
#include <vector>

using namespace std;

class largeIntegers {
private:
    char num;
    vector<char>num1;
    vector<char>num2;
    
public:
    largeIntegers();
    largeIntegers(char newNum);
    friend ostream& operator<< (ostream& output, const largeIntegers& lgInt);
    friend istream& operator>> (istream& input, largeIntegers& lgInt);
};
