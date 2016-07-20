#include <bits/stdc++.h>
using namespace std;

vector<vector<int> >tree;
int n,t;
struct treeNode
{
	struct treeNode *left;
	int data;
	struct treeNode *right;
};
typedef struct treeNode node;

node* CreateTree(vector<vector<int> >tree)
{
	vector<node*> tree_node(n+1);
	for(int i=1;i<=n;i++)
	{
		tree_node[i] = (node*) malloc(sizeof(node));
        tree_node[i]->left = NULL;
		tree_node[i]->data = i;
		tree_node[i]->left = NULL;
	}

	for(int i=1;i<=n;i++)
	{
        if(tree[i][0]!=-1)
            tree_node[i]->left = tree_node[tree[i][0]];
        if(tree[i][1]!=-1)
		tree_node[i]->right = tree_node[tree[i][1]];
	}

	return tree_node[1];
}

void inorder(node* root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
int main()
{
	int l,r;;
	cin>>n;

	tree.resize(n+1);
	int level[n+1] = {-1};
	level[1] = 1; // level of parent
	for(int i=1;i<=n;i++)
	{
		cin>>l>>r;
		tree[i].push_back(l);
		tree[i].push_back(r);
		level[l] = level[r] = level[i] + 1;
	}
    int depth = level[n];
    // find all nodes in a given depth

    vector<vector<int> >level_node;
    level_node.resize(depth+1);

    for(int i=1;i<=depth;i++)
        for(int j=1;j<=n;j++)
            if(level[j]==i)
                level_node[i].push_back(j);

    cin>>t;
	while(t--)
	{
	    int k;
		cin>>k;
		int i = 1;
		for(int h=k;h<=depth;h=h*i)
		{
		    for(int q=0;q<level_node[h].size();q++)
            {
                int val = level_node[h][q];
                swap(tree[val][0],tree[val][1]);
            }
			i++;
		}
		node* root = CreateTree(tree);
		inorder(root);
		cout<<endl;
	}
}
