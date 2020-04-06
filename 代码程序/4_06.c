class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;

        struct ListNode* n0 = NULL;
        struct ListNode* n1 = pHead;
        struct ListNode* n2 = n1->next;
        while (n2 != NULL)
        {
            //如果相邻节点不相同，则不需要删除，更新节点，继续向后遍历
            if (n1->val != n2->val)
            {
                n0 = n1;
                n1 = n2;
                n2 = n2->next;
            }
            else
            {
                //如果相邻节点相同
                //则n2去找第一个不相同的节点
                while (n2 && n2->val == n1->val)
                {
                    n2 = n2->next;
                }
                //重新链接，如果要删除的包括头节点，则更新头节点
                if (n0)
                    n0->next = n2;
                else
                    pHead = n2;

                // 删除掉重复的节点
                while (n1 != n2)
                {
                    struct ListNode* next = n1->next;
                    free(n1);
                    n1 = next;
                }
                //更新节点
                n1 = n2;
                if (n2)
                    n2 = n2->next;
            }
        }

        return pHead;
    }
};




struct ListNode* hasCycle(struct ListNode* head) {
    struct ListNode* fast, * slow;
    fast = slow = head;
    if (head == NULL)
        return NULL;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* cur, * fast, * slow;
    fast = slow = head;
    cur = hasCycle(head);
    if (cur)
    {
        while (cur != head)
        {
            cur = cur->next;
            head = head->next;
        }
        return cur;
    }
    return NULL;

}



bool hasCycle(struct ListNode* head) {
    struct ListNode* fast, * slow;
    fast = slow = head;
    if (head == NULL)
        return false;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}


