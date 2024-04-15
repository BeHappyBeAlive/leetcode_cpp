#include <vector>
#include <stack>
#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//删除链表的倒数第N个节点
// 计算链表的长度
int GetListNodeLength(ListNode* head) {
  int len = 0;
  while (head) {
    len++;
    head = head->next;
  }
  return len;
}

ListNode* removeNthFromEnd_len(ListNode* head, int n) {
  if (!head) {
    return nullptr;
  }
  ListNode* dummy_node = new ListNode(0, head);
  int len = GetListNodeLength(head);
  ListNode* cur = dummy_node;
  for (int i = 0; i < len - n; i++) {
    cur = cur->next;
  }
  cur->next = cur->next->next;
  ListNode* result = dummy_node->next;
  delete dummy_node;
  return result;
}
// 栈的方式
ListNode* removeNthFromEnd_stack(ListNode* head, int n) {
  if (!head) {
    return nullptr;
  }
  ListNode* dummy_node = new ListNode(0, head);
  std::stack<ListNode*> stack_list_node;
  auto cur = dummy_node;
  while (cur) {
    stack_list_node.push(cur);
    cur = cur->next;
  }
  for (int i = 0; i < n; i++) {
    stack_list_node.pop();
  }
  auto delete_node_pre = stack_list_node.top();
  delete_node_pre->next = delete_node_pre->next->next;
  ListNode* result = dummy_node->next;
  delete dummy_node;
  return result;
}
// 快慢双指针
ListNode* removeNthFromEnd_fast_slow(ListNode* head, int n) {
  if (!head) {
    return nullptr;
  }
  ListNode* dummy_node = new ListNode(0, head);
  auto fast = head;
  auto slow = dummy_node;
  for (int i = 1; i <= n; i++) {
    fast = fast->next;
  }
  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = slow->next->next;
  ListNode* result = dummy_node->next;
  delete dummy_node;
  return result;
}

//盛最多水的容器
int maxArea(std::vector<int>& height_vec) {
  int l = 0, right = height_vec.size() - 1;
  int result = 0;
  while (l < right) {
    int area_size = std::min(height_vec[l], height_vec[right]) * (right - l);
    result = std::max(area_size, result);
    if (height_vec[l] <= height_vec[right]) {
      l++;
    }
    else {
      right--;
    }
  }
  return result;
}

int main() {
  removeNthFromEnd_fast_slow(nullptr, 0);
  std::cout << "aaa" << std::endl;
  std::vector<int> res = { 1,8,6,2,5,4,8,3,7 };
  maxArea(res);
}