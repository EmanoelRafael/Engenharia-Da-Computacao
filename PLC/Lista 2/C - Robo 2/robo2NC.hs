data Command = Forward Int | Backward Int | TurnLeft | TurnRight deriving (Eq, Show, Read)
data Orientation = North | East | South | West deriving (Show, Read, Eq)

faces' :: Orientation -> [Command] -> Orientation
faces' a [] = a
faces' a (c:cs) | c == TurnLeft && a == North  =  faces' East cs
                | c == TurnLeft && a == East   = faces' South cs
                | c == TurnLeft && a == South  = faces' West cs
                | c == TurnLeft && a == West   = faces' North cs
                | c == TurnRight && a == North = faces' West cs
                | c == TurnRight && a == West  = faces' South cs
                | c == TurnRight && a == South = faces' East cs
                | c == TurnRight && a == East  = faces' North cs
                | otherwise                    = a

faces :: Orientation -> [Command] -> Orientation
faces orienti comlist = faces' orienti (filter (\x->x==TurnLeft||x==TurnRight) comlist)

main :: IO ()
main = do
       a <- getLine
       b <- getLine
       let result = faces (read a) (read b)
       print result