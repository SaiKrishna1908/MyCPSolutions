import java.util.Arrays;

public class TrappingRainWater {
    public static int trap(int[] height) {
      int prefixSum[] = new int[height.length];
      prefixSum[0] = height[0];
      for(int i=1;i<height.length;i++) {
        prefixSum[i] = prefixSum[i-1] + height[i];
      }

      int sum = 0;
      for(int i=0;i<height.length;i++) {
        for(int j=i+1;j<height.length;j++) {
            if (height[j] >= height[i] && height[i] != 0 && height[j] != 0) {
                System.out.println(i + " " + j);
                sum +=  Math.min(height[i], height[j]) * (j-i-1) - (prefixSum[j-1] - prefixSum[i]);
                i=j-1;
                break;
            }            
        }
      }

      return sum;
    }
    public static void main(String[] args) {
        System.out.println(trap(new int[]{0,2,0,3,1,0,1,3,2,1}));
    }
}
