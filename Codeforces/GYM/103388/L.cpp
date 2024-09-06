#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 6e5+3;   
int p[N], szd[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; szd[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(szd[a] < szd[b]) swap(a,b);
    p[b] = a;
    szd[a] += szd[b];
}

int sz[N];
pair<int,int> vp[N];
vector<int> vh[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    init();
    for(int i=1;i<=2*n;i++){
        vp[i] = {INF_INT, INF_INT};
    }
    for(int i=0;i<m;i++){
        int l, r;
        cin >> l >> r;
        int x = 2* l - 1;
        int y = 2 * r - 1;
        int c = (x + y) / 2;
        vp[c] = min(vp[c], make_pair(x, y));
    }
    int l = 0, r = 1;
    for(int i=1;i<=2*n;i++){
        auto [cl, cr] = vp[i];
        if(i >= r){
            while(get(i - sz[i]) == get(i + sz[i]) || (i - sz[i]) >= cl){
                unite(i - sz[i], i + sz[i]);
                sz[i]++;
            }
        }else{
            int p = l + r - i;
            sz[i] = min(sz[p], p - l);
            while(get(i - sz[i]) == get(i + sz[i]) || (i - sz[i]) >= cl){
                unite(i - sz[i], i + sz[i]);
                sz[i]++;
            }
        }
        if(i + sz[i] > r){
            r = i + sz[i];
            l = i - sz[i];
        }
    }
    int ans = 1;
    vector<int> st;
    for(int i=1;i<=n;i++){
        vh[get(2*i-1)].push_back(i);
        st.push_back(get(2*i-1));
    }
    sort(st.begin(), st.end());
    st.resize(unique(st.begin(), st.end()) - st.begin());
    for(auto x : st){
        bool h0 = false, h1 = false;
        for(auto y : vh[x]){
            if(s[y-1] == '1') h1 = true;
            if(s[y-1] == '0') h0 = true;
        }
        if(h1 && h0){
            ans = 0;
            break;
        }else if(h1 || h0); //nothing
        else ans = (ans * 2) % MOD;
    }
    cout << ans << "\n";
}
