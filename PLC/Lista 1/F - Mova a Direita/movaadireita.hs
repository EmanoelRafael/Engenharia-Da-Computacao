
addEspacos :: Int -> String
addEspacos n = [' '|_<-[1..n]]

paraDireita::Int->String->String
paraDireita n s = s++addEspacos n

parseInput :: Read a => String -> (a, String)
parseInput str = let [n, s] = words str
                 in (read n, s)
main :: IO()
main = interact $ uncurry paraDireita . parseInput