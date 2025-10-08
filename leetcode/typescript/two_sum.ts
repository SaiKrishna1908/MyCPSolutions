function twoSum(nums: number[], target: number): number[] {

    const indexMap = {};

    for(let i =0;i<nums.length;i++) {
        indexMap[nums[i]] = i;
    }

    let low: number = 0;
    let high: number = nums.length-1;

    nums.sort((a,b) => a-b);

    console.log(nums)

    console.log(indexMap)

    while(low < high) {
        let current: number = nums[low] + nums[high];
        console.log(nums[low])
        console.log(nums[high])
        if (current < target) {
            low = low+1;
        } else if (current > target) {
            high = high-1;
        } else {            
            return [indexMap[nums[low]], indexMap[nums[high]]];
        }
    }

    return [-1,-1];
}

console.log(twoSum([3,2,4], 6));