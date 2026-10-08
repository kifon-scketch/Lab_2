#include <iostream>
#include <string>

int main() 
{
    std::setlocale(LC_ALL, "Russian");
    char weather_event;
    double temperature, wind_speed, visibility;

    std::cout << "Введите явление (R - Дождь, S - Снег, F - Туман, W - Ветер): ";
    std::cin >> weather_event;

    std::cout << "Введите температуру (°C): ";
    std::cin >> temperature;

    std::cout << "Введите скорость ветра (м/с): ";
    std::cin >> wind_speed;

    std::cout << "Введите видимость (км): ";
    std::cin >> visibility;

    if (wind_speed < 0) {
        std::cout << "Ошибка: Скорость ветра не может быть отрицательной.\n";
        return 1;
    }
    if (visibility <= 0) {
        std::cout << "Ошибка: Видимость должна быть строго больше нуля.\n";
        return 1;
    }

    int level = 0;
    std::string reason = "Базовый уровень";

    switch (weather_event) {
    case 'R':
    case 'r':
        level = 1;
        if (wind_speed >= 20) {
            level += 1;
            reason = "Сильный ветер при дожде";
        }
        break;

    case 'S':
    case 's':
        level = 1;
        if (temperature < -10 && wind_speed >= 15) {
            level += 1;
            reason = "Мороз и сильный ветер при снегопаде";
        }
        break;

    case 'F':
    case 'f':
        level = 2;
        if (visibility < 0.2) {
            level += 1;
            reason = "Крайне низкая видимость при тумане";
        }
        break;

    case 'W':
    case 'w':
        level = 2;
        if (wind_speed >= 30) {
            level += 1;
            reason = "Штормовой ветер";
        }
        break;

    default:
        std::cout << "Ошибка: Неизвестное погодное явление.\n";
        return 1;
    }

    if (level > 3) {
        level = 3;
    }

    std::cout << "\n--- Результат ---\n";
    std::cout << "Итоговый уровень опасности: " << level << "\n";
    std::cout << "Причина повышения: " << reason << "\n";

    return 0;
}

