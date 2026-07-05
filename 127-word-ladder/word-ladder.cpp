class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_map<string, int> store;
        for (string s : wordList) {
            store[s]++;
        }
        if (store[endWord] != 1)
            return 0;

        queue<string> q1;
        q1.push(beginWord);
        int ans = 0;
        while (!q1.empty()) {
            int n = q1.size();
            ans++;
            for (int k = 0; k < n; k++) {
                string curr = q1.front();
                q1.pop();
                for (int i = 0; i < curr.length(); i++) {
                    string temp = curr; 

                    for (int j = 0; j < 26; j++) {
                        temp[i] = 'a' + j;
                       
                        if (store[temp] == 1) {
                            q1.push(temp);
                            store[temp]++;
                        }
                    }
                }
            }
            if (store[endWord] == 2)
                return ans+1;
        }
        return 0;
    }
};