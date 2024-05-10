#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<Program*> programs;
vector<Course*> courses;
vector<CLO*> clos;
vector<PLO*> plos;
vector<Teacher*> teachers;
vector<AcademicOfficer*> academicOfficers;
vector<Evaluation*> evaluations;

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

    cout << "what would you like to do?" << endl;
    cout << "1. Enter Topic(s) Covered" << endl;
    cout << "2.Remove Topic(s) Covered" << endl;
    cout <<"3. View Topics(s) covered"<<endl;
    cout << "0. Exit" << endl;
    int option;
    std::cin >> option;
    switch (option)
    {
    case 0:
    {
        break;
    }
    case 1:
    {
        cout << "Courses Taught by " << teacher->getName() << ":" << endl;
        teacher->listTaughtCourses();
        cout << "which course would you like to add Topic?" << endl;
        int courseID;
        std::cin >> courseID;
        cout << "CLo(s) In course" << endl;
        teacher->listclosofCourse(courseID);
        cout << "Enter the CLO ID covered in class" << endl;
        int cloID;
        std::cin >> cloID;
        cout << "Enter the topic(s) covered in the class" << endl;
        cin.ignore();
        string topics;
        getline(cin, topics);
        cout << "Topics covered: " << topics << endl;
        cout<<"Review Topics Covered"<<endl;
        teacher->getTaughtCourse(courseID)->addTopicsCovered(topics,cloID);
        taughtCoursesInterface(teacher);
        break;
    }
    case 2:
    {
        cout << "Courses Taught by " << teacher->getName() << ":" << endl;
        teacher->listTaughtCourses();
        cout << "which course would you like to remove Topic?" << endl;
        int courseID;
        std::cin >> courseID;
        cout << "Enter Topic(s) To Remove" << endl;
        cin.ignore();
        string topics;
        getline(cin, topics);
        teacher->removeTopicsCovered(topics);
        taughtCoursesInterface(teacher);
        break;
    }
    case 3:
    {
        cout << "Courses Taught by " << teacher->getName() << ":" << endl;
        teacher->listTaughtCourses();
        cout << "which course would you like to view Topic(s)?" << endl;
        int courseID;
        std::cin >> courseID;
        teacher->listTopicsCovered(courseID);
        taughtCoursesInterface(teacher);
        break;
    }

    default:
        cout << "Invalid option selected. Please try again!" << endl;
        taughtCoursesInterface(teacher);
        break;
    }

    teacher->listTaughtCourses();
}

