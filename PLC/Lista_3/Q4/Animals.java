package Q4;

public abstract class Animals {
    private String name;
    private int[] pos;
    
    public Animals(String name, int x, int y){
        /*Inicializa o nome do animal, e a sua posicao */
        this.name = name;
        int[] position = {x,y};
        this.pos = position;
    }

    public String getName(){
        /*Retorna o nome do animal */
        return this.name;
    }

    public int[] getPos(){
        /*Retorna a posicao do animal */
        return this.pos;
    }

    public void setName(String name){
        /*Muda o nome do animal */
        this.name = name;
    }

    public void setPos(int x, int y){
        /*Retorna a posicao do animal */
        this.pos[0] = x;
        this.pos[1] = y;
    }

    //Metodo abstrado, a ser implementado por cada tipo de animal
    public abstract String talk();
}
