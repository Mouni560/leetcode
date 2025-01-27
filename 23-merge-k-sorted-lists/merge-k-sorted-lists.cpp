#include <queue>
using namespace std;

// No need to redefine ListNode; it's already provided in the environment.

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparator for the min-heap
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
        
        // Push the head of each list into the min-heap
        for (ListNode* list : lists) {
            if (list) minHeap.push(list);
        }
        
        // Dummy node to simplify list construction
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        
        while (!minHeap.empty()) {
            // Get the smallest element
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            // Add the smallest element to the merged list
            current->next = smallest;
            current = current->next;
            
            // Push the next element from the same list into the heap
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy->next;
    }
};
