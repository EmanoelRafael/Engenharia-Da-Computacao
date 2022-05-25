package Q3;

public class SavingAccount extends Account {
    double rate;

    public SavingAccount(String id, String ag, float bal, String alphaPass, String numPass){
        /*Inicializa os atributos do objeto, definindo a taxa default como 0,03 (3%) e o 
        construtor com parametros da senha*/
        super(id, ag, bal ,alphaPass, numPass);
        this.rate = 0.03;
    }

    public SavingAccount(String id, String ag, float bal){
        /*Inicializa os atributos do objeto, definindo a taxa default como 0,03 (3%) e o 
        construtor sem parametros da senha*/
        super(id, ag, bal);
        this.rate = 0.03;
    }

    public double getRate(){
        /*Funcao que retorna a taxa da conta*/
        return this.rate;
    }

    public void setRate(double rate){
        /*Funcao que muda a taxa da conta*/
        this.rate = rate;
    }

    public void render(double rate){
        /*Funcao que recebe uma taxa e faz o rendimento da conta a partir dessa taxa
         (debita na conta o valor "ganho")*/
        this.debit((float)rate*this.getBalance());
    }

    public void render(){
        /*Funcao que faz o rendimento da conta a partir da taxa default da conta
         (debita na conta o valor "ganho")*/
        this.debit((float)this.rate*this.getBalance());
    }
}
