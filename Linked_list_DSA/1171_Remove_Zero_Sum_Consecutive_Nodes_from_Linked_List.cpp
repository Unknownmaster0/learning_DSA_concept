#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Nice question of the linked list.
// Do solve again.
// problem link -> https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/?envType=daily-question&envId=2024-03-12

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};


class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;

        int prefixSum = 0;
        unordered_map<int, ListNode*> freq;
        freq[0] = dummyNode; // dummyNode value.

        while(head != NULL){
            prefixSum += head->val;

            // if prefix is present earlier in the map
            if(freq.find(prefixSum) != freq.end()){
                // delete their occurrence from map
                ListNode* start = freq[prefixSum]->next;
                int currPf = prefixSum + start->val; // current prefix sum = prefixsum + prefix sum of start.
                while(start != head){
                    freq.erase(currPf);
                    start = start->next;
                    currPf += start->val;
                }
                // delete nodes
                freq[prefixSum]->next = head->next;
            }
            else{
                freq[prefixSum] = head;
            }

            head = head->next;
        }
        
        return dummyNode->next;
    }
};

int main()
{

    return 0;
}