#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n;
    vector<int> a(n);
    ll s1 = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        s1 += a[i];
    }
    cin >> k;
    vector<int> b(k);
    for(int i=0;i<k;i++){
        cin >> b[i];
        s1 -= b[i];
    }
    if(s1 != 0){
        cout << "NO\n";
        return 0;
    }
    int p1 = 0, p2 = 0;
    vector<pair<int, char>> ans;
    int lel = 0;
    while(p1 < n && p2 < k){
        if(a[p1] == b[p2]){
            p1++;
            p2++;
            continue;
        }
        int val = b[p2];
        int cur = p1;
        int s = 0;
        while(s < val){
            s += a[p1++];
        }
        if(s != val){
            cout << "NO\n";
            return 0;
        }
        int ind = -1;
        bool lef;
        int maxe = *max_element(a.begin() + cur, a.begin() + p1);
        for(int i = cur; i < p1 ; i++){
            if(a[i] == maxe){
                if(i != cur && a[i-1] < maxe){
                    ind = i;
                    lef = true;
                    break;
                }
                if(i != (p1 - 1) && a[i+1] < maxe){
                    ind = i;
                    lef = false;
                    break;
                }
            }
        }
        if(ind == -1){
            cout << "NO\n";
            return 0;
        }
        int ql = ind - cur;
        int qr = p1 - ind - 1;
        if(lef){
            while(ql--){
                ans.push_back({ind - lel + 1, 'L'});
                lel++;
            }
            for(int i=0;i<qr;i++){
                ans.push_back({ind - lel + 1, 'R'});
            }
        }else{
            for(int i=0;i<qr;i++){
                ans.push_back({ind - lel + 1, 'R'});
            }
            while(ql--){
                ans.push_back({ind - lel + 1, 'L'});
                lel++;
            }
        }
        lel += qr;
        p2++;
    }
    cout << "YES\n";
    for(auto x : ans) cout << x.first << " " << x.second << "\n";
}
 