#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Node{
    int val;
    Node *left = nullptr, *right = nullptr;
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    Node *beg, *cur;
    map<int, Node*> mp;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(i == 0){
            beg = new Node();
            beg->val = x;
            cur = beg;
        }else{
            Node *newn = new Node();
            newn->val = x;
            newn->left = cur;
            cur->right = newn;
            cur = newn;
        }
        mp[x] = cur;
    }
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x, y;
            cin >> x >> y;
            cur = mp[x];
            Node *newn = new Node();
            newn->val = y;
            newn->right = cur->right;
            if(cur->right != nullptr) cur->right->left = newn;
            newn->left = cur;
            cur->right = newn;
            mp[y] = newn;
        }else{
            int x;
            cin >> x;
            cur = mp[x];
            if(cur == beg) beg = cur->right;
            if(cur->left != nullptr) cur->left->right = cur->right;
            if(cur->right != nullptr) cur->right->left = cur->left;
            delete(cur);
            mp.erase(x);
        }   
    }
    while(beg != nullptr){
        cout << beg->val << " ";
        beg = beg->right;
    }
}
