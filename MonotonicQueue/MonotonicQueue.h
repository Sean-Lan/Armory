/**
 *
 * Sean
 * 2016-07-19
 *
 * Monotonic.h
 *
 */
#ifndef MONOTONIC_QUEUE_H
#define MONOTONIC_QUEUE_H

#include <functional>
#include <deque>

template <
    class ValueType,
    class Compare = std::less<ValueType> // default is monotonically increasing
> class MonotonicQueue {
    private:
        std::deque<int> indexQueue;          // records the indexes
        std::deque<ValueType> valueQueue;    // records the corresponding value
        Compare comp;

    public:
        MonotonicQueue(const Compare &comp = Compare()) {
            this->comp = comp;
        }

        void push(int index, ValueType value) {
            // maintain the monotune of valueQueue
            while (!valueQueue.empty() && !comp(valueQueue.back(), value)) {
                indexQueue.pop_back();
                valueQueue.pop_back();
            }
            indexQueue.push_back(index);
            valueQueue.push_back(value);
        }

        void pop() {
            indexQueue.pop_front();
            valueQueue.pop_front();
        }

        ValueType getExtremum() {
            return valueQueue.front();
        }

        int getExtremumIndex() {
            return indexQueue.front();
        }

        int size() {
            return valueQueue.size();
        }

        bool empty() {
            return valueQueue.empty();
        }

        // Just remove all the elements of `indexQueue` and `valueQueue`
        void clear() {
            indexQueue = std::deque<int>();
            valueQueue = std::deque<ValueType>();
        }

};

#endif
