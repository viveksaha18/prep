// interface 
interface camera {
    void takePhoto();
}
interface musicplayer {
    void playMusic();
}
class SmartPhone implements camera, musicplayer {
    public void takePhoto() {
        System.out.println("Take Photo");
    }
    public void playMusic() {
        System.out.println("Play Music");
    }
}
public class Main {
    public static void main(String[] args) {
        SmartPhone sp = new SmartPhone();
        sp.takePhoto();
        sp.playMusic();
    }
}