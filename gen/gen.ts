import fs from "fs";
import YAML from 'yaml'
import { CharStream, CommonTokenStream } from "antlr4ng";
import { CPP14Lexer } from "./.antlr/CPP14Lexer";
import { CPP14ParserVisitor } from "./.antlr/CPP14ParserVisitor";
import { ClassNameContext, ClassSpecifierContext, CPP14Parser, NamespaceDefinitionContext } from "./.antlr/CPP14Parser";

class Info
{
    gen_config!: GenConfig;
}

class MyVisitor extends CPP14ParserVisitor<Info>
{
    visitNamespaceDefinition = (ctx: NamespaceDefinitionContext) =>
    {
        let identifier = ctx.Identifier();
        if (identifier && info.gen_config.namespaces.includes(identifier.getText()))
        {
            console.log("namespace name: " + ctx.Identifier());
        }

        return info;
    };

    visitClassSpecifier = (ctx: ClassSpecifierContext) =>
    {
        let classHead = ctx.memberSpecification();
        console.log('eeeeeeeeeeeeeeee');
        
        console.log("class name: " + classHead?.getText());
        
        if (classHead)
        {
            console.log("class name: " + classHead.getText());
        }

        return info;
    }

    visitClassName = (ctx: ClassNameContext) =>
    {
        let className = ctx.Identifier()
        console.log("class name: " + className?.getText());
        if (className)
        {
            console.log("class name: " + className.getText());
        }

        return info;
    }
}

interface GenConfig
{
    files: string[];
    namespaces: string[];
}

const info = new Info();

/***********************************************************************************
 * Script entry point.
 ***********************************************************************************/

function main()
{
    const gen_config_file = fs.readFileSync('./gen_config.yaml', 'utf-8')
    const gen_config: GenConfig = YAML.parse(gen_config_file)
    info.gen_config = gen_config

    function visitFile(file: string)
    {
        const input = fs.readFileSync(file, { encoding: "utf8" })
        const inputStream = CharStream.fromString(input);
        const lexer = new CPP14Lexer(inputStream);
        const tokenStream = new CommonTokenStream(lexer);
        const parser = new CPP14Parser(tokenStream);

        const visitor = new MyVisitor();
        visitor.visit(parser.translationUnit());
    }

    gen_config.files.forEach(visitFile)
}

main()