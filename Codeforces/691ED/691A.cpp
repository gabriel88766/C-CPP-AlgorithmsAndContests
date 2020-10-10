#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int cont=0;
int n,cur;
cin >> n;
for(int i=0;i<n;i++){
    cin >> cur;
    if(cur==1) cont++;
}
if(n==1){
    if(cont==1) cout << "YES";
    else cout << "NO";
}else{
    if((n-cont)==1) cout << "YES";
    else cout << "NO";
}
}

