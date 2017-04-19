/*给一个链表,查看有没有回路,要求原址
 * 思路:类似操场跑步的原理,一个快一个慢,如果快的追上慢的说明有环*/
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution{
public:
	bool Hascycle(ListNode* head){
		if(head==NULL)return head;
		ListNode dummy(-1);
		dummy.next=head;
		ListNode* quick=&dummy;
		ListNode* slow=&dummy;
		while(quick!=NULL&&quick->next!=NULL){
			quick=quick->next->next;
			slow=slow->next;
			if(quick==slow)
				return true;
		}return false;
	}
};


int main(){}

