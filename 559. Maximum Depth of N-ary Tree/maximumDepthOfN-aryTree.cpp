/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int maxChildrenDepth = 0;
        for(auto ch : root->children){
            int currentChildrenDepth = maxDepth(ch);
            if(currentChildrenDepth > maxChildrenDepth){
                maxChildrenDepth = currentChildrenDepth;
            }
        }
        return 1 + maxChildrenDepth;
    }
};
