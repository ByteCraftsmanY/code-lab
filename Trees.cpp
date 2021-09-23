#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;
//Binary Tree Formulas:
/*

    Number of trees that can be generated with n nodes
        case 1 : with unlabled node
            2n
              C                                          n
               n                        
            ______   (Catalenn Numbers)     or         [Submission of]          = T(i-1)*T(n-i)
             n+1                                            i = 1

            Total trees with max heights = pow(2,n-1);


        case 2 : with labled nodes
            2n
              C                     n
               n                        
            ______   *  n!     or         [Submission of]          = [T(i-1)*T(n-i)] * n!
             n+1                    i = 1

             because one tree can generate n! diffrent labeled trees

    Number of nodes when height(h) is given
        minNodes(n) = h+1;
        maxNodes(n) = pow(2,h+1)-1;
    Heights when nodes(n) are given
        minHeight(h) = log2(n+1)-1;
        maxHeight(h) = n-1;
    Relationship Between internal nodes vs external nodes
        deg(0) = deg(2)+1;
*/
//Strict Binary Tree Formula
/*
    Condition : Every Node can have 0 || 2 Child
    
    Height vs nodes
        when height is given
            minNodes(n) = 2h + 1
            maxNodes(n) = pow(2,h+1)-1
        when node is given
            minHeight(h) = log2(n+1)-1;
            maxHeight(h) = (n-1)/2

    Internal Nodes vs extenal nodes
        e = i + 1

*/
//Strict M-ary trees formula
/*
    Height vs nodes
        when Height(h) is given
            minNodes (n) = (m * h) +1
            maxNodes (n) = ( pow(M,h+1)-1 )/(m-1)
        when nodes(n) is given
            minHeight (h) = logM((n*(m-1))+1)-1
            maxHeight (h) = (n-1)/m


    internal nodes vs extenal nodes
        e  = 2*i + 1;
*/
//representation of binary tree
/*
    Array:
            fill level by level
            formula : 
            e = i
            lc = (2*i) +1
            rc = (2*i) +2
            parant of child = floor((i-1)/2)

    Linked Representation :
        struct Node
        {
            Node *leftChild;
            int data;
            Node *rightChild;
        }

        Number of nullptr = No. of nodes +1;

*/
// Full vs complete binary tree
/*
    full binary tree
        It must have maximum nodes for its height(h) [pow(2,h+1)-1]
    complete binary tree
        * height - 1 must be full binary tree
        * last level must fill from left to right without skipping any element
        
        or
        can be represented using array without skiping any element
    full binary tree can be a complete binary tree
                            but
    complete binary tree need not to be a full binary tree 

*/
// Strict vs complete
/*
    for some authers
        strict = complete
        complete = almost complete
*/
class Node
{
public:
    Node *leftChild;
    char data;
    Node *rightChild;
    Node(char d, Node *lc, Node *rc)
    {
        this->data = d;
        this->leftChild = lc;
        this->rightChild = rc;
    }
};
class tree
{
private:
    Node *root = NULL, *temp = NULL;
    queue<Node *> q;
    char val;

public:
    Node *getRoot()
    {
        return root;
    }
    void createTree();
    void preorder(Node *);
    void inorder(Node *);
    void postorder(Node *);
    void iterativePreorder(Node *);
    void iterativeInorder(Node *);
    void iterativePostorder(Node *);
    void levelorder(Node *);
    int height(Node *);
    int countNodes(Node *);
    int countLeafNodes(Node *);
    int countNonLeafNodes(Node *);
    int countNodesDeg1(Node *);
    int countNodesDeg2(Node *);

    //Tree Print In with format
    int getLeft(int r, int c, int h)
    {
        int p = pow(2, h - r - 1);
        return c - p;
    }
    int getRight(int r, int c, int h)
    {
        int p = pow(2, h - r - 1);
        return c + p;
    }
    vector<vector<string>> printTree(Node *root)
    {
        queue<pair<Node *, pair<int, int>>> q;
        Node *t = root;
        int h = height(root);
        int c = pow(2, h) - 1;
        vector<vector<string>> arr(h, vector<string>(c, " "));
        int r = 0;
        q.push({t, {0, (c - 1) / 2}});
        while (q.empty() == false)
        {
            pair<Node *, pair<int, int>> pr = q.front();
            q.pop();
            auto [rw, cl] = pr.second;
            // cout<<"insert "<<pr.first->val <<"to["<<rw<<","<<cl<<"]\n";
            arr[rw][cl] = pr.first->data; //to_string(pr.first->data);
            if (pr.first->leftChild)
            {
                // cout<<"Inserted l "<<pr.first->left->val<<endl;
                q.push({pr.first->leftChild, {rw + 1, getLeft(rw + 1, cl, h)}});
            }
            if (pr.first->rightChild)
            {
                q.push({pr.first->rightChild, {rw + 1, getRight(rw + 1, cl, h)}});
            }
            if (pr.first->leftChild || pr.first->rightChild)
                r++;
        }
        for (auto x : arr)
        {
            auto y = x;
            for (auto z : y)
                cout << z << " ";
            cout << endl;
        }
        return arr;
    }
};
void tree::createTree()
{
    cout << "Enter root ";
    cin >> val;
    cout << endl;
    root = new Node(val, NULL, NULL);
    q.push(root);
    while (!q.empty())
    {
        cout << "enter left child of " << q.front()->data << " ";
        cin >> val;
        if (val != 'x')
        {
            temp = new Node(val, NULL, NULL);
            q.front()->leftChild = temp;
            q.push(temp);
        }
        cout << endl;
        cout << "enter right child of " << q.front()->data << " ";
        cin >> val;
        if (val != 'x')
        {
            temp = new Node(val, NULL, NULL);
            q.front()->rightChild = temp;
            q.push(temp);
        }
        q.pop();
        cout << endl;
    }
}

