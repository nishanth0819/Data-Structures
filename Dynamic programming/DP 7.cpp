#Ninja is planing this ‘N’ days-long training schedule. 
#Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). #
Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. #
Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. 
#Your task is to calculate the maximum number of merit points that Ninja can earn.
#I/P:

2
10 50 1
5 100 11
#O/P:
110

#I/P:
3
18 11 19
4 13 7
1 8 13
#o/p
45

#RECURSIVE CODE:

int find(int day,int last,vector<vector<int>> &points)
{
    int maxi=0;
    if(day==0)
    {
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                maxi=max(points[0][i],maxi);
            }
        }
        return maxi;
    }
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point=points[day][task]+find(day-1,task,points);
            maxi=max(maxi,point);
        }
    }
    return maxi;
 }
int ninjaTraining(int n, vector<vector<int>> &points)
{
    return find(n-1,3,points);
}


#BOTTOM-UP CODE:

int find(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp)
{
    int maxi=0;
    if(day==0)
    {
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                maxi=max(points[0][i],maxi);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1)
        return dp[day][last];
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point=points[day][task]+find(day-1,task,points,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
 }
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>  dp(n,vector<int>(4,-1));
    return find(n-1,3,points,dp);
}

