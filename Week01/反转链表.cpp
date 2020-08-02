 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//递归
ListNode* reverseList(ListNode* head) { 
    //terminator
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    //process
    ListNode* temp = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
   
    return temp;
}

//迭代
ListNode* reverseList(ListNode* head) { 
    ListNode* reverseList(ListNode* head) {  
    ListNode* pre = nullptr;
    ListNode*  temp;
    while (head != nullptr){
        temp = head->next;temp存放当前结点的下一个节点的地址
        head->next = pre; //当前结点指向前一个结点
        pre = head; //pre往前走一个结点
        head = temp;   //cur也走到下一个结点，重复上述步骤
    }
    return pre;
    }
}


