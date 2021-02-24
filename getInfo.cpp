#include <bits/stdc++.h>
#include <dirent.h>

using namespace std;

struct Country{
    char name[100]={};
    int points[20]={};
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

// function which reads data from files
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
            int k;
            for (k = 0; k < items[0].size() && k < 100; k++)
                contr[*numberOfCountries].name[k] = items[0][k];
            contr[*numberOfCountries].name[k]='\0';
            for (k = 1; k < items.size(); k++)
                contr[*numberOfCountries].points[k - 1] = stoi(items[k]);
            (*numberOfCountries)++;
        }
        input.close();
    }
}



//Checks is file in format .csv
//function which is visible only inside void getNameOfFiles()
//in case of does not use in other functions
bool isCSV(char* fileName){
    int dotPos=0;
    while(dotPos<strlen(fileName) && fileName[dotPos]!='.')dotPos++;
    if(dotPos==strlen(fileName) )
        return false;//this is folder
    string r="";
    for(int i=dotPos+1; i<strlen(fileName); i++)
        r+=fileName[i];
    if(r=="csv")return true;
        else return false;
}


//to get array of names of files(absolute way)
void getNamesOfFiles(char* wayToFolder,char (*namesOfFiles)[260], int* numberOfFiles){
    bool isCSV(char*);
    char* path = wayToFolder;
    dirent *entry;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Folder not found.\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL){
        if( isCSV(entry->d_name) ){
                strcat(namesOfFiles[*numberOfFiles], wayToFolder);
                strcat(namesOfFiles[*numberOfFiles],"\\\\");
                strcat(namesOfFiles[*numberOfFiles], entry->d_name);
            printf("%s\n", namesOfFiles[*numberOfFiles]);
            ++*numberOfFiles;
        }
    }
    closedir(dir);
    /*
        D:\\Problems\\Var2
        D:\\Users\\Bogdan\\Desktop\\dir
        D:\\Users\\Bogdan\\Desktop\\Introduction-To-Programming\\labs_spring_2020\\examples_2\\var1
    */
}

