#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Course;
class Time;
class Class;

class User {
    public:
    string name;
    string ID;
    string password;
    User(string name = "", string ID = 0)
    {
        this->name = name;
        this->ID = ID;
    }
};

class Professor : User {
    public:
    Professor(){}
    Professor(string name, string ID, string password) {
        this->name = name;
        this->ID = ID;
        this->password = password;
    }
    
    friend Time getFinishingTime(Course course);
    friend bool checkTimeConfliction(Course course1, Course course2);
    friend bool checkLocationConfliction(Course course1, Course course2);
    friend void assignClasses(Course course, Class currentClass);
};

class Student : User {
    Student(){}
    Student(string name, string ID, string passwrod) {
        this->name = name;
        this->ID = ID;
        this->password = password;
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
    public:
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
    public:
    int classNumber;
    ClassLocation(){}
    public: ClassLocation(int classNumber)
    {
        this->classNumber = classNumber;
    }
};

class Class {
    int number;
    bool hasProjector;
    int capacity;
    int* lessonID;
    static Class classes[];
    ClassLocation classLocation;

    Class(int number, bool hasProjector, int capacity, ClassLocation classLocation)
    {
        this->number = number;
        this->hasProjector = hasProjector;
        this->capacity = capacity;
        this->classLocation = classLocation;
    }

};

class Course {
    public:
    static int counter;
    int id;
    string name;
    Professor professor;
    Day day;
    Time time;
    int studentCapacity;
    int* studentList;
    ClassLocation classLocation;
    bool hasProjector;
    
    public:
    Course(string name, Professor professor, Day day, Time time, int studentCapacity, ClassLocation location, bool hasProjector)
    {
        this->id = counter++;
        this->name = name;
        this->professor = professor;
        this->day = day;
        this->time = time;
        this->studentCapacity = studentCapacity;
        this->classLocation = classLocation;
        int* studentList = new int[studentCapacity];
        this->hasProjector = hasProjector;
    }
};

int Course::counter = 0;
//Class Class:: classes[];

Time getFinishingTime(Course course) {
    int finishingHour = course.time.startingHour + course.time.hourDuration;
    int finishingMinute = course.time.startingMinute + course.time.minuteDuration;
    Time finishingTime(finishingHour, finishingMinute, 0, 0);
    return finishingTime;
}

bool checkTimeConfliction(Course course1, Course course2) {
    Time finishingTime1 = getFinishingTime(course1);
    Time finishingTime2 = getFinishingTime(course2);

    if (course1.time.startingHour <= finishingTime2.startingHour && course1.time.startingMinute <= finishingTime2.startingMinute)
        return false;
    if (course1.time.startingHour >= finishingTime2.startingHour && course1.time.startingMinute >= finishingTime2.startingMinute) 
        return false;
    cout<<"Can't operate the command. two classes are in time confliction";
    return true;
}


bool checkLocationConfliction(Course course1, Course course2) {
    if (course1.classLocation.classNumber != course2.classLocation.classNumber)
        return false;
    bool timeConflict = checkLocationConfliction(course1, course2);
        
    cout<<"Can't operate the command. two classes are in location confliction";
    return true;
}

int main(void){
    // string fileName = "lessons.txt";
    // ifstream file;
    // file.open(fileName);

    // if (file.fail())
    //     {
    //     cout<<"Error in openning the file";
    //     return 1;
    //     }

    // vector<Course> courses;


    return 0;
}