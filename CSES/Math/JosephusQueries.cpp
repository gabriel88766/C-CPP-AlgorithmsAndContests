#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    ll a, b, pot, pi, pf, parity, total, ans, beg, end;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        parity = 1; //1 if pi is first, 0 if pi is second
        pot = 1;
        pi = 1;
        pf = a;
        while(b > 0){
            if(pi == pf){
                ans = pi;
                break;
            }       
            beg = pi + parity * pot;
            end = (pf - beg) % (2*pot) ? pf - pot : pf;

            if(!parity){ // new pi
                pi = beg + pot;
            }

            if(pf == end){ // new pf and new parity
                parity = 1;
                pf = end - pot;
            }else{
                parity = 0;
            }

            ans = end;

            total = (end - beg)/(pot*2) + 1;
            
            if(b >= total){
                b -= total;
            }else{
                ans = beg + (b-1) * 2 * pot;
                b = 0;
            }
            pot <<= 1;
        }
        cout << ans << "\n";
    }
}
