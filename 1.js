var findMedianSortedArrays = function(nums1, nums2) {
    
    let w = nums1.concat(nums2).sort((a,b)=> a-b)
    let t =  (nums1.toString().replaceAll(",",'') + nums2.toString().replaceAll(',','')).toString().split("").sort();
    if(t.length %2 === 1){
        return t[(t.length-1)/2]
    }
    if(t.length %2 === 0){
        return ((t[(t.length)/2]) - -t[(t.length-2)/2])/2.0
    }
    
};

//console.log(findMedianSortedArrays([1,2,3], [4,5,6]))
console.log([-3,-2,-1,1,23].concat() )