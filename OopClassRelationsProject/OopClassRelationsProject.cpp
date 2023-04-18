#include <iostream>

using namespace std;

// Compositions classes
class Point
{
    int x;
    int y;
public:
    int& X() { return x; }
    int& Y() { return y; }

    Point(int x, int y) : x{ x }, y{ y } {}
    Point() : Point(0, 0) {}

    void SetPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    ~Point()
    {
        cout << "Point destruct\n";
    }
};

class Circle
{
    int radius;
    Point point;
public:
    int& Radius() { return radius; }

    Circle(Point point, int radius)
        : point{ point }, radius{ radius } {}
    
    Circle(int x, int y, int radius)
        : Circle(Point(x, y), radius) {}
    
    Circle() : Circle(0, 0, 0) {}
    
    ~Circle()
    {
        cout << "Circle destruct\n";
    }
};


// Aggregations classes
class Teacher;
class Department
{
    string title;
    Teacher* head;
public:
    string& Title(){ return title; }
    Teacher*& Head(){ return head; }

    Department(string title, Teacher* head)
        : title{ title }, head{ head } {}
    
    Department(string title) : Department(title, nullptr) {}

    ~Department()
    {
        cout << "Department destruct\n";
    }
};

class Teacher
{
    string name;
public:
    string& Name() { return name; }

    Teacher(string name) : name{ name } {}

    ~Teacher()
    {
        cout << "Teacher destruct\n";
    }
};

// Associations classes
class Patient;
class Doctor
{
    string name;
    Patient* patient;
public:
    Doctor(string name) : name{ name } {}
    
    string Name() { return name; }

    Patient*& Patient() { return patient; }
};

class Patient
{
    string name;
    Doctor* doctor;
public:
    Patient(string name) : name{ name } {}

    string Name() { return name; }

    Doctor*& Doctor() { return doctor; }

    friend ostream& operator<<(ostream& out, const Patient& patient);
};

//Dependency
ostream& operator<<(ostream& out, const Patient& patient)
{
    out << patient.name;
    return out;
}

int main()
{
    /*{
        Circle circle(2, 3, 10);
    }*/
    

    /*Teacher leo("Leo");
    {
        Department("Math", &leo);
    }
    cout << "prog work\n";*/
}
