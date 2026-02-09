#include <iostream>
#include "mylib/Student.h"

int main() {
    using mylib::Student;

    // 1) Создать 2-3 объекта разными конструкторами
    Student s1;                       // по умолчанию
    Student s2("Иван", 4.3);           // с параметрами
    Student s3(s2);                   // копирование

    std::cout << "Начальные объекты:\n";
    s1.printState();
    s2.printState();
    s3.printState();

    // 2) Продемонстрировать работу всех методов
    std::cout << "\nget/set методы:\n";
    std::cout << "s2: id=" << s2.getId()
              << ", имя=" << s2.getName()
              << ", средний балл=" << s2.getAverageGrade() << "\n";

    std::cout << "\nМеняем имя и средний балл у s1:\n";
    s1.setName("Пётр");
    s1.setAverageGrade(4.6);
    s1.printState();

    std::cout << "\nПроверка isExcellent():\n";
    std::cout << "s1 отличник? " << (s1.isExcellent() ? "ДА" : "НЕТ") << "\n";
    std::cout << "s2 отличник? " << (s2.isExcellent() ? "ДА" : "НЕТ") << "\n";

    std::cout << "\nupgradeGrade / downgradeGrade:\n";
    s2.upgradeGrade(0.4);
    s2.printState();
    s2.downgradeGrade(0.2);
    s2.printState();

    std::cout << "\nСтроковое представление (toString):\n";
    std::cout << s2.toString() << "\n";

    // 3) Показать перегруженные операторы
    std::cout << "\nПерегруженные операторы:\n";
    std::cout << "s2 == s3 ? " << (s2 == s3 ? "ДА" : "НЕТ") << "\n";
    std::cout << "s1 > s2 ? " << (s1 > s2 ? "ДА" : "НЕТ") << "\n";
    std::cout << "Вывод через << : " << s1 << "\n";

    // 4) Вызвать статический метод
    std::cout << "\nСтатический метод generateId():\n";
    std::cout << "Новый id (без создания объекта) = " << Student::generateId() << "\n";

    // 5) Вывести информацию об объектах
    std::cout << "\nИтоговые состояния объектов:\n";
    s1.printState();
    s2.printState();
    s3.printState();

    return 0;
}
