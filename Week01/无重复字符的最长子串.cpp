//超时
int lengthOfLongestSubstring(string s) {
    
    if (s.size() == 0 || s.size() == 1) {
        return s.size();
    }
    
    set<char> set;
    map<char,int> map;
    int left = 0;
    int right = 0;
    
    int max = 0;
    for ( ; right < s.size();) {
        //没有重复的，就放set
        if(set.find(s[right]) == set.end()) {
            set.insert(s[right]);
            map[s[right]] = right;
            right++;
        } else {
            //存在重复的，则先设置max值
            
            max = max > set.size() ? max : set.size();
            left = map[s[right]] + 1;
            map[s[right]] = right;
            set.clear();
            right = left;
        }
    }
    
    return  max > set.size() ? max : set.size();
}


//双指针
int lengthOfLongestSubstring(string s) {
	vector<int> m(128, 0);
	int ans = 0;
	int left = 0;
	for (int right = 0; right < s.size(); right++) {
		left = max(left, m[s[right]]);//如果是新的，则m[s[right]]==0，左指针仍不变
		m[s[right]] = right + 1;  //+1是为了区分原来vector的0
		ans = max(ans, right - left + 1);
	}
	return ans;
}



