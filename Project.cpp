// Group Project
// Software Design & Analysis
// Muhammad Tayyab (21L-7686) & Tauqeer Ahson (21L-6036)

#include <iostream>
#include <fstream>
#include <string>

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
};

// CLO (Course Learning Outcome)
class CLO
{
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
    
};

int main()
{
}