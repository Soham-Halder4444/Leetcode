class Trienode{
    public:
    Trienode*children[26];
    char data;
    bool isTerminal;
    Trienode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie {
    public:
    Trienode*root;
    Trie() {
        root=new Trienode('\0');
    }
    void insertuntill(Trienode*root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        Trienode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new Trienode(word[0]);
            root->children[index]=child;
        }
        insertuntill(child,word.substr(1));
    }
    void insert(string word) {
        insertuntill(root,word);
    }
    bool searchuntill(Trienode*root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'a';
        Trienode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchuntill(child,word.substr(1));
    }
    bool search(string word) {
        return searchuntill(root,word);
    }
    bool prefixuntill(Trienode*root,string word){
        if(word.length()==0){
            return true;
        }
        int index=word[0]-'a';
        Trienode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return prefixuntill(child,word.substr(1));
    }
    bool startsWith(string prefix) {
        return prefixuntill(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */