class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0, total = 0, seen1 = 0;

        for(auto f: flowerbed){
            if(f == 0){
                cnt++;
            }
            else{
                if(seen1)
                    cnt--;

                total += cnt/2;
                cnt = 0;
                seen1 = 1;
            }
        }

        total += (cnt/2);

        if(seen1 == 0 && cnt%2 == 1)
            total++;

        return total>=n;
    }
};