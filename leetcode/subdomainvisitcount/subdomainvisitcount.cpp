class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> result;
        unordered_map<string, int> subd;
        for (auto cp : cpdomains) {
            int count{0};
            string dom;
            stringstream st(cp); // Use stringstream to simplify parsing each entry
            st >> count >> dom;
            subd[dom] += count;
            string::size_type pos;
            // loop to find all subdomains, i.e. find periods and get substring after 
            // a period.
            while ((pos = dom.find('.')) != string::npos) {
                dom = dom.substr(pos+1);
                subd[dom] += count;
            }
        }
        for (auto cpres : subd) {
            // Iterate over all entries in map and create result string for each
            result.push_back(to_string(cpres.second) + " " + cpres.first);
        }
        return result;
    }
};
