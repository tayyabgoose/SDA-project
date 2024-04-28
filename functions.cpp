#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Program ::Program(int programID, string programName)
{
    ID = programID;
    name = programName;
}
void Program::manageProgram()
{
    cout << "What would you like to do with the program?" << endl;
    cout << "1. Add Course" << endl;
    cout << "2. Remove Course" << endl;
    cout << "3. delete Program" << endl;
    int option;
    std::cin >> option;
    int courseID=courses.back()->getCourseID()+1;
    string courseName;
    switch (option)
    {
    case 1:
    {
        cout << "course ID" << endl<<courseID<<endl;
        cout << "Enter the course name" << endl;
        std::cin >> courseName;
        Course *course = new Course(courseID, courseName);
        courses.push_back(course);
        break;
    }
    case 2:
    {
        cout << "Enter the course ID you would like to remove" << endl;
        std::cin >> courseID;
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i]->getCourseID() == courseID)
            {
                removeCourse(courses[i]);
            }
        }
        break;
    }
    case 3:
    {
        delete this;
        break;
    }
    default:
    {
        cout << "Invalid option selected. Please try again!" << endl;
    }
    }
}
int Program ::getProgramID()
{
    return ID;
}
string Program ::getProgramName()
{
    return name;
}
vector<Course *> Program ::getCourses()
{
    return courses;
}
vector<PLO *> Program ::getPLOs()
{
    return PLOs;
}
void Program::addCourse(Course *course)
{
    courses.push_back(course);
}
void Program ::removeCourse(Course *course)
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
void Program ::setProgramName(string programName)
{
    name = programName;
}
void Program ::setProgramID(int programID)
{
    ID = programID;
}
void Program ::setCourses(Course *cr)
{
    courses.push_back(cr);
}
void Program ::setPlOs(PLO *plos)
{
    PLOs.push_back(plos);
}
void Program::listCourses()
{
    for (int i = 0; i < courses.size(); i++)
    {
        cout << courses[i]->getCourseID() << " " << courses[i]->getCourseName() << endl;
    }
}
Course::Course(int courseID, string courseName)
{
    ID = courseID;
    name = courseName;
}
void Course::setName(string courseName)
{
    name = courseName;
}
void Course::setDescription(string courseDescription)
{
    description = courseDescription;
}
void Course::setCourseID(int courseID)
{
    ID = courseID;
}
void Course::setCourseName(string courseName)
{
    name = courseName;
}
int Course::getCourseID()
{
    return ID;
}
string Course::getCourseName()
{
    return name;
}
vector<Evaluation *> Course::getEvaluations()
{
    return evaluations;
}
vector<CLO *> Course::getCLOs()
{
    return CLOs;
}
void Course::addCLO(CLO *clo)
{
    CLOs.push_back(clo);
}
void Course::removeCLO(CLO *clo)
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
void Course::updateCLO(CLO *clo)
{
    cout << "What would you like to update?" << endl;
    cout << "1. Description" << endl;
    cout << "2. Related PLOs" << endl;
    string newDescription;
    int option;
    std::cin >> option;
    switch (option)
    {
    case 1:
        cout << "Enter the new description for the CLO" << endl;
        std::cin >> newDescription;
        clo->updateDescription(newDescription);
        break;
    case 2:
        cout << "Enter the PLO ID you would like to add" << endl;
        int ploID;
        std::cin >> ploID;
        for (int i = 0; i < clo->getRelatedPLOs().size(); i++)
        {
            if (clo->getRelatedPLOs()[i]->getID() == ploID)
            {
                clo->addRelatedPLO(clo->getRelatedPLOs()[i]);
            }
        }
        break;
    default:
        cout << "Invalid option selected. Please try again!" << endl;
    }
}
void Course::addEvaluation(Evaluation *evaluation)
{
    evaluations.push_back(evaluation);
}

