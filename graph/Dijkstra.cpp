#include <bits/stdc++.h>
#define ll long long
#define sz(s) s.size()
#define OO 20000000000
#define pb push_back
#define nl '\n'

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
        out << x << "\n";
    return out;
}

// Dijkstra_algorithm with connected graph
// Time Complexity n log(n)
vector<ll> Dijkstra(ll start, vector<vector<pair<ll, ll>>> &graph)
{
    int sz = sz(graph);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dis(sz, OO);
    pq.push({0, start});
    dis[start] = 0;

    while (!pq.empty())
    {
        auto [Dis, node] = pq.top();
        pq.pop();

        if (Dis != dis[node])
            continue;

        for (auto &[ch, Distance] : graph[node])
        {
            if (Dis + Distance < dis[ch])
            {
                dis[ch] = Dis + Distance;
                pq.push({dis[ch], ch});
            }
        }
    }

    return dis;
}

void solve()
{
}

int main()
{
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
