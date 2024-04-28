#include<header.h>
void ProgramsInterface(OBESupportSystem system)
{
    // Option to add, remove, and update programs
    // Show a list and details of current program(s)
    system.listPrograms();
    system.manageProgram();
    system.listPrograms();
}

void CoursesInterface()
{
}

void GenerateReport()
{
}

int main()
{
    Program* program1 = new Program(1, "Software Engineering");
    Program* program2 = new Program(2, "Computer Science");

    // Creating courses
    Course* course1 = new Course(101, "Introduction to Programming");
    Course* course2 = new Course(102, "Software Design");

    // Adding courses to programs
    program1->addCourse(course1);
    program1->addCourse(course2);

    // Creating CLOs
    CLO* clo1 = new CLO(1);
    CLO* clo2 = new CLO(2);

    // Adding CLOs to courses
    course1->addCLO(clo1);
    course2->addCLO(clo2);

    // Creating PLOs
    PLO* plo1 = new PLO(1, "Problem Solving");
    PLO* plo2 = new PLO(2,"Teamwork");

    // Adding CLOs to PLOs
    plo1->addCLO(clo1);
    plo2->addCLO(clo2);


    //Creating academic officers
    AcademicOfficer* officer1 = new AcademicOfficer("Muhammad Tayyab", 1);
    AcademicOfficer* officer2 = new AcademicOfficer("Tauqeer Ahson", 2);

    //Creating teachers
    Teacher* teacher1 = new Teacher("John Doe", 101);
    Teacher* teacher2 = new Teacher("Jane Doe", 102);

    // Adding taught courses to teachers
    teacher1->addTaughtCourse(course1);
    teacher2->addTaughtCourse(course2);

    // Adding evaluations
    Evaluation* evaluation1 = new Evaluation("Quiz", 1);
    Evaluation* evaluation2 = new Evaluation("Assignment", 2);

    // Adding evaluations to courses
    course1->addEvaluation(evaluation1);
    course2->addEvaluation(evaluation2);

    // Managing evaluations by teachers
    teacher1->manageEvaluation(evaluation1);
    teacher2->manageEvaluation(evaluation2);

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
    }
    if (selection == 'a')
    {
        cout << "Welcome Academic Officer!" << endl;
        int option=1;
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
    else
    {
        cout << "Invalid user role. Only Teachers and Academic Officers are allowed."<<endl;
    }
    return 0;
}