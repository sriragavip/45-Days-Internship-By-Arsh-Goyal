
class Solution {
public:
    TreeNode* dfs(vector<int>& preorder,int prestart,int preend, vector<int>& postorder,int poststart,int postend)
    {
        if(prestart>preend)
        {
            return NULL;
        }
        if(poststart>postend)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[prestart]);
        if(prestart==preend)
        {
            return root;
        }
        int postindex=poststart;
        while(postorder[postindex]!=preorder[prestart+1])
        {
            postindex++;
        }
        int len= postindex-poststart+1;
        root->left=dfs(preorder,prestart+1,prestart+len,postorder,poststart,postindex);
        root->right=dfs(preorder,prestart+len+1,preend,postorder,postindex+1,postend-1);
        return root;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return dfs(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
    }
};