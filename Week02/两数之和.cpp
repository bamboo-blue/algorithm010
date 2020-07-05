vector<int> twoSum(vector<int>& nums, int target) {
    //1、暴力法
//    vector<int> dst;
//    for (int i = 0; i < nums.size() - 1; i++) {
//        for (int j = i+1; j < nums.size(); j++) {
//            if ( nums[i] + nums[j] == target ) {
//                dst.push_back(i);
//                dst.push_back(j);
//                break;
//            }
//        }
//    }
//    return dst;
    
    //2、首先想到了双指针，但由于数组不是有序的，所以需要排序
    //但排序之前需要记录下标与值得对应关系，所以再开一个数组
    //用map不行，因为考虑到重复的情况
//    int left = 0;
//    int right = nums.size() - 1;
//    vector<int> temp = nums;
//    vector<int> dst;  
    
//    sort(temp.begin(),temp.end());
    
//    while (left < right) {
//        if (temp[left] + temp[right] > target) {
//            right--;
//        } 
        
//        if (temp[left] + temp[right] < target) {
//            left++;
//        } 
        
//        if (temp[left] + temp[right] == target) {
//            break;
//        } 
//    }
    
//    //这里跳出来区分left == right（没找到） 、left < right（找到）
//    if (left < right) {
//        //根据值去找nums中对应的值的下标
//        for (int i = 0; i < nums.size(); i++) {
//            if (left >= 0 && nums[i] == temp[left]) {
//                dst.push_back(i);
//                left = -1;//修改left的值可以排除索引为left值==>解决重复 
//            }else if (right >= 0 && nums[i] == temp[right]) {
//                dst.push_back(i);
//                right = -1;  
//            }
            
//            if (left == right) {
//                return dst;
//            } 
//        }   
//    }
//    return dst;
    //3、hash表法
    // nums[i]  + nums[j] = target
    //即数组中存在一个值target - nums[i]；
    unordered_map<int,int> map;
    vector<int> dst;
    for (int i = 0; i < nums.size(); i++) {
        if (map.find(target - nums[i]) != map.end()) {
            return {i,map[target - nums[i]]};
        }
        map[nums[i]] = i;
    }
    return {};
}