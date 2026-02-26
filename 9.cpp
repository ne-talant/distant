#include <iostream>

int main() {
    int pizza_slices;
    std::cin >> pizza_slices;

    int calories = pizza_slices * 300;
    double weight = calories / 10.0;

    std::cout << "Ты съел " << calories << " калорий, это примерно как поднять " << weight << " кг веса на 1 метр!" << std::endl;
    std::cout << "Так держать, чемпион!";

    return 0;
}
