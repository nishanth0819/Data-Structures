/*Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.*/


//CODE:

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        vector<vector<string>> res;
        queue<vector<string>> q;
        unordered_set<string> visited;
        bool flag=false;
        int k=beginWord.size();
        for(auto it:wordList)
        {
            if(it==endWord)
                flag=true;
            st.insert(it);
        }
        if(!flag)
           return res;
        q.push({beginWord});
        while(q.empty()==false)
        {
            int n=q.size();
            while(n--)
            {
                vector<string> currentpath=q.front();
                q.pop();
                for(int i=0;i<k;i++)
                {
                    string temp=currentpath.back();
                    for(char c='a';c<='z';c++)
                    {
                        temp[i]=c;
                        if(st.find(temp)!=st.end())
                        {
                            vector<string> newpath=currentpath;
                            newpath.push_back(temp);
                            visited.insert(temp);
                            if(temp==endWord)
                                res.push_back(newpath);
                            else
                                q.push(newpath);
                            
                        }
                    }
                }
            }
             for(auto &it:visited)
                    st.erase(it);
                
        }
        return res;
    }
