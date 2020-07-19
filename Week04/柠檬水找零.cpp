bool lemonadeChange(vector<int>& bills) {
    //贪心算法：优先使用10元的
    unordered_map<int,int> map;
    for (auto it : bills) {
        if (it == 5) {
            map[5]++;
        }
        if (it == 10) {
            map[10]++;
            map[5]--;
        }   
        if (it == 20) {
            //有10元和没有10元
            if (map[10] > 0) {
                map[10]--;
                map[5]--;
            } else {
                map[5] -=3;
            } 
        }      
        if (map[5] < 0) {
            return 0;
        }
    }  
    return 1;  

//上面使用了map导致查询效率低了，这里使用int表示对应的币值数量
	// int five = 0, ten = 0;
	// for (int bill: bills) {
		// if (bill == 5)
			// five++;
		// else if (bill == 10) {
			// if (five == 0) return false;
			// five--;
			// ten++;
		// } else {
			// if (five > 0 && ten > 0) {
				// five--;
				// ten--;
			// } else if (five >= 3) {
				// five -= 3;
			// } else {
				// return false;
			// }
		// }
	// }

	// return true;
    
}




