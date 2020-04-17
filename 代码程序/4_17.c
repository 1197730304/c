/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//两个链表相加
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//    if (l1 == NULL)
//        return l2;
//    if (l2 == NULL)
//        return l1;
//    struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* cur1, * cur2, * newnode;
//    cur1 = l1;
//    cur2 = l2;
//    struct ListNode* p = l1;
//    int sum = 0;
//    while (l1 != NULL || l2 != NULL)
//    {
//        if (l1 != NULL && l2 != NULL)
//        {
//            l1->val += l2->val + sum;
//            sum = 0;
//            if (l1->val / 10)
//            {
//                l1->val %= 10;
//                sum = 1;
//            }
//            cur = l1;
//            l1 = l1->next;
//            l2 = l2->next;
//        }
//        else if (l1 != NULL && l2 == NULL)
//        {
//            l1->val += sum;
//            sum = 0;
//            if (l1->val / 10)
//                sum++;
//            l1->val %= 10;
//            cur = l1;
//            l1 = l1->next;
//        }
//        else if (l1 == NULL && l2 != NULL)
//        {
//            cur->next = l2;
//            l2->val += sum;
//            sum = 0;
//            if (l2->val / 10)
//                sum++;
//            l2->val %= 10;
//            cur = l2;
//            l2 = l2->next;
//        }
//    }
//    if (sum)
//    {
//        newnode = malloc(sizeof(struct ListNode));
//        newnode->val = sum;
//        newnode->next = NULL;
//        cur->next = newnode;
//    }
//    return p;
//}


//最长字符串
int lengthOfLongestSubstring(char* s) {
    char p[256] = { 0 };
    int len = strlen(s);
    int max = 0;
    int p1 = 0, p2 = 0;
    while (p1 < len && p2 < len)
    {
        max = max > (p2 - p1) ? max : (p2 - p1);
        while (p[s[p2]] != 0)
        {
            p[s[p1]] = 0;
            p1++;
        }
        p[s[p2]] = 1;
        p2++;
    }
    max = max > (p2 - p1) ? max : (p2 - p1);
    return max;
}
