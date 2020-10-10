
#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< int, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
# define PI          3.141592653589793238462643383279502884L
//matrix vector<vector<int>> matrix(row,vector<int>(col));

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int n,m,aux,lo,hi;
cin >> n >> m;
vector<int> a;
a.reserve(n);

for(int i = 0;i<n;i++){
    cin >> aux;
    a.push_back(aux);
}
sort(a.begin(),a.end());
for(int i = 0;i<m;i++){
    cin >> aux;
    hi = n-1;
    lo = 0;
    if(aux >=a[n-1]){
        lo = n-1;
    }
    else if(aux >= a[0]){
        while(lo<(hi-1)){
            if(aux>=a[(lo+hi)/2]){
                lo = (lo+hi)/2;
            }else{
                hi = (lo+hi)/2;
            }
        }
    }else{
        lo= -1;
    }
    cout << lo+1 << " ";
}

}
