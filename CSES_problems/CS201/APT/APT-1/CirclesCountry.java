public class CirclesCountry {
    public int leastBorders(int[] x, int[] y, int[] r, 
                            int x1, int y1, int x2, int y2) {
        int c=0;
        for(int i=0;i<x.length;i++){
            if(((x[i]-x1)*(x[i]-x1)+(y[i]-y1)*(y[i]-y1)<(r[i]*r[i]))!=((x[i]-x2)*(x[i]-x2)+(y[i]-y2)*(y[i]-y2)<(r[i]*r[i]))){
                c++;
            }
        }
        return c;  
    }
 }