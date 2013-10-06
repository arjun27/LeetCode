class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = dict.size();
        if (n == 0 || start == end) return 0;
        queue<string> bfs;
        unordered_set<string> done;
        bfs.push(start);
        bool found = false;
        int level = 1, nlevel = 1, nextlevel = 0;
        while (!bfs.empty()) {
            string now = bfs.front();
            bfs.pop();
            nlevel--;
            for (int i = 0; i < now.length(); i++) {
                string copy = now;
                for (int j = 0; j < 26; j++) {
                    copy[i] = 'a' + j;
                    if (end == copy) {
                        return level + 1;
                    }
                    if (dict.find(copy) != dict.end() && done.find(copy) == done.end()) {
                        bfs.push(copy);
                        done.insert(copy);
                        nextlevel++;
                    }
                }
            }
            if (nlevel == 0) {
                nlevel = nextlevel;
                nextlevel = 0;
                level++;
            }
        }
        return 0;
    }
};