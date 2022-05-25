package Q4;

public class Robot {
    private String identifier;
    private int[] pos;

    public Robot(String id, int x, int y){
        /*Inicializa o robo, com seu id e sua posicao*/
        this.identifier = id;
        int[] position = {x,y};
        this.pos = position;
    }

    public int[] getPos(){
        /*Retorna a posicao do robo*/
        return this.pos;
    }

    public String getIdentifier(){
        /*Retorna o identificador do robo*/
        return this.identifier;
    }

    public void setPos(int x, int y){
        /*Muda a posicao do robo*/
        this.pos[0] = x;
        this.pos[1] = y;
    }

    public void setIdentifier(String id){
        /*Muda o identificador do robo*/
        this.identifier = id;
    }
}
