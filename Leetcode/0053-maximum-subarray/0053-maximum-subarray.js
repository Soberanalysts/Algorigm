/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {


    if(nums.length==0){
        return 0;
    }

    const n = nums.length;
    let dp = new Array(n + 1);

    dp[0]=nums[0];
    for(let i=1; i<nums.length;i++){
        dp[i]=Math.max(nums[i],nums[i]+dp[i-1]);
    }
    dp.sort((a, b) => a - b);
    sum = dp[n-1];

    return sum;
};
