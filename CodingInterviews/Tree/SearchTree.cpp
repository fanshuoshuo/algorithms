/*
recursive �㷨����

Preorder-Tree-Walk(x)
    if x!=NIL
        print x
        Preorder-Tree-Walk(x.left)
        Preorder-Tree-Walk(x.right)

Inorder-Tree-Walk(x)
    if x!=NIL
        Inorder-Tree-Walk(x.left)
        print x
        Inorder-Tree-Walk(x.right)


Postorder-Tree-Walk(x)
    if x!=NIL
       Postorder-Tree-Walk(x.left)
       Postorder-Tree-Walk(x.right)
       print x

*/
/*
non-recursive  url��http://blog.csdn.net/sjf0115/article/details/8645991

Preorder-Tree-Walk(Tree *x){
    stack<Tree> stack;
    Tree *p=x
    while(p||!stack.empty()){
        if(p!=NIL){

            print(p)
            stack.push(p)
            p=p->left
        }
        else{
            p=stack.top();
            stack.pop()
            p=p->right
        }

    }

}
Inorder-Tree-Walk(Tree *x){
    stack<Tree> stack
    Tree *p=x;
     while(p||!stack.empty()){
        if(p!=NIL){

            stack.push(p)
            p=p->left
        }
        else{
            p=stack.top()
            stack.pop()
            print(p)
            p=p->right
        }

    }

}
����Ҫ����
Postorder-Tree-Walk(Tree *x){
    stack<Tree> stack
    Tree *p=x;
     while(p||!stack.empty()){
        while(p!=NULL){
            stack.push(p)
            p=p->left
            p.tag='L'
        }
         while(!stack.empty() && (stack.top())->tag == 'R'){
            p = stack.top()
            stack.pop()
            print(p)
        }
         if(!stack.empty()){
            p = stack.top()
            p->tag = 'R';
            p = p->rchild
        }

    }

}
*/
/*
//��α���
void LevelOrder(BiTree T){
    BiTree p = T;
    //����
    queue<BiTree> queue;
    //���ڵ����
    queue.push(p);
    //���в���ѭ��
    while(!queue.empty()){
        //��ͷԪ�س���
        p = queue.front();
        //����pָ��Ľ��
        printf("%c ",p->data);
        //�˳�����
        queue.pop();
        //���������գ������������
        if(p->lchild != NULL){
            queue.push(p->lchild);
        }
        //���������գ������������
        if(p->rchild != NULL){
            queue.push(p->rchild);
        }
    }
}
*/
