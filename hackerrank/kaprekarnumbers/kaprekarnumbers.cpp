#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    int count {0};
    string r;
    string l;
    unsigned long long rnum;
    unsigned long long lnum;
    unsigned long long sq;
    string istr;
    string sqstr;
    int istrlen;
    int sqstrlen;
    for (unsigned long long i = p ; i <= q ; i++) {
        sq = (i * i);
        istr = to_string(i);
        istrlen = istr.size();
        sqstr = to_string(sq);
        sqstrlen = sqstr.size();
        r = sqstr.substr(sqstrlen - istrlen);
        l = sqstr.substr(0, sqstrlen - istrlen);
        if (r.size() > 0) {
            rnum = stoull(r);
        } else {
            rnum = 0;
        }
        if (l.size() > 0) {
            lnum = stoull(l);
        } else {
            lnum = 0;
        }
        if ((lnum + rnum) == i) {
            cout << i << " ";
            count++;
        }
    }
    if (count == 0) {
        cout << "INVALID RANGE";
    }
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
