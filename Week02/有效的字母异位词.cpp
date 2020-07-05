bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    
    //1、暴力破解
//    sort(s.begin(),s.end());
//    sort(t.begin(),t.end());
    
//    for (int i = 0; i < s.size(); ++i) {
//       if(s[i] != t[i]) {
//           return false;
//       } 
//    }
//    return true;
    
    //2、数组  两边遍历
//    int array[26] = {0};
//    for (auto &it : s) {
//        array[it - 'a'] += 1;
//    }
    
//    for (auto &it : t) {
//        array[it - 'a'] -= 1; 
//    }
    
//    for (auto &it : array) {
//        if (it) {
//            return false;
//        } 
//    }
//    return true;

    //2、数组  一边遍历
    int array[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
        array[s[i] - 'a'] += 1;
        array[t[i] - 'a'] -= 1; 
    }
     
    for (auto &it : array) {
        if (it) {
            return false;
        } 
    }
    return true;  
}