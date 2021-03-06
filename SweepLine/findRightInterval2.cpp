/**
 *
 * Sean
 * 2016-12-17
 *
 * https://leetcode.com/problems/find-right-interval/
 *
 * Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.
 *
 * For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.
 *
 * Note:
 * You may assume the interval's end point is always bigger than its start point.
 * You may assume none of these intervals have the same start point.
 * Example 1:
 * Input: [ [1,2] ]
 *
 * Output: [-1]
 *
 * Explanation: There is only one interval in the collection, so it outputs -1.
 * Example 2:
 * Input: [ [3,4], [2,3], [1,2] ]
 *
 * Output: [-1, 0, 1]
 *
 * Explanation: There is no satisfied "right" interval for [3,4].
 * For [2,3], the interval [3,4] has minimum-"right" start point;
 * For [1,2], the interval [2,3] has minimum-"right" start point.
 * Example 3:
 * Input: [ [1,4], [2,3], [3,4] ]
 *
 * Output: [-1, 2, -1]
 *
 * Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
 * For [2,3], the interval [3,4] has minimum-"right" start point.
 *
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct Event {
    int index;
    int timestamp;
    bool isStart;
    Event(int index, int timestamp, bool isStart): index(index), timestamp(timestamp), isStart(isStart) {}
    bool operator< (const Event& e) const {
        if (timestamp != e.timestamp) return timestamp < e.timestamp;
        return !isStart; // let end event be first
    }
};

// event based sweep line algorithm
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        auto cmp = [&intervals] (int i, int j) {
            return intervals[i].start < intervals[j].start;
        };
        set<int, decltype(cmp)> notStartIndexes(cmp); // sort according to the start time of intervals
        vector<Event> events;
        int n = intervals.size();
        vector<int> result(n, -1);
        for (int i=0; i<n; ++i) {
            notStartIndexes.insert(i);
            events.emplace_back(i, intervals[i].start, true);
            events.emplace_back(i, intervals[i].end, false);
        }
        sort(events.begin(), events.end());
        for (auto &e : events) {
            if (e.isStart) {
                notStartIndexes.erase(e.index);
            } else { // end event
                if (!notStartIndexes.empty()) { // find the earliest start event
                    result[e.index] = *notStartIndexes.begin();
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
