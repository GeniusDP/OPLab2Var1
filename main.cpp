#include <bits/stdc++.h>

using namespace std;

struct Country{
    char name[100]={};
    int points[100]={};
    int totalScore=0;
};

//�������� ������ ���� ������(���������� ����)
void getNamesOfFiles(char* wayToFolder,char (*namesOfFiles)[100], int* numberOfFiles);

//������� ���������� ���������� �� ���� ������ � �������� �������(������ csv)
void parsingFiles(Country* contr, int* numberOfCountries, char (*namesOfFiles)[100], int numberOfFiles);

//������� ���������� ����� �� ���-�� ������ � ��������
void Qsort(Country* left, Country* right, bool (*comp)(Country, Country, int), int posToCompare);

void processing(Country* contr, int numberOfCountries);


void leadersByTotalScore(Country* contr, int numberOfCountries);
/*
������ ��� �����
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
    char wayToFolder[100];
    char namesOfFiles[100][100];//No more than 100 files
    int numberOfFiles=0;


    cout << "������� ���������� ���� � ����� � �������(�������������� \\):\n";
    gets(wayToFolder);

    getNamesOfFiles(wayToFolder, namesOfFiles, &numberOfFiles);

    parsingFiles(contr, &numberOfCountries, namesOfFiles, numberOfFiles);

    processing(contr, numberOfCountries);

    leadersByTotalScore(contr, numberOfCountries);

    return 0;
}
