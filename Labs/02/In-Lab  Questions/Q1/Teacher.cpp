#include "Teacher.h"

Teacher::Teacher(const std::string& name) : name(name) {}

void Teacher::teachCourse(Course* course) {
    teachingCourses.push_back(course);
}

const std::string& Teacher::getName() const {
    return name;
}

const std::vector<Course*>& Teacher::getTeachingCourses() const {
    return teachingCourses;
}
