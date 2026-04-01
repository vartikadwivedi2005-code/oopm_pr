#include <iostream> 
using namespace std; 
 
class Student { 
private: 
    string name; 
    int marks[3]; 
    float percentage; 
 
public: 
    Student(string studentName, int subject1, int subject2, int 
subject3) { 
        name = studentName; 
        marks[0] = subject1; 
        marks[1] = subject2; 
        marks[2] = subject3; 
        calculatePercentage(); 
    } 
 
    void calculatePercentage() { 
        int totalMarks = 0; 
        for (int i = 0; i < 3; i++) { 
            totalMarks += marks[i]; 
        } 
        percentage = (float(totalMarks) / 300) * 100; 
    } 
 
    bool isEligible() { 
        return percentage >= 45.0; 
    } 
 
    void displayDetails() { 
        cout << "Student Name: " << name << endl; 
        cout << "Marks: " << marks[0] << ", " << marks[1] << "," << marks[2] << endl; 
        cout << "Percentage: " << percentage << "%" << endl; 
 
 
        if (isEligible()) { 
            cout << "Status: Eligible" << endl; 
        } else { 
            cout << "Status: Not Eligible" << endl; 
        } 
    } 
}; 
 
int main() { 
    string studentName; 
    int mark1, mark2, mark3; 
 
    cout << "Enter Student Name: "; 
    cin >> studentName; 
    cout << "Enter marks for 3 subjects (out of 100): "; 
    cin >> mark1 >> mark2 >> mark3; 
 
    Student student(studentName, mark1, mark2, mark3); 
    student.displayDetails(); 
 
    return 0; 
}