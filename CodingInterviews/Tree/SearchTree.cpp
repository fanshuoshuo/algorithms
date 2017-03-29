/*
recursive 算法导论

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
non-recursive  url：http://blog.csdn.net/sjf0115/article/details/8645991

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
还需要修正
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
//层次遍历
void LevelOrder(BiTree T){
    BiTree p = T;
    //队列
    queue<BiTree> queue;
    //根节点入队
    queue.push(p);
    //队列不空循环
    while(!queue.empty()){
        //对头元素出队
        p = queue.front();
        //访问p指向的结点
        printf("%c ",p->data);
        //退出队列
        queue.pop();
        //左子树不空，将左子树入队
        if(p->lchild != NULL){
            queue.push(p->lchild);
        }
        //右子树不空，将右子树入队
        if(p->rchild != NULL){
            queue.push(p->rchild);
        }
    }
}
*/
