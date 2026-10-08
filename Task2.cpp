#include <iostream>

int main() {
    std::setlocale(LC_ALL, "Russian");

    double temperature;
    double humidity;
    int precipitation;

    std::cout << "Введите температуру: ";
    std::cin >> temperature;

    std::cout << "Введите влажность (0..100): ";
    std::cin >> humidity;

    std::cout << "Введите признак осадков (0 - нет, 1 - есть): ";
    std::cin >> precipitation;

    if (humidity < 0 || humidity > 100) {
        std::cout << "Ошибка: некорректное значение влажности!" << std::endl;
        return 1;
    }

    bool has_warning = false;

    if (temperature >= -3 && temperature <= 1 && precipitation == 1) {
        std::cout << "Предупреждение о гололёде!" << std::endl;
        has_warning = true;
    }

    if (temperature > 30 && humidity >= 70) {
        std::cout << "Предупреждение о жаре!" << std::endl;
        has_warning = true;
    }

    if (!has_warning) {
        std::cout << "Предупреждений нет" << std::endl;
    }

    return 0;
}
