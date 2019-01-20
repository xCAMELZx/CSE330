/*
Yousef Jarrar 005845836
CSE 330 - Dr. Murphy - Lab 3
*/

#include <vector>
#include <time.h>
#include <iostream>

using namespace std;

template <typename T>
class PQ {

public:
	PQ();
	PQ(vector<T> v);
	int size();
	T front();
	void print();
	void addBack(T x);
	void removeFront();

private:
	vector<T> STL;
	void sort();
};

template <typename T>
PQ<T>::PQ() {}

template <typename T>
PQ<T>::PQ(vector<T> v) {
	this->STL = v;
	this->sort();
}

template <typename T>
void PQ<T>::sort() {
	       //Sort Selection
	for (int i = 0; i < this->STL.size() - 1; i++) {

		for (int j = i + 1; j <  this->STL.size(); j++)	{

			if (this->STL[i] >  this->STL[j])	{

				swap(this->STL[i], this->STL[j]);
			}
		}
	}
}

template <typename T>
 int PQ<T>::size() {
	return this->STL.size();
}

template <typename T>
 T PQ<T>::front() {
	return this->STL[0];
}

template <typename T>
 void PQ<T>::print() {
	for (unsigned int i = 0; i < this->STL.size(); i++)	{
		std::cout << this->STL[i] << ' ';
	}
}

template <typename T>
 void PQ<T>::addBack(T x) {
	this->STL.push_back(x);
	this->sort();
}

template <typename T>
 void PQ<T>::removeFront() {
	this->STL.erase(this->STL.begin());
}


int main() {
	int length = 5;
	srand(time(NULL));
	vector<int> v;

	for (int i = 0; i < length; i++) {
		v.push_back(rand() % 10);
	}

	PQ<int>q(v);
	q.print();
	cout << endl << "The size of the vector is: " << q.size() << endl << "The front of the vector is: " << q.front() << endl;
	q.addBack(4);
	q.print();
	cout << endl;
	q.removeFront();
	q.print();
	cout << endl;

	return 0;
}
