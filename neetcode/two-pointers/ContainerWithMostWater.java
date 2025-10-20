
public class ContainerWithMostWater {
    public static int maxArea(int[] heights) {
        int max = 0;
        
        for(int i=0;i<heights.length;i++) {
            for(int j=i+1;j<heights.length;j++) {
                max = Math.max((j-i) * Math.min(heights[i], heights[j]), max);
            }
        }

        return max;
    }

    public static void main(String[] args) {
        System.out.println(maxArea(new int[]{1,7,2,5,4,7,3,6}));
    }
}