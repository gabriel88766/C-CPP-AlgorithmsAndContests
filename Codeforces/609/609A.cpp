#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int n,m,aux,ep,cont=0,S=0;

vector<int> v;
cin >> n >> m;
for(int i=0;i<n;i++){
    cin >> aux;
    v.push_back(aux);
}
sort(v.begin(),v.end());
ep = v.size()-1;
while(S<m){
    cont++;
    S+=v[ep];
    ep--;
}
cout << cont;

}


