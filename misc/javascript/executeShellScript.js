/**
 * Executes a shell script using Node.js child_process module.
 * 
 * @param {string} scriptPath - The path to the shell script.
 * @param {Function} callback - The callback function to handle the execution result.
 */
const executeShellScript = (scriptPath, callback) => {
    const { exec } = require('child_process');

    exec(`bash ${scriptPath}`, (error, stdout, stderr) => {
        // Handle any errors or output from the shell script
        if (error) {
            console.error('Error:', error);
        }
        if (stderr) {
            console.error('stderr:', stderr);
        }
        
        // Call the callback function with the result
        callback(stdout);
    });
};

// Usage example
const scriptPath = 'temp.sh';
executeShellScript(scriptPath, (output) => {
    console.log('Script output:', output);
});

// Suggested file name: executeShellScript.js
