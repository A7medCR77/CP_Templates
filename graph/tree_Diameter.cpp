#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
#define MOD 1000000007
#define ceil(n, m) (n + m - 1) / m
#define round(n, m) (n + m / 2) / m
#define sz(s) s.size()
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define sum_of_first_n_odd_number(n) ((n % MOD) * (n % MOD)) % MOD;
#define all(s) s.begin(), s.end()
#define OO 20000000000
#define ld long double
#define pi 3.141592653589793
#define rall(s) s.rbegin(), s.rend()
#define fixed(n) cout << fixed << setprecision(n)
#define mod_combine(a, b, m) (((a % m) * (b % m)) % m)
#define se second
#define fi first
#define eb emplace_back
#define pb push_back
#define pf push_front
#define nl '\n'
#define PI acos(-1.0)
#define EPS 1e-9
#define dot_prod(a, b) real(conj(a) * (b))
#define cross_prod(a, b) imag(conj(a) * (b))
#define rotateO(p, theta) (p) * polar(1.0, theta)
#define rotateA(p, a, theta) rotateO((p) - (a), theta) + (a)
#define reflectO(p, m) conj((p) / (m)) * (m)
#define reflectA(p, a, m) reflectO((p) - (a), m) + (a)
#define MAXll 9223372036854775807
#define E 2.71828182846
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)

using namespace std;

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << " ";
    return out;
}

// start from any node for example this node will be (a)
// get the farthest node from (a) and this node will be (b)
// get the farthest node from (b) and this node will be (c)
// distance from node b to node c will be the length of the tree_Diameter

struct tree_Diameter
{
    int n;
    vector<vector<int>> graph;
    vector<int> par;
    int start_node, last_node;

    tree_Diameter(int _n, vector<vector<int>> &_graph, int node = 1) : n(_n), graph(_graph), start_node(node)
    {
        par.assign(n + 1, -1);

        int dis = 0;
        queue<pair<int, int>> q;
        vector<int> vis(n + 5);
        q.push({start_node, 0});

        while (!q.empty())
        {
            // auto [par, dis_par]
            pair<int, int> pr = q.front();
            q.pop();

            vis[pr.fi]++;

            if (pr.se > dis)
                dis = pr.se, start_node = pr.fi;

            for (auto &child : graph[pr.fi])
            {
                if (!vis[child])
                    q.push({child, pr.se + 1});
            }
        }
    };

    int get_distance()
    {
        int dis = 0;
        queue<pair<int, int>> q;
        vector<int> vis(n + 5);
        q.push({start_node, 0});

        while (!q.empty())
        {
            pair<int, int> pr = q.front();
            q.pop();

            vis[pr.fi]++;

            if (pr.se > dis)
                dis = pr.se, last_node = pr.fi;

            for (auto &child : graph[pr.fi])
            {
                if (!vis[child])
                    q.push({child, pr.se + 1}), par[child] = pr.fi;
            }
        }

        return dis;
    }

    vector<int> get_tree_Diameter()
    {
        get_distance();

        vector<int> ans;
        for (int i = last_node; i != -1; i = par[i])
            ans.eb(i);

        return ans;
    }
};

void solve()
{
}

int main()
{
    ll t = 1;
    // cin >> t;
    // cin.ignore();
    while (t--)
    {
        solve();
    }
    return 0;
}
