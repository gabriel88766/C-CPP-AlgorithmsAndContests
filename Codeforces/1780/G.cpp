// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


//BASED ON Linear Suffix Array Construction by Almost Pure Induced-Sorting 
//Ge Nong, Sen Zhang Wai, Hong Chan
//NEED TO IMPROVE TO REAL O(n), but this O(n log n) is fast, anyway.
const int N = 1e6+5; 
int n;
int hd[N], adv[N];

vector<int> induced_sort(vector<int> &v, vector<bool> &type){
    int n = v.size();
    vector<int> sc;
    for(int i=1;i<n;i++){
        if(type[i] == 1 && type[i-1] == 0){
            sc.push_back(i);
        }
    }
    int c = *max_element(v.begin(), v.end());
    vector<int> gs;
    if(sc.size() != 1){
        vector<bool> ntp(sc.size());
        vector<int> nv(sc.size());


        //BEGIN ALGO 1:

        /*vector<pair<vector<int>, int>> vx;
        for(int i=0;i<sc.size();i++){
            if(i == sc.size() - 1){
                vx.push_back({{0}, i});
            }else{
                vector<int> vn;
                for(int j=sc[i];j<=sc[i+1];j++) vn.push_back(v[j]);
                vn.push_back(c+1);
                vx.push_back({vn, i});
            }
        }
        sort(vx.begin(), vx.end());
        int p = -1;
        for(int i=0;i<sc.size();i++){
            if(i == 0 || vx[i].first != vx[i-1].first){
                nv[vx[i].second] = ++p;
            }else{
                nv[vx[i].second] = p;
            }
        }
        
        ntp.back() = 1;
        for(int i=nv.size()-1;i>=1;i--){
            if(nv[i-1] != nv[i]){
                if(nv[i-1] < nv[i]) ntp[i-1] = 1;
                else ntp[i-1] = 0;
            }else ntp[i-1] = ntp[i];
        }*/

        //END ALGO 1:

        //BEGIN ALGO 2:
        
        vector<int> val(c+1, 0);
        for(auto &x : sc) val[v[x]] = 1;
        int p = 0;
        for(int i=0;i<=c;i++){
            if(val[i]) val[i] = p++;
        }
        for(int i=sc.size() - 1;i>=0;i--){
            if(i == sc.size() - 1) ntp[i] = 1;
            else{
                int p1 = sc[i], p2 = sc[i+1];
                while(true){
                    assert(p1 < v.size() && p2 < v.size());
                    if(v[p1] != v[p2]){
                        if(v[p1] < v[p2]) ntp[i] = 1;
                        else ntp[i] = 0;
                        break;
                    }else if(type[p1] != type[p2]){
                        
                        if(type[p1] == 1) ntp[i] = 0;
                        else ntp[i] = 1;
                        break;
                    }else{
                        assert(i+2 < sc.size());
                        if(p1 == sc[i+1] || p2 == sc[i+2]){
                            assert(p1 == sc[i+1] && p2 == sc[i+2]);
                            ntp[i] = ntp[i+1];
                            break;
                        }else p1++, p2++;
                    }
                }
            }
            nv[i] = val[v[sc[i]]];
        }

        //END ALGO 2:

        gs = induced_sort(nv, ntp);
    }else{
        gs.push_back(0);
    }

    vector<int> sa(v.size(), -1);
    
    fill(hd, hd + c + 2, 0); //head pointer
    fill(adv, adv + c + 2, 0); //advance of head pointer
    for(int i=0;i<n;i++){
        hd[v[i] + 1]++;
    }
    for(int i=1;i<=(c+1);i++) hd[i] += hd[i-1];
    vector<int> ax(gs.size());
    for(int i=0;i<gs.size();i++) ax[gs[i]] = i;
    for(auto &x : sc){
        adv[v[x]]++;
    }
    for(int i=0;i<gs.size();i++){
        auto &y = sc[gs[i]];
        int pl = hd[v[y] + 1] - adv[v[y]]--;
        sa[pl] = y;
    }
    for(int i=0;i<n;i++){
        int j = i;
        if(sa[j] > 0){
            while(j <= i){
                if(sa[j] == 0) break;
                if(type[sa[j] - 1] != 0) break;
                int nj = hd[v[sa[i] - 1]] + adv[v[sa[i] - 1]]++;
                sa[nj] = sa[j] - 1;
                j = nj;
            }
        }
    }
    fill(adv, adv + c + 2, 0);
    for(int i=n-1;i>=0;i--){
        int j = i;
        if(sa[j] > 0){
            while(j >= i){
                if(sa[j] == 0) break;
                if(type[sa[j] - 1] != 1) break;
                int nj = hd[v[sa[i] - 1] + 1] - 1 - adv[v[sa[i] - 1]]++;
                sa[nj] = sa[j] - 1;
                j = nj;
            }
        }
    }
    return sa;
}

