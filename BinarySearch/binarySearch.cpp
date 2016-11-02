/**
 *
 * Sean
 * 2016-11-02
 *
 * Demos for how to write binary search.
 *
 * Serveral note points:
 * 
 * 1. to avoid infinite loop, carefully choose down round ( start = start + (end-start)/2 ) or 
 *    up round ( start = start + (end-start+1)/2 ), you should use the array with 2 elements to test.
 *
 * 2. use start = start + (end-start)/2 instead of start = (start+end)/2, to ensure (end-start)/2 always
 *    down round.
 *
 * 3. be careful with the search space, [start, end] should contain the answer.
 *
 * 4. be careful with array indexing out of range.
 *
 */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// The array to be searched.
vector<int> iVec(15);

// >
int first_greater_than_idx(int start, int end, int target) {
    int mid;
    while (start < end) {
        mid = start + (end-start)/2;
        if (iVec[mid] <= target) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}

// >=
int first_greater_than_or_equal_to_idx(int start, int end, int target) {
    int mid;
    while (start < end) {
        mid = start + (end-start)/2;
        if (iVec[mid] < target) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}

// <
int last_less_than_idx(int start, int end, int target) {
    int mid;
    while (start < end) {
        // up round
        mid = start + (end-start+1)/2;
        if (iVec[mid] >= target) {
            end = mid -1;
        } else {
            start = mid;
        }
    }
    return start;
}

// <=
int last_less_than_or_equal_to_idx(int start, int end, int target) {
    int mid;
    while (start < end) {
        // up round
        mid = start + (end-start+1)/2;
        if (iVec[mid] <= target) {
            start = mid;
        } else {
            end = mid-1;
        }
    }
    return start;
}

void test_first_greater_than_idx(int target) {
    cout << "target: " << target;
    int index = first_greater_than_idx(0, iVec.size(), target);
    cout << "\tindex: " << index;
    cout << "\tvalude: ";
    if (index < iVec.size())
        cout << iVec[index];
    else
        cout << "greater than the largest";
    cout << endl;
}

void test_first_greater_than_or_equal_to_idx(int target) {
    cout << "target: " << target;
    int index = first_greater_than_or_equal_to_idx(0, iVec.size(), target);
    cout << "\tindex: " << index;
    cout << "\tvalude: ";
    if (index < iVec.size())
        cout << iVec[index];
    else
        cout << "greater than the largest";
    cout << endl;
}

void test_last_less_than_idx(int target) {
    cout << "target: " << target;
    int index = last_less_than_idx(-1, iVec.size()-1, target);
    cout << "\tindex: " << index;
    cout << "\tvalude: ";
    if (index >= 0)
        cout << iVec[index];
    else
        cout << "less than the smallest";
    cout << endl;
}

void test_last_less_than_or_equal_to_idx(int target) {
    cout << "target: " << target;
    int index = last_less_than_or_equal_to_idx(-1, iVec.size()-1, target);
    cout << "\tindex: " << index;
    cout << "\tvalude: ";
    if (index >= 0)
        cout << iVec[index];
    else
        cout << "less than the smallest";
    cout << endl;
}

int main() {
    iota(iVec.begin(), iVec.end(), 100);

    cout << "Array is: ";
    for (auto &i : iVec)
        cout << i << " ";
    cout << endl;

    vector<int> testValues = {10, 100, 101, 110, 113, 114, 115, 120};

    cout<< "test first_greater_than_idx" << endl;
    for (auto i: testValues)
        test_first_greater_than_idx(i);
    cout << endl;

    cout<< "test first_greater_than_or_equal_to_idx" << endl;
    for (auto i: testValues)
        test_first_greater_than_or_equal_to_idx(i);
    cout << endl;

    cout << "test last_less_than_idx" << endl;
    for (auto i: testValues)
        test_last_less_than_idx(i);
    cout << endl;

    cout << "test last_less_than_or_equal_to_idx" << endl;
    for (auto i: testValues)
        test_last_less_than_or_equal_to_idx(i);
    cout << endl;

    return 0;
}
