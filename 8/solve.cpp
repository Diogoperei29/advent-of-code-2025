#include "chrym.hpp"
#include <iostream>

class Day8 {
private:
    std::vector<std::string> lines;
    std::vector<std::vector<int>> boxes;

public:
    Day8(std::string_view path) {
        lines = chrym::read_lines(path, false);
        boxes.reserve(lines.size());
        for (const auto& line : lines) {
            auto box_pos = chrym::split(line, ',');
            boxes.push_back({ stoi(box_pos[0]), stoi(box_pos[1]), stoi(box_pos[2]) });
        }
    }

    struct Edge {
        int id_A;
        int id_B;
        double dist;
    };

    class DSU {
        public:
        std::vector<int> parent, rank;

        DSU (int n_edges){
            parent.reserve(n_edges);
            rank.reserve(n_edges);
            for (int i = 0; i < n_edges; i++) {
                parent.push_back(i);
                rank.push_back(i);
            }
        }

        int find(int i) {
            return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
        }

        void unite(int x, int y) {
            int s1 = find(x), s2 = find(y);
            if (s1 != s2) {
                if (rank[s1] < rank[s2]) parent[s1] = s2;
                else if (rank[s1] > rank[s2]) parent[s2] = s1;
                else parent[s2] = s1, rank[s1]++;
            }
        }
    };

    double getDistance(int id_A, int id_B) {
        return pow(boxes[id_A][0] - boxes[id_B][0] , 2.0) + 
               pow(boxes[id_A][1] - boxes[id_B][1] , 2.0) + 
               pow(boxes[id_A][2] - boxes[id_B][2] , 2.0);
    }

    std::string part1() {
        int result = 0;
        std::vector<Edge> edges;

        for (int i = 0; i < static_cast<int>(boxes.size()); i++) {
            for (int j = i+1; j < static_cast<int>(boxes.size()); j++) {
                edges.push_back({i, j, getDistance(i, j)});
            }
        }

        std::sort(edges.begin(), edges.end(),
            [](const Edge& a, const Edge& b) { return a.dist < b.dist; } );

        // DSU dsu(static_cast<int>(boxes.size()));
        // int cost = 0, count = 0;

        // for (const auto& edge : edges) { 
        //     if (dsu.find(edge.id_A) != dsu.find(edge.id_B)) {
        //         dsu.unite(edge.id_A, edge.id_B);
        //         if (++count >= static_cast<int>(boxes.size()) - 1) break;
        //     }
        // }

        for (const auto& edge : edges) { 
        
            
        
        }



        return std::to_string(result);
    }

    std::string part2() {
        // TODO: Implement part 2 solution
        int result = 0;
        // return std::to_string(result);
        return "Not implemented";
    }
};
