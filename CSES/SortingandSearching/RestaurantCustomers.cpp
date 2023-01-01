#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

vector<int> vin, vout;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    
    int n,bpin=0,bpout=0,ans=0,count=0, aux;
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> aux;
        vin.push_back(aux);
        cin >> aux;
        vout.push_back(aux);
    }
    sort(vin.begin(), vin.end());
    sort(vout.begin(), vout.end());
    while(bpin < n){
        if(vin[bpin] <= vout[bpout]){
            count++;
            bpin++;
            ans = max(ans, count);
        }else{
            bpout++;
            count--;
        }
    }
    cout << ans;
}
