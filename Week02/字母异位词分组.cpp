//暴力破解，超时
bool isSame(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

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

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if (strs.size() < 1) {
        return {{strs[0]}};
    }


    vector<vector<string>> dst;
    vector<string> temp;
    temp.push_back(strs[0]);
    cout << "push:" << strs[0] << endl;
    dst.push_back(temp);
    temp.clear();
    bool isFind = false;

    for (int i = 1; i < strs.size(); ++i) {
        for (int j = 0; j < dst.size(); ++j) {
            if (isAnagram(dst[j][0],strs[i])) {
                dst[j].push_back(strs[i]);
                isFind = true;
                break;
            }
        }

        if (!isFind) {
            temp.push_back(strs[i]);
            dst.push_back(temp);
            isFind = false;
            temp.clear();
        }

        isFind = false;
    }
    return dst;
}

//hash映射
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for(auto s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            hashmap[temp].push_back(s);
        }
        int len = hashmap.size();
        vector<vector<string>> ans(len);
        int index = 0;
        for(auto i : hashmap){
            ans[index] = i.second;
            ++ index;
        }
        return ans;
    }