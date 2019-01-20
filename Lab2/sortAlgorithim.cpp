/*
Yousef Jarrar - 005845836
Lab2 - Sorting Algorithim
Summer 2018 - CSE 330 - Dr.Murphy
*/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

void prntVector(vector<int> &v) {

    for(int i=0; i<v.size(); i++)    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void prntTime (vector<int> &time, int length) {
    cout << "For length " << length << ": " << endl;

    for(int i=0; i<time.size(); i++) {
        cout << "On try " << i+1 << ", the time was " << time[i] << " " << endl;
    }

    cout << endl;
}

void prntTime(vector<int> &time, vector<int> &lengths) {

    for(int i=0; i<lengths.size(); i++) {

        cout << "For length " << lengths[i] << ": " << endl;

        for(int j=0; j<time.size(); j++) {
            cout << "On try " << j+1 << ", the time was " << time[j] << " " << endl;
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> selectSort(vector<int> v) {
 for (int i = 0; i < v.size()-1; i++) {

    for (int j = i+1; j < v.size(); j++){
        if (v[i] > v[j]) {
            swap(v[i], v[j]);
                }
      }
 }
    return v;
}

vector<int> bubbleSort(vector<int> v) {

 for (int i = v.size()-1; i > 0; i--) {

    for (int j = 0; j < i; j++) {

        if (v[j] > v[j+1]) {

            swap(v[j], v[j+1]);
                }
        }
  }
        return v;
}

vector<int> randomNumGen(int length) {
        vector<int> v;

    for(int i=0; i<length; i++)    {
        v.push_back(rand() % 10);
    }
    return v;
}

vector<int> getSortTimes(vector<int> v, string type, int numOfTests) {

    vector<int> vSorted, time;
    clock_t start, finish;

    if(type == "Selection Sort") {

        for(int i=0; i<numOfTests; i++)    {
            start = clock();
            vSorted = selectSort(v);
            finish = clock();
            time.push_back(finish-start);
        }
    }

    else if(type == "Bubble Sort") {

        for(int i=0; i<numOfTests; i++)    {
            start = clock();
            vSorted = bubbleSort(v);
            finish = clock();
            time.push_back(finish-start);
        }
    }

    return time;
}

int main() {
    vector<int> v, lengths, selTimes, bubTimes, sortedLengths, randVecs;
    int numOfTests, length;
    srand (time(NULL));

    cout << "Number of tests that you want to perform: ";
    cin >> numOfTests;
    cout << endl << endl;

    cout << "Enter the 10 lengths of the vectors that you want to sort: ";

    for(int i=0; i<10; i++) {
        cin >> length;
        lengths.push_back(length);
    }

        //sortedLengths = selectSort(lengths);
        for(int j = 0; j<lengths.size(); j++) {
            v = randomNumGen(lengths[j]);
            selTimes = getSortTimes(v, "Selection Sort", numOfTests);
            bubTimes = getSortTimes(v, "Bubble Sort", numOfTests);
            cout << "The time/times for Selection Sort were:" << endl << endl;
            prntTime(selTimes, lengths[j]);
            cout << "The time/times for Bubble Sort were:" << endl << endl;
            prntTime(bubTimes, lengths[j]);
        }
}
