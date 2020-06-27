vector<int> plusOne(vector<int>& digits) {
    //1、进位法-递归：先推到底，再回溯   
    //索引： 0 1 2 3 4
    //进位*10： (size()- 1 - i) * 10   
    //这里没有产生递归，只是处理最一般的情况比如  128
    if (digits.back() >= 0 && digits.back() <= 8) {
        digits.back()++;
        return digits;
    }
    
    //产生递归
    if (digits.back() == 9) {
        //删除最后一位
        digits.pop_back();
        
        //递归推到底，判断终止条件    9 > 10 : 先删除9，再尾补1、0，最后返回
        if(digits.size() == 0){
            digits.push_back(1);
            digits.push_back(0);
            return digits;
        }
        
        //没有推到底则继续递归
        plusOne(digits);
    }
    
    //补上最开始删除的第一个9的0
    digits.push_back(0);
    return digits;
    
    //2、字符串与整数互相转换:  错误解法
//    vector<int> dst;
//    string str;
//    for (auto & it : digits) {
//        str.append(std::to_string(it));
//    }

//    int temp = std::atoi(str.c_str()) + 1;// 当str.c_str() > INT_MAX时,atoi会导致整数溢出

//    str.clear();
//    str = std::to_string(temp);

//    stringstream ss;
//    int a;
//    ss<<str;
//    for (int i = 0;i < str.size();i++) {
//        ss<<str.at(i);
//        ss>>a;
//        dst.push_back(a);//这种方式能防止越界
//        ss.clear();
//    }
//    return dst;
    
//    for (int i = 0;i < str.size();i++) {
//        char ch = str.at(i);
//        int a = std::atoi(&ch);//这种方式力扣会报栈越界访问
//        dst.push_back(a);
//    }
//    return dst;  
}
