void moveZeroes(vector<int>& nums) {
    //1、额外数组法： 统计0数，非0放入新数组，尾插0
    //2、双指针: 
//    慢指针：过程中需要保证慢指针所指的一定是0，不是0就需要往前走，可以保证非0元素顺序稳定。当快指针找到非0值时则与其交换，
//          慢指针往前走一步，交换后判断慢指针所指的是不是0，不是，则往前走一步，确保非0的元素顺序稳定，此时快指针也走一步，
//          是确保快指针始终领先慢指针至少一步，一个循环走完，再判断快慢指针所指值的情况。 
//    快指针：找非0，只管往前走，走出界说明找不到非0的了，则表示过程结束

    int p1 = 1;
    int p2 = 0;

    while (p1 < nums.size()) {
        if ( nums[p2] == 0 && nums[p1] != 0) {
            swap(nums[p2++],nums[p1]);
        }
        if (nums[p2]!= 0) {
            ++p2;
        } 
        p1++;
    }

    //双指针 ： 错误解法： 没有理清p1、p2的作用
    // int p1 = 1;
    // int p2 = 0;

    // while (p1 < nums.size()) {
    //     if ( nums[p2] == 0 && nums[p1] != 0) {
    //         swap(nums[p2++],nums[p1]);
    //         p1 = p2 + 1;//没必要修改p1
    //     }

    //     if (nums[p2] == 0 && nums[p1] == 0) {
    //         p1++;
    //     }
    //     if (nums[p2]!= 0) {
    //         p1 = (++p2) + 1;
    //     }
    // }
}