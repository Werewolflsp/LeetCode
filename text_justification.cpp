/**************************************************************

Given an array of words and a length L, format the text such that each line has
exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as
you can in each line. Pad extra spaces ' ' when necessary so that each line has
exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the
number of spaces on a line do not divide evenly between words, the empty slots
on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is
inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

Corner Cases:
A line other than the last line might contain only one word. What should you
do in this case?
In this case, that line should be left-justified.

***************************************************************/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        vector<string> line;
        int width = 0;
        int start = 0;
        for(int i = 0; i < words.size(); i++){
            if(width + words[i].size() + i - start <= L){
                width += words[i].size();
                line.push_back(words[i]);
            }
            else{
                start = i;
                i--;
                int spaceCount = L - width;
                if(line.size() == 1){
                    string space;
                    for(int j = 0; j < spaceCount; j++){
                        space += string(" ");
                    }
                    line[0] += space;
                }
                else{
                    string space;
                    int spaceEach = spaceCount / (line.size() - 1);
                    int oneMore = spaceCount % (line.size() - 1);
                    for(int j = 0; j < spaceEach; j++){
                        space += string(" ");
                    }
                    for(int j = 0; j < line.size() - 1; j++){
                        line[j] += space;
                        if(j < oneMore){
                            line[j] += string(" ");
                        }
                    }
                }
                string thisLine;
                for(int j = 0; j < line.size(); j++){
                    thisLine += line[j];
                }
                res.push_back(thisLine);
                line.clear();
                width = 0;
            }
        }
        string thisLine;
        for(int j = 0; j < line.size() - 1; j++){
            thisLine += line[j] + " ";
        }
        thisLine += line[line.size()-1];
        int spaceCount = L-thisLine.size();
        for(int i = 0; i < spaceCount; i++){
            thisLine += " ";
        }
        res.push_back(thisLine);

        return res;
    }
};
