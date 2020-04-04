//1.合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* newh, * newt;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    //1.方法一：需要判断头节点
    /*if (l1->val <= l2->val)
    {
        newh = newt = l1;
        l1 = l1->next;
    }
    else
    {
        newh = newt = l2;
        l2 = l2->next;

    }*/

    //方法2：创建一个头节点
    newh = newt = (struct ListNode*)malloc(sizeof(struct ListNode));

    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            newt->next = l1;
            l1 = l1->next;

        }
        else
        {
            newt->next = l2;
            l2 = l2->next;
        }
        newt = newt->next;
    }
    if (l1)
    {
        newt->next = l1;
    }
    if (l2)
    {
        newt->next = l2;
    }
    //return newh;
    return newh->next;

}

//判断回文链表
bool chkPalindrome(ListNode* A) {
    // write code here
    struct ListNode* prve, * next, * cur, * fast, * slow;
    if (A == NULL || A->next == NULL)
    {
        return false;
    }
    fast = slow = A;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cur = slow;
    prve = NULL;

    //翻转
    while (cur)
    {
        next = cur->next;
        cur->next = prve;
        prve = cur;
        cur = next;
    }
    cur = prve;
    while (A && cur)
    {
        if (A->val != cur->val)
        {
            return false;
        }
        A = A->next;
        cur = cur->next;
    }
    return true;
}

//方法二：
int arr[900] = { 0 };
int index = 0, start = 0, end = 0;
cur = A;
while (cur)
{
    arr[index++] = cur->val;
    cur = cur->next;
}
end = index - 1;
while (start <= end)
{
    if (arr[start] != arr[end])
    {
        return false;
    }
    start++;
    end--;
}
return true;
    }


    //两个链表相遇的第一个节点
    struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        int l1 = 0, l2 = 0;
        struct ListNode* cur1, * cur2, * curA, * curB;
        cur1 = headA;
        cur2 = headB;
        while (cur1)
        {
            l1++;
            cur1 = cur1->next;
        }
        while (cur2)
        {
            l2++;
            cur2 = cur2->next;
        }
        int k = abs(l1 - l2);
        curA = headA;
        curB = headB;

        if (l1 < l2)
        {
            curA = headB;
            curB = headA;

        }

        for (int i = 1; i <= k; i++)
        {
            curA = curA->next;
        }
        while (curA && curB)
        {
            if (curA == curB)
            {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }

  //判断是否有环
    bool hasCycle(struct ListNode* head) {
        struct ListNode* fast, * slow;
        fast = slow = head;
        if (head == NULL)
            return NULL;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;

    }


    //链表的环入口的结点
    struct ListNode* hasCycle(struct ListNode* head) {
        struct ListNode* fast, * slow;
        fast = slow = head;
        if (head == NULL)
            return NULL;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                return fast;
            }
        }
        return NULL;

    }
    struct ListNode* detectCycle(struct ListNode* head) {
        struct ListNode* fast, * slow, * cur;
        cur = hasCycle(head);
        fast = slow = head;
        if (head == NULL)
        {
            return NULL;
        }
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








