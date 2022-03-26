data Tree t = Nilt | Node t (Tree t) (Tree t) deriving(Read,Show)

insertElem::(Ord t)=>Tree t->t->Tree t
insertElem (Nilt) elem = Node elem Nilt Nilt
insertElem (Node v leftTree rightTree) elem | elem < v  = Node v (insertElem leftTree elem) rightTree
                                            | elem > v  = Node v leftTree (insertElem rightTree elem)
                                            | otherwise = Node v leftTree rightTree

insertList::(Ord t)=>Tree t->[t]->Tree t
insertList tree [] = tree
insertList tree (value:values) = insertList (insertElem tree value) values

main :: IO ()
main = do
       a <- getLine
       b <- getLine
       let result = insertList (read a::Tree Int) (read b)
       print result