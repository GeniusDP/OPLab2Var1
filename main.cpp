#include <bits/stdc++.h>

using namespace std;

struct Country{
    char name[100]={};
    int points[20]={};
    int totalScore=0;
};

//to get an array of names of files(absolute way)
void getNamesOfFiles(char* wayToFolder,char (*namesOfFiles)[260], int* numberOfFiles);


//the process of reading information from all of the files in format .csv
void parsingFiles(Country* contr, int* numberOfCountries, char (*namesOfFiles)[260], int numberOfFiles);

//comfortable quick_sort of countries by points in each col
void Qsort(Country* left, Country* right, bool (*comp)(Country, Country, int), int posToCompare);


//function which makes all work
void calcTotalScore(Country* contr, int numberOfCountries, vector< int >&);


void leadersByTotalScore(Country* contr, int numberOfCountries);
/*
‘ормат дл€ файла
result.csv
10
1)Ukraine <totalScore>
2)Germany <totalScore>
...
*/

int main()
{
    setlocale(LC_ALL, "rus");
    Country contr[200];
    int numberOfCountries=0;
    char wayToFolder[260]={};
    char namesOfFiles[100][260]={};//No more than 100 files
    int numberOfFiles=0;
    vector< int > values;
    int N;
    cout << "¬ведите абсолютный путь к папке с файлами(разграничитель \\\\):\n";
    gets(wayToFolder);
    cout << "¬ведите количество элеметов values" << endl;
    cin >> N;
    values.resize(N);
    for (int i = 0; i < N; i++)
        cin >> values[i];

    getNamesOfFiles(wayToFolder, namesOfFiles, &numberOfFiles);

    parsingFiles(contr, &numberOfCountries, namesOfFiles, numberOfFiles);

    calcTotalScore(contr, numberOfCountries, values);

    leadersByTotalScore(contr, numberOfCountries);

    return 0;
}
