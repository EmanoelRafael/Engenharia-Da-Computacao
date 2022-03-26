
recursiva::[Char]->Int->Int
recursiva s p 
    | s == ['0']    = 0
    | s == ['1']    = p
    | last s == '0' = recursiva (init s) p*2
    | last s == '1' = p+recursiva (init s) p*2

btoi::String->Int
btoi s 
    | s == []   = 0
    | otherwise = recursiva s 1

main :: IO ()
main = do
    s <- getLine
    let result = btoi s
    print result