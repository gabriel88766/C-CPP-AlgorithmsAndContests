//Here is some stuff I found somewhere for some reason...
//it is not in all_geometry (yeah, not all)
//circle of apollonius...
template<typename T>
Circle<T> find_circle(Circle<T> c1, Circle<T> c2){
    if(c1.R > c2.R) swap(c1, c2);
    Point<T> p1 = c1.C;
    Point<T> dir = c2.C - c1.C;
    T dist = dir.abs();
    dir = dir / dist;
    Point<T> nd = c1.C + dir * (dist * (c1.R) / (c1.R + c2.R));
    Point<T> an = c1.C - dir * (dist * (c2.R - c1.R) / c1.R);
    Circle<T> ans((an+nd)/2, an.dist(nd)/2);
    return ans;
}
