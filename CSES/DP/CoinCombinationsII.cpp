#include <bits/stdc++.h>

using namespace std;

const int N  = 1e6+5;
const int MOD = 1e9+7;

int dp[N];

int main() {
   int n,S,aux,k,mincur;
   dp[0]=1;
   cin >> n >> S;
   vector <int> v;
   for(int i=0;i<n;i++){
       cin >> aux;
       v.push_back(aux);
   }
   sort(v.begin(),v.end());
   for(int i=0;i<v.size();i++){
       int c = v[i];
       for(int j=c;j<=S;j++){
           dp[j]+=dp[j-c];
           dp[j]%=MOD;
       }
   }

  cout << dp[S];
}

