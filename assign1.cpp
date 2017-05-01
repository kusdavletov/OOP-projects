#include <iostream>
using namespace std;

bool final_check(string beg[], int beg_length, string end[], int end_length, string both[], int both_length){
    for (int i = 0; i < beg_length; i++){   //checking the content of the array
        if (beg[i] != ""){
            return false;
        }
    }
    for (int i = 0; i < end_length; i++){   //checking the content of the array
        if (end[i] != ""){
            return false;
        }
    }
    for (int i = 0; i < both_length; i++){   //checking the content of the array
        if (both[i] != ""){
            return false;
        }
    }
    return true;
}

bool check(string mass[], int first, int second, int number){
    string both[300], beg[300], end[300];   //dividing initial array into three
    string example;   //the correct(answer) string
    example = string(mass[first]) + string(mass[second]);
    int str_length = example.length();   //correct string's length
    int both_length = 0, beg_length = 0, end_length = 0;   //the length of three new arrays
    int var_length = 0;   //the length of the variable strings
    for (int i = 0; i < number; i++){   //dividing strings to the arrays
        var_length = mass[i].length();
        if (example.substr(0, var_length) == mass[i] && example.substr(str_length - var_length, var_length) == mass[i]){
            both[both_length] = mass[i];
            both_length += 1;
        }
        else if (example.substr(0, var_length) == mass[i]){
            beg[beg_length] = mass[i];
            beg_length += 1;
        }
        else if (example.substr(str_length - var_length, var_length) == mass[i]){
            end[end_length] = mass[i];
            end_length += 1;
        }
        else{   //if it does not fit the conditions then return false
            return false;
        }
    }
    //searching pairs and delete them
    for (int i = 0; i < beg_length; i++){
        int find_length = str_length - beg[i].length();
        for (int j = 0; j < end_length; j++){
            if (end[j].length() == find_length){
                beg[i] = "";
                end[j] = "";
                break;
            }
        }
    }
    for (int i = 0; i < beg_length; i++){
        int find_length = str_length - beg[i].length();
        for (int j = 0; j < both_length; j++){
            if (both[j].length() == find_length){
                beg[i] = "";
                both[j] = "";
                break;
            }
        }
    }
    for (int i = 0; i < both_length; i++){
        int find_length = str_length - both[i].length();
        for (int j = 0; j < end_length; j++){
            if (end[j].length() == find_length){
                both[i] = "";
                end[j] = "";
                break;
            }
        }
    }
    for (int i = 0; i < both_length; i++){
        int find_length = str_length - both[i].length();
        for (int j = 0; j < both_length; j++){
            if (both[j].length() == find_length){
                both[i] = "";
                both[j] = "";
                break;
            }
        }
    }
    //checking whether all strings are empty or not
    if (final_check(beg, beg_length, end, end_length, both, both_length) == true){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int tests_number;   //number of tests
    string input;       //input string
    cin >> tests_number;
    getline(cin, input);
    getline(cin, input);
    for (int i = 0; i < tests_number; i++){
        string arr[300];   //array to store all input strings
        int count = 0;     //number to strings
        int total_length = 0;   //length of all strings combined
        while (true){
            getline(cin, input);   //read a line
            if (input.length() == 0){   //if empty go to next test
                break;
            }
            else{
                arr[count] = input;   // else store string into array
                total_length += input.length();   //to compute the length of all strings combined
                count += 1;   //count the number of the strings
            }
        }
        int string_length = total_length / (count / 2);   //the length of the final(answer) string
        int search_length = string_length - arr[0].length();   //the length of the pair which is pair to the first string
        for (int k = 1; k < count; k++){   //searching pair to the first string
            if (arr[k].length() == search_length){
                if (check(arr, 0, k, count) == true){   //checking two possibilities, first+found or found+first
                    cout << string(arr[0]) + string(arr[k]) << endl;
                    break;
                }
                else if (check(arr, k, 0, count) == true){
                    cout << string(arr[k]) + string(arr[0]) << endl;
                    break;
                }
	        }
        }
	if (i < tests_number - 1){   //to make blank between answers
        cout << endl;
	}
    }
    return 0;
}
