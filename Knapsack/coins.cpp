/**
 *
 * Sean
 *
 * 2016-07-20
 *
 * http://poj.org/problem?id=1742
 *
 * Description
 *
 * People in Silverland use coins.They have coins of value A1,A2,A3...An Silverland dollar.
 * One day Tony opened his money-box and found there were some coins. He decided to buy a
 * very nice watch in a nearby shop. He wanted to pay the exact price(without change) and
 * he known the price would not more than m.But he didn't know the exact price of the watch.
 * You are to write a program which reads n, m, A1, A2, A3...An and C1, C2, C3...Cn
 * corresponding to the number of Tony's coins of value A1,A2,A3...An then calculate how
 * many prices(form 1 to m) Tony can pay use these coins.
 *
 * Input
 *
 * The input contains several test cases. The first line of each test case contains two
 * integers n(1<=n<=100),m(m<=100000).The second line contains 2n integers, denoting
 * A1, A2, A3...An, C1, C2, C3...Cn (1<=Ai<=100000,1<=Ci<=1000). The last test case is followed by two zeros.
 * Output
 *
 * For each test case output the answer on a single line.
 *
 * Sample Input
 *
 * 3 10
 * 1 2 4 2 1 1
 * 2 5
 * 1 4 2 1
 * 0 0
 *
 * Sample Output
 *
 * 8
 * 4
 *
 */
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

static const int MAX_M = 100000;
static const int MAX_N = 100;

int N, M;
int total;
int A[MAX_N];
int C[MAX_N];

bool possible[MAX_M+1];
int aQueue[MAX_M+1];
void completePack(int v) {
    for (int i=v; i<=M; ++i)
        if (possible[i-v] && !possible[i]) {
            ++total;
            possible[i] = true;
        }
}

void multiPack(int v, int cnt) {
    if (v * cnt >= M) {
        completePack(v);
        return;
    }

    bool oldValue;
    for (int r=0; r<v; ++r) {
        int k = (M-r)/v;
        int s=0, e=0;
        for (int i=0; i<=k; ++i) {
            int pos = i*v+r;

            while (s != e && i-aQueue[s] > cnt) ++s;

            oldValue = possible[pos];
            if (s != e && !oldValue) {
                possible[pos] = true;
                ++total;
            }
            if (oldValue)
                aQueue[e++] = i;
        }
    }

}

int main() {
    while (~scanf("%d%d", &N, &M)) {
        if (N == 0 && M == 0)
            break;
        total = 0;
        fill(possible, possible+M+1, false);
        possible[0] = true;

        for (int i=0; i<N; ++i)
            scanf("%d", A+i);

        for (int i=0; i<N; ++i)
            scanf("%d", C+i);

        for (int i=0; i<N; ++i)
            multiPack(A[i], C[i]);

        printf("%d\n", total);
    }
    return 0;
}


