const PRECISION = 5;
function CheckOutput(output, outputTestCase) {
    const outputValues = [];
    for (line of output.trim().split('\n')) {
        line = line.replace(/  +/g, " ");
        line = line.replace(",", "");
        if (!line.length)
            continue;
        for (value of line.split(' ')) {
            value = value.replace(/^[\.]+/g, "");
            value = value.replace(/[\.]+$/g, "");
            if (!value)
                continue;
            if (isNaN(value)) {
                let textValue = value.toLowerCase();
                outputValues.push(textValue);
            } else {
                let numValue = Number(value);
                numValue = Number(numValue.toFixed(PRECISION));
                outputValues.push(numValue);
            }
        }
    }
    const expectedValues = [];
    for (line of outputTestCase.trim().split('\n')) {
        line = line.replace(/  +/g, " ");
        line = line.replace(",", "");
        if (!line.length)
            continue;
        for (value of line.split(' ')) {
            value = value.replace(/^[\.]+/g, "");
            value = value.replace(/[\.]+$/g, "");
            if (!value)
                continue;
            if (isNaN(value)) {
                let textValue = value.toLowerCase();
                expectedValues.push(textValue);
            } else {
                let numValue = Number(value);
                numValue = Number(numValue.toFixed(PRECISION));
                expectedValues.push(numValue);
            }
        }
    }
    if (outputValues.length !== expectedValues.length)
        return false;
    const minLength = Math.min(outputValues.length, expectedValues.length);
    for (let idx = 0; idx < minLength; idx += 1) {
        const val1 = outputValues[idx];
        const val2 = expectedValues[idx];
        if ((val1 !== val2) && (String(val1) !== String(val2))) {
            return false;
        }
    }
    return true;
}