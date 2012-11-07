{
module Main where
import Scanner
}

%name dcc
%tokentype { Token }
%error parseError

%token 
    "void"                              { TVoid }
    "int"                               { TInt }
    "char"                              { TChar }
    ";"                                 { TSemicolon }
    "{"                                 { TLeftBrace }
    "}"                                 { TRightBrace }
    "("                                 { TLeftParen }
    ")"                                 { TRightParen }
    "["                                 { TLeftBracket }
    "]"                                 { TRightBracket }
    "*"                                 { TAsterick }
    "-"                                 { THyphen }
    "+"                                 { TPlus }
    "/"                                 { TForwardSlash }
    ","                                 { TComma }
    "&"                                 { TAmpersand }
    "."                                 { TFullstop }
    "if"                                { TIf }
    "else"                              { TElse }
    "while"                             { TWhile }
    "for"                               { TFor }
    "return"                            { TReturn }
    "continue"                          { TContinue }
    "!"                                 { TNot }
    "="                                 { TAssign }
    "=="                                { TEqualityYes }
    "!="                                { TEqualityNo }
    "&&"                                { TAnd }
    "||"                                { TOr }
    digit                              { TIntLiteral $$ }
    string                             { TStringLiteral $$ } 
    identifier                         { TIdentifier $$ }
%%

declaration:
    declaration-specifiers initialized-declarator list ";"

declaration-specifiers:
    /*
    storage-class-specifier declaration-specifiers
    |*/ type-specifier declaration-specifiers
    /*
    | type-qualifier declaration-specifiers
    */
    | function-specifier declaration-specifiers

initialized-declarator-list:
    initialized-declarator
    | initialized-declarator-list "," initialized-declarator

initialized-declarator:
    declarator
    declarator "=" initializer

    /*
storage-class-specifier:
    "auto"
    | "extern"
    | "register"
    | "static"
    | "typedef"
    */

function-specifier:
    "inline"

type-specifier:
    /*
    enumeration-type-specifier
    | floating-point-type-specifier
    | */integer-type-specifier
    /*
    | structure-type-specifier
    | typedef-name
    | union-type-specifier
    | void-type-specifier
    */

    /*
type-qualifier:
    "const"
    | "volatile"
    | "restrict"
    */

declarator:
    pointer-declarator
    direct-declarator

direct-declarator:
    simple-declarator
    "(" declarator ")"
    function-declarator
    array-declarator

simple-declarator:
    identifier  

pointer-declarator:
    pointer direct-declarator

pointer:
    "*" type-qualifier-list
    "*" type-qualifier-list pointer

type-qualifier-list:
    type-qualifier
    type-qualifier-list type-qualifier

array-declarator:
    direct-declarator [ constant-expression ]
    /*
    | direct-declarator [ array-qualifier-list array-size-expression ]
    | direct-declarator [ array-qualifier-list ]
    */

constant-expression:
    conditional-expression

    /*
array-qualifier-list:
    array-qualifier
    | array-qualifier-list array-qualifier
    */

    /*
array-qualifier:
    "static"
    | "restrict"
    | "const"
    | "volatile"
    */

    /*
array-size-expression:
    assignment-expression
    | "*"
    */

function-declarator:
    direct-declarator "(" paramater-type-list ")"
    | direct-declarator "(" identifier-list ")"

paramater-type-list:
    paramater-list
    /* We don't support the vargs
    | parameter-list "," ...
    */

parameter-list:
    parameter-declaration
    | parameter-list "," parameter-declaration

parameter-declaration:
    declaration-specifiers declarator
    | declaration-specifiers abstract-declarator

identifier-list:
    identifier
    | parameter-list "," identifier

initializer:
    assignment-expression
    | "{" initializer-list "}"

initializer-list:
    initializer
    | initializer-list "," initializer
    /* C99
    | designation initializer
    | initializer-list "," designation initializer  

designation:
    designator-list "*"

designator-list:
    designator
    | designator-list designator

designator:
    "[" constant-expression "]"
    | "." identifier
    */


