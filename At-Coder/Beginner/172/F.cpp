
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=3;i<n;i++) v[2] = v[2] ^ v[i];
    ll a = v[0], b = v[1], c = v[2];
    ll ans = 0;
    //UNPROVED :) :) :)))
    while(a && (a ^ b ^ c)){
        for(int j=50;j>=0;j--){
            int bt = 0;
            if(a & (1LL << j)) bt++;
            if(b & (1LL << j)) bt++;
            if(c & (1LL << j)) bt++;
            if(bt == 0 || bt == 2) continue;
            else{
                ll bm = (1LL << j) - 1;
                ll ca = (bm & a) + 1;
                if(ca > a) ca = a;
                ll cb = (1LL << j) - (bm & b);
                
                if(ca == cb){
                    //this situation make the answer impossible
                    a = 0;
                }else if(ca < cb){
                    a -= ca;
                    b += ca;
                    ans += ca;
                }else{
                    a -= cb;
                    b += cb;
                    ans += cb;
                }
                break;
            } 
        }
    }
    if((a^b^c)) cout << "-1\n";
    else cout << ans << "\n";
} 
