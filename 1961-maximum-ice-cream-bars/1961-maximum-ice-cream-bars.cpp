class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());
    vector<int> count(maxCost + 1, 0);
    for (int cost : costs) {
        count[cost]++;
    }

    int bars = 0;
    for (int cost = 1; cost <= maxCost; ++cost) {
        if (coins < cost) break;
        int buy = min(count[cost], coins / cost);
        coins -= buy * cost;
        bars += buy;
    }

    return bars;
    }
};