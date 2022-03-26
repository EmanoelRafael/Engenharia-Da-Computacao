
{-percorre::String->String
percorre (a:as)| as == [] = [a]
               | otherwise    = [a]++percorre as

teste::String->Int->String
teste (a:as) d | d == 3    = ""
               | otherwise = [a]++teste as (d-1)-}


check::String->Int->Char->Int->Bool
check (a:as) b c d | as == [] && d == (b-1) && a == c = True
                   | as == []                         = False
                   | d >= b || a /= c                 = False
                   | otherwise                        = check as b c (d+1)

isReplica::String->Int->Char->Bool
isReplica a b c
    | a == [] && b == 0 = True
    | a == []           = False
    | otherwise         = check a b c 0

main :: IO ()
main = do
    a <- getLine
    b <- getLine
    c <- getChar
    let result = isReplica a (read b) c
    print result


fibonacci::Int->Int
fibonacci n
    | n == 0 = 0
    | n == 1 = 1
    | otherwise = fibonacci (n-1) + fibonacci (n-2)

compareWithHundred :: (Num a, Ord a) => a -> Ordering  
compareWithHundred = compare 100
