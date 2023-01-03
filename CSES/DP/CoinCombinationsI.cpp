#include <bits/stdc++.h>

using namespace std;

const int N  = 1e6+5;
const int MOD = 1e9+7;

int dp[N];

int main() {
   int n,S,aux,k,cursum;
   dp[0]=1;
   cin >> n >> S;
   vector <int> v;
   for(int i=0;i<n;i++){
       cin >> aux;
       v.push_back(aux);
   }
   sort(v.begin(),v.end());
   for(int i=1;i<=S;i++){
       cursum=0;
       for(int j=0;j<v.size();j++){
           k = i-v[j];
           if(k>=0){
               cursum += dp[k];
               if(cursum>=MOD) cursum -=MOD;
           }
       }
       dp[i] = cursum;
   }

  cout << dp[S];
}
