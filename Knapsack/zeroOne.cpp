/**
 *
 * Sean
 * 2016-07-19
 *
 * http://ac.jobdu.com/problem.php?pid=1123
 *
 * 题目描述：
 * 辰辰是个很有潜能、天资聪颖的孩子，他的梦想是称为世界上最伟大的医师。
 * 为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。
 * 医师把他带到个到处都是草药的山洞里对他说：
 * “孩子，这个山洞里有一些不同的草药，采每一株都需要一些时间，每一株也有它自身的价值。
 * 我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”
 * 如果你是辰辰，你能完成这个任务吗？
 *
 * 输入：
 * 输入的第一行有两个整数T（1 <= T <= 1000）和M（1 <= M <= 100），T代表总共能够用来采药的时间，M代表山洞里的草药的数目。
 * 接下来的M行每行包括两个在1到100之间（包括1和100）的的整数，分别表示采摘某株草药的时间和这株草药的价值。
 *
 * 输出：
 * 可能有多组测试数据，对于每组数据，
 * 输出只包括一行，这一行只包含一个整数，表示在规定的时间内，可以采到的草药的最大总价值。
 *
 * 样例输入：
 * 70 3
 * 71 100
 * 69 1
 * 1 2
 *
 * 样例输出：
 * 3
 *
 */
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
static const int MAX_V = 1000;
ll maxWeight[MAX_V+1];

int V; // volume
int N; // number of goods

void zeroOnePack(int volume, int weight) {
    // note: the lower bound for i, i.e, volume can be improved to max(sum{v[i+1..n]}, c[i])
    for (int i=V; i>=volume; --i) {
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
            zeroOnePack(volume, weight);
        }
        cout << maxWeight[V] << endl;
    }
    return 0;
}
