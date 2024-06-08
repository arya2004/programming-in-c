// File Name: submission.js
// Description: Handles a submission and throws an error.

const submission = () => {
    let thing = "manuscript";
    throw(thing);
  };
  
  try {
    submission();
  } catch (thing) {
    console.log(thing);
  }
  