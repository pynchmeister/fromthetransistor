module Main where

import Text.Parsec
import Text.Parsec.String (Parser)
import Text.Parsec.Language (emptyDef)
import Text.Parsec.Token (TokenParser, makeTokenParser)
import qualified Text.Parsec.Expr as E
import qualified Text.Parsec.Token as T
import Control.Monad.Identity (Identity)

data Expr
  = Add Expr Expr
  | Sub Expr Expr
  | Mul Expr Expr
  | Div Expr Expr
  | Val Integer
  deriving (Show)

data OpCode
  = PUSH Integer
  | ADD
  | SUB
  | MUL
  | DIV
  deriving (Show)

type ByteCode = [OpCode]

lexer :: TokenParser ()
lexer = makeTokenParser emptyDef
  { T.commentStart    = "/*"
  , T.commentEnd      = "*/"
  , T.commentLine     = "//"
  , T.opStart         = T.opLetter emptyDef
  , T.opLetter        = oneOf ":!#$%&*+./<=>?@\\^|-~"
  , T.reservedOpNames = ["+", "-", "*", "/"]
  , T.reservedNames   = ["true", "false"]
  }

parseExpression :: Parser Expr
parseExpression = buildExpressionParser operators term <?> "expression"

operators :: [[E.Operator String () Identity Expr]]
operators =
  [ [ binary "*" Mul E.AssocLeft, binary "/" Div E.AssocLeft ]
  , [ binary "+" Add E.AssocLeft, binary "-" Sub E.AssocLeft ]
  ]
  where
    binary  name fun assoc = E.Infix (do{ reservedOp lexer name; return fun }) assoc

term :: Parser Expr
term = parens lexer parseExpression
  <|> fmap Val (natural lexer)
  <?> "simple expression"

genCode :: Expr -> ByteCode
genCode (Val n) = [PUSH n]
genCode (Add x y) = genCode x ++ genCode y ++ [ADD]
genCode (Sub x y) = genCode x ++ genCode y ++ [SUB]
genCode (Mul x y) = genCode x ++ genCode y ++ [MUL]
genCode (Div x y) = genCode x ++ genCode y ++ [DIV]

main :: IO ()
main = do
  input <- getLine
  case parse parseExpression "" input of
    Left  err -> print err
    Right expr -> mapM_ print $ genCode expr