void EvaluationsInterface(Teacher *teacher)
{
    cout<<"1. Add evaluation to course"<<endl;
    cout<<"2. view evaluations of course"<<endl;
    cout<<"0. Exit"<<endl;
    int option;
    std::cin>>option;
    switch(option)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            cout<<"which course would you like to add evaluation"<<endl;
            teacher->listTaughtCourses();
            int courseID;
            std::cin>>courseID;
            cout<<"Enter the evaluation name like Quiz,Assignment and etc."<<endl;
            string evaluationName;
            std::cin>>evaluationName;
            int e_id=evaluations.size()+1;
            Evaluation *evaluation=new Evaluation(evaluationName,e_id);
            int cloID;
            while(true)
            {
                cout<<"CLO(s) list to select from"<<endl;
                teacher->listclosofCourse(courseID);
                cout<<"Enter CLO(s) Id to test"<<endl;
                std::cin>>cloID;
                evaluation->addCLO(evaluation->getCLO(cloID));
                cout<<"Do you want to add more CLO(s) to this evaluation? (y/n)"<<endl;
                char choice;
                std::cin>>choice;
                if(choice=='n')
                {
                    break;
                }
            }
            while(true)
            {
                cout<<"Enter Clos(s) for the related question"<<endl;
                teacher->listclosofCourse(courseID);
                cout<<"Enter CLO(s) Id to test"<<endl;
                std::cin>>cloID;
                CLO *clo= new CLO(cloID);
                evaluation->addCLO(clo);
                cout<<"Add question description"<<endl;
                cin.ignore();
                string question;
                getline(cin,question);
                Question *q=new Question();
                q->setDescription(question);
                q->addRelatedCLO(clo);
                evaluation->addQuestion(q);
                cout<<"Do you want to add more questions to this evaluation? (y/n)"<<endl;
                char choice;
                std::cin>>choice;
                if(choice=='n')
                {
                    break;
                }
            }

            teacher->getTaughtCourse(courseID)->addEvaluation(evaluation);
            EvaluationsInterface(teacher);
            break;
        }
        case 2:
        {
            cout<<"which course would you like to view evaluation"<<endl;
            teacher->listTaughtCourses();
            int courseID;
            std::cin>>courseID;
            teacher->listEvaluations(courseID);
            EvaluationsInterface(teacher);
            break;
        }
    }

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
            break;
        case 2:
            cout << "Which Program's course(s) would you like to manage?" << endl;
            system.listPrograms();
            int programID;
            std::cin >> programID;
            CoursesInterface(system.getProgram(programID));
            academicOfficerInterface(system);
            break;
        case 3:
            GenerateReport();
            academicOfficerInterface(system);
            break;
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
        cout << "1. Manage Topic(s) Covered" << endl;
        cout << "2. Manage Evaluation(s)" << endl;
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
            Teacher *teacher = dynamic_cast<Teacher*>(system.getUser(userID));
            if (teacher) {
                taughtCoursesInterface(teacher);
            } else {
                cout << "Invalid User ID!" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "which User are you?" << endl;
            system.listTeachers();
            int userID;
            std::cin >> userID;
            Teacher *teacher = dynamic_cast<Teacher*>(system.getUser(userID));
            if (teacher) {
                EvaluationsInterface(teacher);
            } else {
                cout << "Invalid User ID!" << endl;
            }
            break;
        }
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option selected. Please try again!" << endl;
            break;
        }
    }
}
void createObjectsFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string type, temp, name;
        int id;
        getline(iss, type, '\n'); // Extract type
        int comaIndex = type.find(',');
        temp = type.substr(0,comaIndex); // Assign type to temp for comparison
        type=type.substr(comaIndex+1);
        if (temp == "Program") 
        {
            string name;
            string tempid;
            int id;
            int index = 0;
            // Extracting id from type
            while (type[index] != ',')
            {
                tempid += type[index];
                index++;
            }
            id = stoi(tempid);
            // Skipping the comma
            index++;
            // Extracting name from the rest of the string
            while (index < type.length())
            {
                name += type[index];
                index++;
            }
            Program* program = new Program(id, name);
            programs.push_back(program);

            type,temp,name="";
            id=0;
        }
        else if (temp == "Course") {
        string name;
        string tempid;
        int id;
        int index = 0;

        // Extracting id from type
        while (type[index] != ',')
        {
            tempid += type[index];
            index++;
        }
        id = stoi(tempid);

        // Skipping the comma
        index++;

        // Extracting name from the rest of the string
        while (type[index] != ',')
        {
            name += type[index];
            index++;
        }

        Course* course = new Course(id, name);
        courses.push_back(course);

        // Skipping the comma
        index++;

        // Extracting program ID from the rest of the string
        string programIDStr;
        while (index < type.size())
        {
            programIDStr += type[index];
            index++;
        }

        // Converting program ID string to integer
        int programID = stoi(programIDStr);

        // Finding the program with the matching ID and adding the course to it
        for (int i = 0; i < programs.size(); i++)
        {
            if (programs[i]->getProgramID() == programID)
            {
                programs[i]->addCourse(course);
                break; // Once found, no need to continue searching
            }
        }
        type,temp,name="";
        id=0;

    }   

        else if (temp == "CLO") {
            string name;
            string tempid;
            int id;
            int index = 0;
            // Extracting id from type
            while (type[index] != ',')
            {
                tempid += type[index];
                index++;
            }
            id= stoi(tempid);
            // Skipping the comma
            index++;
            // Extracting name from the rest of the string
            while (type[index] != ',')
            {
                name += type[index];
                index++;
            }
            index++;
            CLO* clo = new CLO(id);
            clos.push_back(clo);
            clo->updateDescription(name);

            string CourseIDStr;
            while (index < type.size())
            {
                CourseIDStr += type[index];
                index++;
            }

            // Converting Course ID string to integer
            int CourseID = stoi(CourseIDStr);

            for (int i = 0; i < courses.size(); i++)
            {
                if (courses[i]->getCourseID() == CourseID)
                {
                    courses[i]->addCLO(clo);
                    break;
                }
            }
            type,temp,name="";
            id=0;
        } 
        else if (temp == "PLO") 
        {
            string name;
            string tempid;
            int id;
            int index = 0;
            // Extracting id from type
            while (type[index] != ',')
            {
                tempid += type[index];
                index++;
            }
            id = stoi(tempid);
            // Skipping the comma
            index++;
            // Extracting name from the rest of the string
            while (type[index] != ',')
            {
                name += type[index];
                index++;
            }
            index++;
            PLO* plo = new PLO(id,name);
            plos.push_back(plo);
            plo->updateDescription(name);

            string CLOIDStr;
            while (index < type.size())
            {
                CLOIDStr += type[index];
                index++;
            }
            int clo_id = stoi(CLOIDStr);
            for (int i = 0; i < clos.size(); i++)
            {
                if (clos[i]->getID() == clo_id)
                {
                    plo->addCLO(clos[i]);
                    break;
                }
            }
            type,temp,name="";
            id=0;

        } 
        else if (temp == "AcademicOfficer") 
        {
            string name;
            string tempid;
            int id;
            int index = 0;
            // Extracting id from type
            while (type[index] != ',')
            {
                tempid += type[index];
                index++;
            }
            id = stoi(tempid);
            // Skipping the comma
            index++;
            // Extracting name from the rest of the string
            while (type[index] != ',')
            {
                name += type[index];
                index++;
            }
            index++;
            AcademicOfficer* officer = new AcademicOfficer(name,id);
            academicOfficers.push_back(officer);

            type,temp,name="";
            id=0;

        } 
        else if (temp == "Teacher") {
            string name;
            string tempid;
            int id;
            int index = 0;
            // Extracting id from type
            while (type[index] != ',')
            {
                tempid += type[index];
                index++;
            }
            id = stoi(tempid);
            // Skipping the comma
            index++;
            // Extracting name from the rest of the string
            while (type[index] != ',')
            {
                name += type[index];
                index++;
            }
            index++;
            Teacher* teacher = new Teacher(name,id);
            teachers.push_back(teacher);

            string courseIDStr;
            while(index < type.length())
            {
                courseIDStr += type[index];
                index++;
                
            }
            int courseID = stoi(courseIDStr);
            for (int i = 0; i < courses.size(); i++)
            {
                if (courses[i]->getCourseID() == courseID)
                {
                    teacher->addTaughtCourse(courses[i]);
                    break;
                }
            }
            type,temp,name="";
            id=0;
        } 
        else if (temp == "Evaluation") 
        {
            string name;
            string tempid;
            int id;
            int index = 0;
            // Extracting id from type
            while (type[index] != ',')
            {
                tempid += type[index];
                index++;
            }
            id = stoi(tempid);
            // Skipping the comma
            index++;
            // Extracting name from the rest of the string
            while (type[index] != ',')
            {
                name += type[index];
                index++;
            }
            index++;
            Evaluation* evaluation = new Evaluation(name,id);
            evaluations.push_back(evaluation);

            string courseIDStr;
            while(type[index] != ',')
            {
                courseIDStr += type[index];
                index++;
            }
            int courseID = stoi(courseIDStr);
            for (int i = 0; i < courses.size(); i++)
            {
                if (courses[i]->getCourseID() == courseID)
                {
                    courses[i]->addEvaluation(evaluation);
                    break;
                }
            }
            index++;
            string TeacherId;
            while(index < type.length())
            {
                TeacherId += type[index];
                index++;
            }
            int t_id=stoi(TeacherId);
            for (int i = 0; i < teachers.size(); i++)
            {
                if (teachers[i]->getID() == t_id)
                {
                    teachers[i]->addEvaluation(evaluation);
                    break;
                }
            }
            type,temp,name="";
            id=0;
        }
    }
    file.close();

}
void writeToCSV(const string& filename)
{
    ofstream file(filename);
    
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    for (Program* program : programs)
    {
        file << "Program" << "," << program->getProgramID() << "," << program->getProgramName() << endl;
    }
    // Write courses to file
    for (Course* course : courses)
    {
        file << "Course" << "," << course->getCourseID() << "," << course->getCourseName() << ",";
        for (int i = 0; i < programs.size(); i++)
        {
            for(int j=0;j<programs[i]->getCourses().size();j++)
            {
            if(programs[i]->getCourses().size() > 0 && programs[i]->getCourses()[j]->getCourseID() == course->getCourseID() )
            {
                file << programs[i]->getProgramID() << endl;
            }
            }
            
        }
        
    }

    // Write CLOs to file
    for (CLO* clo : clos)
    {
        file << "CLO" << "," << clo->getID() << "," << clo->getDescription() << ",";
        for (int i = 0; i < courses.size(); i++)
        {
            for(int j=0;j<courses[i]->getCLOs().size();j++)
            {
            if(courses[i]->getCLOs().size() > 0 && courses[i]->getCLOs()[j]->getID() == clo->getID() )
            {
                file << courses[i]->getCourseID() << endl;
            }
            }
            
        }
    }
    // Write PLOs to file
    for (PLO* plo : plos)
    {
        // Ensure that plos and clos vectors are of the same size and have valid indices
        file << "PLO" << "," << plo->getID() << "," << plo->getDescription() << ",";
        for (int i = 0; i < clos.size(); i++)
        {
            for(int j=0;j<clos[i]->getRelatedPLOs().size();j++)
            {
                if(clos[i]->getRelatedPLOs().size() > 0 && clos[i]->getRelatedPLOs()[j]->getID() == plo->getID() )
                {
                    file << clos[i]->getID() << endl;
                }
            }
            
        }
    }

    // Write academic officers to file
    for (AcademicOfficer* officer : academicOfficers)
    {
        file << "Academic Officer" << "," << officer->getID() << "," << officer->getName() << endl;
        
    }
    // Write teachers to file
    for (Teacher* teacher : teachers)
    {
        // Ensure that teachers and courses vectors are of the same size and have valid indices
        file << "Teacher" << "," << teacher->getID() << "," << teacher->getName() << ",";
            for (int i = 0; i < teachers.size(); i++)
            {
                for(int j=0;j<courses.size();j++)
                {
                if(courses[j]->getTeacher()->getID() == teacher->getID())
                {
                    file << courses[j]->getCourseID() << endl;
                }
                
            }
    }
    }

    // Write evaluations to file
    for (Evaluation* evaluation : evaluations)
    {
        file << "Evaluation" << "," << evaluation->getID() << "," << evaluation->getType() << ",";
        for (int i = 0; i < evaluation->getRelatedCLOs().size(); i++)
        {
            file << evaluation->getRelatedCLOs()[i]->getID() << ",";
        }
    }

    file.close();
}


int main()
{
    createObjectsFromCSV("file.csv");
    OBESupportSystem system;

    // Add academic officers to the system
    for (AcademicOfficer* officer : academicOfficers)
    {
        system.addUser(officer);
    }

    // Add teachers to the system
    for (Teacher* teacher : teachers)
    {
        system.addUser(teacher);
    }

    // Add programs to the system
    for (Program* program : programs)
    {
        system.addProgram(program);
    }
    

    cout << "Welcome to Our Outcome Based Education Support System" << endl;
    cout << "Are you a Teacher or an Academic Officer? (t/a)" << endl;
    char selection;
    std::cin >> selection;
    if (selection == 't')
    {
        cout << "Welcome Teacher!" << endl;
        teachersInterface(system);
    }
    else if (selection == 'a') // Changed to else if
    {
        cout << "Welcome Academic Officer!" << endl;
        academicOfficerInterface(system);
    }
    else
    {
        cout << "Invalid user role. Only Teachers and Academic Officers are allowed." << endl;
    }

    writeToCSV("file_2.csv");

    return 0;
}
