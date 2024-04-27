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
class OBESupportSystem;

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
    int getProgramID()
    {
        return ID;
    }
    string getProgramName()
    {
        return name;
    }
    vector<Course *> getCourses()
    {
        return courses;
    }
    vector<PLO *> getPLOs()
    {
        return PLOs;
    }
    void addCourse(Course *course)
    {
        courses.push_back(course);
    }


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

    void setProgramName(string programName)
    {
        name = programName;
    }
    void setProgramID(int programID)
    {
        ID = programID;
    }

    void setCourses(vector<Course *> courses)
    {
        this->courses = courses;
    }

    void setPlOs(vector<PLO *> PLOs)
    {
        this->PLOs = PLOs;
    }

    void listCourses()
    {
        for(int i=0;i<courses.size();i++)
        {
            cout << courses[i]->getCourseID() << " " << courses[i]->getCourseName()<< endl;           
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
    void setCourseID(int courseID)
    {
        ID = courseID;
    }
    void setCourseName(string courseName)
    {
        name = courseName;
    }

    int getCourseID()
    {
        return ID;
    }

    string getCourseName()
    {
        return name;
    }

    vector<Evaluation *> getEvaluations()
    {
        return evaluations;
    }

    vector<CLO *> getCLOs()
    {
        return CLOs;
    }
    void addCLO(CLO *clo)
    {
        CLOs.push_back(clo);
    }

    void updateCLO(CLO *clo)
    {
        cout<<"What would you like to update?"<<endl;
        cout<<"1. Description"<<endl;
        cout<<"2. Related PLOs"<<endl;
        string newDescription;
        int option;
        cin >> option;
        switch(option)
        {
            case 1:
            cout<<"Enter the new description for the CLO"<<endl;
            cin >> newDescription;
            clo->updateDescription(newDescription);
            break;
            case 2:
            cout<<"Enter the PLO ID you would like to add"<<endl;
            int ploID;
            cin >> ploID;
            for(int i=0;i<clo->getRelatedPLOs().size();i++)
            {
                if(clo->getRelatedPLOs()[i]->getID() == ploID)
                {
                    clo->addRelatedPLO(clo->getRelatedPLOs()[i]);
                }
            }
            break;
            default:
            cout<<"Invalid option selected. Please try again!"<<endl;
        }
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
        for(int i=0;i<evaluations.size();i++)
        {
            if(evaluations[i] == evaluation)
            {
                cout<<"Which attribute of the evaluation would you like to change?"<<endl;
                cout<<"1. Question"<<endl;
                cout<<"2. Marks"<<endl;
                int option;
                string questionDescription;
                cin >> option;
                switch(option)
                {
                    case 1:
                    cout<<"what would you like to change?"<<endl;
                    cout<<"1. Add Question"<<endl;
                    cout<<"2. Update Question"<<endl;
                    cout<<"3. Remove Question"<<endl;
                    int option1;
                    cin >> option1;
                    switch(option1)
                    {
                        case 1:
                        cout<<"Enter the question number"<<endl;
                        int questionNumber;
                        cin >> questionNumber;
                        Question *question = new Question(questionNumber);
                        cout<<"Enter the question description"<<endl;
                        cin >> questionDescription;
                        question->addDescription(questionDescription);
                        evaluation->addQuestion(question);
                        break;
                        case 2:
                        cout<<"Enter the question number you would like to update"<<endl;
                        int questionNumber1;
                        cin >> questionNumber1;
                        for(int i=0;i<evaluation->getQuestions().size();i++)
                        {
                            if(evaluation->getQuestions()[i]->getNumber() == questionNumber1)
                            {
                                cout<<"Enter the new description for the question"<<endl;
                                string newDescription;
                                cin >> newDescription;
                                evaluation->getQuestions()[i]->addDescription(newDescription);
                            }
                        }
                        break;
                        case 3:
                        cout<<"Enter the question number you would like to remove"<<endl;
                        int questionNumber2;
                        cin >> questionNumber2;
                        for(int i=0;i<evaluation->getQuestions().size();i++)
                        {
                            if(evaluation->getQuestions()[i]->getNumber() == questionNumber2)
                            {
                                evaluation->getQuestions().erase(evaluation->getQuestions().begin() + i);
                            }
                        }
                        break;
                    }
                    case 2:
                    cout<<"Enter the new marks for the evaluation"<<endl;
                    float newMarks;
                    cin >> newMarks;
                    evaluation->setMarks(newMarks);
                    break;
                    default:
                    cout<<"Invalid option selected. Please try again!"<<endl;
                }   
            }
    }
    }

    void removeEvaluation(Evaluation *evaluation)
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
        for (int i = 0; i < CLOs.size(); i++)
        {
            delete CLOs[i];
        }
    }
};

