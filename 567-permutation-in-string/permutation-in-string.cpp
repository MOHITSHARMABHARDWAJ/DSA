class Solution {
private:
    bool checkequals(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;   
            }
        }
        return true;           
    }

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int count1[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            int index = s1[i] - 'a';   
            count1[index]++;
        }

        int windowsize = s1.length();  
        int count2[26] = {0};

        // first window
        int i = 0;
        while (i < windowsize) {
            int index = s2[i] - 'a';  
            count2[index]++;
            i++;
        }

        if (checkequals(count1, count2)) return true;  

        // sliding window
        while (i < s2.length()) {      
            char newchar = s2[i];
            int index = newchar - 'a';
            count2[index]++;

            char oldchar = s2[i - windowsize]; 
            index = oldchar - 'a';
            count2[index]--;

            if (checkequals(count1, count2)) return true;
            i++;
        }

        return false;
    }
};
