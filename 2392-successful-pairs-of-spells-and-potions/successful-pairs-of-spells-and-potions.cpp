class Solution {
public:
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;
        for (int i = 0; i < spells.size(); i++) {
            long long spellPower = spells[i];
            long long minPotion = (success + spellPower - 1) / spellPower; 

            int index = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();
            int count = m - index;

            ans.push_back(count);
        }

        return ans;
    }
};