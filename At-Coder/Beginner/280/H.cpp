#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3; 
int n, c;
// n log n
int cnt[N], aux[N], mp2[N];
pair<int, int> cs[N];
vector<int> suffix_array(vector<int> &s){
    // s += "$";
    n = s.size(), c=-1;
    vector<int> mp(n);

    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=0;i<N;i++){
        if(cnt[i]) mp2[i] = ++c;
        if(i) cnt[i] += cnt[i-1];
    } 
    for(int i=0;i<n;i++) mp[--cnt[s[i]]] = i; 
    for(int i=0;i<n;i++) cs[i].first = mp2[s[i]];

    for(int i=0;(1 << i) < n;i++){
        fill(cnt, cnt + c + 2, 0);
        int offset = 1 << i;
        for(int j=0;j<n;j++){
            int mindex = (j + offset) >= n ? j + offset - n : j + offset;
            cs[j].second = cs[mindex].first;
            cnt[cs[j].second + 1]++;
        }
        //begin raddix_sort of pair O(n)
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n; j++) aux[cnt[cs[j].second]++] = j;
        fill(cnt, cnt + c + 2, 0);
        for(int j=0; j<n; j++) cnt[cs[j].first+1]++; 
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n;j++) mp[cnt[cs[aux[j]].first]++] = aux[j]; 
        //end raddix_sort
        aux[mp[0]] = c = 0;
        for(int j=1;j<n;j++){
            if(cs[mp[j]] == cs[mp[j-1]]) aux[mp[j]] = c;
            else aux[mp[j]] = ++c;
        }
        for(int j=0;j<n;j++) cs[j].first = aux[j];
    }
    return mp;
}
//longest common prefix in O(n), between 2 consecutive indexes of suffix array
vector<int> lcp(vector<int> &s, vector<int> &sa){
    vector<int> ans(n - 1, 0);
    vector<int> invmp(n, 0);
    for(int i=0;i<n; i++) {invmp[sa[i]] = i;}
    int cnt = 0;
    for(int i=0;i < (n-1); i++){
        if(invmp[i] == (n-1)){
            cnt = 0;
            continue;
        }
        int j = sa[invmp[i] + 1];
        while (s[i+cnt] == s[j+cnt]) cnt++;
        ans[invmp[i]] = cnt;
        if (cnt) cnt--;
    }
    return ans;
}



const int M = 20; // M >= log2(N)
int sparse[N][M];

void build(vector<int> v){
    int n = v.size();
    for(int i=0;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

int query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> vs;
    vector<int> bg(n+1);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        bg[i] = vs.size();
        for(auto c : s){
            vs.push_back(c - 'a');
        }
        vs.push_back(26 + i);
    }
    bg[n] = vs.size();
    auto sa = suffix_array(vs);
    auto lc = lcp(vs, sa);
    vector<pair<int, int>> vx;
    int q;
    cin >> q;
    vector<tuple<int, int, int>> ans(q+1);
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        vx.push_back({x, i});
    }
    sort(vx.begin(), vx.end());
    int px = 0;
    ll tt = 0;
    build(lc);
    for(int i = 0; ; i++){
        if(px == q) break;
        if(vs[sa[i]] >= 26) assert(false);
        auto it = upper_bound(bg.begin(), bg.end(), sa[i]);
        int cv = i == 0 ? 0 : lc[i-1];
        int len = *it- sa[i] - 1;
        int idx = it - bg.begin();
        int l = sa[i] - *prev(it) + 1;
        for(int j = cv + 1; j <= lc[i]; j++){
            //TODO, solve
            int k = i;
            for(int jmp = n; jmp >= 1; jmp >>= 1){
                while(k + jmp < lc.size() && query(i, k + jmp) >= j) k += jmp;
            }
            tt += (k - i + 2);

            //END
            while(px < q && tt >= vx[px].first){
                int r = l + j - 1;
                ans[vx[px].second] = {idx, l, r};
                px++;
            }
            cv = j;
        }
        while(px < q && len - cv + tt >= vx[px].first){
            int r = l + cv + (vx[px].first - tt) - 1;
            ans[vx[px].second] = {idx, l, r};
            px++;
        }
        tt += len - cv;
    }
    for(int i=1;i<=q;i++){
        cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << "\n";
    }
}
