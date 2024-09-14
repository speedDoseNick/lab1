#include "Date.h"

// Конструкторы
Date::Date() : year(2000), month(1), day(1) {}

Date::Date(int y, int m, int d) {
    validateDate(y, m, d);
    year = y;
    month = m;
    day = d;
}

Date::Date(const Date& other) : year(other.year), month(other.month), day(other.day) {}

// Проверка даты
void Date::validateDate(int y, int m, int d) const noexcept {
    if (m < 1 || m > 12) {
        throw std::invalid_argument("Некорректный месяц");
    }

    int daysInMonth[] = { 31, (isLeapYear() ? 29 : 28), 31, 30, 31, 30,  31, 31, 30, 31, 30, 31 };

    if (d < 1 || d > daysInMonth[m - 1]) {
        throw std::invalid_argument("Некорректный день");
    }
}

// Инициализация
void Date::Init(int y, int m, int d) {
    validateDate(y, m, d);
    year = y;
    month = m;
    day = d;
}

void Date::Init(const Date& other) {
    year = other.year;
    month = other.month;
    day = other.day;
}

// Ввод/вывод
void Date::Read() {
    int y, m, d;
    std::cout << "Введите дату (год месяц день): ";
    std::cin >> y >> m >> d;
    Init(y, m, d);
}

void Date::Display() const noexcept {
    std::cout << toString() << std::endl;
}

std::string Date::toString() const noexcept {
    return std::to_string(year) + "." + std::to_string(month) + "." + std::to_string(day);
}

// Геттеры
int Date::getYear() const noexcept { return year; }
int Date::getMonth() const noexcept { return month; }
int Date::getDay() const noexcept { return day; }

// Сеттеры
void Date::setYear(int y) { validateDate(y, month, day); year = y; }
void Date::setMonth(int m) { validateDate(year, m, day); month = m; }
void Date::setDay(int d) { validateDate(year, month, d); day = d; }

// Проверка високосного года
bool Date::isLeapYear() const noexcept {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Добавление дней к дате
Date Date::addDays(int days) const noexcept {
    Date newDate(*this);

    newDate.day += days;

    while (true) {
        int daysInMonth[] = { 31, (newDate.isLeapYear() ? 29 : 28), 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31 };

        if (newDate.day > daysInMonth[newDate.month - 1]) {
            newDate.day -= daysInMonth[newDate.month - 1];
            newDate.month++;
            if (newDate.month > 12) {
                newDate.month = 1;
                newDate.year++;
            }
        }
        else {
            break;
        }
    }

    return newDate;
}

// Вычитание дней из даты
Date Date::subtractDays(int days) const noexcept {
    Date newDate(*this);

    newDate.day -= days;

    while (newDate.day < 1) {
        newDate.month--;
        if (newDate.month < 1) {
            newDate.month = 12;
            newDate.year--;
        }

        int daysInMonth[] = { 31, (newDate.isLeapYear() ? 29 : 28), 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31 };

        newDate.day += daysInMonth[newDate.month - 1];
    }

    return newDate;
}

// Сравнение дат
bool Date::operator==(const Date& other) const noexcept {
    return year == other.year && month == other.month && day == other.day;
}

bool Date::operator!=(const Date& other) const noexcept {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const noexcept {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator>(const Date& other) const noexcept {
    return other < *this;
}

// Количество дней между датами
int Date::daysBetween(const Date& other) const noexcept {
    

    int totalDays1 = year * 365 + day; // Простая оценка
    for (int i = 1; i < month; ++i) {
        totalDays1 += (i == 2 && isLeapYear()) ? 29 : ((i == 4 || i == 6 || i == 9 || i == 11) ? 30 : 31);
    }

    int totalDays2 = other.year * 365 + other.day; // Простая оценка
    for (int i = 1; i < other.month; ++i) {
        totalDays2 += (i == 2 && other.isLeapYear()) ? 29 : ((i == 4 || i == 6 || i == 9 || i == 11) ? 30 : 31);
    }

    return abs(totalDays1 - totalDays2);
}
