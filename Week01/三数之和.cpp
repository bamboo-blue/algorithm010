//暴力法  3个for

//for+双指针
vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) {
        return {};
    }
    
    sort(nums.begin(),nums.end());
    int left;
    int right;
    vector<vector<int>> ans;
    
    
    for (int i = 0; i < nums.size()-2 && nums[i] <= 0; ++i) {
        if (i>0 && nums[i] == nums[i-1]) continue;

        left = i + 1;
        right = nums.size()-1;

        while (left < right ) {//&& nums[right] < 0

            if(nums[left] + nums[right] + nums[i] == 0) {
                //这里的left\right必须变化，不然while里面为!=
                //则left\right永远不变，会导致一直在最外层的while循环里面
				// ans.push_back({nums[i],nums[left],nums[right]});
                // while(left < right && nums[left] == nums[left++]);//等也++ 不等也++
				
                ans.push_back({nums[i],nums[left++],nums[right--]});

                while(left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
				
				
				
                while(left < right && nums[right] == nums[right + 1]) {
                    right--;
                }


            }else if (nums[left] + nums[right] + nums[i] > 0) {
                --right;
            }else if(nums[left] + nums[right] + nums[i] < 0) {
                ++left;
            }

        }
    }
    return ans;
}

