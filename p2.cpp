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

class Program {
private:
    int ID;
    string name;
    vector<Course *> courses;
    vector<PLO *> PLOs;

public:
    Program(int programID, string programName) : ID(programID), name(programName) {}

    void addCourse(Course *course) {
        courses.push_back(course);
    }

    void updateCourse(Course *course) {
        // Implement logic to update course details (e.g., name, description)
    }

    void removeCourse(Course *course) {
        // Implement logic to remove course from program and memory (if applicable)
    }

    vector<Course *> getCourses() const {
        return courses;
    }

    vector<PLO *> getPLOs() const {
        return PLOs;
    }

    void listCourses() {
        for (Course *course : courses) {
            cout << "Course ID: " << course->getCourseID() << ", Name: " << course->name << endl;
        }
    }
};

class Course {
private:
    int ID;
    string name;
    string description;
    vector<CLO *> CLOs;
    vector<Evaluation *> evaluations;

public:
    Course(int courseID, string courseName) : ID(courseID), name(courseName) {}

    int getCourseID() const {
        return ID;
    }

    void addCLO(CLO *clo) {
        CLOs.push_back(clo);
    }

    void updateCLO(CLO *clo) {
        cout << "Please enter the description for this CLO ID: " << clo->getID() << endl;
        string cloDescription;
        cin >> cloDescription;
        clo->updateDescription(cloDescription);
    }

    void removeCLO(CLO *clo) {
        for (auto it = CLOs.begin(); it != CLOs.end(); ++it) {
            if (*it == clo) {
                it = CLOs.erase(it);
                break; // Exit the loop after removing the first occurrence
            }
        }
    }

    void addEvaluation(Evaluation *evaluation) {
        evaluations.push_back(evaluation);
    }

    void updateEvaluation(Evaluation *evaluation) {
        // Implement logic to update evaluation details (e.g., type, marks)
    }

    void removeEvaluation(Evaluation *evaluation) {
        // Implement logic to remove evaluation from course and memory (if applicable)
    }

    void updateDescription(string newDescription) {
        description = newDescription;
    }

    vector<CLO *> getCLO() const {
        return CLOs;
    }
};

// PLO (Program Learning Outcome)
class PLO {
private:
    int ID;
    string description;

public:
    PLO(int ploID) : ID(ploID) {}

    int getID() const {
        return ID;
    }

    void updateDescription(string cloDescription) {
        description = cloDescription;
    }

    // Function implementation for addCLO is omitted (PLOs don't directly contain CLOs)
};

// CLO (Course Learning Outcome)
class CLO {
private:
    int ID;
    string description;
    vector<string> topics;
    vector<PLO *> relatedPLOs;

public:
    CLO(int cloID) : ID(cloID) {}

    int getID() const {
        return ID;
    }

    void updateDescription(string description) {
        this->description = description;
    }

    void addRelatedPLO(PLO *plo) {
        relatedPLOs.push_back(plo);
    }

    void addTopic(string topic) {
        topics.push_back(topic);
    }

    // Function implementations for updateTopic and removeTopic are omitted for brevity
};

