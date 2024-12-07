#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* bool compare(pair<int, int> p1, pair<int, int> p2) { //Sorting in descending order on the basis of profit.
    return p1.second > p2.second;
}

int maxProfit(vector<pair<int, int>> jobs) {
    //Step-1 : Sorted the vector on the basis of job price.
    sort(jobs.begin(), jobs.end(), compare);

    int profit = jobs[0].second; //Stored the profit of jobs
    int safeDeadline = jobs[0].first; //The safeDeadline must be greater then the ending deadline of the first job.
    for(int i=1; i<jobs.size(); i++) { //Lopping over each job.
        if(jobs[i].first > safeDeadline) { //Choosing those jobs that have a safedeadline greater then the deadline of the first job. 
            profit += jobs[i].second;
            safeDeadline++;
        }
    }

    return profit;
} */

class Job {
public: 
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> pairs) {
    //Created a vector of jobs -> storing the (idx, deadline, profit) 
    vector<Job> jobs;
    int n = pairs.size();
    for(int i=0; i<n; i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second); //idx deadline profit
    }

    sort(jobs.begin(), jobs.end(), [](Job &obj1, Job &obj2) {
        return obj1.profit > obj2.profit; //Descending order sorting on the basis of profit
    });

    cout<<"Selection Job"<<jobs[0].idx<<endl;
    int profit = jobs[0].profit;
    int safeDeadline = jobs[0].deadline;

    for(int i=1; i<n; i++) {
        if(jobs[i].deadline > safeDeadline) {
            cout<<"Selection Job"<<jobs[i].idx<<endl;
            profit += jobs[i].profit;
            safeDeadline++;
        }
    }

    return profit;
}

int main() {
    vector<pair<int, int>> jobs = {{4, 20}, {1, 10}, {1, 40}, {1, 30}};
    cout<<maxProfit(jobs);
    return 0;
}