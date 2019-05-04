#include <iostream>
#include <vector>
using namespace std;
std::vector<int> in(205,-1);
struct node
{
    int value;
    struct node *left, *right;
    node (int x) : value(x), left(NULL), right(NULL){};
};
node *rotateL(node *root){
    node *t = root -> right;
    root -> right = t -> left;
    t ->left = root;
    return t;
}
node *rotateR(node *root){
    node *t = root -> left;
    root -> left = t ->right;
    t -> right = root;
    return t;
}
node *rotateLR(node *root){
    root -> left = rotateL(root -> left);
    return rotateR(root);
}
node *rotateRL(node *root){
    root ->right = rotateR(root ->right);
    return rotateL(root);
}
int getHeight(node *root){
    if(root == NULL)
        return 0;
    return max(getHeight(root ->left), getHeight(root -> right)) + 1;
}
node *insert(node *root, int val){
    if(root == NULL)
        root = new node(val);
    else if(val < root -> value){
        root -> left = insert(root -> left, val);
        if(getHeight(root -> left) - getHeight(root -> right) == 2)
            root = val < root -> left -> value ? rotateR(root) : rotateLR(root);
    }
    else{
        root -> right = insert(root -> right ,val);
        if(getHeight(root -> right) - getHeight(root ->left) == 2)
            root = val > root -> right -> value ? rotateL(root) : rotateRL(root);
    }
    return root;
}
void dfs(node *root, int index){
    if(root == NULL)
        return;
    in[index] = root -> value;
    dfs(root -> left, 2 * index);
    dfs(root -> right, 2 * index + 1);
}
int main(){
    int n, val,cnt = 1;
    bool flag = true;
    node *root = NULL;
    cin>>n;
    for(int i = 0; i < n; i++){
        scanf("%d",&val);
        root = insert(root, val);
    }
    dfs(root, 1);
    printf("%d",in[cnt++]);
    for(int i = 1; i < n; i++){
        while(in[cnt] == -1){
            flag = false;
            cnt++;
        }
        printf(" %d",in[cnt++]);
    }
    printf("\n%s",flag == true ? "YES" : "NO");
}
