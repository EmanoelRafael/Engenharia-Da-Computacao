package Q5;

public class Main {
    public static void show(String str){
        System.out.println(str);
    }

    public static int expType(String exp){
        /*Metodo que recebe uma obtem o tipo de expressao seu tipo */

        //Se a expressao conter o caractere '?' eh uma expressao ternaria
        //Se a expressao nao conter '?' e conter alguma operacao logica, eh uma expressao logica
        //Se a expressao nao conter '?' nem for uma operacao logica, eh uma expressao aritmetica
        if (exp.contains("\\?")) {
            return 1;
        } else if (exp.contains("<") || exp.contains(">") || exp.contains("=") ) {
            return 2;
        }else{
            return 3;
        }
    }

    public static void main(String[] args) {
        
        //Instancia uma expressao aritmetica
        ArithmeticExpr expA = new ArithmeticExpr("2*3+4/6");
        
        //Mostra o resultado da expressao aritmetica
        show(expA.solve());
        show(expA.show());
        
        //Instancia uma expressao logica
        LogicalExpr expL = new LogicalExpr("2+5/10<12+16");

        //Mostra o resultado da expressao logica
        show(expL.solve());
        show(expL.show());

        //Instancia uma expressao ternaria
        TernaryExpr expT = new TernaryExpr("2*3+4/6!=3/4?3<5+6:26*7*6/4+3");

        //Mostra o resultado da expressao ternaria
        show(expT.solve());
        show(expT.show());
        
        //Foi observado uma diferenca entre a expressao com parenteses retornada pela expressao ternaria do codigo
        //E a expressao esperada no enunciado, isso porque o codigo esta adicionando parenteses para isolar as subexpressoes
        //e a expressao ternaria em si: ((cond)?(fstExp):(sndExp)) e o esperado pelo enunciado eh cond?(fstExp):(sndExp)
        
    }
}
