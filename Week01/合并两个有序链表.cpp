ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //解法一
//    //创建新头结点
//    ListNode* l3 = new ListNode() ;
//    ListNode* head = l3;
//    //比较两个链表头结点
//    while (l1 && l2) {
//        if (l1->val <= l2->val) {
//            head->next = l1;
//            l1 = l1->next;
//        } else {
//            head->next = l2;
//            l2 = l2->next;
//        }  
//        head = head->next;    
//    }

//    head->next = (l1 ? l1 : l2); 
//    return l3->next;
      //解法二 递归
//    递归函数必须要有终止条件，否则会出错；
//    递归函数先不断调用自身，直到遇到终止条件后进行回溯，最终返回答案。
    if ( l1 == nullptr) {
        return l2;
    }
    if ( l2 == nullptr) {
        return l1;
    }
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }
    
    l2->next = mergeTwoLists(l1,l2->next);
    return l2;
  
}