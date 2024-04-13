// Group Project
// Software Design & Analysis
// Muhammad Tayyab (21L-7686) & Tauqeer Ahson (21L-6036)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Program
{
private:
    string name;

public:
    Program(string name)
    {
        this->name = name;
    }

    void addCourse(Course *course)
    {
    }

    void updateCourse(Course *course)
    {
    }

    void removeCourse(Course *course)
    {
    }

    void listCourses()
    {
    }
};

class Course
{
private:
    string name;

public:
    void addCLO(CLO *clo)
    {
    }

    void updateCLO(CLO *clo)
    {
    }

    void removeCLO(CLO *clo)
    {
    }

    void addEvaluation(Evaluation *evaluation)
    {
    }

    void updateEvaluation(Evaluation *evaluation)
    {
    }

    void removeEvaluation(Evaluation *evaluation)
    {
    }
};

// PLO (Program Learning Outcome)
class PLO
{
private:
public:
};

// CLO (Course Learning Outcome)
class CLO
{
private:
public:
};

class Evaluation
{
private:
    string type; // Quiz, Assignment, or Exam

public:
    Evaluation(string type)
    {
        this->type = type;
    }
    void addQuestion(Question *question)
    {
    }

    void updateQuestion(Question *question)
    {
    }

    void removeQuestion(Question *question)
    {
    }
};

class Question
{
private:
    int number;
    CLO *clo;

public:
    Question(int number = 1)
    {
        this->number = number;
    }
};

class User
{
};

class AcademicOfficer : public User
{
};

class Teacher : public User
{
};

class Report
{
private:
public:
    void CLOTested(CLO *clo)
    {
    }

    void CLOsOfCourse(Course *course)
    {
    }

    void PLOContainsCourses(PLO *plo)
    {
    }
};

void ProgramsInterface()
{
    // Option to add, remove, and update programs
    // Show a list and details of current program(s)
}

void CoursesInterface()
{
    
}

void GenerateReport()
{
}

int main()
{
    cout << "Welcome to Our Outcome Based Education Support System" << endl;
    cout << "Are you a Teacher or an Academic Officer? (t/a)" << endl;
    char selection;
    cin >> selection;
    if (selection == 't')
    {
        else if (selection == 'a')
        {
        }
        else
        {
            cout << "Invalid user role. Only Teachers and Academic Officers are allowed."
        }
    }
    int option;
    while (option != 0)
    {
        cout << "What would you like to do today?" << endl;
        cout << "1. Manage Programs" << endl;
        cout << "2. Manage Courses" << endl;
        cout << "3. Generate Report" << endl;
        cout << "0. Exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            ProgramsInterface();
        case 2:
            CoursesInterface();
        case 3:
            GenerateReport();
        case 0:
            option = 0;
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option selected. Please try again!" << endl;
        }
    }
}