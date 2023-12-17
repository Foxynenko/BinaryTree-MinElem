#include <iostream>
#include <stack>

// Визначення вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->right; // Інвертований обхід: правий-корінь-лівий
        }

        current = s.top();
        s.pop();
        k--;

        if (k == 0) {
            return current->val; // Знайдено k-те найменше значення
        }

        current = current->left;
    }

    return -1; // Це взагалі не повинно відбутися, якщо k дійсно менше або дорівнює кількості вузлів у дереві.
}

int main() {
    // Приклад використання
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->right = new TreeNode(2);

    std::cout << "Example 1: " << kthSmallest(root1, 1) << std::endl; // Виведе 1

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(6);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->left->left->left = new TreeNode(1);

    std::cout << "Example 2: " << kthSmallest(root2, 3) << std::endl; // Виведе 3

    // Додайте інші приклади або тести, якщо необхідно

    return 0;
}
