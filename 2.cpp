#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));
    
    std::string name;
    std::getline(std::cin, name);

    std::vector<std::string> excuses = {
        "застрял в пробке",
        "компьютер завис",
        "инопланетяне похитили",
        "сосед залил ноутбук",
        "кот уснул на клавиатуре"
    };

    int index = rand() % excuses.size();

    std::cout << "Привет, " << name << "! Если кто спросит, скажи, что ты не смог прийти, потому что " << excuses[index] << ".";

    return 0;
}
