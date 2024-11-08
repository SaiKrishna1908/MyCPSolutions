#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7

template <class c>
struct rge
{
  c b, e;
};
template <class c>
rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug
{

  ~debug() { cerr << endl; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i)
  {
    cerr << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
  template <class c, class b>
  debug &operator<<(pair<b, c> d)
  {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug &operator<<(rge<c> d)
  {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
      *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
};


 // Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution
{

private:
  inline bool operator() (const std::string& first,  const std::string& second) const {
    return first.size() < second.size();
  }
public:
  ListNode* solve(ListNode* head)
  {
    
      if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* current = head->next;
        ListNode* newHead = current;

        while(current != nullptr) {        
            if (current->next ==nullptr || current->next->next ==nullptr) {
                break;    
            }
            auto ptr1 = current->next;
            auto ptr2 = ptr1->next;
            auto temp = ptr2->next;
            ptr2->next = ptr1;
            ptr1->next = temp;
            current->next = ptr2;
            current=ptr1;
        }

        auto temp = newHead->next;
        newHead->next = head;
        head->next =temp;
        return newHead;
    
  }
};
int main()
{

  // cin.tie(0);
  // cin.sync_with_stdio(false);

  auto start = high_resolution_clock::now();

  auto solution = new Solution();

  ListNode* list1 = new ListNode(1);
  ListNode* list2 = new ListNode(2);
  ListNode* list3 = new ListNode(3);
  ListNode* list4 = new ListNode(4);
  ListNode* list5 = new ListNode(5);
  ListNode* list6 = new ListNode(6);

  list1->next = list2;
  list2->next = list3;
  list3->next = list4;
  list4->next = list5;
  list5->next = list6;

  auto sol = solution->solve(list1);

  // ListNode* current = list1;

  while(sol!=nullptr) {
    cout<<sol->val<<endl;
    sol = sol->next;
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
