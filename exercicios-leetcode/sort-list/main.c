//Given the head of a linked list, return the list after sorting it in ascending order.

/**
 * Definition for singly-linked list.
 * 
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode* mergeList(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    if (list1->val <= list2->val) {
        list1->next = mergeList(list1->next, list2);
        return list1;

    } else {
        list2->next = mergeList(list1, list2->next);
        return list2;
    }
}

struct ListNode* sortList(struct ListNode* head){

    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    struct ListNode* temp = NULL;
    struct ListNode* high = head;
    struct ListNode* low = head;

    while (high != NULL && high->next != NULL) {
        temp = low;
        low = low->next;
        high = high->next->next;
    }
    
    temp->next = NULL;

    return mergeList(sortList(head), sortList(low));
}