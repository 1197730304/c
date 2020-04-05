
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* newh, * newt;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    newh = newt = (struct ListNode*)malloc(sizeof(struct ListNode));

    while (l1 && l2)
    {
        if (l1->val < l2->val)
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
    return newh->next;
}



class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        struct ListNode* gt, * gh, * lh, * lt, * cur;
        gh = gt = (struct ListNode*)malloc(sizeof(struct ListNode));
        lh = lt = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (pHead == NULL)
            return NULL;
        cur = pHead;;
        while (cur)
        {
            if (cur->val < x)
            {
                lt->next = cur;
                lt = lt->next;
            }
            else
            {
                gt->next = cur;
                gt = gt->next;
            }
            cur = cur->next;
        }
        gt->next = NULL;
        lt->next = gh->next;

        lt = lh;
        gt = gh;
        lh = lh->next;
        free(lt);
        free(gt);
        return lh;
    }

};



struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* la, * lb, * cur;
    la = headA;
    lb = headB;
    int l1 = 0, l2 = 0, k = 0;
    if (headA == NULL || headB == NULL)
        return NULL;
    while (la)
    {
        l1++;
        la = la->next;
    }

    while (lb)
    {
        l2++;
        lb = lb->next;
    }
    k = abs(l1 - l2);
    la = headA;
    lb = headB;
    if (l1 < l2)
    {
        lb = headA;
        la = headB;

    }
    while (k--)
    {
        la = la->next;
    }
    while (la && lb)
    {
        if (la == lb)
            return la;
        la = la->next;
        lb = lb->next;
    }
    return NULL;

}