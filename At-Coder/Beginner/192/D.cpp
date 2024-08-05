    #include <bits/stdc++.h>
    typedef long long int ll;
    typedef unsigned long long int ull;
    const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
    const int INF_INT = 0x3f3f3f3f;
    const long double PI = acosl(-1.), EPS = 1e-9; 
    using namespace std;

    ll n;

    bool check(string &s, ll b){
        ll num = 0;
        ll auxb = 1;
        for(auto c : s){
            ll dig = c - '0';
            if(dig){
                if((INF_LL - num)/dig >= auxb) num += dig * auxb;
                else num = INF_LL;
            }
            if(INF_LL/b >= auxb) auxb *= b;
            else auxb = INF_LL;
        }
        return num <= n;
    }

    //cout << fixed << setprecision(6)
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        //freopen("in", "r", stdin); //test input
        string x;
        
        cin >> x >> n;
        reverse(x.begin(), x.end());
        int d = 0;
        for(auto c : x){
            d = max(d, c - '0');
        }
        d++;
        if(x.size() == 1){
            if((x[0]-'0') <= n) cout << "1\n";
            else cout << "0\n";
        }
        else{
            if(n < d){
                cout << "0\n";
                return 0;
            }
            //all integers are different
            //x at least 10, so ans at most n - d + 1
            ll lo = d, hi = n;
            while(lo != hi){
                ll mid = lo + (hi - lo + 1)/2;
                if(check(x, mid)) lo = mid;
                else hi = mid - 1;
            }
            ll ans = lo - d + 1;
            if(lo == d){
                //check d
                if(!check(x, d)) ans = 0;
            }
            cout << ans << "\n";
        }
    }
