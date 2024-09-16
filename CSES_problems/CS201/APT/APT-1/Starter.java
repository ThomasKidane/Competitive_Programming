import java.util.HashSet;

public class Starter {
    public int begins(String[] words, String first) {
        HashSet<String> set=new HashSet<>();
        int wcount=0;
        for(int i=0;i<words.length;i++){
            String toC=words[i];
            if(words[i].startsWith(first)){
                set.add(words[i]);
            }            
        }
        return set.size();
    }
}