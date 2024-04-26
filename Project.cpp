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

    // void updateCourse(Course *course)
    // {
    //     for (int i = 0; i < courses.size(); i++)
    //     {
    //         if (courses[i]->getCourseID() == course->getCourseID())
    //         {
    //             cout << "Which attribute would you like to update? enter valid number" << endl;
    //             cout << "1. Name" << endl;
    //             cout << "2. Description" << endl;
    //             cout << "3. Edit CLO" << endl;
    //             int option;
    //             cin >> option;
    //             int exit = 0;
    //             while (exit == 0)
    //             {
    //                 switch (option)
    //                 {
    //                 case 1:
    //                 {
    //                     cout << "What would you like to change the name to?" << endl;
    //                     string courseName;
    //                     cin >> courseName;
    //                     course->setName(courseName);
    //                     break;
    //                 }
    //                 case 2:
    //                 {
    //                     cout << "What would you like to update the description to?" << endl;
    //                     string courseDescription;
    //                     cin >> courseDescription;
    //                     course->setDescription(courseDescription);
    //                     break;
    //                 }
    //                 default:
    //                     cout << "The option you have selected is invalid." << endl;
    //                     exit = 1;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }

    void removeCourse(Course *course)
    {
        for (auto it = courses.begin(); it != courses.end();)
        {
            if (*it == course)
            {
                it = courses.erase(it);
            }
            else
            {
                ++it;
            }
        }
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
        for(int i=0;i<courses.size();i++)
        {
            cout << courses[i]->getCourseID() << " " << courses[i]->getCourseName() << endl;           
        }
    }
};

class Course
{
private:
    int ID;
    string name;
    string description;
    vector<CLO *> CLOs;
    vector<Evaluation *> evaluations;

public:
    Course(int courseID, string courseName)
    {
        ID = courseID;
        name = courseName;
    }

    void setName(string courseName)
    {
        name = courseName;
    }

    void setDescription(string courseDescription)
    {
        description = courseDescription;
    }

    int getCourseID()
    {
        return ID;
    }

    string getCourseName()
    {
        return name;
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
        for (auto it = CLOs.begin(); it != CLOs.end();)
        {
            if (*it == clo)
            {
                it = CLOs.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    void addEvaluation(Evaluation *evaluation)
    {
        evaluations.push_back(evaluation);
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

    ~Course()
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

    void removeTeacher()
    {
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
private:
    vector<User *> users;

public:
    void addProgram()
    {
    }

    void removeProgram()
    {
    }

    void manageProgram()
    {
    }

    void addUser()
    {
    }

    void removeUser()
    {
    }

    void manageUser()
    {
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