package Q2;

public class Main {

    public static void show(String str){
        /*Funcao que recebe uma string e mostra na tela */
        System.out.println(str);
    }
    public static void main(String[] args) {
        
        //Instancia uma conta usando o construtor com parametros do Password
        Account c1 = new Account("1", "045-3", 0, "10NaLista3", "132022");
        //Instancia uma conta usando o construtor default do Password
        Account c2 = new Account("2", "029-1", 0);

        //Mostra as duas senhas das contas
        show("       Senhas:");
        show("Senha AlphaNumerica de c1:  " + c1.getPassword().getAlphaPass());
        show("Senha Numerica de c1:       " + c1.getPassword().getNumPass());
        show("Senha AlphaNumerica de c2:  " + c2.getPassword().getAlphaPass());
        show("Senha Numerica de c2:       " + c2.getPassword().getNumPass() + "\n");
        
        //Muda a senha alphanumerica de c1 e a senha numerica de c2
        c1.changeAlphaPass("10NaProva3");
        c2.changeNumPass("202213");

        //Mostra as duas senhas das contas
        show("       Senhas:");
        show("Senha AlphaNumerica de c1:  " + c1.getPassword().getAlphaPass());
        show("Senha Numerica de c1:       " + c1.getPassword().getNumPass());
        show("Senha AlphaNumerica de c2:  " + c2.getPassword().getAlphaPass());
        show("Senha Numerica de c2:       " + c2.getPassword().getNumPass() + "\n");

        //Mostra o identificador e a agencia de c1
        show("      Dados c1");
        show("Identificador de c1: "+c1.getIdentifier());
        show("Agencia de c1:       "+c1.getAgency() + "\n");

        //Muda os dados de c2
        c2.setAgency("111-1");
        c2.setIdentifier("3");

        //Mostra o identificador e a agencia de c2
        show("      Dados c2");
        show("Identificador de c2: "+c2.getIdentifier());
        show("Agencia de c2:       "+c2.getAgency() + "\n");
    }
}
