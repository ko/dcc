{
module Main (main) where
}

%wrapper "basic"

$digit      = 0-9
$alpha      = [a-zA-Z]
$graphic    = $printable # $white
@string     = \" ($graphic # \")* \"

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
    "\"                                 { \s -> TBackSlash }
    ","                                 { \s -> TComma }
    "&"                                 { \s -> TAmpersand }
     
    "if"                                { \s -> TIf }
    "else"                              { \s -> TElse }
    "while"                             { \s -> TWhile }
    "for"                               { \s -> TFor }
    
    "main"                              { \s -> TMain }
    "return"                            { \s -> TReturn }

    "!"                                 { \s -> TNot }
    "="                                 { \s -> TAssign }
    "=="                                { \s -> TEqualityYes }
    "!="                                { \s -> TEqualityNo }
    "&&"                                { \s -> TAnd }
    "||"                                { \s -> TOr }


    $digit+                             { \s -> TIntLiteral (read s) }
    @string                             { \s -> TStringLiteral (init (tail s)) } 

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
                | TBackSlash
                | TComma
                | TAmpersand
            | TIf
                | TElse
                | TWhile
                | TFor
            | TMain
                | TReturn
            | TNot
                | TAssign
                | TEqualityYes
                | TEqualityNo
                | TAnd
                | TOr
            | TIntLiteral String
                | TStringLiteral String
            deriving (Eq,Show)


main    = do
            s <- getContents
            print (alexScanTokens s)
            

}
