data Tree t = Nilt | Node t (Tree t) (Tree t) deriving(Read)

alturaArvore::Tree t->Int
alturaArvore (Nilt) = 0
alturaArvore (Node _ leftTree rightTree) = 1+max (alturaArvore leftTree) (alturaArvore rightTree)

main :: IO ()
main = do
       a <- getLine
       let result = alturaArvore (read a::Tree Int)
       print result