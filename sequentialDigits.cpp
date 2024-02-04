class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums;

        for(int digit = 1; digit <= 9; digit++){
            int num = digit, nextDigit = digit + 1;
            if(num >= low && num <= high){
                nums.push_back(num);
            }
            while(num <= high && nextDigit <= 9){
                num = num * 10 + nextDigit;
                if(num >= low && num <= high) nums.push_back(num);
                nextDigit++;
            }
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};
