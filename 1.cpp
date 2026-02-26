#include <iostream>

int main() {
    int days;
    std::cin >> days;

    if (days == 0) {
        std::cout << "Поздравляю, ты официально просрочил дедлайн!";
    } else if (days < 5) {
        std::cout << "Эй, бегом за кофе, ведь дедлайн уже близко! Осталось всего " << days << " дней!";
    } else {
        std::cout << "Расслабься, у тебя еще целых " << days << " дней... Хотя, может, пора начать?";
    }

    return 0;
}
