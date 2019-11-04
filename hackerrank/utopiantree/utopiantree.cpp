#include <bits/stdc++.h>

using namespace std;

// Complete the utopianTree function below.
int utopianTree(int n) {
    int height {0};
    int numcycles = n / 2;

    // This is a progression in which we alternate an arithmetic and geometric
    // progression at each step. The arithmetic progression adds 1 to n - 1, the 
    // geometric one multiplies n - 1 times 2. Came up with this formula after a 
    // bit of tinkering and having seen a code example in discussions that didn't 
    // actually work. This is more of a mathematical problem than a coding one, 
    // although a solution with a loop could have been implemented.
    if (n % 2) { // Odd number
        height = (pow(2, numcycles + 2)) - 2;
    } else { // Even nunmber
        height = (pow(2, numcycles + 1) - 1);
    }
    return height;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = utopianTree(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
