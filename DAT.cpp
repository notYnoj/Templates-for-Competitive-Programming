//This is a double array trie that I implemented. it is a memory efficent trie that doesn't use memory inefficent classes + pointers

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>
#include <fstream>

class DAT{
private:
std::vector<int> offset;
std::vector<int> parent;
void resize(int n){
    if(offset.size() < n){
        offset.resize(n + 1000, 0);
        parent.resize(n+1000, -1);
    }

}

public:
    DAT(){
        offset.resize(1500000, 0);
        parent.resize(1500000, -1);
        offset[0] = 1;
        parent[0] = 0;
    }
    int toCode(char c){
        return(c == '#' ? 27 : c - 'A' + 1);
    }

    void insert(std::string s){
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::toupper(c);
        });
        s+="#";
        int root = 0;
        for(size_t i{0}; i < s.size(); i++){
            int target = offset[root] + toCode(s[i]);
            if (target >= (int)parent.size()) {
                resize(target);
            }
            //Not Open
            if(parent[target] != -1 && parent[target] != root){
                int targetParent = parent[target];
                std::vector<int> c1, c2;
                //count children of root + targetparent
                //whcihever one has less we will move those
                //move the children to a new place. Then update offset of parent
                //Also update any grandchildren to new index
                for(int child = 1; child <= 27; child++){
                    int pChild = offset[root] + child;
                    if(pChild > target){
                        resize(pChild);
                    }
                    if(pChild < parent.size() && pChild > -1 && parent[pChild] == root){
                        c1.push_back(child);
                    }
                }
                //c1 = cur movement c2 = squatter
                int newOffset;
                int oldOffset;
                int root2;
                std::vector<int> lookat;
                newOffset = offset[root];
                oldOffset = newOffset;
                root2 = root;
                lookat = c1;
                while(true){
                    newOffset++;
                    if(parent.size() <= newOffset){
                        resize(newOffset+10);
                    }
                    bool flag = true;
                    for(int j: lookat){
                        if(parent[newOffset + j] != -1){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        if(root2 == root){
                            if (parent[newOffset + toCode(s[i])] != -1) flag = false;
                        }
                    }
                    if(flag){
                        //found a valid position, begin moving
                        offset[root2] = newOffset;
                        for(int j : lookat){
                            offset[newOffset + j] = offset[oldOffset + j];
                            parent[newOffset + j] = root2;
                            if (offset[oldOffset + j] > 0) {
                                for(int child = 1; child <= 27; child++){
                                    int gChild = offset[oldOffset + j] + child;
                                    if(parent[gChild] == oldOffset + j){
                                        parent[gChild] = newOffset + j;
                                    }
                                }
                            }
                            offset[oldOffset + j] = 0;
                            parent[oldOffset + j] = -1;
                        }
                        break;
                    }

                }
            }
            target = offset[root] + toCode(s[i]);
            if (parent[target] == -1) {
                parent[target] = root;
                offset[target] = 1;
            }
            root = target;
        }
    }

    //returns true if word s is found
    bool search(std::string s){
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
            return std::toupper(c);
        });

        s+="#";
        return pref(s);
    }

    //returns true if the pref s is found
    bool pref(std::string s){
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
            return std::toupper(c);
        });

        int root = 0;
        for(size_t i{0}; i < s.size(); i++){
            int d = offset[root] + toCode(s[i]);
            if(d >= parent.size() || d < 0 || parent[d] != root){
                return false;
            }
            root = d;
        }
        return true;
    }
};

int main(){
    DAT trie;
    std::ifstream Input("../../data/dict.txt");
    std::string buffer;
    int cnt = 0;
    while(getline(Input, buffer)){
        if (!buffer.empty() && buffer.back() == '\r') {
            buffer.pop_back();
        }
        trie.insert(buffer);
        if(trie.search(buffer) == false){
            std::cout<<"INCORRECT AT: ";
            std::cout<<cnt<<" ";
            std::cout<<buffer;
        }
        cnt++;
    }
  //all tests were passed
    std::cout<<"all " << cnt << " tests past!";
    return 0;
}
