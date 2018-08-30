#include <iostream>
#include <fstream>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int appointments_number;   //number of appointments if one day
    int day = 1;   //days counter
    while (cin >> appointments_number){    //while we have some input of number of appointments
        int minutes[appointments_number + 2][2], hours;   //array is to store the values, hours is the read the input
        char useless;   //just for reading useless things, such as ':'
        string trash;   //the useless part of the line with information of activity
        minutes[0][1] = 10 * 60;   //the day begins at 10 am
        minutes[appointments_number + 1][0] = 18 * 60;   //and ends at 6 pm
        for (int i = 1; i < appointments_number + 1; i++){   //reading the lines and getting the input
            while (true){
                cin >> useless;
                if (useless == '1'){
                    break;
                }
            }
            cin >> hours >> useless >> minutes[i][0];
            minutes[i][0] += (hours + 10) * 60;   //storing all information in array
            cin >> hours >> useless >> minutes[i][1];
            minutes[i][1] += hours * 60;   //storing all information in array
            getline(cin, trash);   //reading the rest trash
        }
        for (int i = 1; i < appointments_number + 1; i++){   //sorting the appointments by starting time
            for (int j = i + 1; j < appointments_number + 1; j++){
                if (minutes[i][0] > minutes[j][0]){
                    int temp;
                    temp = minutes[i][0];
                    minutes[i][0] = minutes[j][0];
                    minutes[j][0] = temp;
                    temp = minutes[i][1];
                    minutes[i][1] = minutes[j][1];
                    minutes[j][1] = temp;
                }
            }
        }
        int longest_nap = 0, start_nap = 0, biggest_end = minutes[0][1];   //variables for finding the nap time
        for (int i = 1; i < appointments_number + 2; i++){   //finding the longest nap and starting time
            if ((minutes[i][0] - biggest_end) > longest_nap){
                longest_nap = minutes[i][0] - biggest_end;
                start_nap = biggest_end;
            }
            if (minutes[i][1] > biggest_end){
                biggest_end = minutes[i][1];
            }
        }
        //printing output
        cout << "Day #" << day << ": the longest nap starts at " << (start_nap / 60) << ":";
        if ((start_nap % 60) < 10){   //if time is less than 10, add additional 0
            cout << 0;
        }
        cout << (start_nap % 60);
        cout << " and will last for ";
        if ((longest_nap / 60) > 0){   //if nap is more than or equal to 60 minutes, print hours
            cout << (longest_nap / 60) << " hours and ";
        }
        cout << (longest_nap % 60) << " minutes." << endl;   //printing minutes
        day += 1;   //days counter + 1
    }
    return 0;
}
