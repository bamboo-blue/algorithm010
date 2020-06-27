class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    //1、快慢指针，快的找重复，慢的定位第一个重复值并修改值
    if ( nums.size() < 2) {
        return nums.size();
    }
       
    int fast = 1;
    int slow = 0;
    while(1){
        if(nums[fast] == nums[slow]){
            ++fast;
        } else {
            nums[++slow] = nums[fast++];
        }
        if (fast >= nums.size()) {
            return  ++slow; 
        }  
    }
    }
};