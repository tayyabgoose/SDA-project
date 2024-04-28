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
class OBESupportSystem;
class Program
{
private:
    int ID;
    string name;
    vector<Course *> courses;
    vector<PLO *> PLOs;

public:
    Program(int programID, string programName);

    void manageProgram();

    int getProgramID();

    string getProgramName();

    vector<Course *> getCourses();

    vector<PLO *> getPLOs();

    void addCourse(Course *course);

    void removeCourse(Course *course);

    void setProgramName(string programName);

    void setProgramID(int programID);

    void setCourses(Course * cr);

    void setPlOs(PLO *plos);

    void listCourses();
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
    Course(int courseID, string courseName);

    void setName(string courseName);

    void setDescription(string courseDescription);

    void setCourseID(int courseID);

    void setCourseName(string courseName);

    int getCourseID();

    string getCourseName();

    vector<Evaluation *> getEvaluations();

    vector<CLO *> getCLOs();
    
    void addCLO(CLO *clo);

    void updateCLO(CLO *clo);

    void removeCLO(CLO *clo);

    void addEvaluation(Evaluation *evaluation);

    void updateEvaluation(Evaluation *evaluation);

    void removeEvaluation(Evaluation *evaluation);

    void updateDescription(string newDescription);

    vector<CLO *> getCLO();

    ~Course();
};



// PLO (Program Learning Outcome)
class PLO
{
private:
    int ID;
    string description;
    vector<CLO *> relatedCLOs;

public:
    PLO(int ploID,string Description);

    int getID();
    vector<CLO *> getRelatedCLOs();

    void updateDescription(string cloDescription);

    void addCLO(CLO *clo);
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
    CLO(int cloID);

    int getID();

    vector<PLO *> getRelatedPLOs();

    string getDescription();

    void updateDescription(string description);

    void addRelatedPLO(PLO *plo);

    void addTopic(string topic);

    void updateTopic(string topic);

    void removeTopic(string topic);
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
    Evaluation(string evaluationType, int evaluationID);

    string getType();

    int getID();

    float getMarks();

    void setMarks(float evaluationMarks);

    vector<CLO *> getRelatedCLOs();

    vector<Question *> getQuestions();

    void addQuestion(Question *question);

    void updateQuestion(Question *question);

    void removeQuestion(Question *question);
};

class Question
{
private:
    int number;
    string description;
    vector<CLO *> relatedCLOs;

public:
    Question(int number = 1);

    int getNumber();

    string getDescription();

    vector<CLO *> getRelatedCLOs();

    void setDescription(string questionDescription);

    void addDescription(string questionDescription);

    void addRelatedCLO(CLO *clo);
};

class User
{
private:
    string name;
    string type;
    int ID;
    string password;
    OBESupportSystem *system;

public:
    User(string userName, int userID);

    string getName();

    void setType(string userType);

    string getType();

    int getID();

    virtual void listTaughtCourses();

    string getPassword();

    void setName(string userName);

    void setID(int userID);

    void setPassword(string userPassword);
};

class AcademicOfficer : public User
{
private:
    Program *pr;

public:
    AcademicOfficer(string officerName, int officerID);

    void setType(string type);

    string getType();

    void manageProgram(Program *program);

    void manageCourse(Course *course);

    void managePLO(PLO *plo);

    void manageCLO(CLO *clo);
};

class Teacher : public User
{
private:
    vector<Course *> taughtCourses;
    vector<Evaluation *> evaluations;

public:
    Teacher(string teacherName, int teacherID);

    void setType(string type);

    string getType();

    void addTaughtCourse(Course *course);

    void removeTaughtCourse(Course *course);

    void addTopicsCovered(string topics,int cloID);

    void removeTopicsCovered(string topics);

    void listTaughtCourses();

    void listclosofCourse(int courseID);

    void addEvaluation(Evaluation *evaluation);

    void manageEvaluation(Evaluation *evaluation);

    void updateMarks(Evaluation *evaluation);
};

class Report
{
private:
    int id;
    string semester;
    Program *program;

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

class OBESupportSystem
{
private:
    vector<User *> users;
    vector<Program *> programs;

public:
    void addProgram(Program *pr);

    void removeProgram(Program *pr);

    User* getUser(int id);

    Program* getProgram(int id);

    void manageProgram();

    void listPrograms();

    void listTeachers();

    void addUser(User *user);

    void removeUser(User *user);

    void manageUser();
};