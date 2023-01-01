#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int count = 0, n, w, bp=0,ep;
    cin >> n >> w;
    vector<int> vc(n);
    ep = n-1;
    for(int i = 0; i< n; i++){
        cin >> vc[i];
    }
    sort(vc.begin(), vc.end());
    while(bp < ep){
        if((vc[bp] + vc[ep]) <= w){
            ep--;
            bp++;
            count++;
        }else{
            ep--;
            count++;
        }
    }
    if(bp == ep) count++;
    cout << count;
}
