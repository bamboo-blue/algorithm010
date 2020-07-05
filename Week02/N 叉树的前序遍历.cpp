//递归

vector<int> dst;
vector<int> preorder(Node* root) {
    if (!root) {
        return dst;
    }
    
    dst.push_back(root->val);
    for (auto &it : root->children) {
        preorder(it);
    }
    return dst;   
}

//迭代
vector<int> preorder(Node* root) {
    if (!root) {
        return {};
    }
    stack<Node*>  stack;  
    stack.push(root);
    vector<int> dst;
    while (!stack.empty()) {
        Node* temp = stack.top();
        stack.pop();       
        dst.push_back(temp->val);
        
        for (int i = temp->children.size() - 1; i>=0 ; --i) {
            stack.push(temp->children[i]);
        }  
    }
   
    return dst;
}