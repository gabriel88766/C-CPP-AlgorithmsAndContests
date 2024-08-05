#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int MAXN = 200001;  // 1-based
const ll  INF  = LLONG_MAX;

int N, Q;


using  i64 = int64_t;

i64  inf = 1e18;

struct  Node
{
    i64  max, min, max2, min2;
    int  maxCnt, minCnt, len;
    i64  sum, pAdd;

    Node( i64 val = 0 ) : max( val ), min( val ), max2( -inf ), min2( inf ),
          maxCnt( 1 ), minCnt( 1 ), len( 1 ), sum( val ), pAdd( 0 )  {}

    void  merge( const Node &left, const Node &right )  {
        max = std::max( left.max, right.max );
        
        if( left.max == right.max )  {
            max2   = std::max( left.max2, right.max2 );
            maxCnt = left.maxCnt + right.maxCnt;
        } else  {
            max2   = std::min( left.max, right.max );
            max2   = std::max( { max2, left.max2, right.max2 } );
            maxCnt = left.max > right.max ? left.maxCnt : right.maxCnt;
        }
        
        min = std::min( left.min, right.min );
        
        if( left.min == right.min )  {
            min2   = std::min( left.min2, right.min2 );
            minCnt = left.minCnt + right.minCnt;
        } else  {
            min2   = std::max( left.min, right.min );
            min2   = std::min( { min2, left.min2, right.min2 } );
            minCnt = left.min < right.min ? left.minCnt : right.minCnt;
        }
        
        len = left.len + right.len;
        sum = left.sum + right.sum;

        pAdd = 0;
    }

    void  applyAdd( i64 add ) {
        max  += add;
        min  += add;
        sum  += add * len;
        min2 += add;
        max2 += add;
        pAdd += add;
    }

    void  applyMin( i64 val )  {
        if( max > val )  {
            sum -= (max - val) * maxCnt;
            if( max == min2 )  min2 = val;
        }
        min = std::min( min, val );
        max = std::min( max, val );
    }

    void  applyMax( i64 val )  {
        if( min < val )  {
            sum += ( val - min ) * minCnt;
            if( min == max2 )  max2 = val;
        }
        max = std::max( max, val );
        min = std::max( min, val );
    }
};

class  SegmentTree 
{
  private:
    vector<Node>  tree;

  public:
    SegmentTree( const vector<i64> &arr )  {
        int  n = arr.size();
        tree.resize( 4 * n );
        build( arr, 1, 0, n );
    }
    
    void  add( i64 val, int l, int r, int vtx, int left, int right )  {
        if( l >= right  ||  r <= left )   return;

        if( l <= left  &&  r >= right )  {
            tree[vtx].applyAdd( val );
            return;
        }
        
        push( vtx );
        
        int  mid = ( left + right ) / 2;
        add( val, l, r, 2*vtx, left, mid );
        add( val, l, r, 2*vtx + 1, mid, right );
        
        tree[vtx].merge( tree[2*vtx], tree[2*vtx + 1] );
    }

    void  chMin( i64 val, int l, int r, int vtx, int left, int right )  {
        if( l >= right  ||  r <= left  ||  tree[vtx].max <= val )  return;

        if( l <= left  &&  r >= right  &&  tree[vtx].max2 < val )  {
            tree[vtx].applyMin( val );
            return;
        }
        
        push( vtx );
        
        int  mid = ( left + right ) / 2;
        chMin( val, l, r, 2*vtx, left, mid );
        chMin( val, l, r, 2*vtx + 1, mid, right );
        
        tree[vtx].merge( tree[2*vtx], tree[2*vtx + 1] );
    }

    void  chMax( i64 val, int l, int r, int vtx, int left, int right )  {
        if( l >= right  ||  r <= left  ||  tree[vtx].min >= val )  return;
        
        if( l <= left  &&  r >= right  &&  tree[vtx].min2 > val )  {
            tree[vtx].applyMax( val );
            return;
        }
        
        push( vtx );
        
        int  mid = ( left + right ) / 2;
        chMax( val, l, r, 2*vtx, left, mid );
        chMax( val, l, r, 2*vtx + 1, mid, right );
        
        tree[vtx].merge( tree[2*vtx], tree[2*vtx + 1] );
    }

    i64  getSum( int l, int r, int vtx, int left, int right )  {
        if( l >= right  ||  r <= left )   return  0;
        if( l <= left   &&  r >= right )  return  tree[vtx].sum;

        push( vtx );
        
        int  mid = ( left + right ) / 2;
        return  getSum( l, r, 2*vtx, left, mid ) +
                getSum( l, r, 2*vtx + 1, mid, right );
    }
    
  private:
    void  build( const vector<i64> &arr, int vtx, int left, int right )  {
        if( left + 1 == right )  {
            tree[vtx] = Node( arr[left] );
            return;
        }
        int  mid = ( left + right ) / 2;
        build( arr, 2*vtx, left, mid );
        build( arr, 2*vtx + 1, mid, right );
        
        tree[vtx].merge( tree[2*vtx], tree[2*vtx + 1] );
    }

    void  push( int vtx )  {
        if( tree[vtx].pAdd != 0 )  {
            tree[2*vtx].applyAdd( tree[vtx].pAdd );
            tree[2*vtx + 1].applyAdd( tree[vtx].pAdd );
            tree[vtx].pAdd = 0;
        }
        
        if( tree[vtx].max < tree[2*vtx].max )
            tree[2*vtx].applyMin( tree[vtx].max );
            
        if( tree[vtx].max < tree[2*vtx + 1].max )
            tree[2*vtx + 1].applyMin( tree[vtx].max );
            
        if( tree[vtx].min > tree[2*vtx].min )
            tree[2*vtx].applyMax( tree[vtx].min );
            
        if( tree[vtx].min > tree[2*vtx + 1].min )
            tree[2*vtx + 1].applyMax( tree[vtx].min );
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n;
    vector<int> p(n+1), v(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    cin >> m;
    vector<int>  op(m+1);
    for(int i=1;i<=m;i++) cin >> op[i];
    ordered_set<int> os;

    vector<long int> A(n+1);
    for(int i=1;i<=n;i++){
        int d = os.order_of_key(n+1) - os.order_of_key(p[i]); 
        A[i] = d;
        os.insert(p[i]);
    }
    SegmentTree  tree(A);
    //st.build();
    for(int i=1;i<=m;i++){

        tree.add( -1, 1, op[i]+1, 1, 0, n+1);
        tree.chMax( 0, 1, op[i]+1, 1, 0, n+1 );
        cout << tree.getSum( 1, n+1, 1, 0, n+1) << '\n';
    }

}
