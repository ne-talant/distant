#include <iostream>
#include <string>

int main() {
    std::string name, activity;
    std::getline(std::cin, name);
    std::getline(std::cin, activity);

    int hours = name.length();

    std::cout << "Привет, " << name << "! Согласно данным исследований, ты будешь откладывать " << activity << " ещё " << hours << " часов!";

    return 0;
}
