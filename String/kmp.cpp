#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

auto prefix_function(const string& s)
{
    int n = sz(s);
    vector p(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }
    return p;
}

vector<vector<int>> compute_automaton(string s)
{
    s += '#';
    int n = sz(s);
    vector p = prefix_function(s);
    vector aut(n, vector(26, 0));
    for (int i = 0; i < n; ++i)
        for (int c = 0; c < 26; ++c)
        {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[p[i - 1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    return aut;
}

int main()
{ _
    exit(0);
}

