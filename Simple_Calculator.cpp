#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char choice;
    
    do {
        cout << "Calculator Menu:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exponentiation\n";
        cout << "Enter your choice (1-5): ";
        
        int operation;
        cin >> operation;

        double num1, num2, result;
        
        switch (operation) {
            case 1:
                cout << "Enter two numbers for addition:\n";
                cin >> num1 >> num2;
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;
            case 2:
                cout << "Enter two numbers for subtraction:\n";
                cin >> num1 >> num2;
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;
            case 3:
                cout << "Enter two numbers for multiplication:\n";
                cin >> num1 >> num2;
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;
            case 4:
                cout << "Enter two numbers for division:\n";
                cin >> num1 >> num2;
                try {
                    if (num2 == 0) {
                        throw runtime_error("Error: Division by zero is undefined.");
                    }
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            case 5:
                cout << "Enter base (x) and exponent (y) for exponentiation:\n";
                cin >> num1 >> num2;
                result = pow(num1, num2);
                cout << "Result: " << result << endl;
                break;
            default:
                cerr << "Invalid choice. Please enter a number between 1 and 5.\n";
                continue;
        }

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Calculator program exited.\n";
    return 0;
}