vector<int> vx;
int c;
vector<int> induced_sort2(vector<int> &cs){ //cs is past cs
    int n = cs.size();
    vector<int> sc;
    vector<int> type(cs.size());
    type.back() = 1;
    for(int i=n-2;i>=0;i--){
        auto x = cs[i];
        auto y = cs[i+1];
        while(true){
            if(vx[x] != vx[y]){
                if(vx[x] < vx[y]) type[i] = 1;
                else type[i] = 0;
                break;
            }else if(x == cs[i+1] || (y < n-2 && y == cs[i+2])){
                if(x == cs[i+1] && (y < n-2 && y == cs[i+2])) type[i] = type[i+1];
                else if(x == cs[i+1]) type[i] = 0;
                else type[i] = 1;
                break;
            }else x++, y++;
        }
    }
    for(int i=1;i<n;i++){
        if(type[i] == 1 && type[i-1] == 0){
            sc.push_back(cs[i]);
        }
    }
    vector<int> gs;
    if(sc.size() != 1){
        gs = induced_sort2(sc);
    }else{
        gs.push_back(0);
    }

    vector<int> sa(cs.size(), -1);
    
    //sc is lms by index
    //cs is all by index
    fill(hd, hd + c + 2, 0); //head pointer
    fill(adv, adv + c + 2, 0); //advance of head pointer
    for(int i=0;i<n;i++){
        hd[vx[cs[i]] + 1]++;
    }
    for(int i=1;i<=(c+1);i++) hd[i] += hd[i-1];
    // vector<int> ax(gs.size());
    // for(int i=0;i<gs.size();i++) ax[gs[i]] = i;
    for(int i=0;i<n;i++){
        cout << type[i] << " ";
    }
    cout << endl;
    for(auto &x : sc){
        adv[vx[x]]++;
    }
    for(int i=0;i<gs.size();i++){
        auto y = std::distance(cs.begin(), find(cs.begin(), cs.end(), sc[gs[i]]));// - cs.begin();
        int pl = hd[vx[cs[y]] + 1] - adv[vx[cs[y]]]--;
        sa[pl] = y;
    }
    for(int i=0;i<n;i++){
        int j = i;
        if(sa[j] > 0){
            while(j <= i){
                if(sa[j] == 0) break;
                if(type[sa[j] - 1] != 0) break;
                int nj = hd[vx[cs[sa[i] - 1]]] + adv[vx[cs[sa[i] - 1]]]++;
                sa[nj] = sa[j] - 1;
                j = nj;
            }
        }
    }
    fill(adv, adv + c + 2, 0);
    for(int i=n-1;i>=0;i--){
        int j = i;
        if(sa[j] > 0){
            while(j >= i){
                if(sa[j] == 0) break;
                if(type[sa[j] - 1] != 1) break;
                int nj = hd[vx[cs[sa[i] - 1] + 1]] - 1 - adv[vx[cs[sa[i] - 1]]]++;
                sa[nj] = sa[j] - 1;
                j = nj;
            }
        }
    }
    for(auto &x : sa) cout << x << " ";
    cout << endl;
    return sa;
}

vector<int> suffix_array(vector<int> &v){
    n = v.size();
    vector<bool> type(n);
    type[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        if(v[i] > v[i+1]) type[i] = 0;//large
        else if(v[i] < v[i+1]) type[i] = 1;//small
        else type[i] = type[i+1]; //?!
    }
    // return induced_sort(v, type);
    vx = v;
    c = *max_element(vx.begin(), vx.end());
    
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    return induced_sort2(a);
}
vector<int> suffix_array(string &s){
    int n = s.size();
    vector<int> cv(n);
    vector<bool> is(26, false); //change?!
    for(int i=0;i<n;i++) is[s[i]-'a'] = true;
    vector<int> val(26, -1);
    int p = 0;
    for(int i=0;i<26;i++){
        if(is[i]) val[i] = ++p;
    }
    for(int i=0;i<n;i++) cv[i] = val[s[i]-'a'];
    cv.push_back(0); //lower than anything?!
    return suffix_array(cv);
}


//longest common prefix in O(n), between 2 consecutive indexes of suffix array
vector<int> lcp(string &s, vector<int> &sa){
    s += '$';
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

  
int p[N], sz[N];
vector<pair<int, int>> lcx[N];
vector<int> pad[N];
bool us[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string gen_str(int n){
    string ans = "";
    for(int i=0;i<n;i++){
        char c = uniform_int_distribution<int>(0,25)(rng) + 'a';
        ans += c;
    }
    return ans;
}

// n log n
int cnt[N], aux[N], mp2[256];
pair<int, int> cs[N];
vector<int> suffix_array2(string s){
    s += "$";
    n = s.size(), c=-1;
    vector<int> mp(n);

    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=0;i<256;i++){
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "w", stdout); //test input
    init();
    int n;
    string s;
    // cin >> n >> s;
    n = 14;
    s = "mmississiippii";
    // n = 100;
    // s = gen_str(n);
    auto sa = suffix_array(s);
    auto sa2 = suffix_array2(s);
    assert(sa == sa2);
    auto lc = lcp(s, sa);
    ll ans = n;
    for(int i=1;i<lc.size();i++){
        lcx[lc[i]].push_back({i, i+1});
    }
    vector<int> gp;
    for(int i=n;i>=2;i--){
        vector<int> ng;
        vector<int> nv;
        for(auto &[a, b] : lcx[i]){
            unite(a, b);
            if(sz[get(a)] >= i) ng.push_back(get(a));
            else pad[sz[get(a)]].push_back(get(a));
        }
        for(auto &x : gp){
            x = get(x);
            if(!us[x]){
                nv.push_back(x);
                us[x] = true;
            }
        }
        for(auto &x : ng){
            x = get(x);
            if(!us[x]){
                nv.push_back(x);
                us[x] = true;
            }
        }
        for(auto &x : pad[i]){
            x = get(x);
            if(!us[x]){
                nv.push_back(x);
                us[x] = true;
            }
        }
        for(auto &x : nv) us[x] = false;
        gp = nv;
        for(auto &x : gp){
            if(!(sz[x] % i)) ans += sz[x];
        }
    }
    cout << ans << "\n";
}
