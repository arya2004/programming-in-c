/**
 * Precision for comparing numerical values.
 * Adjust this value as needed for your specific comparison requirements.
 */
const PRECISION = 5;

/**
 * Compares the output of a test case with the expected output.
 * 
 * @param {string} output - The actual output from the tested code.
 * @param {string} outputTestCase - The expected output for comparison.
 * @returns {boolean} - True if the output matches the expected output within the defined precision, false otherwise.
 */
function CheckOutput(output, outputTestCase) {
    // Function to clean up and extract values from output strings
    const extractValues = (str) => {
        const values = [];
        for (line of str.trim().split('\n')) {
            line = line.replace(/  +/g, " ").replace(",", "");
            if (!line.length) continue;
            for (value of line.split(' ')) {
                value = value.replace(/^[\.]+/g, "").replace(/[\.]+$/g, "");
                if (!value) continue;
                if (isNaN(value)) {
                    values.push(value.toLowerCase());
                } else {
                    let numValue = Number(value).toFixed(PRECISION);
                    values.push(Number(numValue));
                }
            }
        }
        return values;
    };

    const outputValues = extractValues(output);
    const expectedValues = extractValues(outputTestCase);

    if (outputValues.length !== expectedValues.length) return false;

    for (let idx = 0; idx < outputValues.length; idx++) {
        const val1 = outputValues[idx];
        const val2 = expectedValues[idx];
        if (String(val1) !== String(val2)) return false;
    }

    return true;
}

// Suggested file name: outputComparison.js
