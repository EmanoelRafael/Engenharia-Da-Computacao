package Q1;

public class Main {
    
    public static void main(String[] args) {
        //OBS: Foi considerado que uma palavra eh uma substring separa do resto do texto por espacos! 
        //ou seja, nao foi considerado pontuacao, no exemplo abaixo 'PLC.' eh uma palavra enquanto 'PLC' seria outra

        //Instanciacao do objeto
        Text texto = new Text("Os melhores Monitores do Cin: Os melhores monitores do Centro de informatica da UFPE com certeza sao os Monitores da disciplina de PLC. Eles sao OS MONITORES");
        
        //Palavra a ser trocada
        String word = "Monitores";

        //Quantidade de palavras total do texto, e frquencia da palavra a ser trocada
        System.out.println("Quantidade de Palavras: "+texto.getSize() +" Frequencia da palavra "+ word + ": "+texto.findFreq(word));

        //Definicao da palavra que vai entrar no lugar da palavra a ser trocada
        texto.setWord("professores");

        //Troca da palavra
        texto.replaceWords(word);

        //Mostragem do novo texto
        System.out.println(texto.getFrase());
        
    }
    
}
