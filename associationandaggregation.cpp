#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 
 
class Course { 
    string courseName; 
public: 
    Course(const string& name) : courseName(name) {} 
    string getCourseName() const { 
        return courseName; 
    } 
}; 
 
class Teacher { 
    string name; 
    vector<Course> courses; 
public: 
    Teacher(const string& teacherName) : name(teacherName) {} 
 
    void addCourse(const Course& course) { 
        courses.push_back(course); 
    } 
 
    void showCourses() const { 
        cout << "Professor  " << name << " teaches the following courses:" << endl; 
        for (const auto& course : courses) { 
            cout << " - " << course.getCourseName() << endl; 
        } 
    } 
 
    string getName() const { 
        return name; 
    } 
}; 
 
class Department { 
    string deptName; 
    vector<Teacher*> teachers; 
 
 
public: 
    Department(const string& name) : deptName(name) {} 
 
    void addTeacher(Teacher* teacher) { 
        teachers.push_back(teacher); 
    } 
 
    void showTeachers() const { 
        cout << deptName << " Department has the following teachers:" << endl; 
        for (const auto& teacher : teachers) { 
            cout << " - " << teacher->getName() << endl; 
        } 
    } 
}; 
 
 
int main() { 
    Course math("Mathematics"); 
    Course oopm("OOPM"); 
    Course ds("Data Structure"); 
 
    Teacher teacher1("Prof. Mukesh Tiwari"); 
    teacher1.addCourse(math); 
 
    Teacher teacher2("Prof. Pankaj Pali"); 
    teacher2.addCourse(oopm); 
 
 
    Teacher teacher3("Prof. Zohaib Hasan"); 
    teacher3.addCourse(ds); 
 
    Department CSE("CSE"); 
    CSE.addTeacher(&teacher1); 
    CSE.addTeacher(&teacher2); 
    CSE.addTeacher(&teacher3); 
 
    CSE.showTeachers(); 
    cout << endl; 
 
    teacher1.showCourses(); 
    cout << endl; 
    teacher2.showCourses(); 
    cout << endl; 
    teacher3.showCourses(); 
 
    return 0; 
} 