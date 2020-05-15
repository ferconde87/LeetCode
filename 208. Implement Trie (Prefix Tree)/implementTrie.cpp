const int ALPHABET_SIZE = 26;

class Trie {
    Trie * letter[ALPHABET_SIZE] = {NULL};
    bool isWord = false;
public:
    /** Initialize your data structure here. */
    Trie() {
    }
    
    Trie * getNode(void) { 
        Trie *pNode =  new Trie(); 
        pNode->isWord = false; 
        for (int i = 0; i < ALPHABET_SIZE; i++) 
            pNode->letter[i] = NULL; 
        return pNode; 
    } 
    
    /** Inserts a word into the trie. */
   	void insert(string word) {
        Trie *pCrawl = this; 
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!pCrawl->letter[index]) 
                pCrawl->letter[index] = getNode(); 
            pCrawl = pCrawl->letter[index]; 
        } 
        // mark last node as leaf 
        pCrawl->isWord = true;
     }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
     	Trie *pCrawl = this; 
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!pCrawl->letter[index]) 
                return false; 
            pCrawl = pCrawl->letter[index]; 
        } 
        return (pCrawl != NULL && pCrawl->isWord);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
   	bool startsWith(string prefix) {
   		Trie *pCrawl = this; 
        for (int i = 0; i < prefix.length(); i++) { 
            int index = prefix[i] - 'a'; 
            if (!pCrawl->letter[index]) 
                return false; 
            pCrawl = pCrawl->letter[index]; 
        } 
        return (pCrawl != NULL);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */ 