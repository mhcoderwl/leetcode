/*给一链表,删除所有重复的数(包括自己)*/
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution{
public:
	ListNode* DeleteDumplicates(ListNode* head){
		if(head==NULL)return head;
		ListNode dummy(head->val+1);
		dummy.next=head;
		ListNode* cur=&dummy;
		ListNode* prev=cur;
		ListNode* p;
		bool dumplicated=false;
		for(cur=cur->next;cur->next!=NULL;prev=prev->next,cur=cur->next,dumplicated=false){
			if(cur->next->val==cur->val){
				dumplicated=true;
				p=cur->next;
				cur->next=cur->next->next;
				delete p;
			}
			if(dumplicated==true&&(cur->next->val!=cur->val||cur->next==NULL)){
				prev->next=cur->next;
				p=cur;
				cur=cur->next;
				delete p;
			}
		}
		return head;
	}
};
			
int main(){
	Solution s;
	ListNode* s1=new ListNode(1);
	s1->next=new ListNode(2);
	s1->next->next=new ListNode(2);
	s.DeleteDumplicates(s1);
	while(s1!=NULL){
		cout<<s1->val<<' ';
		s1=s1->next;
	}cout<<endl;
}
	

					

