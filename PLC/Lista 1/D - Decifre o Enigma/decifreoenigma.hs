
matchingChar::Char->[(Char,Char)]->Char
matchingChar i s
    | tail s == [] && fst (head s) == i = snd (head s)
    | tail s == []                      = i
    | fst (head s) == i                 = snd (head s)
    | otherwise                         = matchingChar i (tail s)

{-charByChar::String->[(Char,Char)]->String
charByChar s t
    | tail s == [] = [matchingChar (head s) t]
    | otherwise    = matchingChar (head s) t:charByChar (tail s) t-}


decEnigma::String->[(Char,Char)]->String
decEnigma s t 
    | tail s == [] = [matchingChar (head s) t]
    | otherwise    = matchingChar (head s) t:decEnigma (tail s) t

main :: IO ()
main = do
    a <- getLine
    b <- getLine
    let result = decEnigma a (read b)
    print result