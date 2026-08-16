struct Node {
    Node* links[26] = {nullptr};
    vector<string> words;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void addWord(string word) {
        words.push_back(word);
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

        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }

            node = node->get(ch);

            // Add only if this key is not already present
            if(find(node->words.begin(), node->words.end(), word)
                == node->words.end()) {
                node->addWord(word);
            }
        }
    }

    vector<string> findwords(string word) {
        Node* node = root;

        for(char ch : word) {
            if(node->containsKey(ch)) {
                node = node->get(ch);
            }
            else {
                return {};
            }
        }

        return node->words;
    }
};

class MapSum {
public:
    Trie trie;
    unordered_map<string, int> mpp;

    MapSum() {
    }

    void insert(string key, int val) {
        trie.insert(key);
        mpp[key] = val;
    }

    int sum(string prefix) {
        vector<string> temp = trie.findwords(prefix);

        int ans = 0;

        for(auto it : temp) {
            ans += mpp[it];
        }

        return ans;
    }
};