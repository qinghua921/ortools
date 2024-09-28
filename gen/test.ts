import { CharStream, CommonTokenStream } from "antlr4ng";
import { ExpressionLexer } from "./g4/.antlr/ExpressionLexer";
import { ExpressionParser } from "./g4/.antlr/ExpressionParser";

const input = "1 + 2 * 3";
const inputStream = CharStream.fromString(input);
const lexer = new ExpressionLexer(inputStream);
const tokenStream = new CommonTokenStream(lexer);
const parser = new ExpressionParser(tokenStream);
const tree = parser.start();

console.log(tree.toStringTree(null));
