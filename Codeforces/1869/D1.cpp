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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> v(n);
        ll avg = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            avg += v[i];
        }
        if(avg % n) cout << "No\n";
        else{
            avg /= n;
            vector<int> s1, s2;
            bool ok = true;
            for(int i=0;i<n;i++){
                int p1 = 0, p2 = 0;
                int goal = v[i] - avg;
                if(v[i] == avg) continue;
                while(p2 <= 30 && p1 <= 30){
                    int val = (1 << p2) - (1 << p1);
                    if(val == goal) break;
                    else if(val < goal) p2++;
                    else p1++; 
                }
                if(p2 == 31 || p1 == 31){
                    ok = false; break;
                }
                s1.push_back(p1);
                s2.push_back(p2);
            }
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            if(s1 != s2) ok = false;
            if(ok) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
