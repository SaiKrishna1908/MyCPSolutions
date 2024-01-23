#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    bool isValidStep(int m, int n, int mx, int ny) {
        if (mx >= m || mx < 0) {
            return false;
        } else if (ny >= n || ny < 0) {
            return false;
        }

        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> directions{{-1,0}, {0,-1}, {0,1}, {1,0}};

        queue<pair<int,int>> q;

        q.push(make_pair(sr,sc));

        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> isVisited(n,vector<bool>(m, false));

        int toMatch = image[sr][sc];
        while(!q.empty()) {
            auto element = q.front();
            q.pop();

            int current_x = element.first;
            int current_y = element.second;

            if (isVisited[current_x][current_y]) {
                continue;
            }

            for(int i=0;i<4;i++) {
                int new_x = current_x+directions[i][0];
                int new_y = current_y+directions[i][1];

                if (isValidStep(image.size(), image[0].size(), new_x, new_y)) {
                    if (image[new_x][new_y] == toMatch) {
                        q.push(make_pair(new_x, new_y));
                    }    
                }
            }
            
            image[current_x][current_y] = color;
            isVisited[current_x][current_y] = true;
        }

        image[sr][sc] = color;

        return image;
    }
};