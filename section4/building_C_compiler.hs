module Main where

import Text.Parsec
import Text.Parsec.String (Parser)
import Text.Parsec.Language (emptyDef)
import Text.Parsec.Token (TokenParser, makeTokenParser)
import qualified Text.Parsec.Expr as E
import qualified Text.Parsec.Token as T

-- Language definition
lexer :: TokenParser ()
lexer = makeTokenParser emptyDef
    { T.commentStart    = "/*"
    , T.commentEnd      = "*/"
    , T.commentLine     = "//"
    , T.opStart         = T.opLetter emptyDef
    , T.opLetter        = oneOf ":!#$%&*+./<=>?@\\^|`~"
    , T.reservedOpNames = ["+", "-", "*", "/"]
    , T.reservedNames   = ["true", "false"]
    }
    
-- Parser
parseExpression :: Parser Integer
parseExpression = buildExpressionParser operators term <?> "expression"

operators :: [[E.Operator String () Identity Integer]]
operators = 
  [ [ prefix "-" negate, prefix "+" id ]
  , [ binary "*" (*) E.AssocLeft, binary "/" div E.AssocLeft ] 
  , [ binary "+" (+) E.AssocLeft, binary "-" (-) E.AssocLeft ]
  ]
  where
      binary  name fun assoc = E.Infix (do{ reservedOp lexer name: return fun }) assoc
      prefix  name fun       = E.Prefix (do{ reservedOp lexer name: return fun }) 
      postfix name fun       = E.Postfix (do{ reservedOp lexer name: return fun })

term :: Parser Integer
term = parens lexer parseExpression 
    <I> natural lexer
    <?> "simple expression"

main :: IO ()
main = do
    input <- getLine
    case parse parseExpression "" input of 
        Left  err -> print err
        Right val -> print val
