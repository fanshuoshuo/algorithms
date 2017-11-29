/***************************
author：shuoshuofan
date  : 20170323
剑指offer纪念版 2.3.3 链表，从尾到头打印链表
****************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstddef>
#include <stack>
using namespace std;
struct ListNode
{
	int val;
	struct ListNode *next;
	 ListNode(int x) :
              val(x), next(NULL) {
     }
};
class Solution{
private:
	ListNode *List;
public:
	void AddToTail(ListNode** pHead,int val);
	void RemoveNode(ListNode** pHead,int val);
	void printListReversingly_Recursively(ListNode* pHead);
	void printListReversingly_UsingStack(ListNode* pHead);
};
void Solution::AddToTail(ListNode ** pHead,int val){

   ListNode *pNew=new ListNode(val);   //新添入的链表

   if(*pHead==NULL){                   //注意是双等号，而不是双等号
   	 *pHead=pNew;
   }
   else {
   		ListNode * pNode= *pHead;     //如果直接使用pHead将会导致在程序结束时链表头指针走到链表尾，返回错误结果
   		while(pNode->next!=NULL)
   			pNode=pNode->next;
   		pNode->next=pNew;
   }
   
   	
}
void Solution::RemoveNode(ListNode** pHead,int val){
	if((*pHead)==NULL||pHead==NULL) return;
	ListNode *pToDeleted=NULL;
	if((*pHead)->val==val){
         pToDeleted=*pHead;
         *pHead=(*pHead)->next;
	}
	else{
		ListNode* pNode=*pHead;
		while(pNode->next->val!=val&&pNode->next!=NULL){
			pNode=pNode->next;
		}
		if(pNode->next->val==val&&pNode->next!=NULL){
			pToDeleted=pNode->next;
			pNode->next=pNode->next->next;
		}
		if(pToDeleted!=NULL){
			delete pToDeleted;
			pToDeleted=NULL;
		}
	}

      
}
void Solution::printListReversingly_Recursively(ListNode* pHead){
    if(pHead!=NULL){
    if (pHead->next!=NULL){
  		printListReversingly_Recursively( pHead->next);
    }
    cout<<pHead->val<<endl;
    }

}
void Solution::printListReversingly_UsingStack(ListNode* pHead){
	if(pHead==NULL) return ;
	stack<int> s;
	while(pHead!=NULL){
		s.push(pHead->val);
		pHead=pHead->next;
	}
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}

}
int main(){

    /**建立一个指向链表的指针有如下三种方法
	//ListNode *test=new ListNode(4);
	//ListNode *test;                 这样建立链表指针会让指针随机指向一个地址，而不是说空地址
	//ListNode *test=NULL;            这时候直接输出test->val程序崩溃

	*/
	ListNode  *test=NULL;
	ListNode **p=&test;              //指向指针的指针，如果要建立链表和删除链表上的某个结点，要用双重指针传地址
	Solution s;
	//creat List
	s.AddToTail(&test,5);            //或者是s.AddToTail(p,5); 
	s.AddToTail(&test,6); 
	s.AddToTail(&test,7); 
	s.AddToTail(&test,8); 
	s.AddToTail(&test,9); 
	//print List reversingly
	s.printListReversingly_Recursively(test);
	//delete Node 7 and 
	s.RemoveNode(&test,7);
	s.printListReversingly_Recursively(test);

	return 0;
}
// 问题1 ，如何建立静态链表