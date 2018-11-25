//
//  main.cpp
//  test
//
//  Created by Shawn on 2018/11/22.
//  Copyright © 2018 Shawn. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//11.22 1 two sum
// search and find all possible valuve, time O(n^2)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> position;
        for(int i = 0; i< nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    position.emplace_back(i);
                    position.emplace_back(j);
                    return position;
                }
            }
        }
        return {-1, -1};
    }
};

// use hash map once, time O(n) space O(n)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++) {
            auto found = record.find(nums[i]);
            if (found != record.end())
                return {found->second, i};
            record.emplace(target - nums[i], i);
        }
        return {-1, -1};
    }
};

// use hash map once, time O(n) space O(n)
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++) {
            if (record.count(nums[i]))
                return {record[nums[i]], i};
            else
                record.emplace(target - nums[i], i);
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> res, nums = {2, 7, 11, 15};
    int target = 9;
//    Solution1 sol;
    Solution2 sol;
//    Solution3 sol;

    res = sol.twoSum(nums, target);
    for (int i = 0; i < res.size(); i+=2) {
        cout<<"["<<res[i]<<", "<<res[i+1]<<"]";
    }
    cout << endl;

    return 0;
}
