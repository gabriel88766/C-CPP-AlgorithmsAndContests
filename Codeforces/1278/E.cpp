#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct LinkedList{
    LinkedList *prev, *next;
    int val;
    LinkedList(){}
    LinkedList(int num){
        val = num;
        prev = nullptr;
        next = nullptr;
    }
    void insertRight(LinkedList *r){
        if(this->next != nullptr){
            this->next->prev = r;
            r->next = this->next;
        }
        r->prev = this;
        this->next = r;
    }
    void insertLeft(LinkedList *l){
        if(this->prev != nullptr){
            l->prev = this->prev;
            this->prev->next = l;
        }
        this->prev = l;
        l->next = this;
    }
};

const int N = 5e5+3;
vector<int> adj[N];
vector<LinkedList> l(N), r(N);
vector<int> pl(N), pr(N);
void dfs(int u, int p = 0){
    for(auto v : adj[u]){
        if(v != p){
            r[u].insertLeft(&l[v]);
            r[u].insertRight(&r[v]);
            dfs(v, u);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        l[i] = LinkedList(i);
        r[i] = LinkedList(i);
    }
    l[1].insertRight(&r[1]);
    dfs(1);
    int cnt = 0;
    LinkedList *rt = &l[1];
    
    while(rt != nullptr){
        if(pl[rt->val]) pr[rt->val] = ++cnt;
        else pl[rt->val] = ++cnt;
        rt = rt->next;
    }
    for(int i=1;i<=n;i++){
        cout << pl[i] << " " << pr[i] << "\n";
    }

}
