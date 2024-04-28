#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
void ProgramsInterface(OBESupportSystem &system)
{
    // Option to add, remove, and update programs
    // Show a list and details of current program(s)
    cout << "Programs" << endl;
    system.listPrograms();
    system.manageProgram();
    cout << "Programs" << endl;
    system.listPrograms();
}

void CoursesInterface(Program *pr)
{
    // Option to add, remove, and update courses
    // Show a list and details of current course(s)
    pr->listCourses();
    pr->manageProgram();
    pr->listCourses();
}

void GenerateReport()
{
}

void taughtCoursesInterface(Teacher *teacher)
{
    // Option to add, remove, and update courses
    // Show a list and details of current course(s)
    cout << "Courses Taught by " << teacher->getName() << ":" << endl;
    teacher->listTaughtCourses();
    cout << "which course would you like to change?" << endl;
    int courseID;
    std::cin >> courseID;

    cout << "what would you like to do?" << endl;
    cout << "1. Enter Topic(s) Covered" << endl;
    cout << "2.Remove Topic(s) Covered" << endl;
    cout << "0. Exit" << endl;
    int option;
    std::cin >> option;
    switch (option)
    {
    case 0:
    {
        cout << "Goodbye!" << endl;
        break;
    }
    case 1:
    {
        cout << "Enter Clo(s) covered in the class" << endl;
        teacher->listclosofCourse(courseID);
        int cloID;
        std::cin >> cloID;
        cout << "Enter the topic(s) covered in the class" << endl;
        string topics;
        std::cin >> topics;
        cout << "Topics covered: " << topics << endl;
        teacher->addTopicsCovered(topics, cloID);
        taughtCoursesInterface(teacher);
    }
    case 2:
    {
        cout << "Enter Topic(s) To Remove" << endl;
        string topics;
        std::cin >> topics;
        teacher->removeTopicsCovered(topics);
        taughtCoursesInterface(teacher);
    }

    default:
        cout << "Invalid option selected. Please try again!" << endl;
        taughtCoursesInterface(teacher);
    }

    teacher->listTaughtCourses();
}

void academicOfficerInterface(OBESupportSystem &system)
{
    int option = 1000;
    while (option != 0)
    {
        cout << "What would you like to do today?" << endl;
        cout << "1. Manage Programs" << endl;
        cout << "2. Manage Courses" << endl;
        cout << "3. Generate Report" << endl;
        cout << "0. Exit" << endl;
        std::cin >> option;
        switch (option)
        {
        case 1:
            ProgramsInterface(system);
            academicOfficerInterface(system);
        case 2:
            cout << "Which Program's course(s) would you like to manage?" << endl;
            system.listPrograms();
            int programID;
            std::cin >> programID;
            CoursesInterface(system.getProgram(programID));
            academicOfficerInterface(system);
        case 3:
            GenerateReport();
            academicOfficerInterface(system);
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option selected. Please try again!" << endl;
        }
    }
}
void teachersInterface(OBESupportSystem &system)
{
    int option = 1000;
    while (option != 0)
    {
        cout << "What would you like to do today?" << endl;
        cout << "1. Enter Topic(s) Covered" << endl;
        cout << "2. Enter Evaluation(s)" << endl;
        cout << "0. Exit" << endl;
        std::cin >> option;
        switch (option)
        {
        case 1:
        {
            cout << "which User are you?" << endl;
            system.listTeachers();
            int userID;
            std::cin >> userID;
            User *user = system.getUser(userID);
            Teacher *teacher = dynamic_cast<Teacher *>(user);
            taughtCoursesInterface(teacher);
        }
        case 0:
        {
            cout << "Goodbye!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid option selected. Please try again!" << endl;
            teachersInterface(system);
        }
        }
    }
}

int main()
{
    Program *program1 = new Program(1, "Software Engineering");
    Program *program2 = new Program(2, "Computer Science");

    // Creating courses
    Course *course1 = new Course(101, "Introduction to Programming");
    Course *course2 = new Course(102, "Software Design");

    // Adding courses to programs
    program1->addCourse(course1);
    program1->addCourse(course2);

    // Creating CLOs
    CLO *clo1 = new CLO(1);
    CLO *clo2 = new CLO(2);

    // Adding CLOs to courses
    course1->addCLO(clo1);
    course2->addCLO(clo2);

    // Creating PLOs
    PLO *plo1 = new PLO(1, "Problem Solving");
    PLO *plo2 = new PLO(2, "Teamwork");

    // Adding CLOs to PLOs
    plo1->addCLO(clo1);
    plo2->addCLO(clo2);

    // Creating academic officers
    AcademicOfficer *officer1 = new AcademicOfficer("Muhammad Tayyab", 1);
    AcademicOfficer *officer2 = new AcademicOfficer("Tauqeer Ahson", 2);

    // Creating teachers
    Teacher *teacher1 = new Teacher("John Doe", 101);
    Teacher *teacher2 = new Teacher("Jane Doe", 102);

    // Adding taught courses to teachers
    teacher1->addTaughtCourse(course1);
    teacher2->addTaughtCourse(course2);

    // Adding evaluations
    Evaluation *evaluation1 = new Evaluation("Quiz", 1);
    Evaluation *evaluation2 = new Evaluation("Assignment", 2);

    // Adding evaluations to courses
    course1->addEvaluation(evaluation1);
    course2->addEvaluation(evaluation2);

    // adding evaluations to teachers
    teacher1->addEvaluation(evaluation1);
    teacher2->addEvaluation(evaluation2);

    OBESupportSystem system;
    system.addUser(officer1);
    system.addUser(officer2);
    system.addUser(teacher1);
    system.addUser(teacher2);

    system.addProgram(program1);
    system.addProgram(program2);

    cout << "Welcome to Our Outcome Based Education Support System" << endl;
    cout << "Are you a Teacher or an Academic Officer? (t/a)" << endl;
    char selection;
    std::cin >> selection;
    if (selection == 't')
    {
        cout << "Welcome Teacher!" << endl;
        teachersInterface(system);
    }
    if (selection == 'a')
    {
        cout << "Welcome Academic Officer!" << endl;
        academicOfficerInterface(system);
    }
    else
    {
        cout << "Invalid user role. Only Teachers and Academic Officers are allowed." << endl;
    }
    return 0;
}