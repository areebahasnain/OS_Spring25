#include "Course.h"

Course::Course(const std::string& name) : name(name) {}

void Course::addStudent(Student* student) {
    students.push_back(student);
}

void Course::addTeacher(Teacher* teacher) {
    teachers.push_back(teacher);
}

const std::string& Course::getName() const {
    return name;
}

const std::vector<Student*>& Course::getStudents() const {
    return students;
}

const std::vector<Teacher*>& Course::getTeachers() const {
    return teachers;
}
