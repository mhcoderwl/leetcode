/*给一个链表,反转每K个节点,最后不足k个的节点顺序不变.
 * 思路:每个节点头插,插k次.*/

#include<iostream>
using namespace std;
struct Listnode{
	int val;
	Listnode* next;
	Listnode(int x):val(x),next(NULL){}
};
class Solution{
public:
	Listnode* ReverseKGroup(Listnode* head,int k){
		if(head==NULL)return head;
		Listnode dummy(-1);
		dummy.next=head;
		Listnode* cur=&dummy;
		while(cur->next!=NULL){
			Listnode* p=cur;
			for(int i=0;i<k;i++){
				if(p==NULL)
					return dummy.next;
				p=p->next;
			}
			p=cur->next;
			for(int i=1;i<k;i++){
				Listnode* q=p->next;
				p->next=q->next;
				q->next=cur->next;
				cur->next=q;
			}
			cur=p;
		}
		return dummy.next;
	}
};

int main(){
	Solution s;
	Listnode* s1=new Listnode(1);
	s1->next=new Listnode(2);
	s1->next->next=new Listnode(3);
	s1->next->next->next=new Listnode(4);
	s1->next->next->next->next=new Listnode(5);
	Listnode* p=s.ReverseKGroup(s1,4);
	while(p!=NULL){
		cout<<p->val<<' ';
		p=p->next;
	}
	cout<<endl;
}
			
				
			



	
