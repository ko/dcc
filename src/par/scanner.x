{
module Main (main) where
}

%wrapper "basic"

$digit      = 0-9
$alpha      = [a-zA-Z]
$graphic    = $printable # $white
$ident      = [0-9a-zA-Z_]
@string     = \" ($graphic # \")* \"
@identifier = ($alpha|_)($ident)*

tokens :-
    $white+                             ;

    "void"                              { \s -> TVoid }
    "int"                               { \s -> TInt }
    "char"                              { \s -> TChar }
    
    ";"                                 { \s -> TSemicolon }
    "{"                                 { \s -> TLeftBrace }
    "}"                                 { \s -> TRightBrace }
    "("                                 { \s -> TLeftParen }
    ")"                                 { \s -> TRightParen }
    "["                                 { \s -> TLeftBracket }
    "]"                                 { \s -> TRightBracket }

    "*"                                 { \s -> TAsterick }
    "-"                                 { \s -> THyphen }
    "+"                                 { \s -> TPlus }
    "/"                                 { \s -> TForwardSlash }
    ","                                 { \s -> TComma }
    "&"                                 { \s -> TAmpersand }
    "."                                 { \s -> TFullstop }
     
    "if"                                { \s -> TIf }
    "else"                              { \s -> TElse }
    "while"                             { \s -> TWhile }
    "for"                               { \s -> TFor }
    "return"                            { \s -> TReturn }
    "continue"                          { \s -> TContinue }

    "!"                                 { \s -> TNot }
    "="                                 { \s -> TAssign }
    "=="                                { \s -> TEqualityYes }
    "!="                                { \s -> TEqualityNo }
    "&&"                                { \s -> TAnd }
    "||"                                { \s -> TOr }


    $digit+                             { \s -> TIntLiteral (read s) }
    @string                             { \s -> TStringLiteral (init (tail s)) } 
    @identifier                         { \s -> TIdentifier (s) }

{
-- Each action has type :: String -> Token 

-- Token type:
data Token  = TVoid
                | TInt
                | TChar
            | TSemicolon
                | TLeftBrace
                | TRightBrace
                | TLeftParen
                | TRightParen
                | TLeftBracket
                | TRightBracket
            | TAsterick
                | THyphen
                | TPlus
                | TForwardSlash
                | TComma
                | TAmpersand
                | TFullstop
            | TIf
                | TElse
                | TWhile
                | TFor
                | TReturn
                | TContinue
            | TNot
                | TAssign
                | TEqualityYes
                | TEqualityNo
                | TAnd
                | TOr
            | TIntLiteral Int 
                | TStringLiteral String
                | TIdentifier String
            deriving (Eq,Show)

}
