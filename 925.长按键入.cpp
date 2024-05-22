/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (typed.size() < name.size()) return false;
        int nameLen = name.size(), typedLen = typed.size();
        int i = 0, j = 0;

        while (i < nameLen || j < typedLen) {
            if (name[i] == typed[j] ) {
                ++i;
                ++j;
            }
            else if (j > 0 && name[i - 1] == typed[j]) {
                ++j;
            }
            else
            {
                return false;
            }
           
        }
        return true;
        
    }
};
// @lc code=end

