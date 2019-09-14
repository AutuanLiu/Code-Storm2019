// 之字形打印二叉树.cpp
// 分奇数层和偶数层 层数从1开始编号
// 奇数层就按照先左后右的顺序访问并入奇数栈
// 偶数层就按照先右后左的顺序访问并入偶数栈
// 每层访问完之后要进行交换

void print_tree(TreeNode* root)
{
    if (root == nullptr)
        return;
    vector<stack<TreeNode*>> sks(2);
    int cur = 0, next = 1;
    sks[cur].push_back(root);
    while (!sks[0].empty() || !sks[0].empty()) {
        TreeNode* node = sks[cur].top();
        sks[cur].pop();
        cout << node->val << " ";
        if (cur == 0) {
            if (node->left) {
                sks[next].push(node->left);
            }
            if (node->right) {
                sks[next].push(node->right);
            }
        } else {
            if (node->right) {
                sks[next].push(node->right);
            }
            if (node->left) {
                sks[next].push(node->left);
            }
        }
        if (sks[cur].empty()) {
            cout << endl;
            cur = 1 - cur;
            next = 1 - next;
        }
    }
    return;
}