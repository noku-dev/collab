#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    /*
     * Write your code here.
     */
    // My intuition is that this is a how many skips of 2 to reach destination problem
    // but it is from both sides. Right side is a bit more complicated because in 
    // the end of the book we might have 1 or 2 pages printed. At the beginning of the 
    // book we know only page 1 is printed on the right side.
    int distfromend;
    int pagecount;
    bool singlelastpage = !(n % 2);
    bool countfromend = false;
    if (p == 1 || p == n) {
         return 0;
    } else {
        if (p > n/2) {
            distfromend = n - p;
            countfromend = true;
        } else {
            distfromend = p;
        }
        if (countfromend && singlelastpage) {
            // I don't like this. It is a way to compensate for the case of singlelast
            // page and because distfromend = p really is not giving us the distance,
            // but the page number, i.e. p, not p - 1 which would be what we get when
            // doing n - p when starting from end. 
            distfromend++;
        }
        pagecount = distfromend / 2 ;
    }
    return pagecount;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
