#include <bits/stdc++.h>

using namespace std;

string numtostr(int n) {
    vector<string> numbers = {
        "zero", 
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine"
    };
    if (n < 30) {
        return numbers[n];
    } else {
        return "";
    }
}
// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    stringstream time;
    if (m == 0) {
        time << numtostr(h) << " o' clock";
    } else if (m == 15) {
        time << "quarter past " << numtostr(h); 
    } else if (m == 30) {
        time << "half past " << numtostr(h); 
    } else if (m == 45) {
        if (h == 12) {
            h = 0;
        }
        time << "quarter to " << numtostr(h + 1);
    } else if (m < 30) {
        time << numtostr(m) << " minute" << ((m > 1)?"s":"") << " past " << numtostr(h);
    } else if (m > 30) {
        if (h == 12) {
            h = 0;
        }
        time << numtostr(60 - m) << " minute" << ((m > 1)?"s":"") << " to " << numtostr(h + 1);
    } else {
        time << "I don't know yet";
    }
    return time.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
