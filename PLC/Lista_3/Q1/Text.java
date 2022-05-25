package Q1;

public class Text {
    private String frase;
    private String word;

    public Text(String frase){
        //Inicializa a string que o Texto armazena
        this.frase = frase;

        //Inicializa a palavra a ser usada quando o metodo replaceWord for chamado
        this.word = "";
    }

    public void setWord(String word){
        //Muda a palavra a ser usada quando o metodo replaceWord for chamado
        this.word = word;
    }

    public String getFrase(){
        //Retorna o texto
        return this.frase;
    }

    public String getWord(){
        //Retorna a palavra a ser usada quando o metodo replaceWord for chamado
        return this.word;
    }

    public int getSize(){
        //Retorna a quantidade de palavras do texto
        return this.frase.split(" ").length;
    }

    public int findFreq(String word){
        /*Funcao que recebe uma palavra e retorna quantas vezes aquela palavra aparece
        no texto, desconsiderando letras maiusculas*/ 


        //Inicializa um contador
        int count = 0;

        //Divide o texto em palavras (Trechos de strings separados por espacos)
        String[] words = frase.split(" ");

        //Desconsidera letras maiusculas
        word = word.toLowerCase();

        //Para cada palavra no texto se a palavra for igual a pedida incrementa o contador
        for (String string : words) {
            if (string.toLowerCase().equals(word)) {
                count++;
            }
        }

        //Retorna o contador (quantidade de vezes que a palavra apareceu no texto)
        return count;
    }

    public void replaceWords(String oldWord){
        /*Funcao que recebe uma palavra e substitui todas as ocorrencias dessa palavra no texto 
        pela palavra armazenada no objeto (na variavel word)*/

        //Inicializa um contador
        int index = 0;

        //Divide o texto em palavras (Trechos de strings separados por espacos)
        String[] words = this.frase.split(" ");
        
        //Para cada palavra no texto se a palavra for igual a pedida realiza a troca
        for (String string : words) {
            
            if (string.toLowerCase().equals(oldWord.toLowerCase())) {
                words[index] = this.word;
            }
            index++;
        }
        
        //Atualiza o texto, juntando o vetor de palavras, ja substituido
        this.frase = String.join(" ", words);
    }
}

