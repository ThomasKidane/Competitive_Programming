public class Totality {
    public int sum(int[] a, String stype) {
        int S=0;
        if(stype.equals("odd")){
            for(int i=0;i<a.length;i++){
                if(i%2==1){
                    S+=a[i];
                }
            }
        } else if(stype.equals("even")){
            for(int i=0;i<a.length;i++){
                if(i%2==0){
                    S+=a[i];
                }
            }
        } else {
            for(int i:a)S+=i;
        }
        
        return S;
    }
    /*public static void main(String[] args){
        System.out.print(Integer.toString(sum(new int[] {1,2,3,4,5},"all")));
        
        //System.out.print(4%2);System.out.print("\n");
    }*/
}