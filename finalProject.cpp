#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

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
    Professor(string name, string ID, string password) {
        this->name = name;
        this->ID = ID;
        this->password = password;
    }
    
    friend Time getFinishingTime(Course course);
    friend bool checkTimeConfliction(Course course1, Course course2);
    friend bool checkLocationConfliction(Course course1, Course course2);
};

class Student : User {
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
    int classNumber;

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

    Class(int number, bool hasProjector, int capacity)
    {
        this->number = number;
        this->hasProjector = hasProjector;
        this->capacity = capacity;
    }

};

class Course {
    public:
    static int counter;
    int id;
    string name;
    Professor* professor;
    Day day;
    Time time;
    int studentCapacity;
    int* studentList;
    ClassLocation* classLocation;
    
    public:
    Course(string name, Professor* professor = NULL, Day day, Time time, int studentCapacity, ClassLocation* location)
    {
        this->id = counter++;
        this->name = name;
        this->professor = professor;
        this->day = day;
        this->time = time;
        this->studentCapacity = studentCapacity;
        this->classLocation = classLocation;
        int* studentList = new int[studentCapacity];
    }
};

int Course::counter = 0;

Time getFinishingTime(Course course) {
    int finishingHour = course.time.startingHour + course.time.hourDuration;
    int finishingMinute = course.time.startingMinute + course.time.minuteDuration;
    Time finishingTime(finishingHour, finishingMinute, 0, 0);
    return finishingTime;
}

bool checkTimeConfliction(Course course1, Course course2) {
    // if (course1.time.startingHour < course2.time.startingHour)
    // {
    //     if (getFinishingTime(course1).startingHour < getFinishingTime(course2).startingHour)

    // }
}
bool checkLocationConfliction(Course couse1, Course course2) {

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