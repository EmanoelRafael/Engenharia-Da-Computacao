package Q3;

public class Account {
    private String identifier;
    private String agency;
    private float balance;
    private Password password;

    public Account(String id, String ag, float bal, String alphaPass, String numPass){
        this.identifier = id;
        this.agency = ag;
        this.balance = bal;
        this.password = new Password(alphaPass, numPass);
    }

    public Account(String id, String ag, float bal){
        this.identifier = id;
        this.agency = ag;
        this.balance = bal;
        this.password = new Password();
    }

    public String getIdentifier(){
        return this.identifier;
    }

    public String getAgency(){
        return this.agency;
    }

    public float getBalance(){
        return this.balance;
    }

    public Password getPassword(){
        return this.password;
    }

    public void setIdentifier(String newId){
        this.identifier = newId;
    }

    public void setAgency(String newAg){
        this.agency = newAg;
    }

    public void setBalance(float newBal){
        this.balance = newBal;
    }

    public void changeAlphaPass(String alphaPass){
        this.password.setAlphaPass(alphaPass);
    }

    public void changeNumPass(String numPass){
        this.password.setNumPass(numPass);
    }

    public void debit(float value){
        /*Funcao que recebe um valor e debita (adiciona) essa quantidade no saldo */
        this.balance += value;
    }

    public boolean credit(float value){
        /*Funcao que recebe um valor e credita (retira) essa quantidade no saldo
        (somente se o saldo for suficiente, ou seja, não permite saldos negativos) */
        if (this.balance>=value) {
            this.balance -= value;
            return true;
        }
        return false;
    }
}
