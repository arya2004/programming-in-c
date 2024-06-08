// File Name: addToArrayForm1.js
// Description: Adds a number to an array form using an alternative approach.

const addToArrayForm1 = function(num, k) {
    num = num.toString().replaceAll(',', '');
    let sum = 0n;
    sum = BigInt(num) - (-BigInt(k));
    sum = sum.toString().split('')
    return sum;
  };
  
  console.log(addToArrayForm1([1, 2, 3], 456));
  // Output: [ '5', '7', '9' ]
  