/**
 * Sean
 * 2016-10-02
 *
 * https://code.google.com/codejam/contest/11274486/dashboard#s=p1
 *
 */

#include <iostream>
using namespace std;

const int MAX_N = 50;
const int MAX_H = 1000;

int T, R, C;

int H[MAX_N][MAX_N];
// mark for whether the point has been visited.
bool mark[MAX_N][MAX_N];

void clearMark() {
    for (int i=0; i<R; ++i)
        for (int j=0; j<C; ++j)
            mark[i][j] = false;
}

int total;

// mark for whether the flood arrives the border
bool out;
int dfsVisit(int i, int j, int h) {
    int cnt = 0;
    int cur = H[i][j];
    if (cur < h) {
        // arrive the border
        if ((i == R-1) || (i == 0) || (j == 0) || (j == C-1))
            out = true;

        ++cnt;
        // make sure to check the index range.
        if (i+1 <= R-1 && !mark[i+1][j]) {
            mark[i+1][j] = true;
            cnt += dfsVisit(i+1, j, h);
        }
        if (i-1 >= 0 && !mark[i-1][j]) {
            mark[i-1][j] = true;
            cnt += dfsVisit(i-1, j, h);
        }
        if (j+1 <= C-1 && !mark[i][j+1]) {
            mark[i][j+1] = true;
            cnt += dfsVisit(i, j+1, h);
        }
        if (j-1 >= 0 && !mark[i][j-1]) {
            mark[i][j-1] = true;
            cnt += dfsVisit(i, j-1, h);
        }

    }
    return cnt;
}

int main() {
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cin >> R >> C;
        total = 0;
        for (int i=0; i<R; ++i)
            for (int j=0; j<C; ++j)
                cin >> H[i][j];

        for (int h=2; h<=MAX_H; ++h) {
            clearMark();
            for (int i=1; i<R-1; ++i)
                for (int j=1; j<C-1; ++j)
                    if (!mark[i][j]) {
                        out = false;
                        mark[i][j] = true;
                        int cnt = dfsVisit(i, j, h);
                        if (!out) total += cnt;
                    }
        }
        cout << "Case #" << t << ": " << total << endl;
    }
}

