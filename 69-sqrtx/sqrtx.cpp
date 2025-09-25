class Solution {
public:
long long int binarysearch(int num){
    int s=0;
    int e=num;
    long long int ans=-1;
    long long int mid=s+(e-s)/2;
    while(s<=e){
        long long int square=mid*mid;
        if(square==num){
            return mid;
        }
        if(square<num){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
    int mySqrt(int x) {
        return binarysearch(x);
    }
};