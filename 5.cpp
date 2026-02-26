#include <iostream>

int main() {
    double scholarship, savings_per_month;
    std::cin >> scholarship >> savings_per_month;

    double total_savings = savings_per_month * 5;

    std::cout << "За семестр ты отложишь: " << total_savings << std::endl;

    if (total_savings > 5000) {
        std::cout << "Поздравляю, ты почти миллионер!";
    } else {
        std::cout << "Придется попросить у родителей!";
    }

    return 0;
}
