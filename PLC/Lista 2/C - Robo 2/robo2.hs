data Command = Forward Int | Backward Int | TurnLeft | TurnRight deriving (Eq, Show, Read)
data Orientation = North | West | South | East deriving (Enum, Show, Read)

succ'::Orientation->Orientation
succ' East = North
succ' a = succ a

pred'::Orientation->Orientation
pred' North = East
pred' a = pred a

runCommand::Orientation->Command->Orientation
runCommand b TurnLeft = succ' b
runCommand b TurnRight = pred' b
runCommand b _ = b;

faces :: Orientation -> [Command] -> Orientation
faces a [] = a
faces a (c:cs) = faces new cs
                 where new = runCommand a c

main :: IO ()
main = do
       a <- getLine
       b <- getLine
       let result = faces (read a) (read b)
       print result