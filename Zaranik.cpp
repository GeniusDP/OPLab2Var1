#include <bits/stdc++.h>
#include <dirent.h>

using namespace std;

struct Country{
    char name[100]={};
    int points[20]={};
    int totalScore=0;
};

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
        printf("Folder not found or folder is empty.\n");
        return;
    }
    printf("Those are all files, from which we will get information.\n");
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
        D:\\Users\\Bogdan\\Desktop\\dir
        D:\\Users\\Bogdan\\Desktop\\Introduction-To-Programming\\labs_spring_2020\\examples_2\\var1
    */
}

/*
    Qsort for each score
*/

bool comp(Country x, Country y, int i){
    return x.points[i] > y.points[i];
}

void Qsort(Country* left, Country* right, bool (*compare)(Country, Country, int), int poleToSort){
    if(right-left>=1){
        Country *i, *j;
        i=left, j=right;
        int jstep = -1;
        bool dir = true;
        while(i!=j){
            if( compare(*i, *j, poleToSort)!=dir ){
                swap(*i, *j);
                swap(i, j);
                jstep = -jstep;
                dir = !dir;
            }
            j+=jstep;
        }
        Qsort(left, i-1, compare, poleToSort);
        Qsort(i+1, right, compare, poleToSort);
    }
}

//This function adds points to each country
void processing(Country* contr, int numberOfCountries){
    for(int parm=0; parm<20; parm++){
        Qsort(contr, contr+numberOfCountries-1, comp, parm);
        for(int i=0; i<numberOfCountries; i++){
            switch(i){
                case 0: contr[i].totalScore+=12; break;
                case 1: contr[i].totalScore+=10; break;
                case 2: case 3: case 4: case 5: case 6:
                case 7: case 8: case 9: case 10:
                    contr[i].totalScore+=(10-i>0)?10-i:0; break;
            }
        }
    }
}
