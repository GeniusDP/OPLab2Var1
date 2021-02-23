#include <bits/stdc++.h>
#include <dirent.h>

using namespace std;

struct Country{
    char name[100]={};
    int points[100]={};
    int totalScore=0;
};

//Проверяет, евляется ли файл формата .csv
//функция видима только внутри void getNamesOfFiles
//так как больше нигде не используется
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

//получить массив имен файлов(абсолютный путь)
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
            for(int i=0; i<strlen(entry->d_name); i++){
                namesOfFiles[*numberOfFiles][i]=(entry->d_name)[i];
            }
            ++*numberOfFiles;
        }
    }
    closedir(dir);
    /*
        D:\\Users\\Bogdan\\Desktop\\dir
    */
}

/*
    Qsort for each score
*/

bool comp(Country x, Country y, int i){
    return x.points[i] < y.points[i];
}

void Qsort(Country* left, Country* right, bool (*compare)(Country, Country, int), int poleToSort){
    if(right-left>=1){
        Country *i, *j;
        i=left, j=right;
        int jstep = -1;
        bool dir = true;
        while(i<j){
            if( comp(*i, *j, poleToSort)!=dir ){
                swap(*i, *j);
                swap(i, j);
                jstep=-jstep;
                dir=!dir;
            }
            j+=jstep;
        }
        Qsort(left, i-1, comp, poleToSort);
        Qsort(i+1, right, comp, poleToSort);
    }
}
