#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<500005> bs[1001];
int v[1001];
bool sg[1001];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    bs[0][0] = 1;
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        sum += v[i];
        bs[i] = bs[i-1] | (bs[i-1] << v[i]); //each v[i] is from 1 to 1000, approx O(N^3 / 128) - if bitset is 64 bits or O(N^3 / 64) if 32bits
    }
    if(sum % 2) cout << "-1\n";
    else if(bs[n][sum/2]){ //sum/2 up to 500000
        //Now do the dp...
        int cs = sum/2;
        for(int i=n;i>=1;i--){
            if(cs >= v[i] && bs[i-1][cs - v[i]]){
                sg[i] = true; // +
                cs -= v[i];
            }//else -
        }
        //now make the sequence of substituing a and b to abs(a-b)
        vector<int> pos, neg;
        for(int i=1;i<=n;i++){
            if(sg[i]) pos.push_back(v[i]);
            else neg.push_back(v[i]);
        }
        while(pos.size() && neg.size()){
            int a = neg.back();
            int b = pos.back();
            neg.pop_back();
            pos.pop_back();
            cout << a << " " << b << "\n";
            if(a > b){
                neg.push_back(a-b);
            }else if(a < b){
                pos.push_back(b-a);
            }else{
                if(neg.size() && pos.size()){
                    cout << neg.back() << " " << 0 << "\n";
                }else{
                    assert(neg.size() == 0);
                    assert(pos.size() == 0);
                }
            }
        }
    }else cout << "-1\n";
}
