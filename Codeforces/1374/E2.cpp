#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int bs(vector<pair<int,int>> &v, int lo, int hi, int val){
    while(lo != hi){
        int mid = lo + (hi - lo + 1)/2;
        if(v[mid-1].first > val) hi = mid-1;
        else lo = mid; 
    }
    return lo;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> a, b, c, d;//10, 01, 11, 00
    for(int i=1;i<=n;i++){
        int t, x1, x2;
        cin >> t >> x1 >> x2;
        if(x1 == 1 && x2 == 1){
            c.push_back({t, i});
        }else if(x1 == 1){
            a.push_back({t, i});
        }else if(x2 == 1){
            b.push_back({t, i});
        }else d.push_back({t, i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    vector<int> psa(n+1, 0), psb(n+1, 0), psc(n+1, 0), psd(n+1, 0);
    int qta = a.size(), qtb = b.size(), qtc = c.size(), qtd = d.size();
    for(int i=0;i<qta;i++) psa[i+1] = psa[i] + a[i].first;
    for(int i=0;i<qtb;i++) psb[i+1] = psb[i] + b[i].first;
    for(int i=0;i<qtc;i++) psc[i+1] = psc[i] + c[i].first;
    for(int i=0;i<qtd;i++) psd[i+1] = psd[i] + d[i].first;
    int ans = 2000000005;
    int am, bm, cm, dm=0, lom;
    for(int i=0;i<=min(qtc, k);i++){
        int x = min(qta, qtb);
        if(x + i >= k){
            int al = k-i, bl = k-i, cl = i, dl = 0;
            if(al+bl+cl > m) continue;
            int av, bv, cv, dv;
            //do search to al+bl+cl+dl = m.
            //how? lowbound t, something like log^2 n
            int lo = 1, hi = 10000;
            while(lo != hi){
                int mid = lo + (hi - lo)/2;
                av = bs(a, al, qta, mid);  
                bv = bs(b, bl, qtb, mid);  
                cv = bs(c, cl, qtc, mid);  
                dv = bs(d, dl, qtd, mid);
                if(av+bv+cv+dv < m) lo = mid+1;
                else hi = mid;  
            }
            av = bs(a, al, qta, lo);  
            bv = bs(b, bl, qtb, lo);  
            cv = bs(c, cl, qtc, lo);  
            dv = bs(d, dl, qtd, lo);
            int cans = psa[av] + psb[bv] + psc[cv] + psd[dv] - (av+bv+cv+dv-m)*lo;
            if(cans < ans){
                ans = cans;
                am = al;
                bm = bl;
                cm = cl;
                lom = lo;
            }
        }else continue;
    }

    if(ans != 2000000005){
         cout << ans << "\n";
         vector<int> ansv;
         for(int i=0;i<am;i++) ansv.push_back(a[i].second);
         for(int i=0;i<bm;i++) ansv.push_back(b[i].second);
         for(int i=0;i<cm;i++) ansv.push_back(c[i].second);
         while(am < qta && a[am].first < lom){
            ansv.push_back(a[am++].second);
         }
         while(bm < qtb && b[bm].first < lom){
            ansv.push_back(b[bm++].second);
         }
         while(cm < qtc && c[cm].first < lom){
            ansv.push_back(c[cm++].second);
         }
         while(dm < qtd && d[dm].first < lom){
            ansv.push_back(d[dm++].second);
         }
         while(ansv.size() < m){
            if(am < qta && a[am].first == lom){
                ansv.push_back(a[am++].second);
            }else if(bm < qtb && b[bm].first == lom){
                ansv.push_back(b[bm++].second);
            }else if(cm < qtc && c[cm].first == lom){
                ansv.push_back(c[cm++].second);
            }else if(dm < qtd && d[dm].first == lom){
                ansv.push_back(d[dm++].second);
            }else assert(1 == 0);
         }
         for(auto x : ansv) cout << x << " ";
         cout << "\n";
    }
    else cout << "-1\n";
}
