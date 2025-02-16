// 332. Reconstruct Itinerary	
// https://leetcode.com/problems/reconstruct-itinerary/description/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> valid_iten;
    
    bool can_travarse(string current_node, vector<string> path, vector<vector<string>> edges, int totalEdges) {
       
        if(edges.size()==0 || totalEdges==path.size()) {
            valid_iten.push_back(path);
            return true;
        }
        
        for(int i=0;i<edges.size();i++) {
            if(edges[i][0]==current_node) {
                vector<vector<string>> new_edges = edges;
                new_edges.erase(new_edges.begin() + i);
                
                vector<string> new_path = path;
                new_path.push_back(edges[i][1]);
                
                if(can_travarse(edges[i][1], new_path, new_edges, totalEdges)) return true;
            }
        }
        
        return false;
    }
    
    static bool comp(vector<string>& a, vector<string>& b) {
        return a[1] < b[1];
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end(), comp);
        
        can_travarse("JFK", vector<string>{"JFK"}, tickets, tickets.size());
        
        return valid_iten[0];
    }
};



int main() {
    // vector<vector<string>> tickets{{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    // vector<vector<string>> tickets{{"JFK","AAA"},{"AAA","BBB"},{"AAA","BBB"},{"BBB","AAA"}};
    
    // TLE case
    vector<vector<string>> tickets{{"JFK","SFO"},{"JFK","ATL"},{"SFO","JFK"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"}};
    
    Solution s;
    auto res = s.findItinerary(tickets);

    for(int i=0;i<res.size();i++) {
        cout << res[i] << endl;
    }

    return 0;
}