#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Node{
    int a;
    int d;
    int dmg;
    int ind;
    Node *next = nullptr;
    Node *prev = nullptr;
    void update(){
        dmg = 0;
        if(next != nullptr) dmg += next->a;
        if(prev != nullptr) dmg += prev->a;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<Node> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i].a;
        for(int i=1;i<=n;i++) cin >> v[i].d;
        for(int i=1;i<=n;i++){
            v[i].ind = i;
            if(i != 1){
                v[i].prev = &v[i-1];
            }
            if(i != n){
                v[i].next = &v[i+1];
            }
            v[i].update();
        }
        vector<int> rml;
        vector<bool> used(n+1, false);
        for(int i=1;i<=n;i++){
            if(v[i].dmg > v[i].d){
                rml.push_back(i);
                used[i] = true;
            }
        }
        
        for(int i=0;i<n;i++){
            if(rml.size()){
                cout << rml.size() << " ";
                vector<int> chk;
                for(auto x : rml){
                    if(v[x].prev != nullptr){
                        v[x].prev->next = v[x].next;
                        v[x].prev->update();
                        chk.push_back(v[x].prev->ind);
                    }
                    if(v[x].next != nullptr){
                        v[x].next->prev = v[x].prev;
                        v[x].next->update();
                        chk.push_back(v[x].next->ind);
                    }
                }
                rml.clear();
                for(auto x : chk){
                    if(!used[x]){
                        if(v[x].dmg > v[x].d){
                            used[x] = true;
                            rml.push_back(x);
                        }
                    }
                }
            }else cout << "0 ";
        }
        cout << "\n";
    }
}
