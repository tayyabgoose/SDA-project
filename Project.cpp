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
    int ID;
    string name;
    vector<Course *> courses;
    vector<PLO *> PLOs;

public:
    Program(int programID, string programName)
    {
        ID = programID;
        name = programName;
    }

    void addCourse(Course *course)
    {
        courses.push_back(course);
    }

    void updateCourse(Course *course)
    {
    }

    void removeCourse(Course *course)
    {
    }

    vector<Course *> getCourses()
    {
        return courses;
    }

    vector<PLO *> getPLOs()
    {
        return PLOs;
    }

    void listCourses()
    {
    }
};

class Course
{
private:
    int ID;
    string name;
    vector<CLO *> CLOs;

public:
    Course(int courseID, string courseName)
    {
        ID = courseID;
        name = courseName;
    }

    int getCourseID()
    {
        return ID;
    }

    void addCLO(CLO *clo)
    {
        CLOs.push_back(clo);
    }

    void updateCLO(CLO *clo)
    {
        cout << "Please enter the description for this CLO ID: " << clo->getID() << endl;
        string cloDescription;
        cin >> cloDescription;
        clo->updateDescription(cloDescription);
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
    int ID;
    string description;

public:
    PLO(int ploID)
    {
        ID = ploID;
    }

    int getID()
    {
        return ID;
    }

    void updateDescription(string cloDescription)
    {
        description = cloDescription;
    }
};

// CLO (Course Learning Outcome)
class CLO
{
private:
    int ID;
    string description;
    vector<PLO *> relatedPLOs;

public:
    CLO(int cloID)
    {
        ID = cloID;
    }

    int getID()
    {
        return ID;
    }

    void updateDescription(string description)
    {
        this->description = description;
    }

    void addRelatedPLO(PLO *plo)
    {
        relatedPLOs.push_back(plo);
    }
};

class Evaluation
{
private:
    string type; // Quiz, Assignment, or Exam
    int ID;
    vector<CLO *> relatedCLOs;
    vector<Question *> questions;

public:
    Evaluation(string evaluationType, int evaluationID)
    {
        type = evaluationType;
        ID = evaluationID;
    }
    void addQuestion(Question *question)
    {
        questions.push_back(question);
    }

    void updateQuestion(Question *question)
    {
    }

    void removeQuestion(Question *question)
    {
    }

    vector<Question *> getQuestions()
    {
        return questions;
    }
};

class Question
{
private:
    int number;
    string description;
    vector<CLO *> relatedCLOs;

public:
    Question(int number = 1)
    {
        this->number = number;
    }

    void addDescription(string questionDescription)
    {
        description = questionDescription;
    }

    void addRelatedCLO(CLO *clo)
    {
        relatedCLOs.push_back(clo);
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

    return 0;
}