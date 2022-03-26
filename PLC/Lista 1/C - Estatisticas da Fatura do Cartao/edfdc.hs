obtemString :: String -> Char -> String
obtemString s c
    | head s == c     = []
    | otherwise  = head s:obtemString (tail s) c

obtemResto :: String -> Char -> String
obtemResto s c
    | head s == c     = tail s
    | otherwise  = obtemResto (tail s) c

quebraString :: String -> Char -> [String]
quebraString s c 
    | s == []              = [[]]
    | obtemResto s c == [] = [obtemString s c]
    | otherwise            = [obtemString s c] ++ quebraString (obtemResto s c) c

obtemSubLista :: [String] -> Int -> Int -> [String]
obtemSubLista s n i
    | i == n && tail s == [] = [head s]
    | i == n                 = [head s]++obtemSubLista (tail s) n 1
    | tail s == []           = []   
    | otherwise              = obtemSubLista (tail s) n (i+1)

strToDouble :: [String] -> [Double]
strToDouble s = [read x :: Double | x <- s]

tratamentoEntrada :: String -> [Double]
tratamentoEntrada s = strToDouble (obtemSubLista (quebraString s ';') 3 1)


minMaxCartao :: String -> (Double, Double)
minMaxCartao s = (minimum xs, maximum xs)
    where xs = tratamentoEntrada s

main :: IO ()
main = do
    a <- getLine
    let result = minMaxCartao a
    print result