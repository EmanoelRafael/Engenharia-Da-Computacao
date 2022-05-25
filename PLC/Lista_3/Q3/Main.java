package Q3;

public class Main {

    public static void show(String str){
        System.out.println(str);
    }
    public static void main(String[] args) {
        
        //Instancia uma conta
        SavingAccount c1 = new SavingAccount("1", "123-4", 10, "10DE10", "131313");
        
        //Mostra o saldo da conta
        show("Saldo da conta:  "+c1.getBalance());

        //Debita um valor na conta 
        float val = (float)100.5;
        c1.debit(val);
        
        //Mostra o novo saldo da conta
        show("Saldo da conta:  "+c1.getBalance());

        //Credita no saldo da conta
        val = (float) 50.25;
        c1.credit(val);

        //Mostra o novo saldo da conta
        show("Saldo da conta:  "+c1.getBalance());

        //Faz a conta render o juros, com a taxa default da conta
        c1.render();

        //Mostra o novo saldo da conta
        show("Saldo da conta:  "+c1.getBalance());

        //Faz a conta render o juros, com a taxa de 0.05 (5%)
        c1.render(0.05);

        //Mostra o novo saldo da conta
        show("Saldo da conta:  "+c1.getBalance());

    }
}
