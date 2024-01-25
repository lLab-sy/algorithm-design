#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;
using std::vector;
using std::stack;
using std::queue;
using std::map;
using std::pair;
using std::priority_queue;
using std:: set;
using std::list;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    stack<vector<queue<int>>> b;
    while(!a.empty()){
        auto data = a.top();
        a.pop();
        vector<queue<int>> nv;
        for(auto& e:data){
            queue<int> q;
            while(!e.empty()){
                auto num = e.front();
                e.pop();
                if(num == from) num = to;
                q.push(num);
            }
            nv.push_back(q);
        }
        b.push(nv);
    }
    while(!b.empty()){
        a.push(b.top());
        b.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here


    for(auto& e: a){
        auto p = e.second;
        priority_queue<int> npq;
        if(p.second == from) p.second = to;
        while(!p.first.empty()){
            int num = p.first.top();
            p.first.pop();
            if(num == from) num = to;
            npq.push(num);
        }
        p.first = npq;
        e.second = p;
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // your code here

    set<pair<list<int>, map<int, pair<int, string>>>> b;

    for(auto& s: a){
        list<int> nl;
        for(auto itr=s.first.begin(); itr!=s.first.end(); ++itr){
            int num = *itr;
            if(num == from) num = to;
            nl.push_back(num);
        }
        
        map<int, pair<int, string>> nmp;
        for(auto& p: s.second){
            int nk = p.first;
            if(nk == from) nk = to;
            int npf = p.second.first;
            if(npf == from) npf = to;
            nmp[nk] = std::make_pair(npf, p.second.second);
        }

        b.insert(std::make_pair(nl, nmp));
    }

    a = b;

}

#endif
