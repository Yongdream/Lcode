/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start

class TrieNode {			// 最标准写法
public:
    bool isWord;
    std::unordered_map<char, TrieNode*> children;

    TrieNode() :
        isWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();  // 构造字典树，就是先构造出一个空的根节点
    }


    //【向字典树插入单词word】
    // 思路：按照word的字符，从根节点开始，一直向下走：
    //          如果遇到null，就new出新节点；如果节点已经存在，cur顺着往下走就可以
    void insert(const string& word) {
        TrieNode* node = root;  // 先指向根节点

        for (char ch : word)
        {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];  // 单字母插入完成 node改变指向字母结尾
        }
        node->isWord = true;    // 完整字母获得isWord=True                    
    }


    //【判断一个单词word是否完整存在于字典树中】
    // 思路：node从根节点开始，按照word的字符一直尝试向下走：
    //  如果走到了null，说明这个word不是前缀树的任何一条路径，返回false;
    //  如果按照word顺利的走完，就要判断此时cur是否为单词尾端：
    //      如果是，返回true
    //      如果不是，说明word仅仅是一个前缀，并不完整，返回false
    bool search(const string& word) {
        TrieNode* node = root;  // 先指向根节点
        for (char ch : word)
        {
            if (!node->children.count(ch)) return false; // 走到了null
            node = node->children[ch];
        }
        return node->isWord;
    }


    //【判断一个单词word是否是字典树中的前缀】
    // 思路：和sesrch方法一样，根据word从根节点开始一直尝试向下走：
    //          如果遇到null了，说明这个word不是前缀树的任何一条路径，返回false;
    //          如果安全走完了，直接返回true就行了———我们并不关心此事cur是不是末尾(isWord)
    bool startsWith(const string& word) {
        TrieNode* node = root;  // 先指向根节点
        for (char ch : word)
        {
            if (!node->children.count(ch)) return false; // 走到了null
                node = node->children[ch];
        }
        return true;        
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

