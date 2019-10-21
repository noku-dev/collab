#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    for (int i = 0 ; i < n ; i++) {
        // Print n - rownum spaces and rownum hashes
        // this would be easier with string, but I wanted to use loops, with strings
        // it would be something like string(n - rownum, " ") and 
        // string(rownum, "#")
        for (int j = i ; j < n - 1 ; j++) {
            cout << " ";
        }
        for (int j = n - i ; j <= n; j++) {
            cout << "#";
        }
        // Don't print a new line after the last line, to match hacker rank output
        if (i < n - 1) {
            cout << endl;
        }
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
