class Solution {
public:

bool canShip(const std::vector<int>& weights, int capacity, int days) {
        int currWeight = 0, requiredDays = 1;

        for (int weight : weights) {
            if (currWeight + weight > capacity) {
                requiredDays++;
                currWeight = 0;
            }
            currWeight += weight;
        }

        return requiredDays <= days;
    }


    int shipWithinDays(vector<int>& weights, int days) {
       int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canShip(weights, mid, days)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result; 
    }
};