#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdexcept>
#include <string>

class Date {
private:
    int year;
    int month;
    int day;

    void validateDate(int y, int m, int d) const noexcept;

public:
    // Конструкторы
    Date();
    Date(int y, int m, int d);
    Date(const Date& other);

    // Методы инициализации
    void Init(int y, int m, int d);
    void Init(const Date& other);

    // Методы для ввода/вывода
    void Read();
    void Display() const noexcept;

    // Преобразование в строку
    std::string toString() const noexcept;

    // Геттеры
    int getYear() const noexcept;
    int getMonth() const noexcept;
    int getDay() const noexcept;

    // Сеттеры
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);

    // Операции с датами
    Date addDays(int days) const noexcept;
    Date subtractDays(int days) const noexcept;
    bool isLeapYear() const noexcept;

    // Сравнение дат
    bool operator==(const Date& other) const noexcept;
    bool operator!=(const Date& other) const noexcept;
    bool operator<(const Date& other) const noexcept;
    bool operator>(const Date& other) const noexcept;

    // Количество дней между датами
    int daysBetween(const Date& other) const noexcept;
};

#endif // DATE_H
