## Description
The first line of input consists of number of cases. Then, comes blank line (there is also a blank line between two consecutive cases) and in each line: team number, problem number, submission time and decision. All of them separated by empty space.
Contestants are ranked first by the number of problems solved (the more the better), then by decreasing amounts of penalty time. If two or more contestants are tied in both problems solved and penalty time, they are displayed in order of increasing team numbers.
A problem is considered solved by a contestant if any of the submissions for that problem was judged correct. Penalty time is computed as the number of minutes it took until the first correct submission for a problem was received, plus 20 minutes for each incorrect submission prior to the correct solution. Unsolved problems incur no time penalties.
The program reads all inputs, computes how many problems each team solved, penalty time, time to solve problem, how many attempts was and was there any submission of any problem or not.
The output for each test case consists of a scoreboard, sorted by the criteria described above. Each line of output contains a contestant number, the number of problems solved by the contestant and the total time penalty
accumulated by the contestant. Since not all contestants are participating, in the output only those contestants
who have made a submission.
The output of two consecutive cases will be separated by a blank line.