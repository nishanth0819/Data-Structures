//You are given two integer arrays ARR1 and ARR2 of length N and M respectively. You have to return true if ARR2 is a subset of ARR1, otherwise, return false.
//INPUT:
//4
//1 2 4 6
//3
//1 2 6
//O/P:True:
//Here, all the elements of ARR2 are present in ARR1.
//Input:
//5
//9 3 6 5
//3
//1 3 3
//O/P:False
 

//Naive Aprroach:
//This Code will not work for some test cases having duplicate elemnts in arr2 and not in arr1
bool checkSubset(vector < int > & arr1, vector < int > & arr2, int n, int m) {
    int flag=0;
    int m1=arr1.size();
    int n1=arr2.size();
    for(int i=0;i<n1;i++)
    {
        flag=0;
        for(int j=0;j<m1;j++)
        {
            if(arr2[i]==arr1[j])
                flag=1;
        }
        if(flag==0)
            return false;
    }
    return true;
}


//Using maps:
bool checkSubset(vector < int > & arr1, vector < int > & arr2, int n, int m) {
   unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr1[i]]++;
    }
    for(int j=0;j<m;j++)
    {
        if(mp[arr2[j]]>0)
            mp[arr2[j]]--;
        else
           return false;
    }
    return true;
 }
