//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
      vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end()); // stores the words from wordList to make deletion easier
        queue<vector<string>> q; // stores sequence of words to reach the endWord
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;

        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();
            // if the size of the vec vector is greater than the current level. If it is, it means that a new level has been reached.
            // Therefore, the level is incremented, and the words used in the previous levels are erased from the set st.
            if (vec.size() > level) {
                level++;
                for (auto it : usedOnLevel) {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = vec.back();
            // If word is equal to endWord, it means the target word has been reached.
            // If ans is empty, the vec vector is added to ans.
            // Otherwise, if the size of ans[0] is equal to the size of vec, it means that the current sequence has the same length
            // as the sequences in ans, so it is added to ans as well.
            if (word == endWord) {
                if (ans.empty()) {
                    ans.push_back(vec);
                } else if (ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
            }
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word) > 0) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends