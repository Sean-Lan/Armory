/**
 *
 * Sean
 * 2016-11-02
 *
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;
using namespace std::placeholders;

// the search space should follow the master theorem

int lastFalse(int start, int end, std::function<bool(int)> p) {
    int mid;
    while (start < end) {
        // up round
        mid = start + (end-start+1)/2;
        if (p(mid)) {
            end = mid - 1;
        } else {
            // should use up round to avoid infinite loop
            start = mid;
        }
    }
    return start;
}

int firstTrue(int start, int end, std::function<bool(int)> p) {
    int mid;
    while (start < end) {
        mid = start + (end-start)/2;
        if (p(mid)) {
            end = mid;
        } else {
            start = mid+1;
        }
    }
    return start;
}

int main() {
    vector<int> iVec(15);
    std::iota(iVec.begin(), iVec.end(), 100);

    cout << "Index is: ";
    for (int i=0; i<iVec.size(); ++i)
        cout << setw(3) << i << " ";
    cout << endl;

    cout << "Array is: ";
    for (auto &i : iVec)
        cout << i << " ";
    cout << endl;

    vector<int> testValues = {10, 100, 101, 110, 113, 114, 115, 120};

    auto greaterThan = [&iVec](int pos, int target) {
        return iVec[pos] > target;
    };

    auto greaterThanOrEqualTo = [&iVec](int pos, int target) {
        return iVec[pos] >= target;
    };

    auto firstGreaterThan = [&greaterThan] (int start, int end, int target) {
        auto p = std::bind(greaterThan, _1, target);
        return firstTrue(start, end, p);
    };

    auto firstGreaterThanOrEqualTo = [&greaterThanOrEqualTo] (int start, int end, int target) {
        auto p = std::bind(greaterThanOrEqualTo, _1, target);
        return firstTrue(start, end, p);
    };

    auto lastLessThanOrEqualTo = [&greaterThan] (int start, int end, int target) {
        auto p = std::bind(greaterThan, _1, target);
        return lastFalse(start, end, p);
    };

    auto lastLessThan = [&greaterThanOrEqualTo](int start, int end, int target) {
        auto p = std::bind(greaterThanOrEqualTo, _1, target);
        return lastFalse(start, end, p);
    };

    cout << "test firstGreaterThan" << endl;
    for (auto target : testValues) {
        cout << "target: " << target;
        int index = firstGreaterThan(0, iVec.size(), target);
        cout << "\tindex: " << index;
        cout << "\tvalude: ";
        if (index < iVec.size())
            cout << iVec[index];
        else
            cout << "greater than the largest";
        cout << endl;
    }

    cout << "test firstGreaterThanEqualTo" << endl;
    for (auto target : testValues) {
        cout << "target: " << target;
        int index = firstGreaterThanOrEqualTo(0, iVec.size(), target);
        cout << "\tindex: " << index;
        cout << "\tvalude: ";
        if (index < iVec.size())
            cout << iVec[index];
        else
            cout << "greater than the largest";
        cout << endl;
    }

    cout << "test lastLessThan" << endl;
    for (auto target : testValues) {
        cout << "target: " << target;
        int index = lastLessThan(-1, iVec.size()-1, target);
        cout << "\tindex: " << index;
        cout << "\tvalude: ";
        if (index >= 0)
            cout << iVec[index];
        else
            cout << "less than the smallest";
        cout << endl;
    }

    cout << "test lastLessThanOrEqualTo" << endl;
    for (auto target : testValues) {
        cout << "target: " << target;
        int index = lastLessThanOrEqualTo(-1, iVec.size()-1, target);
        cout << "\tindex: " << index;
        cout << "\tvalude: ";
        if (index >= 0)
            cout << iVec[index];
        else
            cout << "less than the smallest";
        cout << endl;
    }


    return 0;
}
