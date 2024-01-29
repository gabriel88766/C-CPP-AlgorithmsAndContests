#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st, lz;
    int n;
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, 0);
        lz.assign(4*n, 0);
    }

    void push(int l, int r, int p){
        if(lz[p] != 0){ //0 can be assigned? change!
            st[p] += lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] += lz[p]; // += increment = update
                lz[2 * p + 1] += lz[p];
            } 
            lz[p] = 0;
        }
    }

    int getGr(int l, int r, int p){
        if(l == r) return l;
        push(l, r, p);
        int m = (l + r)/2;
        push(l, m, 2*p);
        push(m+1, r, 2*p+1);
        if(st[2*p] == st[p]) return getGr(l, m, 2*p);
        else return getGr(m+1, r, 2*p+1);
    }
    int getGr(){
        return getGr(0, n-1, 1);
    }
    int query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, T val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, T val){
        update(i, j, val, 0, n-1, 1);
    }
};

int op(int a, int b){
    return max(a, b);
}

int el(){
    return 0;
}

struct Event{
    int i, l, r, v;
    bool operator< (const Event &ev){
        return i < ev.i;
    }
};

bool check(string &ans, vector<int> &adj){
    for(int i=0;i<adj.size();i++) if(__builtin_popcount(adj[i]) > 2) return false;
    vector<int> inx;
    for(int i=0;i<12;i++){
        if(__builtin_popcount(adj[i]) == 1) inx.push_back(i);
    }
    if(inx.size() == 0) return false;
    int x = inx[0];
    ans += ('a'+x);
    queue<int> q;
    q.push(x);
    vector<bool> vis(12, false);
    vis[x] = true;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(int j=0;j<12;j++){
            if((1 << j) & adj[u]){
                if(!vis[j]){
                    q.push(j);
                    vis[j] = true;
                    ans += ('a' + j);
                }
            }
        }
    }
    for(int i=0;i<12;i++) if(adj[i] != 0 && !vis[i]) return false;
    return true;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> adj(12, 0);
    vector<pair<string, int>> vp;
    for(int i=0;i<n;i++){
        string s;
        int c;
        cin >> c >> s;
        auto v = adj;
        for(int i=0;i<s.size();i++){
            if(i != 0){
                v[s[i]-'a'] |= (1 << (s[i-1]-'a'));
            }
            if(i != (s.size()-1)){
                v[s[i]-'a'] |= (1 << (s[i+1]-'a'));
            }
        }
        string ans;
        if(check(ans, v)){
            vp.push_back({ans, c});
        }   
    }
    n = vp.size();
    vector<int> ms;
    for(int i=0;i<(1 << 12);i++){
        if(i & 1) continue; //considering only half wlog
        if(__builtin_popcount(i) == 6) ms.push_back(i);
    }
    const string aux = "abcdefghijkl";
    string ans = aux;
    int maxv = 0;
    for(auto x : ms){
        SegmentTreeLazy<int, op, el> st(720);
        string s1, s2;
        for(int j=0;j<12;j++){
            if((1 << j) & x) s1 += ('a' + j);
            else s2 += ('a' + j);
        }
        map<string, int> mp1, mp2;
        map<int, string> invmp1, invmp2;
        vector<int> perm = {0, 1, 2, 3, 4, 5};
        int cnt = 0;
        do{
            string t1, t2;
            for(auto x : perm){
                t1 += s1[x];
                t2 += s2[x];
            }
            reverse(t1.begin(), t1.end());
            invmp1[cnt] = t1;
            invmp2[cnt] = t2;
            mp1[t1] = mp2[t2] = cnt++;
        }while(next_permutation(perm.begin(), perm.end()));

        map<string, int> pre, suf;
        vector<Event> evt;
        for(int i=0;i<n;i++){
            int c1 = 0, c2 = 0;
            for(auto c : vp[i].first){
                int num = c - 'a';
                if((1 << num) & x) c1++;
                else c2++;
            }
            if(c1 == 0){
                //check all possible suffix
                auto str = vp[i].first;
                suf[str] += vp[i].second;
                reverse(str.begin(), str.end());
                suf[str] += vp[i].second;
            }else if(c2 == 0){
                auto str = vp[i].first;
                pre[str] += vp[i].second;
                reverse(str.begin(), str.end());
                pre[str] += vp[i].second;
            }else{
                string sn = vp[i].first;
                if(((1 << (sn[0] - 'a')) & x) == 0){
                    reverse(sn.begin(), sn.end());
                }
                bool ok = true;
                for(int j=0;j<c1;j++){
                    if( ((1 << (sn[j]-'a')) & x) == 0) ok = false;
                }
                if(ok){
                    //prefix, suffix
                    string stp, sts;
                    vector<bool> insn(12, false);
                    for(auto cs : sn) insn[cs-'a'] = true;
                    for(int j=0;j<12;j++){
                        if(insn[j]) continue;
                        if((1 << j) & x){
                            stp += 'a' + j;
                        }else{
                            sts += 'a' + j;
                        }
                    }
                    string lp = stp + sn.substr(0, c1);
                    reverse(stp.begin(), stp.end());
                    string fp = stp + sn.substr(0, c1);
                    string fs = sn.substr(c1, c2) + sts;
                    reverse(sts.begin(), sts.end());
                    string ls = sn.substr(c1, c2) + sts;
                    evt.push_back({mp1[fp], mp2[fs], mp2[ls], vp[i].second}); 
                    evt.push_back({mp1[lp]+1, mp2[fs], mp2[ls], -vp[i].second});
                }
            }
        }
        sort(evt.begin(), evt.end());
        vector<int> v1(720, 0);
        for(auto [str, ind] : mp1){
            for(int j=0;j<6;j++){
                for(int k=1;k<=6-j;k++){
                    if(pre.count(str.substr(j, k))) v1[ind] += pre[str.substr(j, k)];
                }
            }
        }
        for(auto [str, ind] : mp2){
            for(int j=0;j<6;j++){
                for(int k=1;k<=6-j;k++){
                    if(suf.count(str.substr(j, k))) st.update(ind, ind, suf[str.substr(j, k)]);
                }
            }
        }
        int p = 0;
        for(int j=0;j<720;j++){
            while(p < evt.size() && evt[p].i == j){
                st.update(evt[p].l, evt[p].r, evt[p].v);
                p++;
            }
            int curv = v1[j] + st.query(0, 719);
            if(curv > maxv){
                maxv = curv;
                ans = invmp1[j] + invmp2[st.getGr()];
            }
        }

    }
    cout << ans << "\n";
}
