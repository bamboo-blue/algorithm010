//暴力破解
//两个for循环


//双指针
int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxValue = 0;
    int temp;
    
    while (left != right) {
        temp = (right - left) * min(height[left],height[right]);
        maxValue = max(temp,maxValue);
        height[left] > height[right] ? right-- : left++;
    }

    return maxValue;
}