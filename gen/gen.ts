import fs from "fs";
import YAML from 'yaml'
import { CharStream, CommonTokenStream } from "antlr4ng";
import { CPP14Lexer } from "./.antlr/CPP14Lexer";
import { ClassHeadContext, ClassSpecifierContext, CPP14Parser, NamespaceDefinitionContext } from "./.antlr/CPP14Parser";
import { CPP14ParserVisitor } from "./.antlr/CPP14ParserVisitor";

interface GenConfig
{
    files: string[];
    namespaces: string[];
}

class ClassInfo
{
    name: string;
    namespace: string;

    constructor(name: string, namespace: string)
    {
        this.name = name;
        this.namespace = namespace;
    }
}

class NamespaceInfo
{
    name: string;
    classes: Map<string, ClassInfo> = new Map();

    constructor(name: string)
    {
        this.name = name;
    }
}

class Info
{
    gen_config!: GenConfig;
    namespace_info: Map<string, NamespaceInfo> = new Map();
    current_namespace: string = "";
}

const info = new Info();

class OrToolsVisit extends CPP14ParserVisitor<void>
{
    visitNamespaceDefinition = (ctx: NamespaceDefinitionContext) =>
    {
        let identifier = ctx.Identifier();
        if (!identifier)
        {
            this.visitChildren(ctx);
            return;
        }
        if (!info.gen_config.namespaces.includes(identifier.getText()))
        {
            this.visitChildren(ctx);
            return;
        }

        info.current_namespace = identifier.getText();
        if (!info.namespace_info.has(info.current_namespace))
        {
            info.namespace_info.set(info.current_namespace, new NamespaceInfo(info.current_namespace));
        }

        this.visitChildren(ctx);
    };

    visitClassSpecifier = (ctx: ClassSpecifierContext) =>
    {
        let className = ctx.classHead()?.classHeadName()?.className();

        if (!className)
        {
            this.visitChildren(ctx);
            return;
        }

        let classInfo = new ClassInfo(className.getText(), info.current_namespace);
        info.namespace_info.get(info.current_namespace)!.classes.set(classInfo.name, classInfo);

        this.visitChildren(ctx);
    }
}

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
        const visitor = new OrToolsVisit();
        const tree = parser.translationUnit();
        visitor.visit(tree);
    }

    gen_config.files.forEach(visitFile)

    console.log(JSON.stringify(info, null, 2));

}

main()