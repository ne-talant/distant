#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));

    std::string city;
    int temp;

    std::getline(std::cin, city);
    std::cin >> temp;

    std::vector<std::string> events = {
        "сильный ливень из пончиков",
        "ураган из сахарной ваты",
        "метеоритный дождь из конфет",
        "нашествие милых котиков",
        "внезапный туман из блесток"
    };

    int index = rand() % events.size();

    std::cout << "Сегодня в " << city << " ожидается " << events[index] << " при температуре " << temp << " градусов!";

    return 0;
}
