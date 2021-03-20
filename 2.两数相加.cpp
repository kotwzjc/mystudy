/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
class Solution { // My solution
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=1,len2=1;
        int flag = 0;
        ListNode* temp = l1;
        while(temp->next != nullptr){
            temp = temp->next;
            len1++;
        }
        temp = l2;
        while(temp->next != nullptr){
            temp = temp->next;
            len2++;
        }
        int l = len1>len2?len2:len1;
        ListNode* result = new ListNode();
        ListNode* rTemp = result;
        for(int i = 0; i < l; i++){
            int tResult = l1->val + l2->val;
            int lflag = 0;
            if(flag == 1){
                tResult++;
                flag = 0;
            }
            if(tResult >= 10 && i == l-1 && len1 == len2){
                lflag = 1;
                tResult -= 10;
            }
            else if(tResult >= 10)
            {
                flag = 1;
                tResult -= 10;
            }
            ListNode* newNode = new ListNode();
            rTemp->val=tResult;
            if(i != l-1)
            {
                rTemp->next=newNode;
                rTemp = rTemp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
            if(lflag == 1){
                ListNode* lNode = new ListNode(1);
                rTemp->next=lNode;
            }
        }
        temp = l1?l1:l2;
        while(temp != nullptr){
            int tResult = temp->val;
            int lflag=0;
            if(flag == 1){
                tResult++;
                flag = 0;
            }
            if(tResult >= 10 && temp->next == nullptr)
            {
                lflag=1;
                tResult -= 10;
            }
            else if(tResult >= 10)
            {
                flag = 1;
                tResult -= 10;
            }
            ListNode* newNode = new ListNode(tResult);
            rTemp->next=newNode;
            rTemp = rTemp->next;
            temp = temp->next;
            
            if(lflag){
                ListNode* lNode = new ListNode(1);
                rTemp->next=lNode;
            }
        }
        return result;
    }
};*/

// recommend solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
// @lc code=end

