#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
     
    string hour, minute, second,pmam,result;
    int hour_int;
    int pos = 0;
    pos = s.find(':', pos);
    hour = s.substr(0,2);
    minute = s.substr(pos + 1,2);
    pos = s.find(':', pos+1);
    second = s.substr(pos+1,2);
    pmam = s.substr(pos+3);

    if (pmam == "PM") {
        hour_int = stoi(hour);
        if (hour_int < 12) {
            hour_int += 12;
        }
        hour = to_string(hour_int);
    } else {
        if (hour == "12") {
            hour = "00";
        }
    }

    result = hour + ':' + minute + ':' + second;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
