data Ops = SUM | MUL | SUB deriving (Read)

data IntTree = Nilt Int | Node Ops IntTree IntTree deriving (Read)

evalTree::IntTree->Int
evalTree (Nilt v) = v
evalTree (Node (SUM) leftTree rightTree) = (evalTree leftTree) + (evalTree rightTree)
evalTree (Node (MUL) leftTree rightTree) = (evalTree leftTree) * (evalTree rightTree)
evalTree (Node (SUB) leftTree rightTree) = (evalTree leftTree) - (evalTree rightTree)

main :: IO ()
main = do
    s <- getLine
    let result = evalTree (read s)
    print result