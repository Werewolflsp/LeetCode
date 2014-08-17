/******************************************

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together,
such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

*****************************************/

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> res;
        int i = 0;
        if(path[0] == '/'){
            res.push("/");
            i++;
        }
        int j = i;
        for(; i < path.size(); i++){
            if(path[i] == '/' || i == path.size() - 1){
                string part;
                if(path[i] == '/'){
                    part = path.substr(j, i-j);
                }
                else{
                    part = path.substr(j, i-j+1);
                }
                if(part == string("..")){
                    if(res.top() != string("/")){
                        res.pop();
                    }
                }
                else if(part != string(".") && part != string("")){
                    res.push(part + "/");
                }
                j = i + 1;
            }
        }

        string simPath;
        while(!res.empty()){
            simPath = res.top() + simPath;
            res.pop();
        }
        if(simPath != string("/")){
            simPath.erase(simPath.size()-1);
        }

        return simPath;
    }
};
