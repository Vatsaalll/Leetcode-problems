class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }

        bool vowel = false;
        bool consonant = false;

        for (char c : word) {
            if (!isalnum(c)) {
                return false;
            }

            if (isalpha(c)) {
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    vowel = true;
                } else {
                    consonant = true;
                }
            }
        }

        return vowel && consonant;
    }
};