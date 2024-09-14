#include "Date.h"

int main() {
  //  system("chcp 1251");
    std::cout << "Разработчик: Бычков Роман ДиПРБ 21/2\n";
    std::cout << "Задание: создание и реализация интерфейса даты\n";

    try {
        // Создание объектов класса Date
        Date date1(2024, 2, 29); // Високосный год
        date1.Display();

        Date date2(2023, 2, 28); // Невисокосный год
     //   date2.Display();

        date2.Read(); // Ввод даты с клавиатуры

        if (date1 > date2) {
            std::cout << date1.toString() << " позже " << date2.toString() << std::endl;
        }
        else {
            std::cout << date1.toString() << " не позже " << date2.toString() << std::endl;
        }

        // Пример использования методов добавления и вычитания дней
        date1.addDays(10).Display();
        date2.subtractDays(5).Display();

        std::cout << "Количество дней между " << date1.toString() << " и " << date2.toString() << ": "
            << date1.daysBetween(date2) << " дней" << std::endl;

        // Демонстрация сравнения дат
        if (date1 == date2) {
            std::cout << "Даты равны." << std::endl;
        }
        else if (date1 < date2) {
            std::cout << date1.toString() << " раньше " << date2.toString() << std::endl;
        }
        else {
            std::cout << date1.toString() << " позже " << date2.toString() << std::endl;
        }

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
