type Comando = String
type Valor = Float

sub::Valor->Valor->Valor
sub a b = b - a

operacao::(Comando,Valor)->(Valor->Valor)
operacao (a,b) | a == "Multiplica" = (*b)
               | a == "Divide"     = (/b)
               | a == "Soma"       = (+b)
               | a == "Subtrai"    = (sub b)
               | otherwise         = (*0)

composicao::(Valor->Valor)->(Valor->Valor)->(Valor->Valor)
composicao a b = b.a

executa::[(Comando,Valor)]->Int
executa [] = 0
executa [(a,b)] | a == "Divide" && b == 0 = -666
                | otherwise               = round (operacao (a,b) 0)
executa (a:as) | length (filter (\(b,c)->b=="Divide"&&c==0) (a:as)) > 0 = -666
               | otherwise                                              = round (foldl composicao (operacao a) (map operacao as) 0)

main :: IO ()
main = do
    a <- getLine
    let result = executa (read a)
    print result