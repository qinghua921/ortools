import fs from "fs";
import YAML from 'yaml'
import { CharStream, CommonTokenStream } from "antlr4ng";
import { CPP14Lexer } from "./.antlr/CPP14Lexer";
import { AccessSpecifierContext, ClassSpecifierContext, CPP14Parser, EnumSpecifierContext, FunctionDefinitionContext, MemberdeclarationContext, MemberSpecificationContext, NamespaceDefinitionContext } from "./.antlr/CPP14Parser";
import { CPP14ParserVisitor } from "./.antlr/CPP14ParserVisitor";

interface GenConfig
{
    files: string[];
    namespaces: string[];
}

interface CPPInfo
{
    type: 'NamespaceDefinition' | 'ClassSpecifier' | 'EnumSpecifier' | 'FunctionDefinition';
}

interface FunctionDefinitionInfo extends CPPInfo
{
    type: 'FunctionDefinition';
    name: string;
}

interface ClassSpecifierInfo extends CPPInfo
{
    type: 'ClassSpecifier';
    name: string;
}

interface NamespaceDefinitionInfo extends CPPInfo
{
    type: 'NamespaceDefinition';
    name: string;
}

interface EnumSpecifierInfo extends CPPInfo
{
    type: 'EnumSpecifier';
    name: string;
}



class Info
{
    gen_config!: GenConfig;
    cpp_info: { [path: string]: CPPInfo } = {};

    current_path: string = "";

    push_path(path: string | null | undefined)
    {
        this.current_path += "/" + path;
    }

    pop_path()
    {
        this.current_path = this.current_path.substring(0, this.current_path.lastIndexOf('/'));
    }
}

const info = new Info();

class OrToolsVisit extends CPP14ParserVisitor<void>
{
    visitFunctionDefinition = (ctx: FunctionDefinitionContext) =>
    {
        const function_name = ctx.declarator().pointerDeclarator()?.noPointerDeclarator().attributeSpecifierSeq()
        console.log(function_name);
        
        // info.push_path(function_name);

        // info.cpp_info[info.current_path] = {
        //     type: 'FunctionDefinition'
        // } as CPPInfo;

        // this.visitChildren(ctx);

        // info.pop_path();
    }

    visitMemberSpecification = (ctx: MemberSpecificationContext) =>
    {
        let public_ = false;
        for (const member of ctx.children)
        {
            if (member instanceof AccessSpecifierContext)
                public_ = !!(member as AccessSpecifierContext).Public()

            if (!public_) continue;

            this.visitChildren(member)
        }
    }

    visitEnumSpecifier = (ctx: EnumSpecifierContext) =>
    {
        const enum_name = ctx.enumHead().Identifier()?.getText() ?? ctx.enumHead().nestedNameSpecifier()?.getText()

        info.push_path(enum_name);

        info.cpp_info[info.current_path] = {
            type: 'EnumSpecifier',
            name: enum_name
        } as EnumSpecifierInfo;

        this.visitChildren(ctx);

        info.pop_path();
    }

    visitNamespaceDefinition = (ctx: NamespaceDefinitionContext) =>
    {
        const namespace_name = ctx.Identifier()?.getText() ?? ctx.originalNamespaceName()?.getText()

        info.push_path(namespace_name);

        info.cpp_info[info.current_path] = {
            type: 'NamespaceDefinition',
            name: namespace_name
        } as NamespaceDefinitionInfo;

        this.visitChildren(ctx);

        info.pop_path();
    };

    visitClassSpecifier = (ctx: ClassSpecifierContext) =>
    {
        const class_name = ctx.classHead().classHeadName()?.className().getText()

        info.push_path(class_name);

        info.cpp_info[info.current_path] = {
            type: 'ClassSpecifier',
            name: class_name
        } as ClassSpecifierInfo;

        this.visitChildren(ctx);

        info.pop_path();
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
        const tree = parser.translationUnit();
        const visitor = new OrToolsVisit();
        visitor.visit(tree);
    }

    gen_config.files.forEach(visitFile)

    console.log(JSON.stringify(info, null, 2));

}

main()