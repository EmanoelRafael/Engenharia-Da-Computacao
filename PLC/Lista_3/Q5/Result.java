package Q5;

public class Result<Type> {
    /*Classe auxiliar utilizada para armazenar o resultado completo das expressoes
    que eh composto do resultado que pode ser numerico ou logico
    e da expressao resolvida com parametros */
    private String strRes;
    private Type res;

    public Result(Type res, String strRes){
        /*Construtor da classe, inicializa o resultado da expressao (que pode ser booleano ou double)
        e a expressao resolvida com parenteses */
        this.res = res;
        this.strRes = strRes;
    }

    public Type getRes(){
        /*Retorna o resultado da expressao */
        return this.res;
    }
    public String getStrRes(){
        /*Retorna a expressao com parenteses */
        return this.strRes;
    }
    public void setRes(Type res){
        /*Muda o resultado da expressao */
        this.res = res;
    }
    public void serStrRes(String strRes){
        /*Muda a expressao com parenteses */
        this.strRes = strRes;
    }
}
