struct Node {
    Node* links[26] = {nullptr};
    bool flag  = false;
    string word = "";

    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }


    bool isEnd(){
        return flag;
    }

    void setWord(string temp){
        word = temp;
    }
};

class Trie {
    private : Node* root;

    public : Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(auto ch : word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }

            node = node->get(ch);
        }

        node->setEnd();
        node->setWord(word);
    }

    string findIfExist(string word){
        Node* node = root;
        for(auto ch : word){
            if(node->containsKey(ch)){
                node = node->get(ch);
                if(node->isEnd() == true) return node->word; 
            }else{
                return "";
            }
        }
        return "";
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;

        for(auto it : dictionary){
            trie.insert(it);
        }

        string ans = "";

        stringstream ss(sentence);
        string str;

        while(ss >> str){
            string temp = trie.findIfExist(str);
            if(temp == "") ans += str;
            else ans += temp;

            ans += " ";
        }
        ans.pop_back();
        
        return ans;
    }
};