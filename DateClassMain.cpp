#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;
    const int dayz[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    const int dayNum[12]={0,31,59,90,120,151,181,212,243,273,304,334};
public:
    Date(){

    }

    Date(int m,int d,int y)
    {
        month = m;
        day = d;
        year = y;
    }
    void printDate()
    {
        string m = getMonthString(month);
        cout << month <<"/"<<day<<"/"<<year<<"\n";
        cout << m<<" "<<day<<", "<<year<<endl;
        cout << day<<" "<<m<<" "<<year<<endl;

    }
    string getMonthString(int d)
    {
        switch(d)
        {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";

        }
    }
    Date operator++(int)
    {
        Date nd(month,day,year);
        if (day == dayz[month - 1]) {
            day = 1;
            month++;
            month %= 12;
            if (month == 1)
                year++;
        }
        else
            day++;
        return nd;
    }
    Date operator--(int)
    {
        Date nd(month,day,year);
        day--;
        if (day == 0) {
            month--;
            if (month == 0) {
                month = 12;
                year--;
            }
            day = dayz[month - 1];
        }
        return nd;
    }
    int operator -(Date d)
    {
        int d2 = dayNum[d.month-1]+d.day+(d.year*365);
        int d1 = dayNum[month-1]+day+(year*365);
        if(d2>d1)
            return d2-d1;
        else
            return d1-d2;
    }
    friend ostream & operator << (ostream& strm, const Date& d)
    {
        strm << d.month<<" "<<d.day<<", "<<d.year<<endl;
        return strm;
    }
    friend istream & operator >> (istream& strm, Date& d)
    {
        cout << "Enter Month: ";
        strm >> d.month;
        cout << "Enter Day: ";
        strm >> d.day;
        cout << "Enter Year: ";
        strm >> d.year;
        return strm;
    }

};

int main()
{
    Date d1;
    Date d2;
    Date d3;
    cout << "Date Program\n";
    cin >> d1;
    cin >> d2;
    cout << "d1 - d2 = "<<d1-d2<<endl;
    cout << "d1++: \n";
    d1++;
    d1.printDate();
    cout << endl;
    cout << "d1--: ";
    d2--;
    d2.printDate();
    cout << endl;

    return 0;
}
