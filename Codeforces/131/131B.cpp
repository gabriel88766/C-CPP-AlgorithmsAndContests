#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
long long int n,Total=0;
int aux;
map<int,long long int> mp;
cin >> n;
while(n--){
    cin >> aux;
    mp[aux]++;
}
Total+= ( ( (mp[0]-1)*mp[0] )/2 );
for(int i=1;i<=10;i++){
    Total += mp[i]*mp[-i];
}
cout << Total;
}
