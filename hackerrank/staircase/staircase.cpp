#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    for (int i = 1 ; i <= n ; i++) {
        // Print n - rownum spaces and rownum hashes
        cout << string(n - i, ' ') << string(i, '#');
        // Don't print a new line after the last line, to match hacker rank output
        if (i < n) {
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
