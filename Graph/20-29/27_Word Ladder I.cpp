// LINK: https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder
// Notes: https://takeuforward.org/graph/word-ladder-i-g-29/

// TC: O(N * logN * wordLength * 26)
// SC: O(N) + O(N)
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        
        set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        
        while(!q.empty()) {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(word == targetWord) return level;
            // traverse through the word and check for all possibilities
            for(int i = 0; i < word.size(); i++) {
                string original = word;
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        // if modified word exixts in the set
                        q.push({word, level+1});
                        st.erase(word);
                    }
                }
                word = original;
            }
        }
        return 0;
    }
};
