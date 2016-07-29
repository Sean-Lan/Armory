/**
 *
 * Sean
 * 2016-07-19
 *
 * http://ac.jobdu.com/problem.php?pid=1454
 *
 * Piggy-Bank
 *
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int T;

int E, F, N;

int maxV;

vector<int> minWeights;

void completePack(int v, int w) {
    for (int i=v; i<=maxV; ++i) {
        if (minWeights[i-v] != INT_MAX)
            minWeights[i] = min(minWeights[i], minWeights[i-v] + w);
    }
}

int main() {
    cin >> T;
    int v, w;
    for (int t=0; t<T; ++t) {
        cin >> E >> F;
        maxV = F-E;
        minWeights = vector<int>(maxV+1, INT_MAX);
        minWeights[0] = 0;
        cin >> N;
        for (int i=0; i<N; ++i) {
            cin >> w >> v;
            completePack(v, w);
        }
        if (minWeights[maxV] == INT_MAX) {
            cout << "This is impossible." << endl;
        } else {
            cout << "The minimum amount of money in the piggy-bank is " << minWeights[maxV] << "." << endl;
        }
    }
    return 0;
}
