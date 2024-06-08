// File Name: stringToInt.js
// Description: Converts a string representation of a number to an integer.

const stringToInt = string =>
    string.split('').reverse().reduce((acc, el, i) => acc + el * (10**i), 0);
  
  console.log(stringToInt("56789"));
  // Output: 56789
  


// Description: Converts a string representation of a number to an integer using an alternative approach.

const strToInt = string => {
    let mul = 0;
    for (let i of string) {
      mul = i - -(mul * 10);
    }
    return mul;
  };
  
  console.log(strToInt("56789"));
  // Output: 56789
  