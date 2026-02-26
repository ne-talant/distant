#include <iostream>

int main() {
    double money_left;
    std::cin >> money_left;

    double progress = (money_left / 1000000.0) * 100.0;

    std::cout << "Ты на " << progress << "% приблизился к своей мечте о яхте!" << std::endl;

    if (money_left < 100) {
        std::cout << "Ого! Уже не так уж и далеко, верно?";
    }

    return 0;
}
