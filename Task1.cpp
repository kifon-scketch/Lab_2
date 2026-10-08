#include <iostream>

int main() 
{
    setlocale(LC_ALL, "Russian");
    double temperature;
    double wind_speed;

    std::cout << "Введите температуру воздуха: ";
    std::cin >> temperature;

    std::cout << "Введите скорость ветра: ";
    std::cin >> wind_speed;

    if (wind_speed < 0) {
        std::cout << "Ошибка: скорость ветра не может быть отрицательной." << std::endl;
        return 1;
    }

    if (temperature < -20 && wind_speed >= 10) {
        std::cout << "опасный холод" << std::endl;
    }
    else if (temperature < -20 && wind_speed < 10) {
        std::cout << "сильный холод" << std::endl;
    }
    else if (temperature >= -20 && wind_speed >= 20) {
        std::cout << "ветрено" << std::endl;
    }
    else {
        std::cout << "обычные условия" << std::endl;
    }

    return 0;
}
