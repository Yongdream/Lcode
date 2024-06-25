/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res_;
    vector<int> path_;
public:
    void dfs (vector<vector<int>> graph, int x){
        /**
         * graph：存当前的图
         * x：目前遍历的节点
        */
       int graphSize = graph.size();
       if (x == graphSize - 1){
            res_.push_back(path_);
            return;
       }
       for (int i = 0; i < graph[x].size(); ++i)
       {
            path_.push_back(graph[x][i]);
            dfs(graph, graph[x][i]);
            path_.pop_back();   // 回溯
       }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path_.push_back(0); // 无论什么路径已经是从0节点出发
        dfs(graph, 0);      // 开始遍历
        return res_;
    }
};
// @lc code=end

