public class DNAMaxNucleotide {
    
    public String max(String[] strands, String nuc) {
        String ret="";
        for(int i=0;i<strands.length;i++){
            if(countOc(strands[i], nuc)>countOc(ret, nuc) || (countOc(strands[i], nuc)>=countOc(ret, nuc) && countOc(strands[i], nuc)!=0 && strands[i].length()>ret.length())){
                ret=strands[i];
            }
        }

        return ret;
    }
     
    public int countOc(String str,String nuc){
        int ret=0;
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)==nuc.charAt(0)){
                ret++;
            }
        }
        return ret;
    }
}