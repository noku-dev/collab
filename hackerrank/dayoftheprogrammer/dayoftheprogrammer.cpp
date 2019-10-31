#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

bool isLeapYear(int year) {
    bool isLeap {false};
    const int remainder_4 = year % 4;
    if (year <= 1917) {
        if (remainder_4 == 0) {
            isLeap = true;
        }
    } else {
        if (((remainder_4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            isLeap = true;
        }
    }
    return isLeap;
}

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
    // Use a stringstream to build the return string as if it were cout
    // Use str() method to retrieve the string we've built in the stream
    stringstream day;
    if (isLeapYear(year)) {
        day << "12.09.";
    } else if (year == 1918) {
        // Special case for this year
        day << "26.09.";
    } else {
        day << "13.09.";
    }
    day << year;
    return day.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
