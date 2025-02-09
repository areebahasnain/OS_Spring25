#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

#include "Course.h"

class Course; // Forward declaration

class Student {
private:
    std::string name;
    std::vector<Course*> enrolledCourses;

public:
    Student(const std::string& name);
    void enrollCourse(Course* course);
    const std::string& getName() const;
    const std::vector<Course*>& getEnrolledCourses() const;
};

#endif // STUDENT_H



#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>

#include "Course.h"

class Course; // Forward declaration

class Teacher {
private:
    std::string name;
    std::vector<Course*> teachingCourses;

public:
    Teacher(const std::string& name);
    void teachCourse(Course* course);
    const std::string& getName() const;
    const std::vector<Course*>& getTeachingCourses() const;
};

#endif // TEACHER_H

