#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define oo 0x3f3f3f3fLL
#define INF 0x3f3f3f3f3f3f3f3fLL
#define mem(a,n) memset((a),n,sizeof (a))
#define sz(s) (int) (s.size())
#define all(v) v.begin(), v.end()
void fast();
ll gcd(ll x, ll y) { return(!y ? x : gcd(y, x % y)); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
using namespace std;
const int N = 300+10;
bool prime[N];
vector<int>primes;
ll setBit(ll num, int idx, bool val) {
    return val ? (num | (1LL << idx)) : (num & ~(1LL << idx));
}
void  sieve_v2() {
    for (int i = 0; i < N; i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (int i = 4; i < N; i += 2) {
        prime[i] = 0;
    }
    for (int i = 3; i * i < N; i += 2) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i + i) {
                prime[j] = 0;
            }
        }
    }
    for (int i = 2; i < N; i++)
        if (prime[i])primes.push_back(i);
}
vector<ll>v;
class segment_tree {//1-based
#define LEFT (idx<<1)
#define RIGHT (idx<<1|1)
#define MID ((start+end)>>1)
    int n;
    vector<ll> tree, lazy;
    ll merge(const ll& left, const ll& right) {
        return left & right;
    }
    inline void pushdown(int idx, int start, int end) {
        if (lazy[idx] == 0) return;
        //update tree[idx] with lazy[idx]
        tree[idx] |= lazy[idx];
        if (start != end) {
            lazy[LEFT] |= lazy[idx];
            lazy[RIGHT] |= lazy[idx];
        }
        lazy[idx] = 0; //clear lazy
    }
    inline void pushup(int idx) {
        tree[idx] = merge(tree[LEFT], tree[RIGHT]);
    }

    void build(int idx, int start, int end) {
        if (start == end) {
            tree[idx] = v[start];
            return;
        }
        build(LEFT, start, MID);
        build(RIGHT, MID + 1, end);
        pushup(idx);
    }
    ll query(int idx, int start, int end, int from, int to) {
        pushdown(idx, start, end);
        if (from <= start && end <= to)
            return tree[idx];
        if (to <= MID)
            return query(LEFT, start, MID, from, to);
        if (MID < from)
            return query(RIGHT, MID + 1, end, from, to);
        return merge(query(LEFT, start, MID, from, to),
            query(RIGHT, MID + 1, end, from, to));
    }
    void update(int idx, int start, int end, int lq, int rq, const ll& val) {
        pushdown(idx, start, end);
        if (rq < start || end < lq)
            return;
        if (lq <= start && end <= rq) {
            lazy[idx] |= val;//update lazy
            pushdown(idx, start, end);
            return;
        }
        update(LEFT, start, MID, lq, rq, val);
        update(RIGHT, MID + 1, end, lq, rq, val);
        pushup(idx);
    }
public:
    segment_tree() {
        n = v.size() - 1;
        tree = vector<ll>(n << 2);
        lazy = vector<ll>(n << 2);
        build(1, 1, n);
    }
    ll query(int l, int r) {
        return query(1, 1, n, l, r);
    }
    void update(int l, int r, const ll& val) {
        update(1, 1, n, l, r, val);
    }
#undef LEFT
#undef RIGHT
#undef MID
};
void solve() {
   
}
int main() {

    fast();
    sieve_v2();
    //cout << sz(primes) << "\n";
    int n,q; cin >> n>>q;
    v = vector<ll>(n+1);
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        for (int j = 0; j < sz(primes); j++) {
            if (x % primes[j] == 0)
                v[i] = setBit(v[i], j, 1);
            while (x % primes[j] == 0) {
                x /= primes[j];
            }
        }
    }
    segment_tree sgt;
    string s;
    int l, r;
    while (q--) {
        cin >> s >> l >> r;
        if (s == "MULTIPLY") {
            cin >> x;
            ll num = 0;
            for (int j = 0; j < sz(primes); j++) {
                if (x % primes[j] == 0)
                    num = setBit(num, j, 1);
                while (x % primes[j] == 0) {
                    x /= primes[j];
                }
            }
            sgt.update(l, r, num);
        }
        else {
            ll ans = sgt.query(l, r);
            for (int i = 0; i < sz(primes); i++) {
                if ((1LL << i) & ans)continue;
                cout << primes[i] << "\n";
                break;
            }
        }
    }




    return 0;
}
void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