// PLO (Program Learning Outcome)
class PLO
{
private:
    int ID;
    string description;
    vector<CLO *> relatedCLOs;

public:
    PLO(int ploID)
    {
        ID = ploID;
    }

    int getID()
    {
        return ID;
    }
    vector<CLO*> getRelatedCLOs()
    {
        return relatedCLOs;
    }

    void updateDescription(string cloDescription)
    {
        description = cloDescription;
    }

    void addCLO(CLO *clo)
    {
        relatedCLOs.push_back(clo);
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
    vector<PLO *> getRelatedPLOs()
    {
        return relatedPLOs;
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

    void updateTopic(string topic)
    {
        for (int i = 0; i < topics.size(); i++)
        {
            if (topics[i] == topic)
            {
                cout << "Enter the new topic" << endl;
                string newTopic;
                cin >> newTopic;
                topics[i] = newTopic;
            }
        }
    }

    void removeTopic(string topic)
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
    string getType()
    {
        return type;
    }
    int getID()
    {
        return ID;
    }
    float getMarks()
    {
        return marks;
    }
    vector<CLO *> getRelatedCLOs()
    {
        return relatedCLOs;
    }
    vector<Question *> getQuestions()
    {
        return questions;
    }
    void addQuestion(Question *question)
    {
        questions.push_back(question);
    }

    void updateQuestion(Question *question)
    {
        cout<<"what would you like to update?"<<endl;
        cout<<"1. Description"<<endl;
        cout<<"2. Related CLOs"<<endl;
        int option;
        string newDescription;
        cin >> option;
        switch(option)
        {
            case 1:
            cout<<"Enter the new description for the question"<<endl;
            cin >> newDescription;
            for(int i=0;i<questions.size();i++)
            {
                if(questions[i] == question)
                {
                    questions[i]->setDescription(newDescription);
                }
                
            }
            case 2:
            cout<<"Enter the CLO ID you would like to add"<<endl;
            int cloID;
            cin >> cloID;
            for(int i=0;i<questions.size();i++)
            {
                if(questions[i] == question)
                {
                    for(int j=0;j<relatedCLOs.size();j++)
                    {
                        if(relatedCLOs[j]->getID() == cloID)
                        {
                            questions[i]->addRelatedCLO(relatedCLOs[j]);
                        }
                    }
                }
            }


        }
    }

    void removeQuestion(Question *question)
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
    int getNumber()
    {
        return number;
    }
    string getDescription()
    {
        return description;
    }
    vector<CLO *> getRelatedCLOs()
    {
        return relatedCLOs;
    }
    void setDescription(string questionDescription)
    {
        description = questionDescription;
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
    OBESupportSystem *system;

public:
    User(string userName, int userID)
    {
        name = userName;
        ID = userID;
    }
    string getName()
    {
        return name;
    }
    int getID()
    {
        return ID;
    }
    string getPassword()
    {
        return password;
    }
    void setName(string userName)
    {
        name = userName;
    }
    void setID(int userID)
    {
        ID = userID;
    }
    void setPassword(string userPassword)
    {
        password = userPassword;
    }
};

class AcademicOfficer : public User
{
private:
Program *pr;
public:
    AcademicOfficer(string officerName, int officerID) : User(officerName, officerID)
    {
        officerName = officerName;
        officerID = officerID;
    }

    void manageProgram(Program *program)
    {
        cout<<"What would you like to do with the program?"<<endl;
        cout<<"1. Add Course"<<endl;
        cout<<"2. Remove Course"<<endl;
        cout<<"3. delete Program"<<endl;
        int option;
        cin >> option;
        int courseID;
        string courseName;
        switch(option)
        {
            case 1:
                cout<<"Enter the course ID"<<endl;
                cin >> courseID;
                cout<<"Enter the course name"<<endl;
                cin >> courseName;
                Course *course = new Course(courseID, courseName);
                program->addCourse(course);
                break;
            case 2:
                cout<<"Enter the course ID you would like to remove"<<endl;
                cin >> courseID;
                for(int i=0;i<program->getCourses().size();i++)
                {
                    if(program->getCourses()[i]->getCourseID() == courseID)
                    {
                        program->removeCourse(program->getCourses()[i]);
                    }
                }
                break;
            case 3:
                delete program;
                break;
            default:
                cout<<"Invalid option selected. Please try again!"<<endl;
        }
    }

    void manageCourse(Course *course)
    {
        cout<<"What would you like to do with the course?"<<endl;
        cout<<"1. Update Course"<<endl;
        cout<<"2. Remove Course"<<endl;
        int option;
        int option1;
        string newName;
        string newDescription;
        cin >> option;
        switch(option)
        {
            case 1:
                cout<<"What would you like to update?"<<endl;
                cout<<"1. Name"<<endl;
                cout<<"2. Description"<<endl;
                cin >> option1;
                switch(option1)
                {
                    case 1:
                    cout<<"Enter the new name for the course"<<endl;
                    cin >> newName;
                    course->setName(newName);
                    break;
                    case 2:
                    cout<<"Enter the new description for the course"<<endl;
                    cin >> newDescription;
                    course->setDescription(newDescription);
                    break;
                    default:
                    cout<<"Invalid option selected. Please try again!"<<endl;
                }
                break;
            case 2:
                delete course;
                break;
            default:
                cout<<"Invalid option selected. Please try again!"<<endl;
        }
    }

    void managePLO(PLO *plo)
    {
        cout<<"What would you like to do with the PLO?"<<endl;
        cout<<"1. Update Description"<<endl;
        cout<<"2. Add CLO"<<endl;
        int option;
        string newDescription;
        cin >> option;
        switch(option)
        {
            case 1:
            {
            cout<<"Enter the new description for the PLO"<<endl;
            cin >> newDescription;
            plo->updateDescription(newDescription);
            break;
            }
            case 2:
            {
            cout<<"Enter the CLO ID you would like to add"<<endl;
            int cloID;
            cin >> cloID;
            for(int i=0;i<plo->getRelatedCLOs().size();i++)
            {
                if(plo->getRelatedCLOs()[i]->getID() == cloID)
                {
                    plo->addCLO(plo->getRelatedCLOs()[i]);
                }
            }
            break;
            }
            default:
            cout<<"Invalid option selected. Please try again!"<<endl;
        }
    }

    void manageCLO(CLO *clo)
    {
        cout<<"What would you like to do with the CLO?"<<endl;
        cout<<"1. Update Description"<<endl;
        cout<<"2. Add Topic"<<endl;
        cout<<"3. Update Topic"<<endl;
        cout<<"4. Remove Topic"<<endl;
        int option;
        string newDescription;
        string topic;
        cin >> option;
        switch(option)
        {
            case 1:
            cout<<"Enter the new description for the CLO"<<endl;
            cin >> newDescription;
            clo->updateDescription(newDescription);
            break;
            case 2:
            cout<<"Enter the topic you would like to add"<<endl;
            cin >> topic;
            clo->addTopic(topic);
            break;
            case 3:
            cout<<"Enter the topic you would like to update"<<endl;
            cin >> topic;
            clo->updateTopic(topic);
            break;
            case 4:
            cout<<"Enter the topic you would like to remove"<<endl;
            cin >> topic;
            clo->removeTopic(topic);
            break;
            default:
            cout<<"Invalid option selected. Please try again!"<<endl;
        }
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
        teacherName = teacherName;
        teacherID = teacherID;
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
        cout<<"What would you like to do with the evaluation?"<<endl;
        cout<<"1. Update Evaluation"<<endl;
        cout<<"2. Remove Evaluation"<<endl;
        int option;
        cin >> option;
        switch(option)
        {
            case 1:
            cout<<"What would you like to update?"<<endl;
            cout<<"1. Question"<<endl;
            cout<<"2. Marks"<<endl;
            int option1;
            string questionDescription;
            cin >> option1;
            switch(option1)
            {
                case 1:
                cout<<"what would you like to change?"<<endl;
                cout<<"1. Add Question"<<endl;
                cout<<"2. Update Question"<<endl;
                cout<<"3. Remove Question"<<endl;
                int option2;
                cin >> option2;
                switch(option2)
                {
                    case 1:
                    cout<<"Enter the question number"<<endl;
                    int questionNumber;
                    cin >> questionNumber;
                    Question *question = new Question(questionNumber);
                    cout<<"Enter the question description"<<endl;
                    cin >> questionDescription;
                    question->addDescription(questionDescription);
                    evaluation->addQuestion(question);
                    break;
                    case 2:
                    cout<<"Enter the question number you would like to update"<<endl;
                    int questionNumber1;
                    cin >> questionNumber1;
                    for(int i=0;i<evaluation->getQuestions().size();i++)
                    {
                        if(evaluation->getQuestions()[i]->getNumber() == questionNumber1)
                        {
                            cout<<"Enter the new description for the question"<<endl;
                            string newDescription;
                            cin >> newDescription;
                            evaluation->getQuestions()[i]->addDescription(newDescription);
                        }
                    }
                    break;
                    case 3:
                    cout<<"Enter the question number you would like to remove"<<endl;
                    int questionNumber2;
                    cin >> questionNumber2;
                    for(int i=0;i<evaluation->getQuestions().size();i++)
                    {
                        if(evaluation->getQuestions()[i]->getNumber() == questionNumber2)
                        {
                            evaluation->getQuestions().erase(evaluation->getQuestions().begin() + i);
                        }
                    }
                    break;
                }
                case 2:
                cout<<"Enter the new marks for the evaluation"<<endl;
                float newMarks;
                cin >> newMarks;
                evaluation->setMarks(newMarks);
                break;
                default:
                cout<<"Invalid option selected. Please try again!"<<endl;
    }
    }
    }
    void updateMarks(Evaluation *evaluation)
    {
        cout<<"Enter the new marks for the evaluation"<<endl;
        float newMarks;
        cin >> newMarks;
        evaluation->setMarks(newMarks);
    }

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
    void addProgram(Program *pr)
    {
        programs.push_back(pr);
    }

    void removeProgram(Program *pr)
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

    void manageProgram()
    {
        cout<<"What would you like to do with the program?"<<endl;
        cout<<"1. Add Program"<<endl;
        cout<<"2. Remove Program"<<endl;
        cout<<"3. Update Program"<<endl;
        int option;
        cin >> option;
        switch (option)
        {
            case 1:
            {
                cout<<"Enter the program ID"<<endl;
                int programID;
                cin >> programID;
                cout<<"Enter the program name"<<endl;
                string programName;
                cin >> programName;
                Program *program = new Program(programID, programName);
                addProgram(program);
                break;
            }
            case 2:
            {
                cout<<"Enter the program ID you would like to remove"<<endl;
                int programID;
                cin >> programID;
                for(int i=0;i<programs.size();i++)
                {
                    if(programs[i]->getProgramID() == programID)
                    {
                        removeProgram(programs[i]);
                    }
                }
                break;
            }

        }

    }

    void addUser(User *user)
    {
        users.push_back(user);
    }

    void removeUser(User *user)
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

    void manageUser()
    {
        cout<<"What would you like to do with the user?"<<endl;
        cout<<"1. Add User"<<endl;
        cout<<"2. Remove User"<<endl;
        cout<<"3. Append User"<<endl;
        int option;
        cin >> option;
        switch (option)
        {
            case 1:
            {
                cout<<"Enter the user ID"<<endl;
                int userID;
                cin >> userID;
                cout<<"Enter the user name"<<endl;
                string userName;
                cin >> userName;
                User *user = new User(userName, userID);
                addUser(user);
                break;
            }
            case 2:
            {
                cout<<"Enter the user ID you would like to remove"<<endl;
                int userID;
                cin >> userID;
                for(int i=0;i<users.size();i++)
                {
                    if(users[i]->getID() == userID)
                    {
                        removeUser(users[i]);
                    }
                }
                break;
            }
            case 3:
            {
                cout<<"Enter the user ID you would like to append"<<endl;
                int userID;
                cin >> userID;
                for(int i=0;i<users.size();i++)
                {
                    if(users[i]->getID() == userID)
                    {
                        cout<<"Enter the new name for the user"<<endl;
                        string newName;
                        cin >> newName;
                        users[i]->setName(newName);
                    }
                }
                break;

        }
    }
}
};

// void ProgramsInterface()
// {
//     // Option to add, remove, and update programs
//     // Show a list and details of current program(s)
// }

// void CoursesInterface()
// {
// }

// void GenerateReport()
// {
// }

// int main()
// {
//     cout << "Welcome to Our Outcome Based Education Support System" << endl;
//     cout << "Are you a Teacher or an Academic Officer? (t/a)" << endl;
//     char selection;
//     cin >> selection;
//     if (selection == 't')
//     {
//         cout << "Welcome Teacher!" << endl;
//     }
//     if (selection == 'a')
//     {
//         cout << "Welcome Academic Officer!" << endl;
//     }
//     else
//     {
//         cout << "Invalid user role. Only Teachers and Academic Officers are allowed."<<endl;
//     }
//     int option;
//     while (option != 0)
//     {
//         cout << "What would you like to do today?" << endl;
//         cout << "1. Manage Programs" << endl;
//         cout << "2. Manage Courses" << endl;
//         cout << "3. Generate Report" << endl;
//         cout << "0. Exit" << endl;
//         cin >> option;
//         switch (option)
//         {
//         case 1:
//             ProgramsInterface();
//         case 2:
//             CoursesInterface();
//         case 3:
//             GenerateReport();
//         case 0:
//             option = 0;
//             cout << "Exiting..." << endl;
//             break;
//         default:
//             cout << "Invalid option selected. Please try again!" << endl;
//         }
//     }
//     return 0;
// }