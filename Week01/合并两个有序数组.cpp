void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //解法一:双指针从前到后 + 新vector
    //解法二:双指针从后到前
    int p1 = m - 1;
    int p2 = n - 1;
    int p = n + m - 1;
    
    while (p1>=0 && p2 >=0) {
        nums1[p--] = (nums1[p1] < nums2[p2] ? nums2[p2--] : nums1[p1--]);
    }
     
   //下面的步骤有3种写法
   // 1 通过
    while ( p2 >= 0) {
        nums1[p--] = nums2[p2--];
    }
   
    // 2 通过
     while ( p2 >= 0) {
         nums1[p2--] = nums2[p2];
     }
     
     // 3 【报错】
      while ( p2 >= 0) {
          nums1[p2] = nums2[p2--];
      }
}