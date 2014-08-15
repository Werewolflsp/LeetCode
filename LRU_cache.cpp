/*********************************

Design and implement a data structure for Least Recently Used (LRU) cache.
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists
in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present.
When the cache reached its capacity, it should invalidate the least recently
used item before inserting a new item.

**********************************/

#include <cstring>
#include <unordered_map>
using namespace std;

struct sorted{
    int key;
    int value;
    sorted *next;
    sorted *before;

    sorted(int a, int b):key(a),value(b){
        next = NULL;
        before = NULL;
    }
    ~sorted(){
        delete next;
    }
};

class LRUCache{
public:
    int occupy;
    unordered_map<int, sorted *> storage;
    sorted* newest;
    sorted* oldest;
    int total;

    LRUCache(int capacity) {
        storage.clear();
        occupy = 0;
        total = capacity;
        newest = NULL;
        oldest = NULL;
    }

    ~LRUCache(){
        delete newest;
        storage.clear();
    }

    int get(int key) {
        if(storage.find(key) != storage.end()){
            int temp = storage[key]->value;
            updateList(storage[key]);
            return temp;
        }
        else{
            return -1;
        }
    }

    void set(int key, int value) {
        if(total == 0){
            return;
        }
        if(storage.find(key) != storage.end()){
            storage[key]->value = value;
            updateList(storage[key]);
        }
        else{
            sorted* temp = new sorted(key, value);
            if(occupy == total){
                storage.erase(storage.find(oldest->key));
                if(total == 1){
                    newest = temp;
                    oldest = temp;
                }
                else{
                    oldest = oldest->before;
                    temp->next = newest;
                    newest->before = temp;
                    newest = temp;
                    delete oldest->next;
                    oldest->next = NULL;
                }
            }
            else{
                occupy++;
                if(newest == NULL){
                    newest = temp;
                    oldest = temp;
                }
                else{
                    temp->next = newest;
                    newest->before = temp;
                    newest = temp;
                }
            }
            storage[key] = temp;
        }
    }

    void updateList(sorted* t){
        if(t == newest){
            return;
        }

        if(t == oldest && t->before != NULL){
            oldest = oldest->before;
        }

        if(t->before != NULL){
            t->before->next = t->next;
        }
        if(t->next != NULL){
            t->next->before = t->before;
        }

        t->next = newest;
        t->before = NULL;
        newest->before = t;
        newest = t;
    }
};
