package Q5;

public class LogicalExpr implements Expression<String>  {

    String exp;
    String expSolved;

    public LogicalExpr(String exp){
        /*Inicializa a expressao*/
        this.exp = exp;
        this.expSolved = null;
    }

    public String getExpr(){
        /*Retorna a expressao*/
        return this.exp;
    }

    public boolean verifyExists(String str, String r){
        /*Metodo que verifica se uma dada substring se encontra na expressao */

        if (str.split(r)[0].equals(str)) { //Pode dar problema se r estiver no fim de str
            return false;
        }else{ 
            return true;
        }
    }

    @Override
    public String solve(){
        
        //Instancia um resultado
        Result<Boolean> res = new Result<Boolean>(false, "");

        //Inicializa a variavel op, que armazena a operacao que vai ser realizada
        String op = "";

        //Verifica qual a operacao logica que esta sendo realizada
        if (verifyExists(this.exp, "<")) {
            op = "<";
        } else if (verifyExists(this.exp, ">")) {
            op = ">";
        } else if (verifyExists(this.exp, "==")) {
            op = "==";
        } else if (verifyExists(this.exp, ">=")){
            op = ">=";
        } else if (verifyExists(this.exp, "<=")) {
            op = "<=";
        } else if (verifyExists(this.exp, "!=")){
            op = "!=";
        } 

        //Instancia duas operacoes aritmeticas (pois uma operacao logica eh composta
        //Por duas operacoes aritmeticas) e obtem as subexpressoes
        ArithmeticExpr fst, snd;
        String[] expressions = this.exp.split(op);
        fst = new ArithmeticExpr(expressions[0]);
        snd = new ArithmeticExpr(expressions[1]);

        //Realiza a operacao, chamando o metodo solve para as duas expressoes aritmeticas e 
        //Realizando a operacao logica com os resultados
        if (op == "<") {
            res.setRes(Double.parseDouble(fst.solve()) < Double.parseDouble(snd.solve()));
            res.serStrRes("("+fst.show() + "<" + snd.show()+")");
        } else if (op == ">") {
            res.setRes(Double.parseDouble(fst.solve()) > Double.parseDouble(snd.solve()));
            res.serStrRes("("+fst.show() + ">" + snd.show()+")");
        } else if (op == "==") {
            res.setRes(Double.parseDouble(fst.solve()) == Double.parseDouble(snd.solve()));
            res.serStrRes("("+fst.show() + "==" + snd.show()+")");
        } else if (op == ">="){
            res.setRes(Double.parseDouble(fst.solve()) >= Double.parseDouble(snd.solve()));
            res.serStrRes("("+fst.show() + ">=" + snd.show()+")");
        } else if (op == "<=") {
            res.setRes(Double.parseDouble(fst.solve()) <= Double.parseDouble(snd.solve()));
            res.serStrRes("("+fst.show() + "<=" + snd.show()+")");
        } else if (op == "!="){
            res.setRes(Double.parseDouble(fst.solve()) != Double.parseDouble(snd.solve()));
            res.serStrRes("("+fst.show() + "!=" + snd.show()+")");
        } 

        this.expSolved = res.getStrRes();
        return ""+res.getRes();
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
