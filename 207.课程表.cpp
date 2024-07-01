/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        // prerequisites: [入度][出度]
        // prerequisites[i][0] <--- prerequisites[i][1]

        unordered_map<int, vector<int>> umap; // 

        // 初始化入度数量 和 出度选择
        for (int i = 0; i < prerequisites.size(); ++i)  
        // 注意这里不选择numCourses prerequisites中会包含课程信息
        {
            inDegree[prerequisites[i][0]]++;    // 保存有几个先修课程（入度
            umap[prerequisites[i][1]].push_back(prerequisites[i][0]); // 保存后续修课选中（出度
        }

        queue<int> que;
        for (int i = 0; i < numCourses; ++i)
        {
            if (inDegree[i] == 0) que.push(i);  // 入度初始条件：不需要先修课程
        }

        int count = 0;
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();
            count++;

            vector<int> courses = umap[cur];    // 后修课程
            if (!courses.empty()){
                for (int i = 0; i < courses.size(); ++i)
                {
                    inDegree[courses[i]]--;
                    if (inDegree[courses[i]] == 0) que.push(courses[i]);
                }
            }
        }
        if (count == numCourses) return true;
        return false;
    }
};
// @lc code=end

