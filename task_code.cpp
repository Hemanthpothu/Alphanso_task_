#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    char color;
    Node(int x){
        val=x;
        left=NULL;
        right=NULL;
        color='G';
    }
};
Node* construct(vector<int>&a)
{
    if(a.size()==0)
    return NULL;
    queue<Node*>q;
    Node* root=NULL;
    int i=0;
    root=new Node(a[i++]);
    q.push(root);
    while(!q.empty()&&i<a.size())
    {
        Node* curr=q.front();
        q.pop();
        int leftValue = a[i++];
        if (leftValue != 0) {
            curr->left = new Node(leftValue);
            q.push(curr->left);
        }
        if (i < a.size()) {
            int rightValue = a[i++];
            if (rightValue != 0) {
                curr->right = new Node(rightValue);
                q.push(curr->right);
            }
        }
    }
    return root;
}
void rightnodes(Node* root, unordered_set<Node*>&s)
{
    if(root==NULL)
    return ;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    int p=0;
    while(!q.empty())
    {
        int k=q.size();
        while(k--)
        {
            auto it=q.front();
            Node* curr=it.first;
            q.pop();
            if(k==0&&p==1&&it.second==1)
            {
                s.insert(curr);
            }
            if(curr->left)
            q.push({curr->left,0});
            if(curr->right)
            q.push({curr->right,1});
            p=1;
        }
    }
}
void leftviewcolor(Node* root, char &col,unordered_set<Node*>&s,unordered_set<Node*>&t)
{
    if(root==NULL)
    return ;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int k=q.size();
        int p=0;
        while(k--)
        {
            Node* curr=q.front();
            q.pop();
            if(p==0&&s.find(curr)==s.end())
            {
                t.insert(curr);
                curr->color=col;
                col=(col=='B')?'R':'B';
                p=1;
            }
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
    }
}
void bottomviewnodes(Node* root,vector<Node*>&res,unordered_set<Node*>&t)
{

    if(root==NULL)
    return ;
    if(root->left==NULL&&root->right==NULL&&t.find(root)==t.end())
    {
        res.push_back(root);
        t.insert(root);
        return ;
    }
    bottomviewnodes(root->left,res,t);
    bottomviewnodes(root->right,res,t);
}
void colorbottomnodes(vector<Node*>&res,char &col)
{
    for(int i=0;i<res.size();i++)
    {
        Node* curr=res[i];
        curr->color=col;
        col=(col=='B')?'R':'B';
    }
}
void rightviewcolor(Node* root,char &col,unordered_set<Node*>&s)
{
    if(root==NULL)
    return ;
    queue<Node*>q;
    q.push(root);
    vector<Node*>v;
    while(!q.empty())
    {
        int k=q.size();
        while(k--)
        {
            Node* curr=q.front();
            q.pop();
            if(k==0)
            {
                v.push_back(curr);
            }
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
    }
    for(int i=v.size()-2;i>0;i--)
    {
        Node* curr=v[i];
        if(s.find(curr)==s.end())
        {
            curr->color=col;
            col=(col=='B')?'R':'B';
            s.insert(curr);
        }
    }
}
void print(Node* root)
{
    if(root==NULL)
    return ;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int k=q.size();
        while(k--)
        {
            Node* curr=q.front();
            q.pop();
            cout<<curr->color<<' ';
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
        cout<<'\n';
    }
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        Node* root=construct(a);
        char col = 'B';
        unordered_set<Node*>s;
        unordered_set<Node*>t;
        rightnodes(root,s);
        leftviewcolor(root,col,s,t);
        vector<Node*>res;
        bottomviewnodes(root,res,t);
        colorbottomnodes(res,col);
        rightviewcolor(root,col,t);
        print(root);
        cout<<'\n';
        cout<<'\n';
    }
}
