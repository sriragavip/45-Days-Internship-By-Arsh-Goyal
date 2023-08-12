class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* r=root;
    while(true){
        if(r->val==p->val){return p; break;}
        if(r->val==q->val){return q; break;}
        else if(((r->val)>(p->val) && r->val<q->val) || ((r->val)<(p->val) && (r->val)>(q->val))){return r; break;}
        else if(r->val>p->val && r->val>q->val){
            r=r->left;
        }
        else{
            r=r->right;
        }
    }
}
};