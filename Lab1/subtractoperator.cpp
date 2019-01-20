/*
Yousef Jarrar - 005845836
CSE 330 - Professor Murphy
Summer 2018
Lab 1A
*/

#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

class Time {

   public:
   Time(int hours, int minutes);
   int getHours() const;
   int getMinutes() const;
   void addMinute();
   void subMinute();
   bool operator==(Time t);
   void operator++(); //prefix
   void operator++(int); //postfix
   void operator--(); //prefix
   void operator--(int); //postfix

   private :
   int hours;
   int minutes;

};

Time::Time(int hours, int minutes) {
  hours=h;
  minutes=m;
}

int Time::getHours() const {
   return hours;
}


int Time::getMinutes() const {
   return minutes;
}

bool Time::operator==(Time t) {

  if (this->getHours() != t.getHours()) return false;
  if (this->getMinutes() != t.getMinutes()) return false;
  return true;
}

void Time::operator++() {
  this -> addMinute();
}

void Time::operator++(int) {
  this -> addMinute();
}

void Time::operator--() {
  this -> subMinute();
}

void Time::operator--(int) {
  this -> subMinute();
}

void Time::addMinute() {
   minutes++;
  if (minutes == 60 ) {
      minutes=0;
      hours++;
    }
   if (hours == 13)
      hours=1;
}

void Time::subMinute(){
    minutes--;
  if (minutes == -1 )
    {
      minutes=59;
      hours--;
    }
   if (hours == -1)
      hours=11;
}

int main() {
	Time start = Time(12, 1);
  Time end = Time(12, 0);
  sleep(60); //sleep 60 seconds
  start--; //--start; //negate a minute to start ,,, In this case we are subtracting a minute

if(start==end) {
  cout << to_string(start.getHours()) << " " << to_string(start.getMinutes()) << endl;
  cout << to_string(end.getHours()) << " " << to_string(end.getMinutes()) << endl;
  //if (start == end) cout << "class dismissed";
  cout << "class end"<< endl;
 }

}
