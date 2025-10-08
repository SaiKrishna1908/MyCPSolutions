function twoSum(nums, target) {
    var indexMap = {};
    for (var i = 0; i < nums.length; i++) {
        indexMap[nums[i]] = i;
    }
    var low = 0;
    var high = nums.length - 1;
    nums.sort(function (a, b) { return a - b; });
    console.log(nums);
    console.log(indexMap);
    while (low < high) {
        var current = nums[low] + nums[high];
        console.log(nums[low]);
        console.log(nums[high]);
        if (current < target) {
            low = low + 1;
        }
        else if (current > target) {
            high = high - 1;
        }
        else {
            console.log(indexMap);
            console.log(indexMap[nums[low]]);
            console.log(indexMap[nums[high]]);
            return [indexMap[nums[low]], indexMap[nums[high]]];
        }
    }
    return [-1, -1];
}
console.log(twoSum([3, 2, 4], 6));
