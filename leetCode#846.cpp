class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;

        map<int, int> map;

        for(int num:hand) map[num]++;
        
        for(auto t = map.begin(); t != map.end(); ){
            if(map[t->first] <= 0){
                t++;
                continue;
            }

            cout << t->first << ' ' << t->second << endl;

            for(int i = 0; i < groupSize; i++){
                int card = t->first;
                if((map.find(card + i) != map.end()) && map[card + i] > 0){
                    map[card + i]--;
                }
                else return false;
            }
        }
        return true;
    }
};

/*
1 2 3 6 2 3 4 7 8
1 2 2 3 3 4 6 7 8

1 -> 0
2 -> 0
3 -> 0
4 -> 0
6 -> 0
7 -> 0
8 -> 0




*/
