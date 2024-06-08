// File Name: multiply.js
// Description: Multiplies two numbers represented as strings.

const multiply = function(num1, num2) {
    let m = 0;
    for (let i = 0; i < num2.length; i++) {
      m = m * 10 + (num2 * num1[i]);
    }
    return m.toString();
  };
  
  console.log(multiply("123", "456"));
  // Output: 56088
  