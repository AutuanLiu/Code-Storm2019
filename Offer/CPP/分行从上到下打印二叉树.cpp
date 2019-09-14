// 分行从上到下打印二叉树.cpp
// 需要保存当前行还要打印的节点个数和下一层的节点数
void print_tree(TreeNode* root)
{
    if (root == nullptr)
        return;
    queue<TreeNode*> q;
    q.push(root);
    int toPrint = 1, nextlevel = 0;
    while (!q.empty()) {
        // 打印节点
        TreeNode* p = q.front();
        cout << p->val << " ";
        // 访问下一层
        if (p->left != nullptr) {
            q.push(p->left);
            nextlevel++;
        }
        if (p->right != nullptr) {
            q.push(p->right);
            nextlevel++;
        }
        q.pop();
        toPrint--;
        // 判断这行是不是已经打印
        if (toPrint == 0) {
            cout << endl;
            toPrint = nextlevel;  // 更新要打印的节点数并初始化下一行的节点数
            nextlevel = 0;
        }
    }
}