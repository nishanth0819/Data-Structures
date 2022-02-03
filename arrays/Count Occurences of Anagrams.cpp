#Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.
#Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
  
#Input:
Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
  
#CODE:
int search(string pat, string txt) {
	    // code here
	    sort(pat.begin(),pat.end());
	    string g;
	    vector<char> v;
	    int count=0;
	    int n=txt.length();
	    int i=0,j=0;
	    int k=pat.length();
	    while(j<n)
	    {
	        v.push_back(txt[j]);
	        if(j-i+1<k)
	            j++;
	        else if(j-i+1==k)
	        {
	            string g(v.begin(),v.end());
	            sort(g.begin(),g.end())
	            if(g==pat)
	               count++;
	           v.erase(v.begin());
	           i++;
	           j++;
	            
	        }
	    }
	    return count;
	}


#OPTIMIZED-CODE:

	int search(string pat, string txt) {
	    // code here
	   map<char,int> mp1,mp2;
	   for(auto it:pat)
	     mp1[it]++;
	     
	    int i=0,j=0,k=pat.length(),n=txt.size();int count=0;
	    while(j<n)
	    {
	        auto it=mp1.find(txt[j]);
	       if(it!=mp1.end())
	             mp2[txt[j]]++;
	             
	        if(j-i+1<k)
	          j++;
	        else if(j-i+1==k)
	        {
	           
	           
	            if(mp1==mp2)
	              count++;
	           auto it=mp2.find(txt[i]);
	           if(it!=mp2.end())
	                 mp2[txt[i]]--;
	       
	            i++;
	            j++;
	        }
	    }
	    return count;
	}
  
