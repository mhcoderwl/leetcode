/*删除链表中重复的数,已排序链表
 * 时间复杂度O(n)*/
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
	ListNode* Unique(ListNode* head){
		if(head==NULL)
			return head;
		ListNode* cur=head;
		ListNode* del;
		while(cur->next!=NULL){
			if(cur->next->val==cur->val){
				del=cur->next;
				cur->next=cur->next->next;
				delete del;
			}
			cur=cur->next;
		}
		return head;
	}
};
int main(){
	ListNode* s1=new ListNode(1);
	s1->next=new ListNode(2);
	s1->next->next=new ListNode(2);
	s1->next->next->next=new ListNode(3);
	Solution s;
	s.Unique(s1);
	while(s1!=NULL){
		cout<<s1->val<<' ';
		s1=s1->next;
	}cout<<endl;
}

