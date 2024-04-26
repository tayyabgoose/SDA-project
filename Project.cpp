// Group Project
// Software Design & Analysis
// Muhammad Tayyab (21L-7686) & Tauqeer Ahson (21L-6036)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Course;
class PLO;
class CLO;
class Evaluation;
class Question;
class User;
class AcademicOfficer;
class Teacher;
class Report;

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
    string description;
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

    void updateDescription(string newDescription)
    {
        description = newDescription;
    }

    vector<CLO *> getCLO()
    {
        return CLOs;
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

    void addCLO(CLO *clo)
    {
    }
};

// CLO (Course Learning Outcome)
class CLO
{
private:
    int ID;
    string description;
    vector<string> topics;
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

    void addTopic(string topic)
    {
        topics.push_back(topic);
    }

    void updateTopic()
    {
    }

    void removeTopic(string topic)
    {
    }
};

class Evaluation
{
private:
    string type; // Quiz, Assignment, or Exam
    int ID;
    float marks;
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

    void setMarks(float evaluationMarks)
    {
        marks = evaluationMarks;
    }

    float getMarks()
    {
        return marks;
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
private:
    string name;
    int ID;
    string password;

public:
    User(string userName, int userID)
    {
        name = userName;
        ID = userID;
    }

    void addUser()
    {

    }

    void removeUser()
    {

    }

    
};

class AcademicOfficer : public User
{
private:
public:
    AcademicOfficer(string officerName, int officerID) : User(officerName, officerID)
    {
    }

    void manageProgram(Program *program)
    {
    }

    void manageCourse(Course *course)
    {
    }

    void managePLO(PLO *plo)
    {
    }

    void manageCLO(CLO *clo)
    {
    }
};

class Teacher : public User
{
private:
    vector<Course *> taughtCourses;
    vector<Evaluation *> evaluations;

public:
    Teacher(string teacherName, int teacherID) : User(teacherName, teacherID)
    {
    }

    void addTaughtCourse(Course *course)
    {
        taughtCourses.push_back(course);
    }

    void addEvaluation(Evaluation *evaluation)
    {
        evaluations.push_back(evaluation);
    }

    void manageEvaluation(Evaluation *evaluation)
    {
    }

    void manageMarks(float marks)
    {
    }

    void addTeacher()
    {

    }

    void removeTeacher(){

    }
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

void OBESupportSystem()
{
    void addProgram(){

    }

    void removeProgram(){

    }

    void manageProgram(){

    }

    void addUser(){

    }

    void removeUser(){

    }

    void manageUser(){

    }
}

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