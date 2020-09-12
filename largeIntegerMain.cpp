#include "largeIntegers.hpp"

int main() {
    char userChoice;
    
    do {
        largeIntegers num1;
        largeIntegers num2;
        largeIntegers newNum;
        
        cin >> num1;
        cin >> num2;
        newNum = num1 + num2;
        newNum = num1 - num2;
        newNum = num1 == num2;
        newNum = num1 != num2;
        newNum = num1 > num2;
        newNum = num1 >= num2;
        newNum = num1 < num2;
        newNum = num1 <= num2;
        
        do {
            cout << "Would you like to try again (y/n)? ";
            cin >> userChoice;
            
            if ((userChoice != 'y' && userChoice != 'Y') && (userChoice != 'n' && userChoice != 'N')) {
                cin.clear();
                cin.ignore(200, '\n');
                
                cout << "That is not a valid choice." << "\n";
            }
        } while ((userChoice != 'y' && userChoice != 'Y') && (userChoice != 'n' && userChoice != 'N'));
    } while (userChoice == 'y' || userChoice == 'Y');
}
