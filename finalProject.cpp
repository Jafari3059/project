#include <iostream>
#include <string>
using namespace std;

// capacity of courses
const int MAX_COURSES = 100;

class User {
    public:
    string name;
    string ID;
    User(string name = "", string ID = 0)
    {
        this->name = name;
        this->ID = ID;
    }
};

class Professor : User {
    Professor(string name, string ID) {
        this->name = name;
        this->ID = ID;
    }
};

enum Day {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

class Time {
    int startingHour;
    int startingMinute;
    int hourDuration;
    int minuteDuration;
    
    int fullHours[9];
    int emptyHours[9];

    public: Time(int startingHour = 0, int startingMinute = 0, int hourDuration = 0, int minuteDuration = 0)
    {
        this->startingHour = startingHour;
        this->startingMinute = startingMinute;
        this->hourDuration = hourDuration;
        this->minuteDuration = minuteDuration;
    }
};

class ClassLocation {
    int static counter;
    int classNumber;

    public: ClassLocation()
    {
        this->classNumber = counter++;
    }
};

class Course {
    static int counter;
    int id;
    string name;
    string teacher;
    Day day;
    Time time;
    bool hasProjector;
    int studentCapacity;
    int* studentList;
    ClassLocation classLocation;
   
    Course(string name, string teacher, Day day, Time time, bool hasProjector, int studentCapacity, ClassLocation location)
    {
        this->id = counter++;
        this->name = name;
        this->teacher = teacher;
        this->day = day;
        this->time = time;
        this->hasProjector = hasProjector;
        this->studentCapacity = studentCapacity;
        this->classLocation = classLocation;
        int* studentList = new int[studentCapacity];
    }
};

int ClassLocation::counter = 0;

int Course::counter = 0;

int main(void){return 0;}