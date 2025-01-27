class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            // Identify the two nodes to swap
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Perform the swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move the prev pointer two nodes ahead
            prev = first;
        }

        // Return the new head
        return dummy->next;
    }
};
