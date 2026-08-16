struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;
    vector<string> suggestions;

    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void addWord(string word){
        suggestions.push_back(word);
    }

    int size(){
        return suggestions.size();
    }
};

class Trie {
    private : Node* root;

    public: Trie(){
        root = new Node();
    }
    public :

    void insert(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node = node->get(ch);
            if(node->size() < 3) node->suggestions.push_back(word);
        }

        node->setEnd();
    }

    vector<string> traverse(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return {};
            }
            node = node->get(ch);
        }

        return node->suggestions;
    }
    
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        Trie trie;

        for(int i=0;i<products.size();i++){
            trie.insert(products[i]);
        }

        string s = "";
        vector<vector<string>> ans;

        for(int i=0;i<searchWord.size();i++){
            s += searchWord[i];
            vector<string> temp = trie.traverse(s);
            ans.push_back(temp);
        }

        return ans;
    }
};