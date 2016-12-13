/**
 *
 * Sean
 * 2016-11-18
 *
 * Knuth–Morris–Pratt (KMP) algorithm
 *
 * O(m + n) where m and n are the lengths of the pattern and string respectively.
 *
 */
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// return a table, and table[i] means, if pattern[i] fails to match,
// the next match should begin at table[i] (if table[i] equals -1, i.e. i equals 0, the string
// to be matched should move ahead).
// table[0] and table[1] are fixed value.
vector<int> kmpTable(const string &pattern) {
    int n = pattern.size();
    vector<int> table(n);
    table[0] = -1;
    table[1] = 0;

    // O(n)
    // pos < n
    // In case 1: pos increases, pos-i doesn't change
    // In case 2: pos doesn't change, pos-i increases
    // In case 3: pos increases, pos-i increases since i doesn't change
    int pos = 2;
    int i = 0;
    while (pos < n) {
        if (pattern[pos-1] == pattern[i]) { // case 1
            table[pos] = i + 1;
            ++i;
            ++pos;
        } else if (i > 0){ // case 2
            i = table[i];
        } else { // case 3
            table[pos] = 0;
            ++pos;
        }
    }
    return table;
}

int kmpSearch(const string &pattern, const string &str) {
    vector<int> table =  kmpTable(pattern);
    int n = str.size();
    int m = pattern.size();
    int i = 0;
    int j = 0;

    // O(n)
    // i < n && i + j < n
    // In case 1, i+j increases, i doesn't change
    // In case 2, i+j doesn't change, i increaes since j > table[j]
    // In case 3, both i+j and i increase
    while (i+j < n) {
        if (str[i+j] == pattern[j]) { // case 1
            ++j;
            if (j == m) return i;
        } else if (j > 0) { // case 2
            i = i + j - table[j];
            j = table[j];
        } else { // case 3: j == 0, move i ahead;
            ++i;
        }
    }
    return -1;
}

int main() {
    string pattern = "ABCDABD";
    auto table = kmpTable(pattern);
    for (auto i : table) cout << i << " ";
    cout << endl;

    string str = "ABC ABCDAB ABCDABCDABDE";
    cout << kmpSearch(pattern, str) << endl;
    return 0;
}
