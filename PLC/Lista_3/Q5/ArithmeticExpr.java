package Q5;

public class ArithmeticExpr implements Expression<String> {

    String expr;
    String exprSolved;

    public ArithmeticExpr(String expr){
        /*Inicializa a expressao*/
        this.expr = expr;
        this.exprSolved = null;
    }

    public String getExpr(){
        /*Retorna a expressao*/
        return this.expr;
    }

    private Result<Double> solveDiv(String div){
        /*Funcao que recebe uma expressao contendo somente divisoes (podendo ser
        nenhuma divisao) e resolve ela */

        //Inicializa o resultado da divisao (Double)
        Double res = 0.0;

        //Inicializa a string que vai armazenar a string da expressao resolvida (Com parametros)
        String exp = "";

        //Inicializa um contador
        int i = 0;

        //Obtem os numeros da expressao
        String[] nums= div.split("/");

        //Realiza as divisoes (da esquerda para a direita)
        for (String num : nums) {
            i++;
            
            if (i == 1) {
                //Se o numero for o primeiro, o resultado deve ser inicializado
                res = Integer.parseInt(num) + 0.0;
                exp += ("("+num+")");
            }else{
                //Se o numero nao for o primeiro o resultado vai ser dividido pelo numero
                res /= Integer.parseInt(num);
                exp = ("("+exp + "/"+"("+num+")"+")");
            }
        }

        //Instancia um objeto resultado e armazena o resultado da divisao e a expresso com parenteses
        Result<Double> result = new Result<Double>(res, exp);
        return result;
    }

    private Result<Double> solveMul(String mul){
        /*Funcao que recebe uma expressao contendo multiplicacoes de subexpressoes (que 
        podem conter divisoes) e resolve ela */

        //Inicializa o resultado da multiplicacao (Double)
        Double res = 1.0;

        //Inicializa a string que vai armazenar a string da expressao resolvida (Com parametros)
        String exp = "";

        //Inicializa um contador
        int i = 0;

        //Inicializa um objeto resultado
        Result<Double> result;

        //Obtem as subexpressoes
        String[] divs= mul.split("\\*");

        //Realiza as multiplicacoes (da esquerda para a direita)
        for (String div : divs) {
            i++;
            //Resolve a subexpressao(que pode conter divisao)
            result = this.solveDiv(div);

            //Se for a primeira subexpressao a expressao com parenteses precisa ser inicializada
            if (i == 1) {
                res *= result.getRes();
                exp += result.getStrRes();
            } else {
                res *= result.getRes();
                exp = ("("+exp+"*"+result.getStrRes()+")");
            }
        }
        
        //Instancia um objeto resultado e armazena o resultado da divisao e a expresso com parenteses
        result = new Result<Double>(res, exp);
        return result;
    }

    private Result<Double> solveSub(String sub){
        /*Funcao que recebe uma expressao contendo subtracoes de subexpressoes (que 
        podem conter divisoes e multiplicacoes) e resolve ela */

        //Inicializa o resultado da subtracao (Double)
        Double res = 0.0;

        //Inicializa a string que vai armazenar a string da expressao resolvida (Com parametros)
        String exp = "";

        //Inicia o contador
        int i = 0;

        //Inicializa um objeto resultado
        Result<Double> result;

        //Obtem as subexpressoes
        String[] muls= sub.split("-");

        //Realiza as subtracoes (da esquerda para a direita)
        for (String mul : muls) {
            i++;
            //Resolve a subexpressao(que pode conter multiplicacoes e divisoes)
            result = this.solveMul(mul);

            //Se a subexpressao for a primeira o resultado deve ser inicializado
            if (i == 1) {
                res = result.getRes() + 0.0;
                exp += result.getStrRes();
            }else{
                res -= result.getRes();
                exp = ("("+exp+"-"+result.getStrRes()+")");
            }
        }
        
        //Instancia um objeto resultado e armazena o resultado da divisao e a expresso com parenteses
        result = new Result<Double>(res, exp);
        return result;
    }

    private Result<Double> solveSum(String sum){
        /*Funcao que recebe uma expressao contendo somas de subexpressoes (que 
        podem conter subtracoes, divisoes e multiplicacoes) e resolve ela */

        //Inicializa o resultado da soma (Double)
        Double res = 0.0;

        //Inicializa a string que vai armazenar a string da expressao resolvida (Com parametros)
        String exp = "";

        //Inicia o contador
        int i = 0;

        //Inicializa um objeto resultado
        Result<Double> result;

        //Obtem as subexpressoes
        String[] subs= sum.split("\\+");

        //Realiza as somas (da esquerda para a direita)
        for (String sub : subs) {
            i++;

            //Resolve a subexpressao(que pode conter subtracoes, multiplicacoes e divisoes)
            result = this.solveSub(sub);

            //Se for a primeira subexpressao a expressao com parenteses precisa ser inicializada
            if (i==1) {
                res += result.getRes();
                exp += result.getStrRes();
            } else {
                res += result.getRes();
                exp = ("("+exp+"+"+result.getStrRes()+")");
            }
        }

        //Instancia um objeto resultado e armazena o resultado da divisao e a expresso com parenteses
        result = new Result<Double>(res,exp);
        return result;
    }

    @Override
    public String solve(){
        /*Metodo que resolve a espressao com somas, subtracoes, multiplicacoes e divisoes, 
        obtem o valor e a expressao resolvida com parametros*/

        Result<Double> res = solveSum(this.expr);
        this.exprSolved = res.getStrRes();
        return ""+res.getRes();
    }

    @Override
    public String show(){
        /*Metodo que retorna a expressao resolvida com parametros */

        //Se a expressao ainda nao foi resolvida, precisa ser
        if (this.exprSolved == null) {
            this.solve();
        }

        return this.exprSolved;
    }

}
