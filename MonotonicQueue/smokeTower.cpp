/**
 * Sean
 * 2016-07-20
 *
 * http://www.tyvj.cn/p/1313
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "MonotonicQueue.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;


int main() {
    int n, m;
    while (cin >> n >> m) {
        vi costs  = vi(n);
        vll minCosts = vll(n);
        for (int i=0; i<n; ++i)
            cin >> costs[i];

        MonotonicQueue<ll> incrQueue;
        int minMN = min(m, n);
        for (int i=0; i<minMN; ++i) {
            minCosts[i] = costs[i];
            incrQueue.push(i, minCosts[i]);
        }

        for (int i=minMN; i<n; ++i) {
            while(!incrQueue.empty() && i-incrQueue.getExtremumIndex()>m)
                incrQueue.pop();
            minCosts[i] = incrQueue.getExtremum() + costs[i];
            incrQueue.push(i, minCosts[i]);
        }

        ll minValue = LLONG_MAX;
        for (int i=max(0, n-m); i<n; ++i)
            minValue = min(minValue, minCosts[i]);

        cout << minValue << endl;
    }

    return 0;
}
