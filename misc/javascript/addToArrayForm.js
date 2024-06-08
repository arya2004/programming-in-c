// File Name: addToArrayForm.js
// Description: Adds a number to an array form.

const addToArrayForm = function(num, k) {
    return (BigInt(num.toString().replaceAll(',', '')) - (-BigInt(k))).toString().split("");
  };
  
  console.log(addToArrayForm([1, 2, 3], 456));
  // Output: [ '5', '7', '9' ]
  