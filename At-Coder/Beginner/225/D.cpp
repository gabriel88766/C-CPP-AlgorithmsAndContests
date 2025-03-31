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

const int N = 1e5+3;

LinkedList lst[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) lst[i].val = i;
    for(int i=1;i<=q;i++){
        int x, y;
        cin >> x;
        if(x == 1){
            cin >> x >> y;
            lst[x].insertRight(&lst[y]);
        }else if(x == 2){
            cin >> x >> y;
            lst[x].next->prev = nullptr;
            lst[x].next = nullptr;
        }else{
            cin >> x;
            LinkedList *l = &lst[x];
            while(l->prev != nullptr) l = l->prev;
            vector<int> ans;
            while(l != nullptr){
                ans.push_back(l->val);
                l = l->next;
            }
            cout << ans.size() << " ";
            for(auto &x:ans) cout << x << " ";
            cout << "\n";
        }
    }
}
