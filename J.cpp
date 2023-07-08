#include <bits/stdc++.h>
#define sz(s) (int(s.size()))
#define MemS(s, x) memset(s, x, sizeof(s))
#define f_in(file) freopen(file, "r", stdin)
#define f_out(file) freopen(file, "w", stdout)
#define rtv(st) return void(st)
#define PI acos(-1)
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t xll;
using namespace std;
const ll Mod = 1e9 + 7, INF = 1e18;
const ll N = 1e7 + 1, O_O = LONG_LONG_MAX, T_T = INT_MAX, V_V = INT_MIN;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> Or_Set;

// 8 neighbors

int Dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // Knight_mov:2, 1, -1, -2, -2, -1, 1, 2
int Dy[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // 1, 2, 2, 1, -1, -2, -2, -1

// 4 neighbors

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

string dir = "LRDU";
void SADIEM()
{
    //f_in("../input.txt"); // f_out("output.txt");
    std::ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}
void Catch_Kadr_fe_ALOLo()
{
    int n, m;
    ll mx = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll sum = 0, needed = 0;
        for (ll i = 0, x; i < m && cin >> x; i++)
        {
            sum += x;
            if (sum < 0)
                needed += abs(sum), sum = 0;
        }
        mx = max(mx, needed);
    }
    cout << mx;
}

int main()
{
    SADIEM();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        Catch_Kadr_fe_ALOLo();
        cout << (t ? "\n" : "");
    }
}