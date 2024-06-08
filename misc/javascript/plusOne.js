// File Name: plusOne.js
// Description: Adds one to each digit in an array of digits.

const plusOne = function(digits) {
    return (digits.toString().replaceAll(',', '') - (-1)).toString().split("");
  };
  
  console.log(plusOne([1, 2, 3]));
  // Output: [ '1', '3', '4' ]
  