## Description
The main function of the program is to read all inputs and show the longest possible time for nap for the professor. If there are several longest naps with same duration, then it outputs the earliest one.

Firstly, the program get the number of appointments that the professor has in one day. Then, reads all appointments, store them in array and sort them by starting time. Then, compares the previous appointment’s ending time with present appointment’s starting time and find the difference. By doing so the program finds the longest possible time for nap and outputs the starting time of the nap and duration.

Also, the program works even if there is overlapping appointments, if the appointments arranged randomly by time and if the starting and ending time located not at the beginning of the line.
