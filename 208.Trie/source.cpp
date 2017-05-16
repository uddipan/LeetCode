class TrieNode {
public:
    map<char, TrieNode*>M;
    bool isWord;
    
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        if(word.empty())return ;
        TrieNode *T = root;
        for(auto i=0; i<word.size(); i++)
        {
            if(T->M.find(word[i]) ==T->M.end())
            {
                T->M[word[i]] = new TrieNode();
            }
            T = T->M[word[i]];
        }
        T->isWord = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        if(word.empty())return false;
        TrieNode *T = root;
        for(auto i=0; i<word.size(); i++)
        {
            if(T->M.find(word[i]) ==T-> M.end())
            {
                return false;
            }
            T = T->M[word[i]];
        }
        return(T->isWord);
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(prefix.empty())return false;
        TrieNode *T = root;
        for(auto i=0; i<prefix.size(); i++)
        {
            if(T->M.find(prefix[i]) ==T-> M.end())
            {
                return false;
            }
            T = T->M[prefix[i]];
        }
        return true;
    }
    
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");