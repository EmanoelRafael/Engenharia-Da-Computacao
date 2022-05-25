package Q4;

public class Zoo {
    boolean[][] map;
    Animals[] animals;
    Robot[] robots;
    int qntAnimals;
    int qntRobots;
    int maxAnimals;
    int maxRobots;

    public Zoo(int[] zooSize, int maxAnimals, int maxRobots){
        /*Construtor que inicializa os atributos do objeto, os vetores de robos e animais são 
        inicializados com seus respectivos tamanhos, a quantidade de animais e robos no zoo
        sao inicializados como 0 e todas as posicoes do zoo sao inicializadas como vazias (false)*/

        this.map = new boolean[zooSize[0]][zooSize[1]];
        for (int i = 0; i < zooSize[0]; i++) {
            for (int j = 0; j < zooSize[1]; j++) {
                this.map[i][j] = false;
            }
        }
        this.animals = new Animals[maxAnimals];
        this.robots = new Robot[maxRobots];
        this.qntAnimals = 0;
        this.qntRobots = 0;
        this.maxAnimals = maxAnimals;
        this.maxRobots = maxRobots;
    }

    public boolean insert(Animals newAnimal){
        /*Insere um novo animal no zoo*/
        
        //Se a posicao do animal for fora do zoo, se a posicao do animal ja tiver ocupada ou se o zoo ja 
        //estiver com a quantidade maxima de animais o novo animal não pode ser inserido (retorna false)
        if (newAnimal.getPos()[0]>3 || newAnimal.getPos()[1]>2 || newAnimal.getPos()[0]<0 || newAnimal.getPos()[1]<0) {
            return false;
        }else if (this.map[newAnimal.getPos()[0]][newAnimal.getPos()[1]] || this.qntAnimals >= this.maxAnimals) {
            return false;
        }
        
        //Adiciona o animal no vetor de animais, incrementa a qnt de animais e ocupa a posicao do animal no zoo
        this.animals[this.qntAnimals] = newAnimal;
        this.qntAnimals += 1;
        this.map[newAnimal.getPos()[0]][newAnimal.getPos()[1]] = true;
        return true;
    }

    public boolean insertRobots(Robot newRobot){
        /*Insere um novo robo no zoo*/
        
        //Se a posicao do robo for fora do zoo, se a posicao do robo ja tiver ocupada ou se o zoo ja 
        //estiver com a quantidade maxima de robos o novo robo não pode ser inserido (retorna false)
        if (newRobot.getPos()[0]>3 || newRobot.getPos()[1]>2 || newRobot.getPos()[0]<0 || newRobot.getPos()[1]<0) {
            return false;
        }else if (this.map[newRobot.getPos()[0]][newRobot.getPos()[1]] || this.qntRobots >= this.maxRobots) {
            return false;
        }

        //Adiciona o robo no vetor de robos, incrementa a qnt de robos e ocupa a posicao do robo no zoo
        this.robots[this.qntRobots] = newRobot;
        this.qntRobots += 1;
        this.map[newRobot.getPos()[0]][newRobot.getPos()[1]] = true;
        return true;
    }

    public boolean checkNeighbor(String id, String name){
        /*Funcao que recebe o id de um robo e o nome de um animal e verifica se
        estao lado a lado no zoo*/

        //inicializa o id e a pos do robo e do animal com valores invalidos 
        //(Caso algum deles nao estiver no zoo, esses valores serão usados)
        int animalID = -1, robotID = -1;
        int[] animalPos = {-1,-1}, robotPos = {-1,-1};
        
        //Procura o robo no vetor de robos, quando encontra obtem seu id e sua posicao
        for (int i = 0; i < this.qntRobots; i++) {
            if (this.robots[i].getIdentifier().equals(id)) {
                robotID = i;
                robotPos = this.robots[i].getPos();
            }
        }
        
        //Procura o animal no vetor de animais, quando encontra obtem seu nome e sua posicao
        for (int i = 0; i < this.qntAnimals; i++) {
            
            if (this.animals[i].getName().equals(name)) {
                
                animalID = i;
                animalPos = this.animals[i].getPos();
            }
        }
        
        //Se o animal ou o robo nao foi encontrado no zoo retorna false
        if (animalID == -1 || robotID == -1) {
            return false;
        }

        //Verifica se o robo e o animal sao vizinhos (verificando suas posicoes), 
        //se for faz o animal falar e troca as suas posicoes
        if ((robotPos[0]+1 == animalPos[0] && robotPos[1] == animalPos[1]) || (robotPos[0]-1 == animalPos[0] && robotPos[1] == animalPos[1]) || (robotPos[0] == animalPos[0] && robotPos[1]+1 == animalPos[1]) || (robotPos[0]+1 == animalPos[0] && robotPos[1]-1 == animalPos[1])) {
            System.out.println(this.animals[animalID].talk());
            this.animals[animalID].setPos(robotPos[0], robotPos[1]);
            this.robots[robotID].setPos(animalPos[0], animalPos[1]);
        }
        
        return true;
    }
}
