/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */

    var isPresent = function(key, theArray){
    for(let i =0;i<theArray.length;i++){
        if(theArray[i] == key){
            return 1;
        }
    }
    return 0;
}

var intersection = function(nums1, nums2) {
    let intersectionArray = [];
    for(let i = 0;i<nums1.length;i++){
        //if the number already exist in intersection list, skip
        if(isPresent(nums1[i],intersectionArray)){
            continue;
        }
        //if the number exist in another array, push it into new array
        if(isPresent(nums1[i],nums2)){
            intersectionArray.push(nums1[i]);
        }
    }
    return intersectionArray;
};

