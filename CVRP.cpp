// Problem: Capacitaed Vehicle Routing
// Description
// A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi packages from a central depot 0 to clients 1,2,…,n. Each client i requests d[i] packages. The distance from location i to location j is c[i,j], 0≤i,j≤n. A delivery solution is a set of routes: each truck is associated with a route, starting from depot, visiting some clients and returning to the depot for deliverying requested pepsi packages such that:
// Each client is visited exactly by one route
// Total number of packages requested by clients of each truck cannot exceed its capacity
// Goal
// Find a solution having minimal total travel distance
// Note that: 
// There might be the case that a truck does not visit any client (empty route)
// The orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.
// Input
// Line 1: n,K,Q (2≤n≤12,1≤K≤5,1≤Q≤50)
// Line 2: d[1],...,d[n](1≤d[i]≤10)
// Line i+3 (i=0,…,n): the ith
//  row of the distance matrix c (1≤c[i,j]≤30)
// Output
// Minimal total travel distance
// Example
// Input
// 4 2 15
// 7 7 11 2
// 0 12 12 11 14
// 14 0 11 14 14
// 14 10 0 11 12
// 10 14 12 0 13
// 10 13 14 11 0

// Output
// 70

#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n, k, q;
int f = 0, segments, nbr;
int f_min = INT_MAX, c_min = INT_MAX;
int d[N], c[N][N], vis[N], y[N], x[N], load[N];

void updateBest() {
    if(f < f_min) f_min = f;
}

bool checkX(int v, int u) {
    if (v > 0 && vis[v]) return false;
    if(load[u] + d[v] > q) return false;
    return true;
}

void TRY_X(int s, int u) {
    if (s == 0) {
        if (u < k) TRY_X(y[u + 1], u + 1);
        return;
    }

    for (int v = 0; v <= n; v++) {
        if (checkX(v, u)) {
            x[s] = v;
            vis[v] = true;
            segments++;
            f += c[s][v];
            load[u] += d[v];

            if (v == 0) {
                if(u == k) {
                    if (segments - nbr == n) updateBest();
                } else {
                    if (f + c_min * (n - segments + nbr) < f_min) TRY_X(v, u);
                }
            } else {
                if (f + c_min * (n - segments + nbr) < f_min) TRY_X(v, u);
            }

            vis[v] = false;
            segments--;
            f -= c[s][v];
            load[u] -= d[v];
        }
    }
}

bool checkY(int v, int u) {
    if (v == 0) return true;
    if(vis[v]) return false;
    if (load[u] + d[v] > q) return false;
    return true;
}

void TRY_Y(int u) {
    int s = 0;
    if (y[u - 1] > 0)  s = y[u - 1] + 1;
    for (int v = s; v <= n; v++) {
        if (checkY(v, u)) {
            y[u] = v;
            vis[v] = true;
            f += c[0][v];
            load[u] += d[v];
            if (v > 0) segments++;

            if (u == k) {
                nbr = segments;
                TRY_X(y[1], 1);
            } else TRY_Y(u + 1);

            vis[v] = false;
            f -= c[0][v];
            load[u] -= d[v];
            if (v > 0) segments--;
        }
    }
}

int main(int argc, char const *argv[]){
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++){
        cin >> d[i];
    }

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
            c_min = min(c_min, c[i][j]);
        }
    }

    TRY_Y(1);
    cout << f_min;
    
    return 0;
}