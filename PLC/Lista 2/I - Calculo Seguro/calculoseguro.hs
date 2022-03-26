import Prelude hiding (Maybe (..))

data Maybe a = Just a | Nothing deriving(Show)
type Datas = (String,Int,Int)

firstString::String->Int->Int->String
firstString [] _ _ = ""
firstString (a:as) pos tam | pos >= tam = ""
                           | otherwise  = a:firstString as (pos+1) tam

secondString::String->Int->Int->String
secondString [] _ _ = ""
secondString (a:as) pos tam | pos < tam = secondString as (pos+1) tam
                            | otherwise = (a:as)

findFirstChar::String->Int->Int
findFirstChar [] _ = -1
findFirstChar (a:as) pos | a == 's' || a == 'm' || a == 'd' = pos
                         | otherwise                        = findFirstChar as (pos+1)

returnData::String->Datas
returnData s = (op,op1,op2)
               where op = firstString (secondString s 1 (findFirstChar s 1)) 1 4
                     op1 = read (firstString s 1 (findFirstChar s 1))::Int
                     op2 = read (secondString (secondString s 1 (findFirstChar s 1)) 1 4)::Int

returnOp::Datas->Maybe Int
returnOp (op,op1,op2) | op == "sum"           = Just (op1+op2)
                      | op == "sub"           = Just (op1-op2)
                      | op == "mul"           = Just (op1*op2)
                      | op == "div" && op2/=0 = Just (op1`div`op2)
                      | op == "div"           = Nothing
                      | otherwise             = Nothing


safeCalc :: String -> IO ()
safeCalc s = print (returnOp (returnData s))

main :: IO ()
main = do
       a <- getLine
       safeCalc a