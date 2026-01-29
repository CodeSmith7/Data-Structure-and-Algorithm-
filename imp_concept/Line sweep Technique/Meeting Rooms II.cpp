class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();
        vector<pair<int,int>> events(n);
        
        for ( int i = 0; i < n;i++) {
            events.push_back ({start[i], 1});
            events.push_back( {end[i], -1});
        }
        
        int maxoverlap = INT_MIN;
        int overlap = 0;
        
        sort( events.begin(), events.end());
        
        for ( int i = 0; i < events.size(); i++) {
            overlap += events[i].second;
            maxoverlap = max ( maxoverlap, overlap);
        }
        
        return maxoverlap;
    }
};
