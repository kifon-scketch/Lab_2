#include <iostream>

int main() 
{
    std::setlocale(LC_ALL, "Russian");
    char phenomenon;
    int intensity;

    std::cout << "Введите код явления (R - дождь, S - снег, F - туман, W - сильный ветер): ";
    std::cin >> phenomenon;
    std::cout << "Введите интенсивность (1..3): ";
    std::cin >> intensity;

    int risk_level = 0;
    bool valid = true;

    switch (phenomenon) {
    case 'R':
    case 'r':
    case 'F':
    case 'f':
        risk_level = 1;
        break;
    case 'S':
    case 's':
    case 'W':
    case 'w':
        risk_level = 2;
        break;
    default:
        std::cout << "Ошибка: Неизвестный код явления!" << std::endl;
        valid = false;
        break;
    }

    if (valid) {

        if (intensity < 1 || intensity > 3) {
            std::cout << "Ошибка: Неверная интенсивность (должна быть от 1 до 3)!" << std::endl;
            return 1;
        }


        if (intensity == 3) {
            risk_level++;
            if (risk_level > 3) {
                risk_level = 3;
            }
        }


        std::cout << "Уровень риска: ";
        if (risk_level == 1) {
            std::cout << "Low" << std::endl;
        }
        else if (risk_level == 2) {
            std::cout << "Medium" << std::endl;
        }
        else if (risk_level == 3) {
            std::cout << "High" << std::endl;
        }
    }

    return 0;
}
