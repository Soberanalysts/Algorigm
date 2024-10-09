/**
 * Definition for isBadVersion()
 * 
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
               let s = 0, e = n - 1;
        let m;
        
        while (s <= e) {
            m = Math.floor(s + (e - s) / 2);
            
            if (isBadVersion(m)) {
                e = m - 1; // Move to the left half if it's a bad version
            } else {
                s = m + 1; // Move to the right half if it's not a bad version
            }
        }
        
        return s; // The start index will be at the first bad version 
    };
};