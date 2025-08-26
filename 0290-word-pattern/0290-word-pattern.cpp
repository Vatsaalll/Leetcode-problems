class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        if (words.size() != pattern.size()) {
            return false;
        }
        
        unordered_map<char, int> charToIndex;
        unordered_map<string, int> wordToIndex;
        
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            if (charToIndex.find(c) == charToIndex.end()) {
                charToIndex[c] = i;
            }
            if (wordToIndex.find(w) == wordToIndex.end()) {
                wordToIndex[w] = i;
            }
            
            if (charToIndex[c] != wordToIndex[w]) {
                return false;
            }
        }
        
        return true;
    }
};