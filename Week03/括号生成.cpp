//递归
vector<string> ans;

void _generateParenthesis(int left, int right, int n, string str){
   //terminator
   if (left ==n && right == n) {
       ans.push_back(str);
       return ;
   }
        
   //process
   //drill down
   if(left < n) {
       _generateParenthesis(left + 1,right,n,str + "(");
   }
    
   if (left > right) {
       _generateParenthesis(left,right + 1,n,str + ")");
   }  
   //reverse 
}

//深度遍历
void dfs(string str,int left, int right, vector<string>& ans){
    if(left == 0 && right == 0) {
        ans.push_back(str);
        return ;
    }
    
    if(left > right) {
        return ;
    }
    
    if(left > 0){
        dfs(str + "(",left - 1,right,ans);
    }
    
    if(right > 0){
        dfs(str + ")",left,right - 1,ans);
    }
    
}

vector<string> generateParenthesis(int n) {  
   int left = 0;
   int right = 0;
   _generateParenthesis(left,right,n,"");
}



vector<string> generateParenthesis(int n) {  
    vector<string> ans;
    dfs("",n,n,ans);
    return ans;
}