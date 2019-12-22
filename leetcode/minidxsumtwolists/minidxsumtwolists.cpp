class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int min_dist{10000};
        unordered_map<string, int> rest_ind;
        vector<string> restaurants;
        for (int k = 0; k < list1.size(); k++) {
            rest_ind.insert(pair<string,int>(list1[k],k));
        }
        for (int k = 0; k < list2.size(); k++) {
            auto match = rest_ind.find(list2[k]);
            if (match != rest_ind.end()) {
                int dist;
                dist = k + match->second;
                if (dist == min_dist) {
                    restaurants.push_back(list2[k]);
                } else if (dist < min_dist) {
                    restaurants.clear();
                    restaurants.push_back(list2[k]);
                    min_dist = dist;
                }
            }
        }
        return restaurants;        
    }
};
