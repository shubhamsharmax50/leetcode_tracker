// Last updated: 26/2/2026, 9:12:18 pm
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n =names.size();
        vector<pair<int,string>> vec(n);
        for(int i =0;i<n;i++){
            vec[i]=make_pair(heights[i],names[i]);
        }
        sort(rbegin(vec),rend(vec));
        for(int i=0;i<n;i++){
            names[i]=vec[i].second;
        }
        return names;
    }
};