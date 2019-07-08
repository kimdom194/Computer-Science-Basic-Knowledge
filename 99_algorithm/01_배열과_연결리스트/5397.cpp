/*
https://www.acmicpc.net/problem/5397

#include <bits/stdc++.h>

using namespace std;
int main(void) {
    vector<string> v;
    int num; 
    cin >> num; 

    while (num--){
        string pasw; 
        cin >> pasw;
        vector<string>::iterator it;
        it = v.begin();
        pasw_len = pasw.size;

        for(int i = 0; i < pasw_len; i++){ // ���Ϳ� ���ȣ ����
            v.push_back(pasw.substr(i,1));
        }
        for(int i = 0; i < v.size; i++){
            switch (it)
            {
            case "<":
                it--;
                break;
            case ">":
                it++;
                break;

            case "-":
                v.erase(it);
                break;
            
            default:
                cout << *it;
                break;
            }
        }
       
       //���� ���Ϳ� �ְ� (��� �Է¹��� ���� ���Ϳ� �ִ°�?)
       //�������� Ȯ���ϸ鼭 ����ġ�� ���ư���. �ּҰ� ������Ų��. 
 
    }

}*/


#include<iostream>
#include<string>
#include<list>
#include<queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    while(n--){
        list<char> L;
        for(int i = 0;i<n; i++){
        cin >> s;
        }

        auto cur = L.begin();
        for(auto c:s){
            if(c=='<'){
                if(cur != L.begin()){
                    cur--;
                }
            }
            else if(c=='>'){
                if(cur != L.end()){
                    cur++;
                }
            }
            else if(c=='-'){
                if(cur != L.begin()){
                cur--;
                }
                L.erase(cur);
            }
            else{
                L.insert(cur, c);
            }
        }
        for(auto c:L) cout << c;
        cout << endl;
    }
}

