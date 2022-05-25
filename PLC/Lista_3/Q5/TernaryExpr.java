package Q5;

public class TernaryExpr implements Expression<String> {
    
    String exp;
    String expSolved;
    
    public TernaryExpr(String exp){
        /*Inicializa a expressao da forma: logicalExpression?expression:expression*/
        this.exp = exp;
        this.expSolved = null;
    }

    public int expType(String exp){
    
        if (exp.contains("\\?")) {
            return 1;
        } else if (exp.contains("<") || exp.contains(">") || exp.contains("=") ) {
            return 2;
        }else{
            return 3;
        }
    }

    @Override
    public String solve(){
        /*Metodo que resolve a expressao ternaria */

        //Obtem a expressao logica(condition) e as duas expressoes resultantes(fstExp e sndExp)
        String[] expressions = this.exp.split("\\?");
        String condition = expressions[0];
        String fstExp = expressions[1].split(":")[0];
        String sndExp = expressions[1].split(":")[1];

        //Instancia uma expressao logica e obtem a expressao resolvida com parenteses
        LogicalExpr cond = new LogicalExpr(condition);
        this.expSolved = "("+cond.show() + "?";

        //Instancia duas expressoes
        Expression<String> exp1 = new ArithmeticExpr("0");
        Expression<String> exp2 = new ArithmeticExpr("0");

        //Obtem a expressao ternaria com parenteses, para isso precisa-se obter cada subexpressao
        //resolvida com parenteses e como cada subexpressao pode ser uma expressao aritmetica, logica 
        //ou ternaria os objetos instanciados precisam ser apropriados

        //De acordo com cada par de possiveis tipos de subexpressao instancia as exp1 e exp2 
        //com os tipos apropriados obtem a expressao ternaria com parenteses
        if (expType(fstExp) == 1 && expType(sndExp) == 1) {
            exp1 = new TernaryExpr(fstExp);
            exp2 = new TernaryExpr(sndExp);
            this.expSolved = this.expSolved + exp1.show() + ":" + exp2.show() + ")";
        } else if (expType(fstExp) == 1 && expType(sndExp) == 2) {
            exp1 = new TernaryExpr(fstExp);
            exp2 = new LogicalExpr(sndExp);
            this.expSolved = this.expSolved + exp1.show() + ":" + exp2.show() + ")";
        } else if (expType(fstExp) == 1 && expType(sndExp) == 3) {
            exp1 = new TernaryExpr(fstExp);
            exp2 = new ArithmeticExpr(sndExp);
            this.expSolved = this.expSolved + exp1.show() + ":" + exp2.show() + ")";
        } else if (expType(fstExp) == 2 && expType(sndExp) == 1) {
            exp1 = new LogicalExpr(fstExp);
            exp2 = new TernaryExpr(sndExp);
            this.expSolved = this.expSolved + exp1.show() + ":" + exp2.show() + ")";
        } else if (expType(fstExp) == 2 && expType(sndExp) == 2) {
            exp1 = new LogicalExpr(fstExp);
            exp2 = new LogicalExpr(sndExp);
            this.expSolved = this.expSolved + exp1.show() + ":" + exp2.show() + ")";
        } else if (expType(fstExp) == 2 && expType(sndExp) == 3) {
            exp1 = new LogicalExpr(fstExp);
            exp2 = new ArithmeticExpr(sndExp);
            this.expSolved = this.expSolved + exp1.show() + ":" + exp2.show() + ")";
        } else if (expType(fstExp) == 3 && expType(sndExp) == 1) {
            exp1 = new ArithmeticExpr(fstExp);
            exp2 = new TernaryExpr(sndExp);
            this.expSolved = this.expSolved + exp1.show() + ":" + exp2.show() + ")";
        } else if (expType(fstExp) == 3 && expType(sndExp) == 2) {
            exp1 = new ArithmeticExpr(fstExp);
            exp2 = new LogicalExpr(sndExp);
            this.expSolved = this.expSolved + exp1.show() + ":" + exp2.show() + ")";
        } else if (expType(fstExp) == 3 && expType(sndExp) == 3) {
            exp1 = new ArithmeticExpr(fstExp);
            exp2 = new ArithmeticExpr(sndExp);
            this.expSolved = this.expSolved + exp1.show() + ":" + exp2.show() + ")";
        } 
        
        //Se a condicao for verdadeira, retorna o resultado da primeira expressao, se 
        //do contrario, retorna o resultado da segunda expressao
        if (Boolean.parseBoolean(cond.solve())) {
            return exp1.solve();
        } else {
            return exp2.solve();
        }
    }
    
    @Override
    public String show(){
        /*Metodo que retorna a expressao resolvida com parametros */

        //Se a expressao ainda nao foi resolvida, precisa ser
        if (this.expSolved == null) {
            this.solve();
        }
        return this.expSolved;
    }
}