void Course::updateEvaluation(Evaluation *evaluation)
{
    for (int i = 0; i < evaluations.size(); i++)
    {
        if (evaluations[i] == evaluation)
        {
            cout << "Which attribute of the evaluation would you like to change?" << endl;
            cout << "1. Question" << endl;
            cout << "2. Marks" << endl;
            int option;
            string questionDescription;
            std::cin >> option;
            switch (option)
            {
            case 1:
            {
                cout << "what would you like to change?" << endl;
                cout << "1. Add Question" << endl;
                cout << "2. Update Question" << endl;
                cout << "3. Remove Question" << endl;
                int option1;
                std::cin >> option1;
                switch (option1)
                {
                case 1:
                {
                    cout << "Enter the question number" << endl;
                    int questionNumber;
                    std::cin >> questionNumber;
                    Question *question = new Question(questionNumber);
                    cout << "Enter the question description" << endl;
                    std::cin >> questionDescription;
                    question->addDescription(questionDescription);
                    evaluation->addQuestion(question);
                    break;
                }
                case 2:
                {
                    cout << "Enter the question number you would like to update" << endl;
                    int questionNumber1;
                    std::cin >> questionNumber1;
                    for (int i = 0; i < evaluation->getQuestions().size(); i++)
                    {
                        if (evaluation->getQuestions()[i]->getNumber() == questionNumber1)
                        {
                            cout << "Enter the new description for the question" << endl;
                            string newDescription;
                            std::cin >> newDescription;
                            evaluation->getQuestions()[i]->addDescription(newDescription);
                        }
                    }
                    break;
                }
                case 3:
                {
                    cout << "Enter the question number you would like to remove" << endl;
                    int questionNumber2;
                    std::cin >> questionNumber2;
                    for (int i = 0; i < evaluation->getQuestions().size(); i++)
                    {
                        if (evaluation->getQuestions()[i]->getNumber() == questionNumber2)
                        {
                            evaluation->getQuestions().erase(evaluation->getQuestions().begin() + i);
                        }
                    }
                    break;
                }
                }
            case 2:
            {
                cout << "Enter the new marks for the evaluation" << endl;
                float newMarks;
                std::cin >> newMarks;
                evaluation->setMarks(newMarks);
                break;
            }
            default:
            {
                cout << "Invalid option selected. Please try again!" << endl;
            }
            }
            }
        }
    }
}
void Course::removeEvaluation(Evaluation *evaluation)
{
    for (auto it = evaluations.begin(); it != evaluations.end();)
    {
        if (*it == evaluation)
        {
            it = evaluations.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
void Course::updateDescription(string newDescription)
{
    description = newDescription;
}
vector<CLO *> Course::getCLO()
{
    return CLOs;
}
Course::~Course()
{
    for (int i = 0; i < CLOs.size(); i++)
    {
        delete CLOs[i];
    }
}
PLO::PLO(int ploID, string Description)
{
    ID = ploID;
    updateDescription(Description);
}
int PLO::getID()
{
    return ID;
}
vector<CLO *> PLO::getRelatedCLOs()
{
    return relatedCLOs;
}
void PLO::updateDescription(string cloDescription)
{
    description = cloDescription;
}
void PLO::addCLO(CLO *clo)
{
    relatedCLOs.push_back(clo);
}
CLO::CLO(int cloID)
{
    ID = cloID;
}
int CLO::getID()
{
    return ID;
}
vector<PLO *> CLO::getRelatedPLOs()
{
    return relatedPLOs;
}
string CLO::getDescription()
{
    return description;
}
void CLO::updateDescription(string description)
{
    this->description = description;
}
void CLO::addRelatedPLO(PLO *plo)
{
    relatedPLOs.push_back(plo);
}
void CLO::addTopic(string topic)
{
    topics.push_back(topic);
}
void CLO::updateTopic(string topic)
{
    for (int i = 0; i < topics.size(); i++)
    {
        if (topics[i] == topic)
        {
            cout << "Enter the new topic" << endl;
            string newTopic;
            std::cin >> newTopic;
            topics[i] = newTopic;
        }
    }
}
void CLO::removeTopic(string topic)
{
    for (auto it = topics.begin(); it != topics.end();)
    {
        if (*it == topic)
        {
            it = topics.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
Evaluation::Evaluation(string evaluationType, int evaluationID)
{
    type = evaluationType;
    ID = evaluationID;
}
string Evaluation::getType()
{
    return type;
}
int Evaluation::getID()
{
    return ID;
}
float Evaluation::getMarks()
{
    return marks;
}
void Evaluation::setMarks(float evaluationMarks)
{
    marks = evaluationMarks;
}
vector<CLO *> Evaluation::getRelatedCLOs()
{
    return relatedCLOs;
}
vector<Question *> Evaluation::getQuestions()
{
    return questions;
}
void Evaluation::addQuestion(Question *question)
{
    questions.push_back(question);
}
void Evaluation::updateQuestion(Question *question)
{
    cout << "what would you like to update?" << endl;
    cout << "1. Description" << endl;
    cout << "2. Related CLOs" << endl;
    int option;
    string newDescription;
    std::cin >> option;
    switch (option)
    {
    case 1:
        cout << "Enter the new description for the question" << endl;
        std::cin >> newDescription;
        for (int i = 0; i < questions.size(); i++)
        {
            if (questions[i] == question)
            {
                questions[i]->setDescription(newDescription);
            }
        }
    case 2:
        cout << "Enter the CLO ID you would like to add" << endl;
        int cloID;
        std::cin >> cloID;
        for (int i = 0; i < questions.size(); i++)
        {
            if (questions[i] == question)
            {
                for (int j = 0; j < relatedCLOs.size(); j++)
                {
                    if (relatedCLOs[j]->getID() == cloID)
                    {
                        questions[i]->addRelatedCLO(relatedCLOs[j]);
                    }
                }
            }
        }
    }
}


void Evaluation::removeQuestion(Question *question)
{
    for (auto it = questions.begin(); it != questions.end();)
    {
        if (*it == question)
        {
            it = questions.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
Question::Question(int number)
{
    this->number = number;
}
int Question::getNumber()
{
    return number;
}
string Question::getDescription()
{
    return description;
}
vector<CLO *> Question::getRelatedCLOs()
{
    return relatedCLOs;
}
void Question::setDescription(string questionDescription)
{
    description = questionDescription;
}
void Question::addDescription(string questionDescription)
{
    description = questionDescription;
}
void Question::addRelatedCLO(CLO *clo)
{
    relatedCLOs.push_back(clo);
}
User::User(string userName, int userID)
{
    name = userName;
    ID = userID;
}

string User::getName()
{
    return name;
}
int User::getID()
{
    return ID;
}

void User::listTaughtCourses()
{
}
string User::getPassword()
{
    return password;
}
void User::setName(string userName)
{
    name = userName;
}
void User::setID(int userID)
{
    ID = userID;
}
void User::setPassword(string userPassword)
{
    password = userPassword;
}
void User::setType(string userType)
{
    type = userType;
}
string User::getType()
{
    return type;
}

AcademicOfficer::AcademicOfficer(string officerName, int officerID) : User(officerName, officerID)
{
    officerName = officerName;
    officerID = officerID;
    setType("Academic Officer");
}
void AcademicOfficer::setType(string userType)
{
    User::setType("Academic Officer");
}

string AcademicOfficer::getType()
{
    return User::getType();
}
void AcademicOfficer::manageProgram(Program *program)
{
    cout << "What would you like to do with the program?" << endl;
    cout << "1. Add Course" << endl;
    cout << "2. Remove Course" << endl;
    cout << "3. Delete Program" << endl;
    int option;
    std::cin >> option;
    int courseID;
    string courseName;
    switch (option)
    {
    case 1:
    {
        cout << "Enter the course ID" << endl;
        std::cin >> courseID;
        cout << "Enter the course name" << endl;
        std::cin >> courseName;
        Course *course = new Course(courseID, courseName);
        program->addCourse(course);
        break;
    }
    case 2:
    {
        cout << "Enter the course ID you would like to remove" << endl;
        std::cin >> courseID;
        for (int i = 0; i < program->getCourses().size(); i++)
        {
            if (program->getCourses()[i]->getCourseID() == courseID)
            {
                program->removeCourse(program->getCourses()[i]);
            }
        }
        break;
    }
    case 3:
    {
        delete program;
        break;
    }
    default:
    {
        cout << "Invalid option selected. Please try again!" << endl;
    }
    }
}

void AcademicOfficer::manageCourse(Course *course)
{
    cout << "What would you like to do with the course?" << endl;
    cout << "1. Update Course" << endl;
    cout << "2. Remove Course" << endl;
    int option;
    int option1;
    string newName;
    string newDescription;
    std::cin >> option;
    switch (option)
    {
    case 1:
    {
        cout << "What would you like to update?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Description" << endl;
        std::cin >> option1;
        switch (option1)
        {
        case 1:
        {
            cout << "Enter the new name for the course" << endl;
            std::cin >> newName;
            course->setName(newName);
            break;
        }
        case 2:
        {
            cout << "Enter the new description for the course" << endl;
            std::cin >> newDescription;
            course->setDescription(newDescription);
            break;
        }
        default:
        {
            cout << "Invalid option selected. Please try again!" << endl;
        }
        }
        break;
    }
    case 2:
    {
        delete course;
        break;
    }
    default:
    {
        cout << "Invalid option selected. Please try again!" << endl;
    }
    }
}
void AcademicOfficer::managePLO(PLO *plo)
{
    cout << "What would you like to do with the PLO?" << endl;
    cout << "1. Update Description" << endl;
    cout << "2. Add CLO" << endl;
    int option;
    string newDescription;
    std::cin >> option;
    switch (option)
    {
    case 1:
    {
        cout << "Enter the new description for the PLO" << endl;
        std::cin >> newDescription;
        plo->updateDescription(newDescription);
        break;
    }
    case 2:
    {
        int cloID=plo->getRelatedCLOs().back()->getID()+1;
        cout << "CLO ID" <<endl<<cloID<< endl;
        for (int i = 0; i < plo->getRelatedCLOs().size(); i++)
        {
            if (plo->getRelatedCLOs()[i]->getID() == cloID)
            {
                plo->addCLO(plo->getRelatedCLOs()[i]);
            }
        }
        break;
    }
    default:
        cout << "Invalid option selected. Please try again!" << endl;
    }
}

void AcademicOfficer::manageCLO(CLO *clo)
{
    cout << "What would you like to do with the CLO?" << endl;
    cout << "1. Update Description" << endl;
    cout << "2. Add Topic" << endl;
    cout << "3. Update Topic" << endl;
    cout << "4. Remove Topic" << endl;
    int option;
    string newDescription;
    string topic;
    std::cin >> option;
    switch (option)
    {
    case 1:
        cout << "Enter the new description for the CLO" << endl;
        std::cin >> newDescription;
        clo->updateDescription(newDescription);
        break;
    case 2:
        cout << "Enter the topic you would like to add" << endl;
        std::cin >> topic;
        clo->addTopic(topic);
        break;
    case 3:
        cout << "Enter the topic you would like to update" << endl;
        std::cin >> topic;
        clo->updateTopic(topic);
        break;
    case 4:
        cout << "Enter the topic you would like to remove" << endl;
        std::cin >> topic;
        clo->removeTopic(topic);
        break;
    default:
        cout << "Invalid option selected. Please try again!" << endl;
    }
}

Teacher::Teacher(string teacherName, int teacherID) : User(teacherName, teacherID)
{
    teacherName = teacherName;
    teacherID = teacherID;
    setType("Teacher");
}
void Teacher::setType(string userType)
{
    User::setType("Teacher");
}
string Teacher::getType()
{
    return User::getType();
}
void Teacher::addTaughtCourse(Course *course)
{
    taughtCourses.push_back(course);
}
void Teacher::removeTaughtCourse(Course *course)
{
    for (auto it = taughtCourses.begin(); it != taughtCourses.end();)
    {
        if (*it == course)
        {
            it = taughtCourses.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
void Teacher::listTaughtCourses()
{
    for (int i = 0; i < taughtCourses.size(); i++)
    {
        cout << taughtCourses[i]->getCourseID() << " " << taughtCourses[i]->getCourseName() << endl;
    }
}
void Teacher:: addTopicsCovered(string topics,int cloID)
{
    for(int i=0;i<taughtCourses.size();i++)
    {
        for(int j=0;j<taughtCourses[i]->getCLOs().size();j++)
        {
            if(taughtCourses[i]->getCLOs()[j]->getID()==cloID)
            {
                taughtCourses[i]->getCLOs()[j]->addTopic(topics);
            }
        }
    }
}
void Teacher::removeTopicsCovered(string topics)
{
    for(int i=0;i<taughtCourses.size();i++)
    {
        for(int j=0;j<taughtCourses[i]->getCLOs().size();j++)
        {
            taughtCourses[i]->getCLOs()[j]->removeTopic(topics);
        }
    }
}

void Teacher:: listclosofCourse(int courseID)
{
    for(int i=0;i<taughtCourses.size();i++)
    {
        if(taughtCourses[i]->getCourseID()==courseID)
        {
            for(int j=0;j<taughtCourses[i]->getCLOs().size();j++)
            {
                cout<<taughtCourses[i]->getCLOs()[j]->getID()<<" "<<taughtCourses[i]->getCLOs()[j]->getDescription()<<endl;
            }
        }
    }
}
void Teacher::addEvaluation(Evaluation *evaluation)
{
    evaluations.push_back(evaluation);
}
void Teacher::manageEvaluation(Evaluation *evaluation)
{
    cout << "What would you like to do with the evaluation?" << endl;
    cout << "1. Update Evaluation" << endl;
    cout << "2. Remove Evaluation" << endl;
    int option;
    std::cin >> option;
    switch (option)
    {
    case 1:
        cout << "What would you like to update?" << endl;
        cout << "1. Question" << endl;
        cout << "2. Marks" << endl;
        int option1;
        string questionDescription;
        std::cin >> option1;
        switch (option1)
        {
        case 1:
            cout << "what would you like to change?" << endl;
            cout << "1. Add Question" << endl;
            cout << "2. Update Question" << endl;
            cout << "3. Remove Question" << endl;
            int option2;
            std::cin >> option2;
            switch (option2)
            {
            case 1:
            {
                int questionNumber=evaluation->getQuestions().back()->getNumber()+1;
                cout << "question number" << endl<<questionNumber<<endl;
                Question *question = new Question(questionNumber);
                cout << "Enter the question description" << endl;
                std::cin >> questionDescription;
                question->addDescription(questionDescription);
                evaluation->addQuestion(question);
                break;
            }
            case 2:
            {
                cout << "Enter the question number you would like to update" << endl;
                int questionNumber1;
                std::cin >> questionNumber1;
                for (int i = 0; i < evaluation->getQuestions().size(); i++)
                {
                    if (evaluation->getQuestions()[i]->getNumber() == questionNumber1)
                    {
                        cout << "Enter the new description for the question" << endl;
                        string newDescription;
                        std::cin >> newDescription;
                        evaluation->getQuestions()[i]->addDescription(newDescription);
                    }
                }
                break;
            }
            case 3:
            {
                cout << "Enter the question number you would like to remove" << endl;
                int questionNumber2;
                std::cin >> questionNumber2;
                for (int i = 0; i < evaluation->getQuestions().size(); i++)
                {
                    if (evaluation->getQuestions()[i]->getNumber() == questionNumber2)
                    {
                        evaluation->getQuestions().erase(evaluation->getQuestions().begin() + i);
                    }
                }
                break;
            }
            }
        case 2:
        {
            cout << "Enter the new marks for the evaluation" << endl;
            float newMarks;
            std::cin >> newMarks;
            evaluation->setMarks(newMarks);
            break;
        }
        default:
        {
            cout << "Invalid option selected. Please try again!" << endl;
        }
        }
    }
}
void Teacher::updateMarks(Evaluation *evaluation)
{
    cout << "Enter the new marks for the evaluation" << endl;
    float newMarks;
    std::cin >> newMarks;
    evaluation->setMarks(newMarks);
}

void OBESupportSystem::addProgram(Program *pr)
{
    programs.push_back(pr);
}
void OBESupportSystem::removeProgram(Program *pr)
{
    for (auto it = programs.begin(); it != programs.end();)
    {
        if (*it == pr)
        {
            it = programs.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
Program *OBESupportSystem::getProgram(int programID)
{
    for (int i = 0; i < programs.size(); i++)
    {
        if (programs[i]->getProgramID() == programID)
        {
            return programs[i];
        }
    }
}
User* OBESupportSystem::getUser(int id)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->getID() == id)
        {
            cout << users[i]->getName() << endl;
            return users[i];
        }
    }
}
void OBESupportSystem::manageProgram()
{
    cout << "What would you like to do with the program?" << endl;
    cout << "1. Add Program" << endl;
    cout << "2. Remove Program" << endl;
    cout << "3. Update Program" << endl;
    int option;
    std::cin >> option;
    switch (option)
    {
    case 1:
    {
        int programID=programs.back()->getProgramID()+1;
        cout << "program ID" << endl<<programID<<endl;
        cout << "Enter the program name" << endl;
        string programName;
        std::cin >> programName;
        Program *pr = new Program(programID, programName);
        OBESupportSystem::addProgram(pr);
        break;
    }
    case 2:
    {
        cout << "Enter the program ID you would like to remove" << endl;
        int programID;
        std::cin >> programID;
        for (int i = 0; i < programs.size(); i++)
        {
            if (programs[i]->getProgramID() == programID)
            {
                removeProgram(programs[i]);
            }
        }
        break;
    }
    case 3:
    {
        cout << "Enter the program ID you would like to update" << endl;
        int programID;
        std::cin >> programID;
        Program *program = getProgram(programID);
        if (program != nullptr)
        {
            cout << "Enter the new program name" << endl;
            string newProgramName;
            std::cin >> newProgramName;
            program->setProgramName(newProgramName);
        }
        else
        {
            cout << "Program not found!" << endl;
        }
        break;
    }
    default:
    {
        cout << "Invalid option selected. Please try again!" << endl;
    }
    }
}
void OBESupportSystem::listPrograms()
{
    for (int i = 0; i < programs.size(); i++)
    {
        cout << programs[i]->getProgramID() << " " << programs[i]->getProgramName() << endl;
    }
}

void OBESupportSystem::addUser(User *user)
{
    users.push_back(user);
}
void OBESupportSystem::listTeachers()
{
    for (int i = 0; i < users.size(); i++)
    {
        if(users[i]->getType()=="Teacher")
        {
        cout << users[i]->getID() << " " << users[i]->getName() << endl;
        }
    }
}
void OBESupportSystem::removeUser(User *user)
{
    for (auto it = users.begin(); it != users.end();)
    {
        if (*it == user)
        {
            it = users.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
void OBESupportSystem::manageUser()
{
    cout << "What would you like to do with the user?" << endl;
    cout << "1. Add User" << endl;
    cout << "2. Remove User" << endl;
    cout << "3. Append User" << endl;
    int option;
    std::cin >> option;
    switch (option)
    {
    case 1:
    {
        int userID=users.back()->getID()+1;
        cout << "Enter the user ID" << endl<<userID<<endl;
        cout << "Enter the user name" << endl;
        string userName;
        std::cin >> userName;
        User *user = new User(userName, userID);
        addUser(user);
        break;
    }
    case 2:
    {
        cout << "Enter the user ID you would like to remove" << endl;
        int userID;
        std::cin >> userID;
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i]->getID() == userID)
            {
                removeUser(users[i]);
            }
        }
        break;
    }
    case 3:
    {
        cout << "Enter the user ID you would like to append" << endl;
        int userID;
        std::cin >> userID;
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i]->getID() == userID)
            {
                cout << "Enter the new name for the user" << endl;
                string newName;
                std::cin >> newName;
                users[i]->setName(newName);
            }
        }
        break;
    }
    }
}