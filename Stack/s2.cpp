#Nearst Geater Element to Left
#I/P:
g={1,2,3,4}
O/P:{-1,-1,-1,-1} //if nothing is there print -1

#I/P:
g={6,8,0,1,3}
O/P:{-1,-1,8,8,8}

CODE:

vector<long long> find(vector<long long> a,int n)
{
    int flag=0;
    vector<long long> res;
    for(int i=0;i<n;i++)
    {
        flag=0;
        if(i==0)
            res.push_back(-1);
        else
        {
            for(int j=i-1;j>=0;j--)
            {
                if(a[j]>a[i])
                {
                    flag=1;
                    res.push_back(a[j]);
                    break;
                }
            }
            if(flag==0)
              res.push_back(-1);
        }
    }
    return res;
}


#OPTIMIZED-CODE:

vector<long long> find(vector<long long> a,int n)
{
   vector<long long> res;
   stack<long long> s;
   for(int i=0;i<n;i++)
   {
       if(s.empty()==true)
           res.push_back(-1);
        else if(s.top()<=a[i])
        {
            while(s.empty()==false and s.top()<=a[i])
                s.pop();
            if(s.empty()==true)
                res.push_back(-1);
            else
              res.push_back(s.top());
        }
        else
           res.push_back(s.top());
         s.push(a[i]);
   }
   return res;
}
