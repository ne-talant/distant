#include <iostream>

int main() {
    int hours_slept;
    std::cin >> hours_slept;

    int double_sleep = hours_slept * 2;

    std::cout << "Поздравляю, ты мог бы проспать " << double_sleep << " часов, если бы твоя лень увеличилась вдвое!" << std::endl;

    if (hours_slept > 10) {
        std::cout << "Ты настоящий мастер сна!";
    }

    return 0;
}
