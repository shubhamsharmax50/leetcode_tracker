// Last updated: 16/1/2026, 8:58:06 pm
class Solution {
public:
    bool isDistinct(vector<int>& nums){
        unordered_set<int>seen;
        for(int i : nums){
            if(seen.count(i)){
                return false ;
            }
            seen.insert(i);
        }
        return true ;
    }
void removeElements(vector<int>& nums){
    if(nums.size()<=3){
        nums.clear();
        
    }else{
        nums.erase(nums.begin(),nums.begin()+3);
    }
}
    int minimumOperations(vector<int>& nums) {
      int operations=0;
        while(!nums.empty() && !isDistinct(nums))
            {
                removeElements(nums);
                operations++;
            }
        return operations;
        
    }
};