#include "mylib/Student.h"

namespace mylib {

static int g_nextId = 1;

int Student::generateId() {
    int value = g_nextId;
    g_nextId = g_nextId + 1;
    return value;
}

Student::Student() : id(generateId()), name("Без имени"), averageGrade(0.0) {
    normalizeGrade();
}

Student::Student(const std::string& name_, double grade)
    : id(generateId()), name(name_), averageGrade(grade) {
    normalizeGrade();
}

Student::Student(const Student& other)
    : id(other.id), name(other.name), averageGrade(other.averageGrade) {}

int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
double Student::getAverageGrade() const { return averageGrade; }

void Student::setName(const std::string& value) {
    name = value;
}

void Student::setAverageGrade(double value) {
    averageGrade = value;
    normalizeGrade();
}

void Student::normalizeGrade() {
    // чтобы не было странных значений: ограничим диапазоном 0..5
    if (averageGrade < 0.0) averageGrade = 0.0;
    if (averageGrade > 5.0) averageGrade = 5.0;
}

bool Student::isExcellent() const {
    return averageGrade >= 4.5;
}

void Student::upgradeGrade(double delta) {
    averageGrade = averageGrade + delta;
    normalizeGrade();
}

void Student::downgradeGrade(double delta) {
    averageGrade = averageGrade - delta;
    normalizeGrade();
}

std::string Student::toString() const {
    // без iomanip, максимально просто
    // (double будет печататься как есть; для отчёта это нормально)
    return "id=" + std::to_string(id) +
           ", имя=" + name +
           ", средний_балл=" + std::to_string(averageGrade);
}

void Student::printState() const {
    std::cout << "Студент: " << *this
              << " (id=" << id
              << ", имя=\"" << name << "\""
              << ", средний балл=" << averageGrade
              << ")\n";
}

bool Student::operator==(const Student& other) const {
    // id считается уникальным
    return id == other.id;
}

bool Student::operator>(const Student& other) const {
    return averageGrade > other.averageGrade;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Student{id=" << s.id << ", name=" << s.name
       << ", avg=" << s.averageGrade << "}";
    return os;
}

} // namespace mylib
