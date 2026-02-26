#include <iostream>

int main() {
    int number;
    std::cin >> number;

    std::cout << "Ваше число — это знак ";

    if (number % 2 == 0 && number % 3 == 0) {
        std::cout << "баланса логики и любви!";
    } else if (number % 2 == 0) {
        std::cout << "логики и здравого смысла!";
    } else if (number % 3 == 0) {
        std::cout << "любви и страсти!";
    } else {
        std::cout << "загадочной неопределенности!";
    }

    return 0;
}
