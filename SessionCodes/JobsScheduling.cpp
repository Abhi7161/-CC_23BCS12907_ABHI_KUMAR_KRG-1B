/**
 * give a set of n jobs where each job has a deadline and profit associated with it . ans each job take 1 unit of We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X. 
 * 
 */

 #include<bits/stdc++.h>
 using namespace std;
 struct Jobs
 {
    int id;
    int deadline;
    int profit;
 };
 void jobScheduling(vector<Jobs> &v)
 {
    int cnt=0;
    int totalProfit=0;
    auto cmp = [](const Jobs &a, const Jobs &b) { return a.profit < b.profit; };
    priority_queue<Jobs, vector<Jobs>, decltype(cmp)> pq(cmp);
    for(int i=0;i<v.size();i++)
    {
        pq.push(v[i]);
    }
    vector<int> hash(v.size(),0);
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        for(int i=it.deadline;i>=0;i--)
        {
            if(hash[i]==0)
            {
                cnt++;
                totalProfit+=it.profit;
                hash[i]=1;
                break;
            }
        }
    }
    cout<<totalProfit<<endl;
 }
 int main()
 {
    int n;
    cin>>n;
    vector<Jobs> v1(n);
 }