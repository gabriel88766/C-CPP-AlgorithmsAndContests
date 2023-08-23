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
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            v[i] += v[i]%10;
        }
        bool ok = true;
        for(int i=1;i<n;i++) if(v[i] != v[i-1]) ok = false;
        if(ok) { cout << "Yes\n"; continue;}
        int cnt = 0;
        for(int i=0;i<n;i++) if(v[i] % 10) cnt++;
        if(cnt != 0 && cnt != n){ cout << "No\n"; continue;}
        if(cnt == 0){
            ok = true;
            for(int i=1;i<n;i++) if(v[i] != v[i-1]) ok = false;
            if(ok) cout << "Yes\n";
            else cout << "No\n";
            continue;
        }
        cnt = 0;
        for(int i=0;i<n;i++){
            int num1 = (v[i]/10)%2;
            int num2 = v[i] % 10;
            if(num1 == 1 && (num2 == 2 || num2 == 4 || num2 == 8)) cnt++;
            if(num1 == 0 && num2 == 6) cnt++;
        }
        if(cnt != 0 && cnt != n) cout << "No\n";
        else cout << "Yes\n";
    }
}
