#include <iostream>
#include <cassert>

using namespace std;

// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
double total = 0;
double currentNum = 0;
char operation;

//ОТДЕЛЬНЫЕ ФУНКЦИИ ДЛЯ КАЖДОГО ДЕЙСТВИЯ

void add() { total += currentNum; }
void subtract() { total -= currentNum; }
void multiply() { total *= currentNum; }
void divide() {
    assert(currentNum != 0);
    total /= currentNum;
}

//ФУНКЦИИ ВВОДА

void getNumber() {
    while (!(cin >> currentNum)) {
        cerr << "Error: Enter a number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void getOperation() {
    while (true) {
        cin >> operation;
        if (operation == '+' || operation == '-' || operation == '*' ||
            operation == '/' || operation == 'q' || operation == '=') {
            break;
        }
        cerr << "Error: Unknown operator! Try again (+, -, *, /, =, q): ";
    }
}


int main(int argc, char* argv[]) {
    cout << "Program: " << argv[0] << endl;
    if (argc > 1) cout << "Launched with args!" << endl;

    cout << "Enter starting number: ";
    getNumber();
    total = currentNum;

    while (true) {
        cout << "[" << total << "] Operation: ";
        getOperation();

        if (operation == 'q') break;
        if (operation == '=') {
            cout << "Current result: " << total << endl;
            continue;
        }

        cout << "Enter next number: ";
        getNumber();

        if (operation == '/' && currentNum == 0) {
            cerr << "Critical Error: Division by zero" << endl;
            continue;
        }

        if (operation == '+') add();
        else if (operation == '-') subtract();
        else if (operation == '*') multiply();
        else if (operation == '/') divide();
    }

    cout << "Final: " << total << endl;
    return 0;
}