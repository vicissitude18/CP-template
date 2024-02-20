// ax + by = d を満たす x,y を返す ない場合は false
template <typename T = long long> bool extgcd(T a, T b, T &x, T &y, T d) {
    if(!b and d % a) return false;
    if(!b) {
        x = d / a, y = 0;
        return true;
    }
    if(extgcd(b, a % b, y, x, d)) {
        y -= a / b * x;
        return true;
    }
    return false;
}

// d = gcd(a,b) の時
template <typename T = long long> long long extgcd(T a, T b, T &x, T &y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    }
    long long res = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return res;
    //x = (x % b + b) % b;求x最小正整数解
    //y = (y % a + a) % a;求y最小正整数解
}
long long cal(long long a,long long b,long long c)
{
    long long x,y;//a * x + b * y = d
    long long d = extgcd<long long>(a,b,x,y);
    if(c % d != 0)return -1;
    x *= c / d; //转换为a * x + b * y = c 的解,注意顺序
    b /= d;//约去c后原来b就变为了b / gcd; c可以理解为到y上面
    if(b < 0)b = -b;
    long long ans = x % b;
    if(ans <= 0)ans += b;//求最小正整数解
    return ans;

}
这两种本质上没啥区别，只是在一些问题中a，b等系数可能为负，第一种需要预处理，而第二种则可以直接用
