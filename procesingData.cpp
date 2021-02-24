#include <bits/stdc++.h>

using namespace std;

struct Country{
    char name[100]={};
    int points[20]={};
    int totalScore=0;
};



bool comparator(Country x, Country y, int i){
    return x.points[i] > y.points[i];
}

void qSort(Country* left, Country* right, bool (*compare)(Country, Country, int), int poleToSort){
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
        qSort(left, i-1, compare, poleToSort);
        qSort(i+1, right, compare, poleToSort);
    }
}

//This function adds points to each country
void calcTotalScore(Country* contr, int numberOfCountries, vector< int >& val){
    for(int parm=0; parm<20; parm++){
        qSort(contr, contr+numberOfCountries-1, comparator, parm);
        for(int i=0; i< min(int(val.size()), numberOfCountries); i++){
            contr[i].totalScore += val[i];
        }
    }
}



// custom quick sort
void qSort(Country* arr, int left, int right)
{
    int i = left, j = right, dj = -1;
    if (right <= left)
        return;
    while(i != j)
    {
        if (arr[i].totalScore < arr[j].totalScore && dj == -1)
        {
            swap(arr[i], arr[j]);
            swap(i, j);
            dj *= -1;
        }
        if (arr[j].totalScore < arr[i].totalScore && dj == 1)
        {
            swap(arr[i], arr[j]);
            swap(i, j);
            dj *= -1;
        }
        j += dj;
    }
    qSort(arr, left, i - 1);
    qSort(arr, i + 1, right);
}

// write to file results.csv leader by total score
void leadersByTotalScore(Country* contr, int numberOfCountries)
{
    qSort(contr, 0, numberOfCountries - 1);
    ofstream output("results.csv");
    output << min(10, numberOfCountries) << endl;
    for (int i = 0; i < min(10, numberOfCountries); i++)
    {
        output << i + 1 << ") " << contr[i].name << " " << contr[i].totalScore << endl;
    }
    output.close();
}

