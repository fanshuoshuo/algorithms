#include <iostream>
#include <stack>
using namespace std;
struct  binaryTree
{
	int val;
	binaryTree* left;
	binaryTree* right;
	
};
void preorder(binaryTree* root){
	if(root){
		cout<<root->val<<endl;
		preorder(root->left);
		preorder(root->right);
	}
}
void preorderWithoutRec(binaryTree* root){
	stack<binaryTree* bt> sta;
	binaryTree*p=root;
	while(!p||!sta.empty()){

		while(p){
			cout<<p->val<<endl;
			sta.push(p);
			p=p->left;
		}
		if(!sta.empty()){
			p=sta.top();
			cout<<p->val<<endl;
			sta.push(p->right);
		}
	}
}
void midorder(binaryTree*root){
	if(root){
		midorder(binaryTree->left);
		cout<<root->val<<endl;
		midorder(binaryTree->right);
	}
}
void midorderWithoutRec(binaryTree*root){
	stack<binaryTree*> s;
	binaryTree *p=root;
	while(!p||!s.empty()){

		while(p){
			s.push(p);
			p=p->left;
		}
		if(!s.empty()){

			p=s.top();
			s.pop();
			cout<<p->val();
			p=p->right;
		}

	}
}
int main(){
	cout<<"Hello,world"<<endl;
	return 0;
}