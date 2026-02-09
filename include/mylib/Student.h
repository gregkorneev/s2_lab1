#pragma once
#include <iostream>
#include <string>

namespace mylib {

class Student {
private:
    int id;
    std::string name;
    double averageGrade;

    // вспомогательная проверка/нормализация среднего балла
    void normalizeGrade();

public:
    // Конструкторы
    Student();                              // создаёт студента с новым id
    Student(const std::string& name, double averageGrade);
    Student(const Student& other);          // конструктор копирования

    // get / set
    int getId() const;
    std::string getName() const;
    double getAverageGrade() const;

    void setName(const std::string& value);
    void setAverageGrade(double value);

    // Публичные методы (5-6)
    bool isExcellent() const;               // средний балл >= 4.5
    void upgradeGrade(double delta);        // повысить средний балл на delta
    void downgradeGrade(double delta);      // понизить средний балл на delta
    std::string toString() const;           // строковое представление
    void printState() const;                // вывод состояния

    // Операторы
    bool operator==(const Student& other) const; // сравнение по id
    bool operator>(const Student& other) const;  // по среднему баллу
    friend std::ostream& operator<<(std::ostream& os, const Student& s);

    // Статический метод
    static int generateId();
};

} // namespace mylib
