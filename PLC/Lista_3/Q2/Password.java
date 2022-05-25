package Q2;

public class Password {
    private String alphaPass;
    private String numPass;

    public Password(){
        /*Construtor sem parametros, inicializa a senha com valores default */
        this.alphaPass = "123abc";
        this.numPass = "123";
    }

    public Password(String fst, String snd){
        /*Construtor com parametros, inicializa a senha com os valores passados */
        this.alphaPass = fst;
        this.numPass = snd;
    }

    public String getAlphaPass(){
        /*Retorna a senha alphanumerica */
        return this.alphaPass;
    }

    public String getNumPass(){
        /*Retorna a senha numerica */
        return this.numPass;
    }

    public void setAlphaPass(String newAlphaPass){
        /*Muda a senha alphanumerica */
        this.alphaPass = newAlphaPass;
    }

    public void setNumPass(String newNumPass){
        /*Muda a senha numerica */
        this.numPass = newNumPass;
    }

}
