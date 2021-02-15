public class Solution {
    public int firstMissingPositive(ArrayList<Integer> A) {
        if(A == null)
            return 1;
            
        int size = A.size();
        
        for (int i = 0; i < size; i++) {
            if (A.get(i) <= 0)
                A.set(i, size+2);
        }
        for (int i = 0; i < size; i++) {
            if(Math.abs(A.get(i)) <= size) {
        
                int val = Math.abs(A.get(i));
                val = Math.abs(A.get(val-1));
        
                A.set(Math.abs(A.get(i)) - 1, -val);
            }
        }
        for (int i = 0; i < size; i++) {
            if (A.get(i) > 0)
                return i + 1;
        }
        return size + 1;
    }
}
