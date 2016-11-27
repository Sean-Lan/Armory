/**
 *
 * Sean
 * 2016-11-27
 *
 * Three Way Partition
 *
 * https://en.wikipedia.org/wiki/Dutch_national_flag_problem
 *
 * Sort an array according to a key, after the sorting:
 *  1. elements < key previous to elements == key
 *  2. elements == key previous to elements > key
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int>::iterator It;

// Invariant:
//  1. any x in [0, i), arr[x] < val
//  2. any x in [i, j), arr[x] == val
//  3. any x in (k, n-1], arr[x] > val
void threeWayPartition(It beg, It end, int val) {
    if (beg == end) return;
    It i = beg, j=beg, k=end-1;
    while (j <= k) {
        if (*j < val) {
            iter_swap(i, j);
            ++i, ++j;
        } else if (*j > val) {
            iter_swap(j, k);
            --k;
        } else {
            ++j;
        }
    }
}

void printArray(vector<int> &iVec) {
    for (auto &i : iVec)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> iVec = {1, 3, 3, 4, 2, 2, 5};
    printArray(iVec);
    threeWayPartition(iVec.begin(), iVec.end(), 3);
    printArray(iVec);

    return 0;
}