/*
    total Number of calls : = 2n + 1
        1st n for nodes , 2nd n for null pointers
    
    Maximum stack size : height + 2

    Complexity of tree travrsals : O(n)
*/

void tree::preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->leftChild);
        preorder(p->rightChild);
    }
}
void tree::inorder(Node *p)
{
    if (p)
    {

        inorder(p->leftChild);
        cout << p->data << " ";
        inorder(p->rightChild);
    }
}
void tree::postorder(Node *p)
{
    if (p)
    {
        postorder(p->leftChild);
        postorder(p->rightChild);
        cout << p->data << " ";
    }
}
void tree ::iterativePreorder(Node *p)
{
    //TO DO
}
void tree ::iterativeInorder(Node *p)
{
    stack<Node *> s;
    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->leftChild;
        }
        else
        {
            p = s.top();
            cout << p->data << " ";
            s.pop();
            p = p->rightChild;
        }
    }
}
void tree ::iterativePostorder(Node *p)
{
    stack<Node *> s;
    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->leftChild;
        }
        else
        {
            p = s.top();
            p = p->rightChild;
            if (!p)
            {
                p = s.top();
                s.pop();
                cout << p->data << " ";
                (s.empty() == false)
                    ? p = s.top()
                    : p = NULL;
            }
        }
    }
}
void tree::levelorder(Node *p)
{
    q.push(p);
    while (q.empty() == false)
    {
        temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->leftChild)
            q.push(temp->leftChild);
        if (temp->rightChild)
            q.push(temp->rightChild);
    }
}
int tree::height(Node *p)
{
    if (p == NULL)
        return 0;
    int x = height(p->leftChild);
    int y = height(p->rightChild);
    return x > y ? x + 1 : y + 1;
}
int tree::countNodes(Node *p)
{
    if (!p)
        return 0;
    return countNodes(p->leftChild) + countNodes(p->rightChild) + 1;
}
int tree::countLeafNodes(Node *p)
{
    if (!p)
        return 0;
    if (!p->leftChild && !p->rightChild)
        return countLeafNodes(p->leftChild) + countLeafNodes(p->rightChild) + 1;
    return countLeafNodes(p->leftChild) + countLeafNodes(p->rightChild);
}
int tree::countNonLeafNodes(Node *p)
{
    if (!p)
        return 0;
    if ((p->leftChild || p->rightChild))
        return countNonLeafNodes(p->leftChild) + countNonLeafNodes(p->rightChild) + 1;
    return countNonLeafNodes(p->leftChild) + countNonLeafNodes(p->rightChild);
}
int tree::countNodesDeg1(Node *p)
{
    if (p == NULL)
        return 0;
    if //((p->leftChild != NULL && p->rightChild == NULL) || (p->leftChild == NULL && p->rightChild != NULL))
        //or
        (p->leftChild != NULL ^ p->rightChild != NULL)
        return countNodesDeg1(p->leftChild) + countNodesDeg1(p->rightChild) + 1;
    return countNodesDeg1(p->leftChild) + countNodesDeg1(p->rightChild);
}
int tree::countNodesDeg2(Node *p)
{
    if (!p)
        return 0;
    if ((p->leftChild && p->rightChild))
        return countNodesDeg2(p->leftChild) + countNodesDeg2(p->rightChild) + 1;
    return countNodesDeg2(p->leftChild) + countNodesDeg2(p->rightChild);
}

int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    tree t;
    t.createTree();
    Node *temp = t.getRoot();
    // t.preorder(temp);
    // cout << endl;
    // t.iterativePreorder(temp);
    // t.inorder(temp);
    // cout << endl;
    // t.iterativeInorder(temp);
    // t.postorder(temp);
    // cout << endl;
    // t.iterativePostorder(temp);
    // t.levelorder(temp);
    // cout << endl;
    cout << t.height(temp) << endl;
    cout << t.countNodes(temp) << endl;
    cout << t.countLeafNodes(temp) << endl;
    cout << t.countNonLeafNodes(temp) << endl;
    cout << t.countNodesDeg1(temp) << endl;
    cout << t.countNodesDeg2(temp) << endl;
    vector<vector<string>> arr = t.printTree(temp);

    return 0;
}
