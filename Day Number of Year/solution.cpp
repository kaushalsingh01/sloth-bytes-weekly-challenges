#include <bits/stdc++.h>
using namespace std;

bool isValidDate(const string &str){
    regex pattern(R"(^\d{2}[-/]\d{2}[-/]\d{4}$)");
    return regex_match(str, pattern);
}

string sanitizeDate(const string& str){
    string clean;
    for (char c : str) {
        if(isdigit(c)|| c=='-' || c=='/'){
            clean.push_back(c);
        }
    }
    return clean;
}

vector<string> splitDate(string str)
{
    string clean = sanitizeDate(str);
    if(clean.size() == 8) {
        return {clean.substr(0,2), clean.substr(2,2), clean.substr(4,4)};
    }

    vector<string> res;
    string temp;
    for(char c : clean){
        if(c == '-' || c =='/'){
            res.push_back(temp);
            temp.clear();
        }
        else{
            temp.push_back(c);
        }
    }
    res.push_back(temp);
    if(res.size()==3){
        if(res[0].size() == 1){
            res[0] = "0"+res[0];
        }
        if(res[1].size() == 1){
            res[1] = "0"+res[1];
        }
        while(res[2].size() < 4){
            res[2] = "0" + res[2];
        }
    }
    return res;
}

bool leapYear(int year){
    if(year % 400 == 0){
        return true;
    }
    else if(year % 100 == 0){
        return false;
    }
    else if(year % 4 == 0){
        return true;
    }
    else{
        return false;
    }
}

int dayOfYear(string dateString){
    vector <string> dateSplited = splitDate(dateString);
    try {
        int month = stoi(dateSplited[0]);
        int day = stoi(dateSplited[1]);
        int year = stoi(dateSplited[2]);
        int dayNumber = 0;
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month < 1 || month > 12)
        {
            cout << "You poor soul! Go learn how many months are there?";
            return 0;
        }
        if (leapYear(year))
        {
            daysInMonth[1] = 29;
        }
        if (day < 1 || day > daysInMonth[month - 1])
        {
            cout << "Is your IQ lower than room tempreature!";
            return 0;
        }
        for (int i = 0; i < month - 1; i++)
        {
            dayNumber += daysInMonth[i];
        }
        dayNumber += day;
        return dayNumber;
    }
    catch (const invalid_argument& e){
        cout<<"You can't even enter a date!"<<endl;
        return 0;
    }

}

int main(){
    string dateString;
    cout<<"Enter Date (mm/dd/yyyy or mm-dd-yyyy): ";
    cin>> dateString;
    if(!isValidDate(dateString)){
        cout<<"You don't understand the format?";
        return 0;
    }
    int result = dayOfYear(dateString);
    if(result > 0) {
        cout<<"Day of year:"<<result<<endl;
    }
    return 0;
}