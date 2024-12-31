class Solution {
public:
    //******nvdpsaluja******//

    //Time Complexity-> O(maxDay) 
    //Space Complexity -> O(maxDay)
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();

        // maxDay denotes the maximum day upto which we have to find the cost
        int maxDay=days[n-1];

        // the dp array stores the minimum cost of each day -> till maxDay
        // i.e dp[i] is the minimum cost on day i
        vector<int> dp(maxDay+1,0);

        // set st stores all the days which were present in my days array
        unordered_set<int> st(days.begin(),days.end());

        for(int i=1;i<=maxDay;i++){
            // if the day i was not present in my days array then the minimum cost for that day will be equal to its previous
            if(st.find(i)==st.end()){
                dp[i]=dp[i-1];
                continue;
            }
            // calculate the cost for all possible 3 steps
            int step1=costs[0]+dp[max(0,i-1)];
            int step2=costs[1]+dp[max(0,i-7)];
            int step3=costs[2]+dp[max(0,i-30)];
            // the minimum cost for that day will be minimum of all three steps
            dp[i]=min({step1,step2,step3});
        }
        // return the minimum cost which was achieved at maxDay
        return dp[maxDay];
    }
};