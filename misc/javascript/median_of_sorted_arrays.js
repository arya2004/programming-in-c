/**
 * Calculates the median of two sorted arrays.
 * 
 * @param {number[]} nums1 - The first sorted array.
 * @param {number[]} nums2 - The second sorted array.
 * @returns {number} - The median value.
 */
function findMedianSortedArrays(nums1, nums2) {
    // Combine the arrays and sort them in ascending order
    let combinedArray = nums1.concat(nums2).sort((a, b) => a - b);

    // Concatenate the arrays as strings, remove commas, split into characters, and sort
    let sortedString = (nums1.toString().replaceAll(",", "") + nums2.toString().replaceAll(",", "")).toString().split("").sort();

    // Calculate median based on the length of the sorted string array
    if (sortedString.length % 2 === 1) {
        // For odd length, return the middle element
        return sortedString[(sortedString.length - 1) / 2];
    } else {
        // For even length, calculate the average of the two middle elements
        return ((sortedString[sortedString.length / 2]) - -sortedString[(sortedString.length - 2) / 2]) / 2.0;
    }
}

// Test the function
console.log(findMedianSortedArrays([1, 2, 3], [4, 5, 6])); // Output: 3.5

// Suggested file name: median_of_sorted_arrays.js
