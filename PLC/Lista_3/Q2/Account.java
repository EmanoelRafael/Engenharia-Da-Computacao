package Q2;

public class Account {
    private String identifier;
    private String agency;
    private float balance;
    private Password password;

    public Account(String id, String ag, float bal, String alphaPass, String numPass){
        /*Construtor utsando o construtor com parametros do Password */
        this.identifier = id;
        this.agency = ag;
        this.balance = bal;
        this.password = new Password(alphaPass, numPass);
    }

    public Account(String id, String ag, float bal){
        /*Construtor utsando o construtor default do Password */
        this.identifier = id;
        this.agency = ag;
        this.balance = bal;
        this.password = new Password();
    }

    public String getIdentifier(){
        /*Retorna o identificador */
        return this.identifier;
    }

    public String getAgency(){
        /*Retorna a agencia */
        return this.agency;
    }

    public float getBalance(){
        /*Retorna o saldo */
        return this.balance;
    }

    public Password getPassword(){
        /*Retorna a senha */
        return this.password;
    }

    public void setIdentifier(String newId){
        /*Muda o identificador */
        this.identifier = newId;
    }

    public void setAgency(String newAg){
        /*Muda a agencia */
        this.agency = newAg;
    }

    public void setBalance(float newBal){
        /*Muda o saldo */
        this.balance = newBal;
    }

    public void changeAlphaPass(String alphaPass){
        /*Muda a senha alphanumerica */
        this.password.setAlphaPass(alphaPass);
    }

    public void changeNumPass(String numPass){
        /*Muda a senha numerica */
        this.password.setNumPass(numPass);
    }
}
