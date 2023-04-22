//////////////////////
// Clay Nottingham //
// CS 210          //
// Project One     //
////////////////////

#include<iostream>
#include<string>
using namespace std;
// global variables / functions
int hour12, hour24, minute, second;
string ampm;
void addHour() { //add 12 and 24 hour 
    hour12++;
    hour24++;
    if (hour12 >= 12) {
        hour12 -= 12;
        if (ampm == "AM")
            ampm = "PM";
        else
            ampm = "AM";
    }
    if (hour24 == 24) {
        hour24 = 0;
    }

}
void addMinute() { //add minute
    minute++;
    if (minute > 59) {
        minute = 0;
        addHour();
    }
}
void addSecond() { //add second
    second++;
    if (second > 59) {
        second = 0;
        addMinute();
    }

}

int main() {
    hour12 = 3;
    minute = 22;
    second = 1;
    ampm = "PM";
    int choice = 0;

    if (ampm == "PM") { //adjust 24 or 12-hour function
        hour24 += 12;

        if (hour24 >= 24) {

            hour24 -= 24;
            ampm = "AM";
        }
    }
    else {

        hour24 = hour12;
    }

    while (choice != 4) {
        //outputs
        cout << "**********************************************************************" << endl;
        cout << "*                          12-Hour clock                            **" << endl;
        cout << "*" << hour12 << ":" << minute << ":" << second << " " << ampm << "**" << endl;
        cout << "**********************************************************************" << endl;

        cout << "**********************************************************************" << endl;
        cout << "*                          24-Hour clock                            **" << endl;
        cout << "*" << hour24 << ":" << minute << ":" << second << " "              "**" << endl;
        cout << "**********************************************************************" << endl;

        cout << "****************************" << endl;
        cout << "* 1 - Add One Hour         *" << endl;
        cout << "* 2 - Add One Minute       *" << endl;
        cout << "* 3 - Add One Second       *" << endl;
        cout << "* 4 - Exit Program         *" << endl;
        cout << "****************************" << endl;

        cin >> choice; //choice of adjusting hours, minutes, or seconds

        if (choice == 1) {
            addHour();
        }
        if (choice == 2) {
            addMinute();
        }
        if (choice == 3) {
            addSecond();
        }

    }

    return 0; //exit code

}
