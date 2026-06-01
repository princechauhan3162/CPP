#include <iostream>
using namespace std;

class TimeConverter
{
public:
    void secondtohms()
    {
        int total, hours, minutes, seconds;

        cout << "Enter total seconds: ";
        cin >> total;

        hours = total / 3600;
        minutes = (total % 3600) / 60;
        seconds = (total % 3600) % 60;

        cout << "HH:MM:SS = "
             << hours << ":" << minutes << ":" << seconds << endl;
    }

    void hmstosecond()
    {
        int hours, minutes, seconds, total;

        cout << "Hours: ";
        cin >> hours;

        cout << "Minutes: ";
        cin >> minutes;

        cout << "Seconds: ";
        cin >> seconds;

        total = (hours * 3600) + (minutes * 60) + seconds;

        cout << "Total Seconds = " << total << endl;
    }
};

int main()
{
    TimeConverter tc;

    tc.secondtohms();
    tc.hmstosecond();
}