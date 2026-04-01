#include <iostream> 
using namespace std; 
 
class AccessModifiersDemo { 
private: 
    int privateVar; 
 
    void privateMethod() { 
        cout << "Private method accessed. PrivateVar = " << 
privateVar << endl; 
    } 
 
protected: 
    int protectedVar; 
 
    void protectedMethod() { 
        cout << "Protected method accessed. ProtectedVar = " << 
protectedVar << endl; 
    } 
 
public: 
    int publicVar; 
 
    AccessModifiersDemo() { 
        privateVar = 10; 
        protectedVar = 20; 
        publicVar = 30; 
    } 
 
    void publicMethod() { 
        cout << "Public method accessed. PublicVar = " << 
publicVar << endl; 
 
        privateMethod(); 
        protectedMethod(); 
    } 
}; 
 
class DerivedClass : public AccessModifiersDemo { 
public: 
 
 
    void accessProtectedMembers() { 
        protectedVar = 50; 
        cout << "Accessing protected members in DerivedClass: ProtectedVar = " << protectedVar << endl; 
        protectedMethod(); 
    } 
}; 
 
int main() { 
    AccessModifiersDemo obj; 
 
    cout << "PublicVar before change: " << obj.publicVar << 
endl; 
    obj.publicVar = 100; 
    obj.publicMethod(); 
 
    DerivedClass derivedObj; 
    derivedObj.accessProtectedMembers(); 
 
    return 0; 
} 