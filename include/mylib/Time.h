#pragma once
#include <iostream>

class Time {
private:
    int h; // часы
    int m; // минуты
    int s; // секунды

    // приводит время к корректному виду (0..23, 0..59, 0..59)
    void normalize();

public:
    // 2-3 конструктора
    Time();                      // 00:00:00
    Time(int hh, int mm, int ss);
    Time(const Time& other);     // конструктор копирования

    // get / set
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    void setHours(int hh);
    void setMinutes(int mm);
    void setSeconds(int ss);

    // 5-6 публичных методов
    void addSeconds(int sec);            // добавить секунды
    int toSeconds() const;               // всего секунд от 00:00:00
    Time difference(const Time& t) const; // модуль разницы
    bool isValid() const;                // проверка корректности
    void print() const;                  // вывод состояния

    // статический метод
    static Time fromSeconds(int totalSeconds);

    // операторы (2 штуки)
    bool operator==(const Time& t) const;
    Time operator-(const Time& t) const; // разница как Time

    // вывод через <<
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};
