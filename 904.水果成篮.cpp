/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int edge = 0, right = 0, res = 0;

        while(right < fruits.size())
        {
            basket[fruits[right]]++;

            while(basket.size() > 2){
                // 向前推 
                // 减数/调size/前推
                basket[fruits[edge]]--;
                if (basket[fruits[edge]] == 0) {
                    basket.erase(fruits[edge]);
                }
                edge++;
            }
        res = max(res, right - edge + 1);
        right++;
        }
        return res;
    }
};
// @lc code=end

