#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long a_count = 0;
    long a_remainderct = 0;
    long strsize = s.size();
    // How many string lengths in n
    long numstrings = n / strsize;
    // Remainder in the string
    long remainder = n % strsize;
    long i = 0;
    // The idea here is to only iterate over string to save some computation
    // An optimization could be done to break in case n is less than string size
    // and we don't need to keep doing the a_count. I'll leave that as an exercise
    // I tried to do some computations before the loop to do as much arithmetic instead
    // of iteration. The idea is that in the end the number of a is number of substrings
    // s in infinite string times number of a per substring plus the number of a in the
    // remainder. If n is less than string size, then it is just the remainder amount.
    for (auto c : s) {
        if (c == 'a') {
            a_count++;
            if (i < remainder) {
                a_remainderct++;
            }
        }
        i++;
    }
    return (a_count * numstrings) + a_remainderct;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
