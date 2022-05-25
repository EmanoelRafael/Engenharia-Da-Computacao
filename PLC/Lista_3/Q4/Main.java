package Q4;

public class Main {

    public static void show(String str){
        System.out.println(str);
    }
    public static void main(String[] args) {
        
        //Inicializa um vetor com as dimensoes do zoo
        int[] zooSize = {4,3};

        //Instancia um zoologico, com quantidade maxima de animais e robos == 12
        Zoo zoo = new Zoo(zooSize, 12, 12);

        //Instancia um leao na posicao (0,0)
        Lion lion = new Lion("Alex", 0, 0);

        //Instancia uma cobra na posicao (1,1)
        Snake snake = new Snake("Damares", 1, 1);

        //Instancia um robo na posicao (1,0)
        Robot robot1 = new Robot("11111", 1, 0);

        //Instancia um robo na posicao (2,1)
        Robot robot2 = new Robot("22222", 2, 1);
        
        //Insere o leao, a cobra e os robos no zoologico
        zoo.insert(lion);
        zoo.insert(snake);
        zoo.insertRobots(robot1);
        zoo.insertRobots(robot2);
        
        //Checa  se o robo 1 eh vizinho da cobra Damares
        zoo.checkNeighbor("11111", "Damares");
    }
}
