学习笔记
本周学习主要是深刻理解了DFS和BFS的区别

使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
个人理解思路：
第一次：[4, 5, 6, 7, 0, 1, 2]
找到中间值mid，判断mid与left、right值的关系
left < mid && mid > right  : 左边递增，右边乱序，在右边找

第二次：[7, 0, 1, 2]
找到中间值mid，判断mid与left、right值的关系
left > mid && mid < right  : 右边递增，左边乱序，在左边找

第三次：[7, 0]
找到中间值mid，判断mid与left、right值的关系
left == mid && mid > right  : 左边递增，右边乱序，在右边找

第四次：[0]


