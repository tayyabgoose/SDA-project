#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<sstream>

using namespace std;

int main()
{
    fstream file;
    file.open("file.csv");
    string temp="";
    string line="";
    string word=" ";

    getline(file,line);


    vector<int> PloV;
    vector<string> ProV;
    vector<int> CloV;
    vector<string> CouV;
    vector<string> EvalV;
    vector<int> QV;


    while (getline(file, line))
    {
        stringstream ss(line);
        string word;
        int index = 0;
        while (getline(ss, word, ',')) {
            if (index == 0) {
                PloV.push_back(stoi(word));
            } else if (index == 1) {
                ProV.push_back(word);
            } else if (index == 2) {
                CloV.push_back(stoi(word));
            } else if (index == 3) {
                CouV.push_back(word);
            } else if (index == 4) {
                EvalV.push_back(word);
            } else if (index == 5) {
                QV.push_back(stoi(word));
            }
            index++;
        }
    }
    cout << endl;
    for (int i = 0; i < PloV.size(); ++i) {
        cout <<"Plos:"<< PloV[i] << " "<<"Programs:"<< ProV[i] << " "<<"Clos:"<< CloV[i] << " "<<"Courses:"<< CouV[i] << " "<<"Evaluations:"<< EvalV[i] << " "<<"Questions:"<< QV[i] <<endl;
    }
    cout << endl;


    file.close();
    return 0;
}
