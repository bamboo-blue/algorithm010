class Solution {
public:
    void rotate(vector<int>& nums, int k) {
	//解法1： 递归，每次旋转最后一位到第一位，其他往后移动一位，终止条件 k < 1
    //解法2：根据索引变化规律来移动,特殊情况： nums.size能够整除k
    if (nums.size() < 1 || k < 1) {
             return ;
    }
    int len = nums.size();
    int count = 1;
    int middle = 0;
    int movValue = 0;
    int i = 0;

    for (int start = 0; count <= nums.size(); ++start) {
        i = start;
        movValue = nums[i];
        do { 
            //1、取出目标索引值
            middle = nums[(i + k) % len];
            //2、将目标索引值替换为移动索引值
            nums[(i + k) % len] = movValue;
            //3、修改i为目标索引
            i = (i + k) % len;
            //4、修改移动索引值
            movValue = middle;
            //5、统计修改次数
            ++count;
        } while (start != i );//终止条件：回到原点
    }
    return ;
    }
};

//解法三：反转
// 假设 n=7n=7 且 k=3k=3 。
// 原始数组                   : 1 2 3 4 5 6 7
// 反转所有数字后             : 7 6 5 4 3 2 1
// 反转前 k 个数字后          : 5 6 7 4 3 2 1
// 反转后 n-k 个数字后        : 5 6 7 1 2 3 4 --> 结果

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
	    k %= nums.length;
		reverse(nums, 0, nums.length - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, nums.length - 1);
	}
		
	void reverse(vector<int> nums, int start, int end) {
		while (start < end) {
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;
			start++;
			end--;
		}
	}
};

