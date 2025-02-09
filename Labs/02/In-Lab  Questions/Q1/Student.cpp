#include "Student.h"

Student :: Student(const std :: string& name) : name(name) {}
void Student :: enrollCourse(Course* course){
enrolledCourses.push_back(course);
}

const std :: string& Student::getName() const {return name;}
const std :: vector<Course*>& Student :: getEnrolledCourses() const{return  enrolledCourses;}


