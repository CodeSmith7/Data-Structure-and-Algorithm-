//difference array technique

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int arr[2051] = {0};

        for ( int i = 0; i < logs.size(); i++) {
            int start = logs[i][0];
            int end = logs[i][1] -1;
            arr[start] += 1;
            arr[end +1] -= 1; 
        }

        int cs = 0;
        int maxi = INT_MIN;
        int year = 0;
        for ( int i = 0; i < 2051; i++) {
            cs += arr[i];
            if ( cs > maxi) {
                maxi = cs;
                year = i;
            }
        }

        cout << maxi << endl;

        return year; 
    }
};


//line sweep algo 

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>> events;

        for ( int i = 0; i < logs.size(); i++) {
            events.push_back({logs[i][0], +1});
            events.push_back({logs[i][1], -1});
        }

        sort (begin(events), end(events));

        int currpop = 0, maxpop = INT_MIN, year = 0;

        for ( auto &it : events) {
            currpop += it.second;
            if ( currpop > maxpop) {
                maxpop = currpop;
                year = it.first;
            }
        }


        return year; 
    }
};
