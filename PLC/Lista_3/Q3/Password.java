package Q3;

public class Password {
    private String alphaPass;
    private String numPass;

    public Password(){
        this.alphaPass = "123abc";
        this.numPass = "123";
    }

    public Password(String fst, String snd){
        this.alphaPass = fst;
        this.numPass = snd;
    }

    public String getAlphaPass(){
        return this.alphaPass;
    }

    public String getNumPass(){
        return this.numPass;
    }

    public void setAlphaPass(String newAlphaPass){
        this.alphaPass = newAlphaPass;
    }

    public void setNumPass(String newNumPass){
        this.numPass = newNumPass;
    }

}
