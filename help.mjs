import * as fs from 'fs';

function remove_comments(folder)
{
    let files = fs.readdirSync(folder);

    for (let file of files)
    {
        let filePath = folder + '/' + file;

        if (fs.statSync(filePath).isDirectory())
        {
            remove_comments(filePath);
        } else
        {
            let data = fs.readFileSync(filePath, 'utf8');
            data = data.replace(/\/\*[\s\S]*?\*\//g, '');
            data = data.replace(/\/\/.*/g, '');
            fs.writeFileSync(filePath, data, 'utf8');
        }
    }
}

function main()
{
    let folder = './cmake/include';
    remove_comments(folder);
}

main();
