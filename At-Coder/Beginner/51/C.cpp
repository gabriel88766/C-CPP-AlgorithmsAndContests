#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void move(pair<int,int> src, pair<int,int> dest){
    while(src != dest){
        if(dest.first < src.first){
            cout << "L";
            src.first--;
        }
        if(dest.first > src.first){
            cout << "R";
            src.first++;
        }
        if(dest.second < src.second){
            cout << "D";
            src.second--;
        }
        if(dest.second > src.second){
            cout << "U";
            src.second++;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int x0,y0,x1,y1;
    cin >> x0 >> y0 >> x1 >> y1;
    vector<pair<int,int>> points = { {x0, y0}, {x1, y0}, {x1, y1}, {x0, y1}, {x0,y0-1}, {x1+1, y0-1}, {x1+1, y1}, {x1,y1}, {x1, y1+1}, {x0-1, y1+1}, {x0-1, y0}, {x0,y0}}; 
    for(int i=0;i<11;i++) move(points[i], points[i+1]);
}
