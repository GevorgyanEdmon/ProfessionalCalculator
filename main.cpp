#include <iostream>

int main() {
    double num1;
    double num2;
    char operation;

    while (true) {
        std::cout << "\n Calculation \n";

        std::cout << "Enter first number: ";
        std::cin >> num1;

        if (std::cin.fail()) {
            std::cout << "Error: Its a letter\n";

            std::cin.clear();

            std::cin.ignore(1000, '\n');

            continue;
        }

        std::cout << "Enter operation : ";
        std::cin >> operation;

        if (operation == 'q') {
            std::cout << "Goodbye";
            break;
        }

        std::cout << "Enter second number: ";
        std::cin >> num2;

        if (std::cin.fail()) {
            std::cout << "Error: Its a letter\n";

            std::cin.clear();

            std::cin.ignore(1000, '\n');

            continue;
        }

        if (operation == '+') {
            std::cout << "Result: " << num1 + num2 << "\n";
        }
        else if (operation == '-') {
            std::cout << "Result: " << num1 - num2 << "\n";
        }
        else if (operation == '*') {
            std::cout << "Result: " << num1 * num2 << "\n";
        }
        else if (operation == '/') {
            if (num2 == 0) {
                std::cout << "Error: Division by zero\n";
            }
            else {
                std::cout << "Result: " << num1 / num2 << "\n";
            }
        }
    }

    return 0;
}