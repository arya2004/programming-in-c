// File Name: addBinary.js
// Description: Adds two binary numbers represented as strings.

const addBinary = function(a, b) {
    return (BigInt(('0b' + a).toString(10)) - (-(BigInt(('0b' + b).toString(10))))).toString(2);
  };
  
  console.log(addBinary("101", "111"));
  // Output: 1100
  


// Description: Adds two binary numbers represented as strings using an alternative approach.

const addBinary1 = function(a, b) {
    let aa = '0b' + a;
    let bb = '0b' + b;
    if (a == 0) {
      return b;
    }
    if (b == 0) {
      return a;
    }
    if (a == b) {
      return (aa * 0b10).toString(2);
    }
    return (((aa ** 0b10) - (bb ** 0b10)) / (aa - bb));
  };
  
  console.log(addBinary1("101", "111"));
  // Output: 1100
  