
mult::[Int]->[Int]->[Int]
mult (a:as) (b:bs)
    | as == [] && bs == [] = [a*b]
    | as == []             = a*b:mult [0] bs
    | bs == []             = a*b:mult as [0]
    | otherwise            = a*b:mult as bs

mul2::[Int]->[Int]->[Int]
mul2 a b 
    | a == [] && b == [] = []
    | a == []            = mult [0] b
    | b == []            = mult a [0]
    | otherwise          = mult a b

main :: IO ()
main = do
    sa <- getLine
    let a = read sa :: [Int]
    sb <- getLine
    let b = read sb :: [Int]
    let result = mul2 a b
    print result