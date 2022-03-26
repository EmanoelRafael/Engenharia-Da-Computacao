data Tree t = Nilt | Node t (Tree t) (Tree t) deriving(Read)

allLessThan::(Ord t)=>Tree t->t->Bool
allLessThan (Nilt) _ = True
allLessThan (Node v leftTree rightTree) c | c > v     = (allLessThan leftTree c) && (allLessThan rightTree c)
                                          | otherwise = False

allGreaterThan::(Ord t)=>Tree t->t->Bool
allGreaterThan (Nilt) _ = True
allGreaterThan (Node v leftTree rightTree) c | c < v     = (allGreaterThan leftTree c) && (allGreaterThan rightTree c)
                                             | otherwise = False

isBST::(Ord t)=>Tree t->Bool
isBST (Nilt) = True
isBST (Node v leftTree rightTree) | (allLessThan leftTree v) && (allGreaterThan rightTree v) = isBST leftTree && isBST rightTree
                                  | otherwise                                               = False

main :: IO ()
main = do
       s <- getLine
       let result = isBST (read s::Tree Int)
       print result

--(Node 5 (Node 3 Nilt Nilt) (Node 7 Nilt Nilt))