#include <iostream>
#include "Course.h"
#include "Student.h"
#include "Teacher.h"

int main() {
    // Creating students, teachers, and courses
    Student s1("Alice");
    Student s2("Bob");

    Teacher t1("Professor Smith");
    Teacher t2("Professor Johnson");

    Course c1("Mathematics");
    Course c2("Physics");

    // Populating courses with students and teachers
    c1.addStudent(&s1);
    c1.addStudent(&s2);
    c1.addTeacher(&t1);
    c2.addTeacher(&t2);

    // Accessing data
    std::cout << "Students enrolled in " << c1.getName() << ":\n";
    for (const auto& student : c1.getStudents()) {
        std::cout << student->getName() << std::endl;
    }

    std::cout << "\nTeachers teaching " << c1.getName() << ":\n";
    for (const auto& teacher : c1.getTeachers()) {
        std::cout << teacher->getName() << std::endl;
    }

    std::cout << "\nStudents enrolled in " << c2.getName() << ":\n";
    for (const auto& student : c2.getStudents()) {
        std::cout << student->getName() << std::endl;
    }

    std::cout << "\nTeachers teaching " << c2.getName() << ":\n";
    for (const auto& teacher : c2.getTeachers()) {
        std::cout << teacher->getName() << std::endl;
    }

    return 0;
}


