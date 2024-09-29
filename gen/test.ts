import { CharStream, CommonTokenStream } from "antlr4ng";
import { CPP14Lexer } from "./g4/.antlr/CPP14Lexer";
import { CPP14Parser } from "./g4/.antlr/CPP14Parser";

const input = "1 + 2 * 3";
const inputStream = CharStream.fromString(input);
const lexer = new CPP14Lexer(inputStream);
const tokenStream = new CommonTokenStream(lexer);
const parser = new CPP14Parser(tokenStream);

parser.translationUnit().