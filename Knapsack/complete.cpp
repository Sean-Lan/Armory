#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
static const int MAX_V = 100000;
static const int MAX_N = 100;


int V; // volume
int N; // number of goods
ll maxWeight[MAX_V+1];

void completePack(int volume, int weight) {
    for (int i=volume; i<=V; ++i) {
        maxWeight[i] = max(maxWeight[i],
                maxWeight[i-volume] + weight);
    }
}


int main() {
    int volume, weight;
    while (cin >> V >> N) {
        fill (maxWeight, maxWeight+V+1, 0);
        for (int i=0; i<N; ++i) {
            cin >> volume >> weight;
            completePack(volume, weight);
        }
        cout << maxWeight[V] << endl;
    }
    return 0;
}
