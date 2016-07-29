/**
 *
 * Sean
 * 2016-07-29
 *
 * http://ac.jobdu.com/problem.php?pid=1455
 *
 * 题目描述：
 * 为了挽救灾区同胞的生命，心系灾区同胞的你准备自己采购一些粮食支援灾区，现在假设你一共有资金n元，而市场有m种大米，每种大米都是袋装产品，其价格不等，并且只能整袋购买。请问：你用有限的资金最多能采购多少公斤粮食呢？
 *
 * 输入：
 * 输入数据首先包含一个正整数C，表示有C组测试用例，每组测试用例的第一行是两个整数n和m(1<=n<=100, 1<=m<=100),分别表示经费的金额和大米的种类，然后是m行数据，每行包含3个数p，h和c(1<=p<=20,1<=h<=200,1<=c<=20)，分别表示每袋的价格、每袋的重量以及对应种类大米的袋数。
 *
 * 输出：
 * 对于每组测试数据，请输出能够购买大米的最多重量，你可以假设经费买不光所有的大米，并且经费你可以不用完。每个实例的输出占一行。
 *
 * 样例输入：
 * 1
 * 8 2
 * 2 100 4
 * 4 100 2
 *
 * 样例输出：
 * 400
 *
 */

#include <iostream>
#include <vector>
#include "../MonotonicQueue/MonotonicQueue.h"
using namespace std;

int T;
int N, M;

vector<int> maxWeights;

int v, w, cnt;

void zeroOnePack(int v, int w) {
    for (int i=N; i>=v; --i)
        maxWeights[i] = max(maxWeights[i], maxWeights[i-v] + w);
}

void completePack(int v, int w) {
    for (int i=v; i<=N; ++i)
        maxWeights[i] = max(maxWeights[i], maxWeights[i-v] + w);
}

void multiPack(int v, int w, int cnt) {
    if (v*cnt >= N) { // you can put as many as you want
        completePack(v, w);
        return;
    }

    MonotonicQueue<int, std::greater<int> > aQueue;
    for (int r=0; r<v; ++r) {
        aQueue.clear();
        int k = (N-r)/v;
        for (int i=0; i<=k; ++i) {
            int pos = i*v+r;
            aQueue.push(i, maxWeights[pos]-i*w);
            while(i-aQueue.getExtremumIndex() > cnt) aQueue.pop();
            maxWeights[pos] = aQueue.getExtremum() + i*w;
        }
    }

}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        maxWeights = vector<int>(N+1, 0);
        for (int i = 0; i<M; ++i) {
            cin >> v >> w >> cnt;
            multiPack(v, w, cnt);
        }
        cout << maxWeights[N] << endl;
    }
    return 0;
}
