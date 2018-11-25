class Solution:
    def TwoSum(self, nums, target):
        dict = {}
        # enumerate: traverse both indexes and values
        for index, value in enumerate(nums):
            if value in dict:
                return [dict[value], index]
            dict[target - value] = index


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9
    print(Solution().TwoSum(nums, target))
