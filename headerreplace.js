const fs = require('fs');

let filepath = `./cmake/or-tools_x64_VisualStudio2022_cpp_v9.11.4210/include/ortools/linear_solver/linear_solver.h`; // replace with your file path

fs.readFile(filepath, 'utf8', (err, data) => {
    if (err) {
        console.error('readFile error:', err);
        return;
    }

    const singleLineCommentPattern = /\/\/.*$/gm;
    const multiLineCommentPattern = /\/\*[\s\S]*?\*\//gm;
    const blankLinePattern = /^\s*\n/gm;
    const codeBlockPattern = /{[^}|^{}]*}/g;

    const replacedData = data
        .replace(singleLineCommentPattern, '')
        .replace(multiLineCommentPattern, '')
        .replace(blankLinePattern, '')
        .replace(codeBlockPattern, ';')
        .replace(/\s*;\s*$/gm, ';')

    fs.writeFile(filepath.replace('.h', '_.h'), replacedData, (err) => {
        if (err) {
            console.error('writeFile error:', err);
            return;
        }
        console.log('writeFile success');
    });
});
