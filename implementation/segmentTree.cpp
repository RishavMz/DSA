#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node
{
public:
    int data;
    Node* parent;
    Node* lchild;
    Node* rchild;
    int lb;
    int rb;

    Node()
    {
        data = 0;
        parent = NULL;
        lchild = NULL;
        rchild = NULL;
        int lb = NULL;
        int rb = NULL;
    }
};

class SegmentTree
{
public:
    Node* root = new Node();
    vector<Node*> leaves;
    SegmentTree(vector<int> v)
    {
        vector<Node*> nodes;
        for(int i=0; i<v.size(); i++)
        {
            Node* newnode = new Node();
            newnode->data = v[i];
            newnode->lb = i;
            newnode->rb = i;
            nodes.push_back(newnode);
            leaves.push_back(newnode);
        }
        vector<Node*> temp;
        while(nodes.size()>1)
        {
            for(int i=0; i<nodes.size(); i+=2)
            {
                Node* newnode = new Node();
                if(i == nodes.size()-1)
                {
                    newnode->data = nodes[i]->data;
                    newnode->lchild = nodes[i];
                    newnode->lb = nodes[i]->lb;
                    newnode->rb = nodes[i]->rb;
                    nodes[i]->parent = newnode;
                }
                else
                {
                    newnode->data = nodes[i]->data + nodes[i+1]->data;
                    newnode->lchild = nodes[i];
                    newnode->rchild = nodes[i+1];
                    newnode->lb = nodes[i]->lb;
                    newnode->rb = nodes[i+1]->rb;
                    nodes[i]->parent = newnode;
                    nodes[i+1]->parent = newnode;
                }
                temp.push_back(newnode);
            }
            nodes = temp;
            temp.clear();
        }
        root = nodes[0];    
    }

    void update(int index, int value)
    {
        int change = value - leaves[index]->data;
        Node* temp = new Node();
        temp = leaves[index];
        while(temp != NULL)
        {
            temp->data += change;
            temp = temp->parent;
        }
    }

    int getRange(Node* node, int low, int high)
    {
        if(node == NULL)
            return 0;
        if((node->lb > high) || (node->rb < low))
            return 0;
        if((node->lb >= low) && (node->rb <= high))
            return node->data;
        return getRange(node->lchild, low, high) + getRange(node->rchild, low, high);
    }

    int rangeSum(int low, int high)
    {
        return getRange(root, low, high);
    }

    void traverse()     // This function was developed solely for debugging purpose
    {
        queue<Node*>q;
        q.push(root);
        cout<<"Nodes | LowerBound | UpperBound"<<endl;;
        while(!q.empty())
        {
            if(q.front()->lchild)
                q.push(q.front()->lchild);
            if(q.front()->rchild)
                q.push(q.front()->rchild);
            cout<<q.front()->data<<" "<<q.front()->lb<<" "<<q.front()->rb<<endl;
            q.pop();
        }
        cout<<endl;
        cout<<"Leaves: ";
        for(auto i: leaves)
            cout<<i->data<<" ";
        cout<<endl;
    }
};
