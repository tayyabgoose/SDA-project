#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    fstream file;
    file.open("file.csv");
    string temp = "";
    string line = "";
    string word = " ";

    getline(file, line);

    vector<int> PLO_vector;
    vector<string> program_vector;
    vector<int> CLO_vector;
    vector<string> course_vector;
    vector<string> evaluation_vector;
    vector<int> question_vector;

    while (getline(file, line))
    {
        stringstream ss(line);
        string word;
        int index = 0;
        while (getline(ss, word, ','))
        {
            if (index == 0)
            {
                PLO_vector.push_back(stoi(word));
            }
            else if (index == 1)
            {
                program_vector.push_back(word);
            }
            else if (index == 2)
            {
                CLO_vector.push_back(stoi(word));
            }
            else if (index == 3)
            {
                course_vector.push_back(word);
            }
            else if (index == 4)
            {
                evaluation_vector.push_back(word);
            }
            else if (index == 5)
            {
                question_vector.push_back(stoi(word));
            }
            index++;
        }
    }
    cout << endl;
    for (int i = 0; i < PLO_vector.size(); ++i)
    {
        cout << "PLO: " << PLO_vector[i] << " "
             << "Program: " << program_vector[i] << " "
             << "CLO: " << CLO_vector[i] << " "
             << "Courses: " << course_vector[i] << " "
             << "Evaluations: " << evaluation_vector[i] << " "
             << "Questions: " << question_vector[i] << endl;
    }
    cout << endl;

    file.close();
    return 0;
}
