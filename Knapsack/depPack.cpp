/**
 *
 * Sean
 * 2016-07-21
 *
 * https://www.rqnoj.cn/problem/6
 *
 */
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int N, M;

vi V;
vi W;

vi maxWeights;

vvi dep;

vi primaries;

void groupPack(int primaryId) {
    int cnt = dep[primaryId].size();
    if (cnt == 0) {
        int v = V[primaryId];
        int w = W[primaryId];
        for (int i=N; i>=v; --i)
            maxWeights[i] = max(maxWeights[i], maxWeights[i-v]+w);
    } else if (cnt == 1) {
        int v0 = V[primaryId];
        int w0 = W[primaryId];
        int depId1 = dep[primaryId][0];
        int v1 = V[depId1];
        int w1 = W[depId1];
        for (int i=N; i>=v0; --i) {
            maxWeights[i] = max(maxWeights[i], maxWeights[i-v0]+w0);
            if (i >= v0+v1)
                maxWeights[i] = max(maxWeights[i], maxWeights[i-v0-v1]+w0+w1);
        }
    } else { // cnt == 2
        int v0 = V[primaryId];
        int w0 = W[primaryId];
        int depId1 = dep[primaryId][0];
        int depId2 = dep[primaryId][1];
        int v1 = V[depId1];
        int w1 = W[depId1];
        int v2 = V[depId2];
        int w2 = W[depId2];
        for (int i=N; i>=v0; --i) {
            maxWeights[i] = max(maxWeights[i], maxWeights[i-v0]+w0);
            if (i >= v0+v1)
                maxWeights[i] = max(maxWeights[i], maxWeights[i-v0-v1]+w0+w1);
            if (i >= v0+v2)
                maxWeights[i] = max(maxWeights[i], maxWeights[i-v0-v2]+w0+w2);
            if (i >= v0+v1+v2)
                maxWeights[i] = max(maxWeights[i], maxWeights[i-v0-v1-v2]+w0+w1+w2);
        }
    }
}

int main() {
    int v, p, q;
    while (cin >> N >> M) {
        V = vi(M+1);
        W = vi(M+1);
        dep = vvi(M+1, vi());
        primaries = vi();
        maxWeights = vi(N+1, 0);
        for (int i=1; i<=M; ++i) {
            cin >> v >> p >> q;
            V[i] = v;
            W[i] = v*p;
            if (q) {
                dep[q].push_back(i);
            } else {
                primaries.push_back(i);
            }
        }

        for (int i=0; i<primaries.size(); ++i) {
            groupPack(primaries[i]);
        }

        cout << maxWeights[N] << endl;
    }
    return 0;
}
