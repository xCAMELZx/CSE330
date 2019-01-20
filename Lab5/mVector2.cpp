/*
Yousef Jarrar
Lab 5 - Dr. Murphy
July 19, 2018
*/

#include <iostream>
#include <cassert>
#include <time.h>
#include <cstdlib>

using namespace std;

template<typename T>
class mVector{
public:
	void operator-- (T);
	void operator-- ();
	typedef T* iter;

	void insert(iter ix, T x);
	void erase(iter ix);

	mVector();
	mVector(unsigned int n);
	void pBack(T x);
	void pBack();
	void clear();
	T operator[] (unsigned int i);
	int size();
	void prnt();
	iter begin(){return v;}
 	iter end(){return v+vSize;}

private:
	int vSize;
	int vCap;
	T *v;
	void reserve(unsigned int n);
};

template<typename T>
mVector<T>::mVector()
{
	T *newVector = new T[2];
	assert(newVector != NULL);
	vCap = 2;
	vSize = 0;
	v = newVector;
}

template<typename T>
mVector<T>::mVector(unsigned int n)
{
	T *newVector = new T[n];
	vCap = n;
	vSize = 0;

}

template<typename T>
void mVector<T>::pBack(T x) {
	if (vSize < vCap)	{
		v[vSize] = x;
		vSize++;
	}
	else{
		this->reserve(2*vCap);
		v[vSize] = x;
		vSize++;
	}
}

template<typename T>
void mVector<T>::pBack() {
	assert(vSize > 0);
	vSize--;
}

template<typename T>
void mVector<T>::clear(){
	vSize = 0;
}

//remake with iterators
template<typename T>
void mVector<T>::insert(iter ix, T x){
	if (vSize == vCap)	{
		this->reserve(2 * vCap);
	}
	for (iter jx = v + vSize; jx != ix; jx--)	{
		*jx = *(jx-1);
	}
		*ix = x;
		vSize++;
}

//remake with iterators
template<typename T>
void mVector<T>::erase(iter ix){
	for (iter jx = ix; jx != (v+vSize)-1; jx++)	{
	*jx = *(++jx);
	}
	vSize--;
}

template<typename T>
T mVector<T>::operator[] (unsigned int i){
	assert(i < vSize and vSize > 0);
	return v[i];
}

template<typename T>
int mVector<T>::size(){
	return vSize;
}

template<typename T>
void mVector<T>::prnt(){
	for (int i = 0; i < (this->vSize); i++)
	{
		cout << this->v[i] << ' ';
		cout << endl;
	}
}

template<typename T>
void mVector<T>::reserve(unsigned int n){
	assert(n > vCap);
	T *newVector = new T[n];
	assert(newVector != NULL);
		for (int i = 0; i < vSize; i++){
			newVector[i] = v[i];
		}

	delete[] v;
	v = newVector;
	vCap = n;
}

template<typename T>
void mVector<T>::operator-- (T) //postfix
{
	this->pBack();
}

template<typename T>
void mVector<T>::operator-- () //prefix
{
	this->pBack();
}

int main()
{
	srand(time(NULL));
	mVector<int> x;
	int n = 15;
	for(int i=0;i< n;i++) {
		x.pBack(rand()%100);
	}

	x.prnt();
	x.insert(x.begin() + 1, 5);
	x--;
	--x;
	cout << "Begin/End: " << *x.begin() << "/" << *(x.end()-1) << endl; // *x.end() gives 0 value because it is one past the array
	cout << "***************************************************\n";
	x.prnt();
	return 0;
}
