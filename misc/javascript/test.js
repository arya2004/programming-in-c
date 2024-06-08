// File Name: test.js
// Description: Performs a test operation on a string.

const test = function(s) {
    s = s.split("*");
    let m = 1;
    for (let i in s) {
      m = m + i;
    }
    return m;
  };
  
  console.log(test("abc*def*ghi"));
  // Output: "123"
  