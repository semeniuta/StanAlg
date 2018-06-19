#ifndef TWOSUM_H
#define TWOSUM_H

#include <vector>
#include <set>
#include <unordered_map>

template <typename T>
class TwoSum {

public:

    TwoSum() = delete;

    explicit TwoSum(const std::vector<T>& data) {

        for (const auto& x : data) {
            data_set[x] = true;
        }
    }

    std::vector<std::pair<T, T>> check(T sum) {

        std::vector<std::pair<T, T>> pairs;
        std::set<T> accounted_numbers;
        T y;

        for (const auto& entry : data_set) {

            T x = entry.first;
            y = sum - x;

            bool y_in_set = (data_set.find(y) != data_set.end());
            bool x_accounted = (accounted_numbers.find(x) != accounted_numbers.end());

            if (y_in_set && x != y && !x_accounted) {

                pairs.push_back({x, y});
                accounted_numbers.insert(y);
            }
        }

        return pairs;

    };


private:

    std::unordered_map<T, bool> data_set;


};


#endif
