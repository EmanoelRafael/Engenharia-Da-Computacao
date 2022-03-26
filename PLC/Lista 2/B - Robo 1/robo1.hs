data Command = Forward Int | Backward Int | TurnLeft | TurnRight deriving (Eq, Show, Read)
data Orientation = North | West | South | East deriving (Enum, Eq, Show, Read, Ord)

succ'::Orientation->Orientation
succ' East = North
succ' a = succ a

pred'::Orientation->Orientation
pred' North = East
pred' a = pred a

runCommand::(Int,Int)->Orientation->Command->((Int,Int),Orientation)
runCommand a b TurnLeft = (a,(succ' b))
runCommand a b TurnRight = (a,(pred' b))
runCommand (ax,ay) North (Forward c) = ((ax, ay+c),North)
runCommand (ax,ay) East (Forward c) = ((ax+c, ay),East)
runCommand (ax,ay) South (Forward c) = ((ax, ay-c),South)
runCommand (ax,ay) West (Forward c) = ((ax-c, ay),West)
runCommand (ax,ay) North (Backward c) = ((ax, ay-c),North)
runCommand (ax,ay) East (Backward c) = ((ax-c,ay),East)
runCommand (ax,ay) South (Backward c) = ((ax,ay+c),South)
runCommand (ax,ay) West (Backward c) = ((ax+c,ay),West)

destination'::(Int,Int)->Orientation->[Command]->(Int,Int)
destination' a _ [] = a
destination' a b (c:cs) = destination' (fst sts) (snd sts) cs
                          where sts = runCommand a b c

destination::(Int,Int)->[Command]->(Int,Int)
destination a b = destination' a North b

main :: IO ()
main = do
       a <- getLine
       b <- getLine
       let result = destination (read a) (read b)
       print result