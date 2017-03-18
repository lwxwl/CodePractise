/**
 * Created by Administrator on 2016/11/8.
 */

public class Fruit {
    private String name;
    private int imageId;
    private Fruit(String name,int imageId){
        this.name=name;
        this.imageId=imageId;
    }
    public String getName(){
        return name;
    }
    public int getImageId(){
        return imageId;
    }
}
