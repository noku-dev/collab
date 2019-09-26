#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int valleys = 0;
    int level = 0; // 0 is sea level
    for (auto c : s) {
        if (c == 'D') {
            // Just count one valley when we go from sea level to under sea level
            if (level == 0) {
                valleys++;
            }
            level--;
        } else { // What is not down has to be up, no need to check for char 'U'
            level++;
        }
    }
    return valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
