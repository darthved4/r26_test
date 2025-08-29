#include "planning.h"
#include <cmath>
#include <vector>

using namespace std;

Planner::Planner(const vector<vector<bool>> &grid) : grid(grid) {
  rows = grid.size();
  cols = grid[0].size();
}

bool Planner::isvalid(int x, int y) const {
  return (x >= 0 && x < rows && y >= 0 && y < cols && !grid[x][y]);
}

double Planner::heuristic(int x1, int y1, int x2, int y2) const {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

vector<pair<int, int>> Planner::pathplanning(pair<int, int> start,
                                             pair<int, int> goal) {
  vector<pair<int, int>> path; // store final path 

// my implementation down here
const int sx = start.first, sy = start.second;
const int gx = goal.first, gy = goal.second; // gets coords seperately x and y

if (!isvalid(sx,sy) || !isvalid(gx, gy)){
  return path; //this checks if the coords are in free and in grid
}

// movement up, down, left, right options
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

const double INF = 1e20; //used as unknown placeholder

vector<vector<int>> g(rows, vector<int>(cols, INF)); 

vector<vector<bool>> closed(rows, vector<bool>(cols, false));// closed for selected points

vector<vector<pair<int,int>>> parent(rows, vector<pair<int,int>>(cols, make_pair(-1,-1)));// parents for prev steps


vector<pair<int,int>> open; //list of points can move to

g[sx][sy] = 0;
open.push_back(make_pair(sx, sy));

// helper to compute f = g + h
auto fscore = [&](int x, int y) -> double {
  return g[x][y] + heuristic(x, y, gx, gy);
};

// A* main loop
while (!open.empty()) {
  int bestIdx = 0;
  double bestF = fscore(open[0].first, open[0].second);
  for (int i = 1; i < (int)open.size(); ++i) {
    double fi = fscore(open[i].first, open[i].second);
    if (fi < bestF) { bestF = fi; bestIdx = i; }
  }

  
  const int x = open[bestIdx].first;
  const int y = open[bestIdx].second;

  
  open[bestIdx] = open.back();
  open.pop_back();

  if (closed[x][y]) continue;
  closed[x][y] = true;

  if (x == gx && y == gy) {
    vector<pair<int,int>> rev;
    int cx = gx, cy = gy;
    while (!(cx == sx && cy == sy)) {
      rev.push_back(make_pair(cx, cy));
      pair<int,int> p = parent[cx][cy];
      cx = p.first; cy = p.second;
    }
    rev.push_back(make_pair(sx, sy));

    for (int i = (int)rev.size() - 1; i >= 0; --i) {
      path.push_back(rev[i]);
    }
    return path;
  }

  
  for (int k = 0; k < 4; ++k) {
    int nx = x + dx[k], ny = y + dy[k];
    if (!isvalid(nx, ny)) continue;   // out of bounds or obstacle
    if (closed[nx][ny]) continue;

    double tentativeG = g[x][y] + 1.0;  // each step costs 1 cell
    if (tentativeG < g[nx][ny]) {
      g[nx][ny] = tentativeG;
      parent[nx][ny] = make_pair(x, y);

      // put in open if not already there
      bool inOpen = false;
      for (int i = 0; i < (int)open.size(); ++i) {
        if (open[i].first == nx && open[i].second == ny) { inOpen = true; break; }
      }
      if (!inOpen) open.push_back(make_pair(nx, ny));
    }
  }
}

  return path;
}