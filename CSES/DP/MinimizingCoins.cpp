#include <bits/stdc++.h>

using namespace std;

const int N  = 1e6+5;
const int INF = 0x3f3f3f3f;

int dp[N];

void init(){
    dp[0]=0;
    for(int i=1;i<N;i++)
        dp[i] = INF;
}

int main() {
   int n,S,aux,k,mincur;
   init();
   cin >> n >> S;
   vector <int> v;
   for(int i=0;i<n;i++){
       cin >> aux;
       v.push_back(aux);
   }
   sort(v.begin(),v.end());
   for(int i=1;i<=S;i++){
       mincur=INF;
       for(int j=0;j<v.size();j++){
           k = i-v[j];
           if(k>=0){
               mincur = min(dp[k]+1,mincur);
           }
       }
       dp[i] = mincur;
   }

   if(dp[S] == INF ) cout << -1;
   else cout << dp[S];
}
