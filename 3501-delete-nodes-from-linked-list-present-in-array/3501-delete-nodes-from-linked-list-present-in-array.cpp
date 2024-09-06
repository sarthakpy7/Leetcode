
class Solution {
private:
    std::vector<int> sorted_nums;
    ListNode* DeleteNodes(ListNode* cur)
    {
        if(cur == nullptr) return cur; // this way is more READABLE fr
        cur->next = DeleteNodes(cur->next);
        if(std::binary_search(sorted_nums.begin(), sorted_nums.end(), cur->val)){
            return cur->next;
        }
        else{
            return cur;
        }
    }
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());
        return DeleteNodes(head);
    }
};

auto init = []() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 'c';
}();