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
    // ������������
    Date();
    Date(int y, int m, int d);
    Date(const Date& other);

    // ������ �������������
    void Init(int y, int m, int d);
    void Init(const Date& other);

    // ������ ��� �����/������
    void Read();
    void Display() const noexcept;

    // �������������� � ������
    std::string toString() const noexcept;

    // �������
    int getYear() const noexcept;
    int getMonth() const noexcept;
    int getDay() const noexcept;

    // �������
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);

    // �������� � ������
    Date addDays(int days) const noexcept;
    Date subtractDays(int days) const noexcept;
    bool isLeapYear() const noexcept;

    // ��������� ���
    bool operator==(const Date& other) const noexcept;
    bool operator!=(const Date& other) const noexcept;
    bool operator<(const Date& other) const noexcept;
    bool operator>(const Date& other) const noexcept;

    // ���������� ���� ����� ������
    int daysBetween(const Date& other) const noexcept;
};

#endif // DATE_H
