data Cmd = Cursor Int | Backspace Int | Delete Int | Insert String deriving(Read, Show)
type Text = (String,Int) 

delete::Int->Int->Int->String->String
delete _ _ _ [] = ""
delete s e pos (o:os) | pos<s         = o:delete s e (pos+1) os
                      | pos>=s&&pos<e = delete s e (pos+1) os
                      | pos>=e        = o:delete s e (pos+1) os
                      | otherwise     = ""
firstString::String->Int->Int->String
firstString [] _ _ = ""
firstString (a:as) pos tam | pos >= tam = ""
                           | otherwise  = a:firstString as (pos+1) tam

secondString::String->Int->Int->String
secondString [] _ _ = ""
secondString (a:as) pos tam | pos < tam = secondString as (pos+1) tam
                            | otherwise = (a:as)

insert::String->String->Int->String
insert olds news c = (firstString olds 0 c)++news++(secondString olds 0 c)

runCmd::Text->Cmd->Text
runCmd([],_) _ = ("",-1)
runCmd (s,c) (Cursor n) | c+n<=length s && c+n>=0 = (s,c+n)
                        | otherwise              = (s,c)
runCmd (s,c) (Backspace n) | c-n >= 0   = ((delete (c-n) c 0 s),c-n)
                           | otherwise = (s,c)
runCmd (s,c) (Delete n) | c + n <= length s = ((delete c (c+n) 0 s),c)
                        | otherwise        = (s,c)
runCmd (s,c) (Insert f) = (insert s f c,c)

editText'::Text->[Cmd]->Text
editText' s [] = s
editText' s (a:as) = editText' ret as
                     where ret = runCmd s a

editText::String->[Cmd]->String
editText s a = fst (editText' (s,0) a)

main :: IO ()
main = do
    a <- getLine
    b <- getLine
    let result = editText a (read b)
    print result