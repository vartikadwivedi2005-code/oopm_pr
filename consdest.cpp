#include <iostream> 
using namespace std; 
 
class ObjectCounter { 
private: 
    static int objectCount; // Static variable to keep track of objects created and destroyed 
 
public: 
    // Constructor 
    ObjectCounter() { 
        objectCount++; // Increment object count when an object is created 
        cout << "Object created. Total objects: " << objectCount << endl; 
    } 
 
    // Destructor 
    ~ObjectCounter() { 
        objectCount--; // Decrement object count when an object is destroyed 
        cout << "Object destroyed. Total objects: " << objectCount << endl; 
    } 
 
    // Static method to get the current count of objects 
    static int getObjectCount() { 
        return objectCount; 
    } 
}; 
 
// Initialize static member 
int ObjectCounter::objectCount = 0; 
 
int main() { 
    cout << "Starting program...\n"; 
 
    // Block to test object creation and destruction 
    { 
        ObjectCounter obj1; // First object created 
 
 
        ObjectCounter obj2; // Second object created 
        cout << "Current object count: " << ObjectCounter::getObjectCount() << endl; 
    } // obj1 and obj2 go out of scope, destructors are called 
 
    cout << "Program ending. Final object count: " << ObjectCounter::getObjectCount() << endl; 
    return 0; 
} 