#include <iostream>
using namespace std;

class Date{
    private: 
        int date;
        int month;
        int year;
    
    public: 
        void setDate(int date){
            this->date = date;
        }
        void setMonth(int month){
            this->month = month;
        }
        void setYear(int year){
            this->year = year;
        }
        void displayDate(){
            cout << date << "/" << month << "/" << year;
        }
};

int main(){
    Date date;
    date.setDate(4);
    date.setMonth(2);
    date.setYear(2025);
    date.displayDate();
}