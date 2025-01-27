class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Helper function to reverse a sublist
        auto reverse = [](ListNode* start, ListNode* end) {
            ListNode* prev = nullptr;
            ListNode* curr = start;
            while (curr != end) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev; // New head of the reversed list
        };

        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;

        while (true) {
            // Find the kth node from the current position
            ListNode* groupEnd = groupPrev;
            for (int i = 0; i < k; ++i) {
                groupEnd = groupEnd->next;
                if (!groupEnd) {
                    // Not enough nodes to form a complete group
                    return dummy->next;
                }
            }

            // Store the next group's starting node
            ListNode* nextGroupStart = groupEnd->next;

            // Reverse the current group
            ListNode* groupStart = groupPrev->next;
            groupEnd->next = nullptr; // Temporarily disconnect the group
            groupPrev->next = reverse(groupStart, nullptr);

            // Connect the reversed group to the rest of the list
            groupStart->next = nextGroupStart;

            // Move the groupPrev pointer to the end of the reversed group
            groupPrev = groupStart;
        }
    }
};
