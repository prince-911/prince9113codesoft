#include <iostream>
#include <iomanip>
using namespace std;
double add(double n1, double n2) 
{
    return n1 + n2;
}
double subtract(double n1, double n2) 
{
    return n1 - n2;
}
double multiply(double n1, double n2) 
{
    return n1 * n2;
}
double divide(double n1, double n2) 
{
    if (n2 == 0) {
        cout << "Error: Cannot divide by zero!" << endl;
        return 0.0;
    }
    return n1 / n2;
}
int main() {
    double n1, n2;
    char operation;
    cout<<"Let's get ready to use calculator:\n";

    cout << "Enter the 1st number: ";
    cin >> n1;
    cout << "\nAvailable operations:" << endl;
    cout << "  + : Addition" << endl;
    cout << "  - : Subtraction" << endl;
    cout << "  * : Multiplication" << endl;
    cout << "  / : Division" << endl;
    cout << "Choose an operation to be performed: ";
    cin >> operation;
    cout << "Enter the 2nd number: ";
    cin >> n2;
    double result = 0.0;
    switch (operation) {
        case '+':
            result = add(n1, n2);
            break;
        case '-':
            result = subtract(n1, n2);
            break;
        case '*':
            result = multiply(n1, n2);
            break;
        case '/':
            result = divide(n1, n2);
            break;
        default:
            cout << "Invalid operation selected!" << endl;
            return 1;
    }
    cout << "==========================" << endl;
    cout << "ANSWER: " << fixed << setprecision(2) << result << endl;
    return 0;
}
