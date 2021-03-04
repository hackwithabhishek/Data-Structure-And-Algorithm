#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class tree{
    public:
        ll val;
        tree *left,*right;
    tree(ll value){
        this->val=value;
        this->left=this->right=NULL;
    }
    tree *insert(ll value,tree* root){
        if(root==NULL){
          //  root->val=value;
            return new tree(value);
        }
        if(value<(root->val)){
            root->left=insert(value,root->left);
        }
        else{
            root->right=insert(value,root->right);
        }
        return root;
    }
    void inorder(tree* root)
    {
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->val<<"  ";
        inorder(root->right);
    }
    void preorder(tree* root)
    {
        if(root==NULL){
            return;
        }
        cout<<root->val<<"  ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(tree* root)
    {
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<"  ";
    }
    void level_order_traversal(tree* root){
        queue<tree*> q;
        q.push(root);
        while(!q.empty()){
            tree* temp=q.front();
            q.pop();
            cout<<temp->val<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    void left_view(tree* root)
    {
        queue<tree *> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=1;i<=sz;i++)
            {
                tree* temp=q.front();
                q.pop();
                if(i==1)
                    cout<<temp->val<<" ";
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        
    }
    void right_view(tree* root){
        queue<tree*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=1;i<=sz;i++){
                tree* temp=q.front();
                q.pop();
                if(i==sz)
                    cout<<temp->val<<" ";
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }
    void top_view(tree* root){
        map<int ,int> mp;
        queue<pair<tree*,int> > q;
        q.push({root,0});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int p=temp.second;
            auto node=temp.first;
            if(mp.count(p)==0){
                mp[p]=node->val;
            }
            if(node->left){
                q.push({node->left,p-1});
            }
            if(node->right){
                q.push({node->right,p+1});
            }
        }
        for(auto i:mp){
            cout<<i.second<<" ";
        }
    }
    void bottom_view(tree* root){
        map<int,int> mp;
        queue<pair<tree*,int> > q;
        q.push({root,0});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int p=temp.second;
            auto node=temp.first;
            mp[p]=node->val;
            if(node->left){
                q.push({node->left,p-1});
            }
            if(node->right){
                q.push({node->right,p+1});
            }
        }
        for(auto i:mp){
            cout<<i.second<<" ";
        }
    }
    void height_tree(tree* root){
        queue<tree*> q;
        int count=0;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=1;i<=sz;i++){
                tree* temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
            }
            count++;
        }
        cout<<count;
    }
    int get_tree_height(tree* root){
        if(root==NULL){
            return 0;
        }
        int right=get_tree_height(root->right);
        int left=get_tree_height(root->left);
        return 1+max(right,left);
    }
    tree* array_to_bst(int *a,int st,int en){
        if(st>en){
            return NULL;
        }
        int mid=(st+en)/2;
        tree* root=new tree(a[mid]);
        root->left=array_to_bst(a,st,mid-1);
        root->right=array_to_bst(a,mid+1,en);
        return root;
    }
    tree* create_tree_preorder_inorder(int *b,int st,int en,auto &mp,int &pre_idx){
        if(st>en){
            return NULL;
        }
        tree* root=new tree(b[pre_idx]);
        int idx=mp[b[pre_idx]];
        pre_idx++;
        root->left=create_tree_preorder_inorder(b,st,idx-1,mp,pre_idx);
        root->right=create_tree_preorder_inorder(b,idx+1,en,mp,pre_idx);
        return root;
    }
    bool identical(tree *root,tree *root1){
        if(root==NULL and root1==NULL)
             return true;
        if(root==NULL or root1==NULL)
             return false;
        return identical(root->left,root1->left) and identical(root->right,root1->right);
    }
    bool mirror(tree *root,tree* root1){
        if(root==NULL and root1==NULL)
             return true;
        if(root==NULL and root1==NULL)
             return false;
        return mirror(root->left,root1->right) and mirror(root->right,root->left);
    }
    void serialization(tree* root,auto &s){
        if(root==NULL){
            s.push(-1);
            return;}
        s.push(root->val);
        serialization(root->left,s);
        serialization(root->right,s);
    }
    tree* Deserialization(auto s){
        int val=s.front();
        s.pop();
        if(s.empty() or val==-1)
             return NULL;
        tree* root=new tree(val);
        root->left=Deserialization(s);
        root->right=Deserialization(s);
        return root;
    }
};
int main(){
   tree *root=NULL;
   root= root->insert(6,root);
   root= root->insert(3,root);
   root= root->insert(5,root); 
   root= root->insert(1,root);
   root= root->insert(4,root);
   root= root->insert(8,root);
   root= root->insert(10,root);
   root= root->insert(9,root);
   root= root->insert(2,root);
   root->inorder(root);  
   cout<<endl;
   root->level_order_traversal(root);
   cout<<endl;
   root->left_view(root);
   cout<<endl;
   root->right_view(root);
   cout<<endl;
   root->top_view(root);
   cout<<endl;
   root->bottom_view(root);
   cout<<endl;
   root->height_tree(root);
   cout<<endl;
   cout<<root->get_tree_height(root);
   cout<<endl;
   int* a=new int[10];
   for(int i=0;i<10;i++){
       a[i]=3*i;
   }
   root=root->array_to_bst(a,0,5);
   root->preorder(root);
   cout<<endl;
   int* a1=new int[10];
   for(int i=0;i<10;i++){
       a1[i]=i+1;
   }
   unordered_map<int,int> mp;
   int b[10]={6,3,1,2,5,4,8,7,10,9};
   for(int i=0;i<10;i++){
       mp[a1[i]]=i;
   }
   int pre_idx=0;
   root=root->create_tree_preorder_inorder(b,0,9,mp,pre_idx);
   root->preorder(root);
   cout<<endl;
   root->inorder(root);
   cout<<endl;
   queue<int> s;
   root->serialization(root,s);
//   while(!s.empty()){
//       cout<<s.front()<<" ";
//       s.pop();
//   }
   root=root->Deserialization(s);
   
   
   
   return 0;
}
