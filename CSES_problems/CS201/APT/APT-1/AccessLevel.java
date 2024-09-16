public class AccessLevel {
    public String canAccess(int[] rights, int minPermission) {
        String s=new String();
        for(int i:rights){
            if(i>=minPermission){
                s+="A";
            } else {
                s+="D";
            }
        }
        return s; 
    }


 }