#include <bits/stdc++.h> 

struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;

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
        }

        node->setEnd();
    }

    bool checkIfPrefixExist(string word){
        Node* node = root;

        for(char ch : word){
            if(node->containsKey(ch)){
                node = node->get(ch);
                if(node->isEnd() == false) return false;
            }

            else return false;
        }

        return true;
    }
};


class Solution {
public:
    string longestWord(vector<string>& a) {
         Trie trie;

    for(int i=0;i<a.size();i++){
        string word = a[i];
        trie.insert(word);
    }

    string longest = "";

    for(int i=0;i<a.size();i++){
        string word = a[i];
        if(trie.checkIfPrefixExist(word)){
            if(word.length() > longest.length()){
                longest = word;
            }else if(word.length() == longest.length() && word < longest){
                longest = word;
            }
        }
    }


    if(longest == "") return "";

    return longest;
    }
};