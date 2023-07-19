// fibonnachi using dp.
#include <bits/stdc++.h>
using namespace std;
/*
int f(int n, vector<int>&dp){
    if(n<=1)return n;
    if(dp[n] != -1)return dp[n];
    return dp[n]=f(n-1,dp)+f(n-2,dp);
}
t.c-> O(n)
s.c-> O(n)
this is recurtion to memoization.
*/
/*
int f(int n,vector<int>&dp){
    //base case
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
t.c-> O(n)
s.c-> O(n)
this is recurtion to tabulation.

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<f(n,dp);
return 0;
*/
int main()
{
    int n;
    cin >> n;
    if (n <= 1)
        cout << n;
    else
    {
        int pre2 = 0;
        int pre = 1;

        for (int i = 2; i <= n; i++)
        {
            int curr = pre + pre2;
            pre2 = pre;
            pre = curr;
        }
    cout << pre;
    }
    return 0;
}
//this is the space optimization one t.c-> O(n) s.c-> O(1)