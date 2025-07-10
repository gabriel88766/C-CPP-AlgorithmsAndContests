#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 60005;
bool vis[N];
vector<bool> vis1(N), vis2(N);
vector<int> pr[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //this problem is a 2-sat kind, but we can't solve properly
    //gonna make 2 dfs simultaneously. Why? at least one of them will not be repeated.
    //It will be better if we don't need to repeat both, but if they are both almost same size, complexity OK
    //then, if there is a node we can't chose both, then not satisfiable.
    int n;
    cin >> n;
    map<int, vector<int>> mp; //for each prime;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;//a is 2*i, b is 2*i+1
        for(int j=2;j*j<=a;j++){
            if(a % j == 0){
                while(a % j == 0) a /= j;
                mp[j].push_back(2*i);
                pr[2*i].push_back(j);
            }
        }
        if(a != 1){
             mp[a].push_back(2*i);
             pr[2*i].push_back(a);
        }
        for(int j=2;j*j<=b;j++){
            if(b % j == 0){
                while(b % j == 0) b /= j;
                mp[j].push_back(2*i+1);
                pr[2*i+1].push_back(j);
            }
        }
        if(b != 1){
            mp[b].push_back(2*i + 1);
            pr[2*i+1].push_back(b);
        }
    }
    bool ok = true;
    for(int i=0;i<n;i+=2){
        if(vis[2*i] || vis[2*i+1]) continue;
        bool ok1 = true, ok2 = true;
        vector<int> v1;
        vector<int> v2;
        queue<pair<int, int>> nv1, nv2;
        for(auto x : pr[2*i]){
            nv1.push({x, 2*i});
        }
        for(auto x : pr[2*i+1]){
            nv2.push({x, 2*i + 1});
        }
        vis1[2*i] = true;
        vis2[2*i+1] = true;
        v1.push_back(2*i);
        v2.push_back(2*i+1);
        auto func = [&](vector<int> &v, queue<pair<int, int>> &qv, vector<bool> &vis, bool &ok){
            for(auto x : mp[qv.front().first]){
                if(x == qv.front().second) continue;
                if(vis[x^1]) continue;
                vis[x^1] = true;
                v.push_back(x^1);
                if(vis[x] && vis[x^1]){
                    ok = false;
                    break;
                }
                for(auto y : pr[x^1]){
                    qv.push({y, x^1});
                }
            }
            qv.pop();
        };
        while(ok1 && ok2){
            if(nv1.size() && nv2.size()){
                if(v1.size() + mp[nv1.front().first].size() > v2.size() + mp[nv2.front().first].size()){
                    func(v2, nv2, vis2, ok2);
                }else{
                    func(v1, nv1, vis1, ok1);
                }
            }else{
                if(nv2.size()){
                    ok2 = false; //v1 is ok..
                }else{
                    ok1 = false; //v2 is ok
                }
            }
        }
        while(ok1 && nv1.size()){
            func(v1, nv1, vis1, ok1);
        }
        while(ok2 && nv2.size()){
            func(v2, nv2, vis2, ok2);
        }
        if(ok1){
            for(auto x : v1) vis[x] = true;
        }else if(ok2){
            for(auto x : v2) vis[x] = true;
        }else{
            ok = false;
            break;
        }
        for(auto x : v1){
            vis1[x] = false;
        }
        for(auto x : v2){
            vis2[x] = false;
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
