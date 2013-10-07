class Solution {
public:
    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<string> dirs;
        string slash = "/";
        size_t pos = 0;
        string token;
        path += slash;
        while ((pos = path.find(slash)) != string::npos) {
            token = path.substr(0, pos);
            if (token == "..") {
                if (!dirs.empty()) dirs.pop();
            }
            else if (token != "" && token != ".") dirs.push(token);
            path.erase(0, pos + slash.length());
        }
        stack<string> copy;
        if (dirs.empty()) return "/";
        while (!dirs.empty()) {
            copy.push(dirs.top()); dirs.pop();
        }
        string res = "";
        while (!copy.empty()) {
            res += "/" + copy.top(); copy.pop();
        }
        return res;
    }
};