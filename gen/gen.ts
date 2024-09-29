import { CharStream, CommonTokenStream } from "antlr4ng";
import { CPP14Lexer } from "./g4/.antlr/CPP14Lexer";
import { CPP14Parser, NamespaceAliasContext, NamespaceAliasDefinitionContext, NamespaceDefinitionContext, NamespaceNameContext, OriginalNamespaceNameContext } from "./g4/.antlr/CPP14Parser";
import fs from "fs";
import { CPP14ParserVisitor } from "./g4/.antlr/CPP14ParserVisitor";

class Info { }

const info = new Info();

class MyVisitor extends CPP14ParserVisitor<Info>
{
    visitNamespaceDefinition = (ctx: NamespaceDefinitionContext) =>
    {
        if (ctx.Identifier())
        {
            console.log("namespace name: " + ctx.Identifier());
        }

        return info;
    };
}

const input = fs.readFileSync(
    "D:\\Code\\ortools\\cmake\\or-tools_x64_VisualStudio2022_cpp_v9.11.4210\\include\\ortools\\linear_solver\\linear_solver.h"
    , { encoding: "utf8" }
)
const inputStream = CharStream.fromString(input);
const lexer = new CPP14Lexer(inputStream);
const tokenStream = new CommonTokenStream(lexer);
const parser = new CPP14Parser(tokenStream);

const visitor = new MyVisitor();
const result = visitor.visit(parser.translationUnit());
console.log(result);
