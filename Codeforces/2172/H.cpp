#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 8e5+3; 
int hd[N], adv[N];

//v is the values, sc is the characters
vector<int> induced_sort(vector<int> &v, vector<int> &sc, vector<int> &gs, vector<bool> &type){
    int n = v.size();
    int c = *max_element(v.begin(), v.end());
    vector<int> sa(n, -1);
    
    fill(hd, hd + c + 2, 0); //head pointer
    fill(adv, adv + c + 2, 0); //advance of head pointer
    for(int i=0;i<n;i++){
        hd[v[i] + 1]++;
    }
    for(int i=1;i<=(c+1);i++) hd[i] += hd[i-1];
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

inline bool lms_ne(vector<int> &v, vector<bool> &type, int p1, int p2, int ed1){
    for(;; p1++,p2++){
        if(v[p1] != v[p2]) return true;
        else if(type[p1] != type[p2]) return true;
        else if(type[p1] == 1 && p1 == ed1) return false;
    }
}

vector<int> suffix_array(vector<int> &v){
    int n = v.size();
    vector<bool> type(n);
    type[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        if(v[i] > v[i+1]) type[i] = 0;//large
        else if(v[i] < v[i+1]) type[i] = 1;//small
        else type[i] = type[i+1]; //?!
    }
    vector<int> sc;
    for(int i=1;i<n;i++){
        if(type[i] == 1 && type[i-1] == 0){
            sc.push_back(i);
        }
    }
    int c = *max_element(v.begin(), v.end());
    vector<int> gs;
    vector<int> nv(sc.size());
    if(sc.size() != 1){
        //do induced sort 
        vector<int> gax(sc.size());
        fill(hd, hd + c + 2, 0); 
        fill(adv, adv + c + 2, 0); 
        for(auto &i : sc){ //need values in sc
            hd[v[i] + 1]++;
        }
        for(int i=1;i<=(c+1);i++) hd[i] += hd[i-1];
        for(int j=0;j<sc.size();j++){ //need values in sc
            auto &i = sc[j];
            gax[j] = hd[v[i] + 1] - ++adv[v[i]];
        }
        auto aux = induced_sort(v, sc, gax, type); 
        vector<int> us(n, -1);
        for(int i=0;i<sc.size();i++) us[sc[i]] = i; //need positions in sc
        vector<int> aux2;
        for(auto &x : aux){
            if(us[x] != -1) aux2.push_back(us[x]);
        }
        int p = -1;
        for(int i=0;i<aux2.size();i++){
            if(i == 0 || lms_ne(v, type, sc[aux2[i]], sc[aux2[i-1]], sc[aux2[i] + 1])) nv[aux2[i]] = ++p;
            else nv[aux2[i]] = p;
        }

        gs = suffix_array(nv);
    }else{
        gs.push_back(0);
    }
    return induced_sort(v, sc, gs, type);
}

vector<int> suffix_array(string &s){
    int n = s.size();
    s += '$'; //compatibility with lcp.
    vector<int> cv(n);
    vector<bool> is(26, false); //lower bound latin letters
    for(int i=0;i<n;i++) is[s[i]-'a'] = true;
    vector<int> val(26, -1);
    int p = 0;
    for(int i=0;i<26;i++){
        if(is[i]) val[i] = ++p;
    }
    for(int i=0;i<n;i++) cv[i] = val[s[i]-'a'];
    cv.push_back(0); //sentinel, lower than anything.
    return suffix_array(cv);
}

vector<int> lcp(string &s, vector<int> &sa){
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


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int k, t;
    cin >> k >> t; // k = 1 or 2 doesn't matter;
    string s;
    cin >> s;
    //testing 1
    // vector<int> v(1 << k);
    // for(int i=0;i<v.size();i++) v[i] = i;
    // auto cv = v;
    // for(int i = 1;i <= t % k;i++){
    //     auto nv = cv;
    //     for(int j=0;j<cv.size()/2;j++){
    //         nv[2*j] = cv[j];
    //         nv[2*j+1] = cv[cv.size()/2 + j];
    //     }
    //     cv = nv;
    // }
    //testing 2
    // for(int i = 0; i < v.size();i++){
    //     string cs = s.substr(i, v.size() - i) + s.substr(0, i);
    //     string ss = cs;
    //     for(int j=0;j<cv.size();j++){
    //         ss[j] = cs[cv[j]];
    //     }
    //     cout << ss << "\n";
    // }
    int r = t % k;
    int x = (k - r) % k;
    int jp = 1 << x;
    string cs = s + s;
    int csz = s.size() / jp;
    int estr = csz * 2;
    string fsa;
    for(int i=0; i < jp; i++){
        string tss;
        for(int j = i; j < cs.size() && j < cs.size(); j += jp){
            tss += cs[j];
        }
        fsa += tss;
        fsa += '}';
        // cout << tss << " " << estr << "\n";
    }

    assert(fsa.size() < N);
    auto sa = suffix_array(fsa); 
    auto lc = lcp(fsa, sa);

}
