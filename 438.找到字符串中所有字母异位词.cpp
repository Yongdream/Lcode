/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size()) return res;

        unordered_map<char, int> pCount;
        unordered_map<char, int> swinCount;
        int winLen = p.size();

        for (char c : p){
            pCount[c]++;
            // cout << c << ": " << pCount[c] << endl;
        }

        for (int right = 0; right < s.size(); ++right){
            int  same = 1;

            if (right >= winLen){
                swinCount[s[right-winLen]]--;
            }
            swinCount[s[right]]++;
            for (const auto& pair : pCount) {
                auto it = swinCount.find(pair.first);
                if (it == swinCount.end() || it->second != pair.second) {
                    same = 0;
                }
            }
            
            // if (right >= winLen){
            // // cout << s[right-2] << ": " << swinCount[s[right-2]]
            // // << swinCount[s[right-1]]
            // // << swinCount[s[right]] << '\n'<< endl;
            // }

            if (same){
                res.push_back(right-winLen+1);
            }
        }
        return res;

    }
};
// @lc code=end

