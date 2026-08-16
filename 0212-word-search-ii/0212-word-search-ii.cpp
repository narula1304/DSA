struct Node { 
    Node* links[26] = {nullptr}; 
    bool flag = false; 
    string word = ""; 
 
    bool containsKey(char ch) { 
        return links[ch-'a'] != nullptr; 
    } 
 
    void put(char ch, Node* node) { 
        links[ch-'a'] = node; 
    } 
 
    Node* get(char ch) { 
        return links[ch-'a']; 
    } 
 
    void setEnd() { 
        flag = true; 
    } 
 
    bool isEnd() { 
        return flag; 
    } 
 
    void setWord(string temp) { 
        word = temp; 
    } 
}; 
 
class Trie { 
private: 
    Node* root; 
 
public: 
    Trie() { 
        root = new Node(); 
    } 
 
    void insert(string word) { 
        Node* node = root; 
        for(auto ch : word) { 
            if(!node->containsKey(ch)) { 
                node->put(ch, new Node()); 
            } 
 
            node = node->get(ch); 
        } 
 
        node->setEnd(); 
        node->setWord(word); 
    }

    Node* getRoot() {
        return root;
    }
}; 
 
class Solution { 
public: 
    vector<string> result; 
    int m, n; 

    void dfs(int i, int j, vector<vector<char>>& board, 
             Node* node, vector<vector<int>>& vis) {

        char ch = board[i][j];

        if(!node->containsKey(ch))
            return;

        node = node->get(ch);

        // Found a complete word
        if(node->isEnd()) {
            result.push_back(node->word);

            // Avoid duplicate answers
            node->flag = false;
        }

        vis[i][j] = 1;

        vector<pair<int,int>> dirn = {
            {-1,0}, {0,1}, {1,0}, {0,-1}
        };

        for(auto [di, dj] : dirn) {
            int ni = i + di;
            int nj = j + dj;

            if(ni >= 0 && ni < m && 
               nj >= 0 && nj < n && 
               !vis[ni][nj]) {

                dfs(ni, nj, board, node, vis);
            }
        }

        vis[i][j] = 0;
    }
 
    vector<string> findWords(vector<vector<char>>& board, 
                             vector<string>& words) { 

        m = board.size(); 
        n = board[0].size(); 
 
        Trie trie; 
 
        for(auto it : words) { 
            trie.insert(it); 
        } 
 
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                dfs(i, j, board, trie.getRoot(), vis);

            }
        }
 
        return result; 
    } 
};