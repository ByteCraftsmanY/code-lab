#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<int> vc;
typedef pair<int, int> pr;
/*

    IN BST:
        Left child data must be smaller then parant data
        Right child data must be smaller then parant data

        there will not be data duplicacy

        Inorder gives sorted data

        Complexity : O(nlog(n))

*/
class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node(int data) { this->data = data, this->lchild = NULL, this->rchild = NULL; }
};
class BST
{
private:
    Node *root, *temp;
    Node *findInorderPredescessor(Node *);
    Node *findInorderSucessor(Node *);
    Node *findParant(Node *, Node *);
    bool deleteAndManage(Node *);

public:
    BST(Node *);
    void setRoot(Node *);
    Node *getRoot();
    Node *insert(int, Node *);
    void iInsert(int);
    void inorder(Node *);
    Node *search(int, Node *);
    bool iSearch(int);
    int height(Node *);
    bool deleteNode(int, Node *);
    void createBSTusingPreorder(vector<int> &);
};
BST::BST(Node *p = NULL) { this->root = p, this->temp = NULL; }
Node *BST::getRoot() { return root; }
void BST::setRoot(Node *p) { this->root = p; }
Node *BST::insert(int data, Node *p)
{
    if (!p)
        return new Node(data);
    else if (data < p->data)
        p->lchild = insert(data, p->lchild);
    else
        p->rchild = insert(data, p->rchild);
    return p;
}
void BST::iInsert(int data)
{
    if (!root)
    {
        root = new Node(data);
        return;
    }
    temp = root;
    Node *tail = temp;
    while (temp)
    {
        tail = temp;
        if (temp->data > data)
            temp = temp->lchild;
        else if (temp->data < data)
            temp = temp->rchild;
    }
    temp = new Node(data);
    (tail->data > data) ? tail->lchild = temp : tail->rchild = temp;
}
void BST::inorder(Node *p)
{
    if (!p)
        return;
    inorder(p->lchild);
    cout << p->data << " ";
    inorder(p->rchild);
}
Node *BST::search(int data, Node *p)
{
    if (!p)
        return NULL;
    else if (p->data == data)
        return p;
    else if (p->data > data)
        return search(data, p->lchild);
    return search(data, p->rchild);
}
bool BST::iSearch(int data)
{
    temp = root;
    while (temp)
    {
        if (temp->data == data)
            return true;
        if (temp->data > data)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    return false;
}
//Delete from BST
/*
    Delete data from BST
    after deleting node value its position must be filled with
        inorder predecessor : RIght most child of a left sub tree
            or
        inorder sucesser : Left most child of a right sub tree

    if inorder predecessor or inorder sucesser has also childs then repeat the process agian and again
*/
int BST::height(Node *p)
{
    if (!p)
        return 0;
    return (max(height(p->lchild), height(p->rchild)) + 1);
}
Node *BST::findParant(Node *r, Node *v)
{
    if (!v || (r == v))
        return NULL;
    if (r->data > v->data)
    {
        if (r->lchild && (r->lchild == v))
            return r;
        return findParant(r->lchild, v);
    }
    else
    {
        if (r->rchild && (r->rchild == v))
            return r;
        return findParant(r->rchild, v);
    }
}
Node *BST::findInorderPredescessor(Node *p)
{
    if (!p || !p->lchild)
        return NULL;
    p = p->lchild;
    while (p->rchild)
        p = p->rchild;
    return p;
}
Node *BST::findInorderSucessor(Node *p)
{
    if (!p || !p->rchild)
        return NULL;
    p = p->rchild;
    while (p->lchild)
        p = p->lchild;
    return p;
}
bool BST::deleteAndManage(Node *p)
{
    Node *t = NULL;
    t = (height(p->lchild) < height(p->rchild)) ? findInorderSucessor(p) : findInorderPredescessor(p);
    if (t && (t->lchild || t->rchild))
    {
        p->data = t->data;
        return deleteAndManage(t);
    }
    else
    {
        Node *parant = findParant(p, t);
        p->data = t->data;
        if (parant)
            (parant->lchild == t)
                ? parant->lchild = NULL
                : parant->rchild = NULL;
    }
    return true;
}
bool BST::deleteNode(int data, Node *p)
{
    temp = search(data, p);
    if (!temp)
    {
        cout << "\nNot Found\n";
        return false;
    }
    if (!temp->lchild && !temp->rchild)
    {
        Node *parant = findParant(p, temp);
        if (parant)
            (parant->lchild == temp)
                ? parant->lchild = NULL
                : parant->rchild = NULL;
        if (temp == root)
        {
            delete root;
            root = NULL;
        }
        temp = NULL;
        delete temp;
        return true;
    }
    return deleteAndManage(temp);
}
void BST::createBSTusingPreorder(vector<int> &arr)
{
    stack<Node *> st;
    for (auto x : arr)
    {
        if (!root)
        {
            root = new Node(x);
            temp = root;
        }
        else if (x < temp->data)
        {
            temp->lchild = new Node(x);
            st.push(temp);
            temp = temp->lchild;
        }
        else
        {
            while (st.empty() == false && st.top()->data < x)
            {
                temp = st.top();
                st.pop();
            }
            temp->rchild = new Node(x);
            temp = temp->rchild;
        }
    }
}
int main()
{
    freopen("#input.txt", "r++", stdin);
    freopen("#output.txt", "w++", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    if (0)
    {
        BST *t = new BST();
        Node *ptr = NULL;
        ptr = t->insert(12, ptr);
        t->setRoot(ptr);
        t->insert(4, ptr);
        t->insert(56, ptr);
        t->insert(6, ptr);
        t->inorder(ptr);
        cout << (t->search(11, ptr) ? "\nFound\n" : "\nNot FOund\n");
    }
    {
        BST t;
        vc arr;
        REP(i, 0, 8)
        {
            int v;
            cin >> v;
            // t.iInsert(v);
            arr.emplace_back(v);
        }
        // t.iInsert(40);
        t.createBSTusingPreorder(arr);
        // cout << t.deleteNode(30, t.getRoot()) << endl;
        t.inorder(t.getRoot());
        // cout << "\n"
        //      << t.iSearch(5);
        cout << "\n";
        //  << t.findInorderSucessor(t.search(4, t.getRoot()))->data;
        //  << t.findInorderPredescessor(t.search(4, t.getRoot()))->data;
        //  << t.findParant(t.getRoot(), t.search(5, t.getRoot()))->data;
    }
    return 0;
}
