#include <bits/stdc++.h>

using namespace std;

struct Country{
    char name[100]={};
    int points[100]={};
    int totalScore=0;
};

// function whick delete spaces from start and end
string trim(string& str)
{
    if (str == "")
        return str;
    int start = str.find_first_not_of(" "),
        finish = str.find_last_not_of(" ");
    if (start != -1 && finish != -1)
        return str.substr(start, finish - start + 1);
    else
        return "";
}

// function which split string by symbol ','
vector< string > splitStringByComma(string& str)
{
    vector< string > answer;
    string current;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ',' && str[i] != ';')
            current += str[i];
        else
        {
            current = trim(current);
            if (current != "")
                answer.push_back(current);
            current = "";
        }
    }
    current = trim(current);
    if (current != "")
        answer.push_back(current);
    return answer;
}

// fucntion which reads data from files
void parsingFiles(Country* contr, int* numberOfCountries, char (*namesOfFiles)[260], int numberOfFiles)
{
    (*numberOfCountries) = 0;
    for (int i = 0; i < numberOfFiles; i++)
    {
        ifstream input(namesOfFiles[i]);
        int N;
        input >> N;
        input.ignore();
        for (int j = 0; j < N; j++)
        {
            string data;
            getline(input, data);
            vector< string > items = splitStringByComma(data);
            for (int k = 0; k < items[0].size() && k < 100; k++)
                contr[*numberOfCountries].name[k] = items[0][k];
            for (int k = 1; k < items.size(); k++)
                contr[*numberOfCountries].points[k - 1] = stoi(items[k]);
            (*numberOfCountries)++;
        }
        input.close();
    }
}

// comparator for sorting
bool comp(Country x, Country y)
{
    if (x.totalScore > y.totalScore)
        return true;
    return false;
}

// write to file results.csv leader by total score
void leadersByTotalScore(Country* contr, int numberOfCountries)
{
    sort(contr, contr + numberOfCountries, comp);
    ofstream output("results.csv");
    output << min(10, numberOfCountries) << endl;
    for (int i = 0; i < min(10, numberOfCountries); i++)
    {
        output << i + 1 << ") " << contr[i].name << " " << contr[i].totalScore << endl;
    }
    output.close();
}
