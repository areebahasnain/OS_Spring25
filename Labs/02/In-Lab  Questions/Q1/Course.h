#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

#include "Student.h"
#include "Teacher.h"

class Student;
class Teacher;

class Course {
private:
    std::string name;
    std::vector<Student*> students;
    std::vector<Teacher*> teachers;

public:
    Course(const std::string& name);
    void addStudent(Student* student);
    void addTeacher(Teacher* teacher);
    const std::string& getName() const;
    const std::vector<Student*>& getStudents() const;
    const std::vector<Teacher*>& getTeachers() const;
};

#endif // COURSE_H
