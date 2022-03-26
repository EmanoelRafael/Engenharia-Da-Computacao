sumTo::Int->Int
sumTo n 
    | n == 0    = 0
    | n == 1    = 1
    | otherwise = n+sumTo (n-1)

main :: IO()
main = interact $ show . sumTo . read