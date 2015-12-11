//here in this programm we check that given tree is balance bst or not.......
//if it is balanced bst than return 1 else
//return 0 ........from always i stuck in some recurrsion return value bt i got it 


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * 
 * @Output Integer
 */
 #define max(a,b)(a>b?a:b)
int isBalanced(treenode* A) {
    int left,right,diff;
    if(A == NULL)
    return 1;
    if(isBalanced(A->left) == 0 )
        return 0;
    if(isBalanced(A->right) == 0)
        return 0;
    if(A->left == NULL)
        left = 0;
    else
     left = height(A->left);
    if(A->right == NULL)
        right = 0;
    else
        right = height(A->right);
        #ifndef Debug
           // printf("%d %d\n",left,right);
        #endif
    diff = abs(left-right);
    if(diff>1)
        return 0;
    else
        return 1;
    //isBalanced(A->left);
}

int height(treenode *root)
{
    if(root == NULL)
    return 0;
    else
    {
        return max(height(root->left),height(root->right))+1;
    }
    
}



