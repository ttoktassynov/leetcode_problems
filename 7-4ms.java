class Solution {
    public int reverse(int x) {
        
        String str = Integer.toString(Math.abs(x));
        StringBuilder sb = new StringBuilder();
        String res = sb.append(str).reverse().toString();
        try {
            return (x < 0) ? -Integer.parseInt(res) : Integer.parseInt(res);
        }
        catch(NumberFormatException ex) {
            return 0;
        }
    }
}