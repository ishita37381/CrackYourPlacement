// User function Template for C++

class Solution{
public:
class TrieNode{
    public:
    TrieNode* children[26];
    bool is_leaf;
    TrieNode(){
        is_leaf=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Trie{
    public:
    TrieNode*root;
    Trie()
{
    root=new TrieNode();
    
}
    void insert(string word)
        {
            TrieNode *node=root;
            
            for(char c:word)
            {
                int index=c-'a';
                
                if(node->children[index]==NULL)
                {
                    node->children[index]=new TrieNode();
                    node=node->children[index];
                }
                
                else
                node=node->children[index];
            }
            
            node->is_leaf=true;
        }

void find(string prefix,TrieNode* node,vector<string>&contact){
    if(node->is_leaf)contact.push_back(prefix);
    for(char c='a';c<='z';c++){
        int index=c-'a';
        if(node->children[index]){
            find(prefix+c,node->children[index],contact);
        }
    }
}
vector<string>search(string prefix){
    TrieNode* node=root;
    for(char c:prefix){
        int index=c-'a';
        if(node->children[index]==NULL)return{"0"};
        node=node->children[index];
    }
    vector<string>contact;
    find(prefix,node,contact);
    return contact;
}
};
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie t;
        for(int i=0;i<n;i++)t.insert(contact[i]);
        vector<vector<string>>res;
        string prefix="";
        for(int i=0;i<s.size();i++){
            prefix+=s[i];
            vector<string>contact=t.search(prefix);
            res.push_back(contact);
        }
        return res;
    }
};
