#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

int n,m,k,cont=0,bp1=0,bp2=0;
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  cin >> n >> m >> k;
  vector<int> app,apt;
  long long int dif=0;
  for(int i=1;i<=n;i++){
      int aux;
      cin >> aux;
      app.push_back(aux);
  }
  for(int i=1;i<=m;i++){
      int aux;
      cin >> aux;
      apt.push_back(aux);
  }
  sort(app.begin(),app.end());
  sort(apt.begin(),apt.end());
  while(bp1<n && bp2<m){
      if((app[bp1]-apt[bp2])>k){
 
        bp2++;
      }else if(abs(app[bp1]-apt[bp2]) > k){
 
        bp1++;
      }else{
 
           cont++;
           bp1++;
           bp2++;
      }
  }
  cout << cont;
  return 0;
}