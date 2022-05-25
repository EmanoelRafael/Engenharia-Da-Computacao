package Q4;

public class Lion extends Animals {
    
    private String sound;

    public Lion(String name, int x, int y){
        /*Inicializa o animal e define o som dele */
        super(name, x, y);
        this.sound = "miau";
    }

    public String getSound(){
        /*Retorna o som do animal (Atributo do objeto) */
        return this.sound;
    }

    public void setSound(String sound){
        /*Muda o nome do animal */
        this.sound = sound;
    }

    @Override
    public String talk(){
        /*Retorna o som do animal (Faz o animal "falar")*/
        return this.sound;
    }

}
