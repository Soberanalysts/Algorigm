// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// class Solution {
// public:
//     int bad=1;
//     int i;
//     int firstBadVersion(int n) {
//         i=floor(n/2);
//         if(isBadVersion(i) != isBadVersion(i+1)){
//             bad = n+1;
//         }
//         else if(isBadVersion(i) == false) {
//             firstBadVersion(n+1);
//         }else {
//             firstBadVersion(i);
//         }
//         return bad;
//     }
// };
class Solution {
public:
    int firstBadVersion(int n) {
        int s=0, e=n-1 ;
        int m = s + (e-s)/2 ;
        while (s<=e){
            if (isBadVersion(m)) e = m-1 ;
            else s = m + 1 ;
            m = s + (e-s)/2 ;
        }
        return m ;
    }
};