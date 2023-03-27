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
        int n;
        cin >> n;
        vector<ll> v(n);
        ll sum = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            sum += v[i];
        }
        vector<ll> divs;
        for(ll i = 2; i*i <= sum; i++){
            if(!(sum % i)){
                divs.push_back(i);
                if(i*i != sum) divs.push_back(sum/i);
            }
        }
        if(sum != 1) divs.push_back(sum);
        sort(divs.begin(), divs.end());


        if(divs.empty()) cout << "-1\n";
        else{
            ll ans = INF_LL;
            ll cur;
            for(int i=0;i<divs.size();i++){
                ll x = divs[i];
                ll mid = x/2 + x%2;
                cur = 0;
                auto aux = v;
                for(ll i=0;i<n;i++){
                    ll val = aux[i] % x;
                    if(val == 0) continue;
                    else if(val >= mid){
                        for(ll j=i+1;j<n;j++){
                            ll val2 = aux[j] % x;
                            if(val2 + val >= x){
                                aux[j] -= (x - val);
                                cur += (x - val)*(j-i);
                                break;
                            }else{
                                val += val2;
                                aux[j] -= val2;
                                cur += val2*(j-i);
                            }
                        }
                    }else{
                        cur += val;
                        aux[i+1] += val;
                    }
                    
                }
                ans = min(ans, cur);
            }
            cout << ans << "\n";
        }
    }
    