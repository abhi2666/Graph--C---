// Practice - Left View of Binary Tree 
/*
Can be done by using RLR (PreOrder)

*/

void getLeftView(int level, vector<int>&ans, Node*root)
{
    if(root == NULL) return;
    
    if(ans.size() == level){
        // means current element is the first element of current level
        ans.push_back(root->data);
    }
    // now implement the basic pre order
    getLeftView(level+1, ans, root->left);
    getLeftView(level+1, ans, root->right);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    // we will maintain a level and will pick only the first element from that level
    getLeftView(0, ans, root);
    return ans;
}
