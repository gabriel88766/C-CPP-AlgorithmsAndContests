#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+3;   
int p[N], sz[N], ans[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1; }
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

//BASED ON MANACHER ODD
/*
void manacher_odd(string s){
    int n = s.size();
    s = '^' + s + '$';
    int l = 0, r = 1;
    for(int i=1;i<=n; i++){
        if(i >= r){
            while(s[i - sz[i]] == s[i + sz[i]]) sz[i]++;
        }else{
            int p = l + r - i;
            sz[i] = min(sz[p], p - l);
            while(s[i - sz[i]] == s[i + sz[i]]) sz[i]++;
        }
        if(i + sz[i] > r){
            r = i + sz[i];
            l = i - sz[i];
        }
    }
}
*/
int szz[N];
int v[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    init();
    int l = 0, r = 1;
    bool ok = true;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(!ok) continue;
        if(i >= r){
            while(szz[i] < v[i]){
                szz[i]++;
                unite(i - szz[i], i + szz[i]);
            }
        }else{
            int p = l + r - i;
            szz[i] = min(szz[p], p - l);


            if(szz[p] < min(p-l, v[i])){
                ok = false;
            }
            while(szz[i] < v[i]){
                szz[i]++;
                unite(i - szz[i], i + szz[i]);
            }
            if(szz[i] != v[i]){
                ok = false;
            }
        }
        if(i + szz[i] > r){
            r = i + szz[i];
            l = i - szz[i];
        }
    }
    vector<vector<int>> fbd(n+1);
    for(int i=1;i<=n;i++){
        if(2 <= i - v[i] && i + v[i] <= n - 1){
            if(get(i-v[i]-1) == get(i + v[i] + 1)) ok = false;
            int a = min(get(i - v[i] - 1), get(i + v[i] + 1));
            int b = max(get(i - v[i] - 1), get(i + v[i] + 1));
            fbd[a].push_back(b);
            fbd[b].push_back(a);
        }
    }
    if(ok){
        cout << "Yes\n";
        int cnt = 0;
        ans[get(1)] = ++cnt;
        vector<int> cc = {get(1)};
        for(int i=1;i<=n;i++){
            if(ans[get(i)]);
            else{
                //check if can unite
                set<int> cfb;
                for(auto x : fbd[get(i)]) cfb.insert(get(x));
                for(auto x : cc){
                    if(!cfb.count(get(x))){
                        ans[get(i)] = ans[get(x)];
                        unite(i, x);
                        break;
                    }
                }
                if(!ans[get(i)]){
                    ans[get(i)] = ++cnt;
                    cc.push_back(get(i));
                }
                
            }
            cout << ans[get(i)] << " ";
        }
        cout << "\n";
    }else cout << "No\n";
}
